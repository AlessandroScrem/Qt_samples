#include <QCoreApplication>
#include <QtXml/QtXml>
#include <QDebug>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Write XML
    QDomDocument document;

    // Make the root element
    QDomElement root = document.createElement("Books");

    // Add it to the documet
    document.appendChild(root);

    // Add some elements
    for (int i = 0; i < 10; ++i)
    {
        QDomElement book = document.createElement("Book");
        book.setAttribute("Name", "My Book " + QString::number(i));
        book.setAttribute("ID", QString::number(i));
        root.appendChild(book);

        for (int c = 0; c < 10; ++c)
        {
            QDomElement chapter = document.createElement("Chapter");
            chapter.setAttribute("Name", "My Chapter " + QString::number(c));
            chapter.setAttribute("ID", QString::number(c));
            book.appendChild(chapter);
        }

    }

    //Write to file
    QFile file("myXML.xml");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "failed to open file for write";
        return -1;
    }else
    {
        QTextStream stream(&file);
        stream << document.toString();
        file.close();
        qDebug() << "Finished";
    }


    return a.exec();
}
