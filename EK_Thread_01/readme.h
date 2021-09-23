#ifndef README
#define README

#endif // README

/*
 * КУРИМ ДОЛГО-ДОЛГО-ДОЛГО И ВНИМАТЕЛЬНО-ВНИМАТЕЛЬНО-ВНИМАТЕЛЬНО !!!!!!!!!!!!!!!!!!!!!!!!
 *
 *  https://mayaposch.wordpress.com/2011/11/01/how-to-really-truly-use-qthreads-the-full-explanation/
 *
 * По ссылке выше в данном проекте реализуем все не так как описано ниже (это урок из voidRealms).
 * Ниже скорее разложено по полочкам создание потока и сигналы со слотами.
 * В уроке 31 Функция  run() описана в разделе public класса, унаследованного от Thread  запускает счетчик до 10 000 с задержкой в 100мс, чтобы
 * было видно изменение цифр.
 * Код функции в своответствующем *.cpp файле.
 * В run () происходит генерация сигнала emit NumberChanged();
 * Сигнал-Функция void NumberChanged() - это сигнал (об изменении значения счетчика),
 * прописана в заголовке класса потока. Этот сигнал генерируется функцией emit NumberChanged();
 *
 * Функция void OnNumberChanged(int) - это public slot в заголовке Диалога - обработчик сигнала NumberChanged(),
 * он переписывает значение счетчика на экране

   Еще раз: Сигнал NumberChanged вызывает слот OnNumberChanged
   Вставка паузы QThread::msleep(милисекунд);  Causes the current thread to sleep for msecs milliseconds.


   Функция idealThreadCount(); выдает 4 потока на данном компьютере.
*/
