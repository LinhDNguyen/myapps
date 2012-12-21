#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "buttonread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int cnt;
    ButtonRead *br;
public slots:
    void updateUI();
    void updateButtons(int number, int value);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
