#include <QCoreApplication>
#include <QTimer>
#include <QDebug>
#include <QString>

void printFinish()
{
    qDebug() << "finished\n";
    QCoreApplication::quit();
}

int main(int argc, char *argv[])
{
    const int second2msecondConvert = 1000;
    QCoreApplication a(argc, argv);
    int timeout = a.arguments().at(1).toInt();
    if (timeout < 0)
    {
        return -1;
    }
    qDebug() << "Start: \n";
    QTimer::singleShot(timeout*second2msecondConvert, &a, &printFinish);

    return a.exec();
}
