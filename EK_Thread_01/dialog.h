#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "mythread.h"
#include <QThread>


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
MyThread *worker_1, *worker_2;
QThread *thread_1, *thread_2;

private:
    Ui::Dialog *ui;

public slots:
void OnNumberChanged(int) ;
void OnNumber_2_Changed(int);

private slots:

    void on_Button_Th1_Start_clicked();

    void on_Button_Th2_Start_clicked();

    void on_Button_Th1_Stop_clicked();

    void on_Button_Th2_Stop_clicked();



};

#endif // DIALOG_H
