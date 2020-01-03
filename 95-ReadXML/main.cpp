#include <QCoreApplication>
#include <QtXml/QtXml>
#include <QDebug>

// DOM method of readings xml

void ListElements(QDomElement root, QString tagname, QString attribute)
{
    QDomNodeList items = root.elementsByTagName(tagname);

    qDebug() << "Total items = " << items.count();

    for (int i = 0; i < items.count(); ++i)
    {
        QDomNode itemnode = items.at(i);
        // convert to element
        if (itemnode.isElement())
        {
            QDomElement itemele = itemnode.toElement();
            qDebug() << itemele.attribute(attribute);
        }
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDomDocument document;

    //Read the file
    QFile file("myxml.xml");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Faled to open file for reading";
        return -1;
    }else
    {
        if (!document.setContent(&file))
        {
            qDebug() << "Faled to load documet";
            return -1;
        }
        file.close();
    }
    // get the documet
    QDomElement root = document.firstChildElement();

    // List the books
    ListElements(root, "Book", "Name");

    qDebug() << "\nMore advanced\n";

    // get the chapters
    QDomNodeList books = root.elementsByTagName("Book");
    for (int i = 0; i < books.count(); ++i)
    {
        QDomNode booknode = books.at(i);
        // convert to element
        if (booknode.isElement())
        {
            QDomElement book = booknode.toElement();
            qDebug() << "Chapters in " << book.attribute("Name");
            ListElements(book, "Chapter", "Name");
        }
    }



    qDebug() << "Finished";

    return a.exec();
}
