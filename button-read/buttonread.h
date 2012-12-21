#ifndef BUTTONREAD_H
#define BUTTONREAD_H

#include <QThread>
#include <iostream>
#include <fstream>

class ButtonRead : public QThread
{
    Q_OBJECT
public:
    explicit ButtonRead(QObject *parent = 0);
    ~ButtonRead();
    std::ifstream is;
private:
     void run();
signals:
    void buttonChanged(int number, int value);
    
public slots:
    
};

#endif // BUTTONREAD_H
