#include "buttonread.h"

ButtonRead::ButtonRead(QObject *parent) :
    QThread(parent)
{
    /* Open /dev/IRQ-Test to read */
    this->is.open("/dev/IRQ-Test", std::ios::binary);
}

ButtonRead::~ButtonRead(){
    this->is.close();
}
void ButtonRead::run()
{
    char key_value[8] = {0,0,0,0,0,0,0,0};
    char pre_state[4] = {0,0,0,0};
    int i = 0;
    int number = 0, value = 0;

    while(true){
        this->is.read(key_value, 8);
        for(i=0; i<4; ++i){
            /* Check state */
            if(key_value[i*2] != pre_state[i]){
                /* State changed, print message */
                pre_state[i] = key_value[i*2];
                if(key_value[i*2 + 1] == '0'){
                    value = 2;
                }else{
                    value = 1;
                }
                number = i;
                emit buttonChanged(number, value);
            }
        }
    }
}
