#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>

class MyThread : public QObject
{
    Q_OBJECT
public:
  //  explicit MyThread(QObject *parent = 0);
     MyThread();
    ~MyThread();
    bool finthread;


public slots:
        void process(); /* Создает и запускает Счетчик */
        void process_2(); /* Создает и запускает Счетчик в другом потоке */
 //       void stop();    /* Останавливает Счетчик */


signals:
        void NumberChanged(int);    /* Сигнал об изменении значения счетчика */
        void NumberChanged_2(int);    /* Сигнал об изменении значения счетчика в другом потоке*/
        void finished();            /* Сигнал о завершении работы Потока... одного или всех ? или того, в котором он сигнал вызывается ? */
  //      void error(QString err);  /* Сигнал об ошибке в работе счетчика */




};

#endif // MYTHREAD_H
