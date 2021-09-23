#include "dialog.h"
#include <QApplication>

#include "mythread.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();
/*
    thread_1 = new QThread;
    worker_1 = new MyThread();
    worker_1->moveToThread(thread_1);

        connect(thread_1, SIGNAL(started()), worker_1, SLOT(process()) );
        connect(worker_1, SIGNAL(finished()), thread_1, SLOT(quit()));
        connect(worker_1, SIGNAL(NumberChanged(int)), this, SLOT(OnNumberChanged(int)));

        thread_2 = new QThread;
        worker_2 = new MyThread();
        worker_2->moveToThread(thread_2);

            connect(thread_2, SIGNAL(started()), worker_2, SLOT(process_2()) );
            connect(worker_2, SIGNAL(finished()), thread_2, SLOT(quit()));
            connect(worker_2, SIGNAL(NumberChanged_2(int)), this, SLOT(OnNumber_2_Changed(int)));

*/
    return a.exec();
}
