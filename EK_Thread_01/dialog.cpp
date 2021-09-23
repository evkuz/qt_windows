#include "dialog.h"
#include "ui_dialog.h"
//#include <QObject>
#include <QDialog>
#include "mythread.h"
#include <QThread>
//#include <QtCore>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // ============================================== Создаем поток 1
    thread_1 = new QThread;
    worker_1 = new MyThread();
    worker_1->moveToThread(thread_1);

    connect(thread_1, SIGNAL(started()), worker_1, SLOT(process()) );
    connect(worker_1, SIGNAL(finished()), thread_1, SLOT(quit()));
    connect(worker_1, SIGNAL(NumberChanged(int)), this, SLOT(OnNumberChanged(int)));

    // ============================================== Создаем поток 2
    thread_2 = new QThread;
    worker_2 = new MyThread();
    worker_2->moveToThread(thread_2);

    connect(thread_2, SIGNAL(started()), worker_2, SLOT(process_2()) );
    connect(worker_2, SIGNAL(finished()), thread_2, SLOT(quit()));
    connect(worker_2, SIGNAL(NumberChanged_2(int)), this, SLOT(OnNumber_2_Changed(int)));


}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::OnNumberChanged(int Number)
{
ui->label->setText(QString::number(Number));

}


void Dialog::OnNumber_2_Changed(int Number)
{
ui->label_2->setText(QString::number(Number));

}

void Dialog::on_Button_Th1_Start_clicked()
{
  worker_1->finthread = false;
  thread_1->start() ; //Запускаем поток, и у нас генерируется сигнал started()====> Срабатывает слот process(), в котором и происходит запуск счетчика. !
}

void Dialog::on_Button_Th2_Start_clicked()
{
    // Start Thread 2
    worker_2->finthread = false;
    thread_2->start();
}

void Dialog::on_Button_Th1_Stop_clicked()
{
    // Stop Thread 1
   //  thread_1->quit();
    worker_1->finthread = true;
}

void Dialog::on_Button_Th2_Stop_clicked()
{
    // Stop Thread 2
    worker_2->finthread = true;
}
