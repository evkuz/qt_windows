#include "mythread.h"
#include <QDebug>
#include <QtCore>

//MyThread::MyThread(QObject *parent) : QObject(parent)
MyThread::MyThread()
{

}

MyThread::~MyThread()
{

}

void MyThread::process() // ОБработчик для thread_1
{

    // qDebug("Hello World!");
    // Создаем счетчик до 10 000 и по завершении счета генерируем сигнал NumberChanged()
    for(int i=0; i<1000; i++)
    {
        if (this->finthread) break;

        emit NumberChanged(i);
        QThread::msleep(150);

/*
    qDebug() <<"========================== INSIDE  IF ==============================";
    qDebug() << "Thread_1 Running status is " <<  this->thread()->isRunning();

    qDebug() << "Thread_1 finished status inside 'if' statement is " << this->thread()->isFinished();

    //qDebug() << "Thread idealThreadCount on this computer is " << this->thread()->idealThreadCount();
*/
    } // for

    emit finished(); //Сигнал ключевой. Как только он посылается, поток закрыт. И заход будет сюда снова только по нажатию кнопки Start
    qDebug() <<"========================== OUT OF IF ==============================";
    qDebug() << "Thread_1 Running status is " <<  this->thread()->isRunning();
    qDebug() << "Thread_1 finished status is " << this->thread()->isFinished();
    qDebug() << "Thread_1 The 'finthread' value is " << finthread;


}

void MyThread::process_2() // ОБработчик для thread_2
{

    // Создаем счетчик до 10 000 и по завершении счета генерируем сигнал NumberChanged()
    for(int i=0; i<10000; i++)
    {
        if (this->finthread)
        {

     //   QMutex mutex;
     //   mutex.lock();
           break; //Отсюда выскакивает и все, что идет ниже (а это как раз сигнал finished();!!!) уже не срабатывает !!!
           emit finished(); //Эта строчка не срабатывает. Оставляю, чтобы не забыть эту фичу.
        } //Здесь emit finished(); не отрабатывает. У потока сохраняется статус isRunning = true (!!!)
     //   mutex.unlock();
        emit NumberChanged_2(i);
        QThread::msleep(75);

    }

    emit finished(); // Вот где срабатывает сигнал завершения потока !
    qDebug() << "Thread_2 The 'finthread' value is " << finthread;
    qDebug() << "Thread_2 Running status is " <<  this->thread()->isRunning();
    qDebug() << "Thread_2 finished status is " << this->thread()->isFinished();

}



/*
void MyThread::stop()
{

   emit finished();
}
*/
