#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QString>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "\n";

    QFile file(a.arguments().at(1));
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Error, " << file.errorString();
        return -1;
    }
    qDebug() << "\n";

    QString textInFile;
    QTextStream inputData(&file);
    while (!inputData.atEnd()) {
        textInFile = inputData.readLine();
        qDebug() << textInFile;
    }
    qDebug() << "\n";

    file.close();

    return a.exec();
}
