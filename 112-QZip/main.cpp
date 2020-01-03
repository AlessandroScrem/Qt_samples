#include <QCoreApplication>
#include <QtDebug>
#include <QFile>
#include "JlCompress.h"

void CompressDir(QString ZipFile, QString Directory)
{
    if(JlCompress::compressDir(ZipFile, Directory))
    {
        qDebug() << "Created: " << ZipFile;
    }else
    {
        qDebug() << "Could not create: " << ZipFile;
    }
}
void DecompressDir(QString ZipFile, QString Directory)
{
    QStringList list = JlCompress::extractDir(ZipFile, Directory);

    foreach(QString item, list)
    {
        qDebug() << "Extracted: " << item;
    }
}
void CompressFiles(QString ZipFile, QStringList Files)
{
    if(JlCompress::compressFiles(ZipFile, Files))
    {
        qDebug() << "Created: " << ZipFile;
    }else
    {
        qDebug() << "Could not create: " << ZipFile;
    }
}
void DecompressFiles(QString ZipFile, QStringList Files, QString Directory)
{
    QStringList list = JlCompress::extractFiles(ZipFile, Files, Directory);

    foreach(QString item, list)
    {
        qDebug() << "Extracted: " << item;
    }

}
void ListContents(QString ZipFile)
{
    QFile File(ZipFile);

    if(!File.exists())
    {
        qDebug() << "ZipFIle not found!";
        return;
    }

    QStringList list = JlCompress::getFileList(ZipFile);

    foreach(QString item, list)
    {
        qDebug() << item;
    }

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString ZipFile = "C:/Users/ascre_p1ijxgd/Documents/ProgC/Qtesempi/QZip/test.zip";
    QString OriginalDir = "C:/Users/ascre_p1ijxgd/Documents/ProgC/Qtesempi/QZip/Original";
    QString NewDir = "C:/Users/ascre_p1ijxgd/Documents/ProgC/Qtesempi/QZip/newdir";
    QString SingleFile = OriginalDir + "/text.txt";

    // Compress a directory
    CompressDir(ZipFile, OriginalDir);

    // List content of a zip file
    ListContents(ZipFile);

    // Compress a single file
    //CompressFiles(ZipFile, QStringList() << SingleFile);

    // Decompress an archive to a directory
    //DecompressDir(ZipFile, NewDir);

    // Decompress a single file
    DecompressFiles(ZipFile, QStringList() << "text.txt", NewDir);

    return a.exec();
}
