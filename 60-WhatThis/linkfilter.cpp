#include "linkfilter.h"
#include <QWhatsThisClickedEvent>

LinkFilter::LinkFilter(QObject *parent) : QObject(parent)
{

}

bool LinkFilter::eventFilter(QObject *object, QEvent *event)
{


    if(event->type() == QEvent::WhatsThisClicked)
    {
        QWhatsThisClickedEvent *wtcEvent = static_cast<QWhatsThisClickedEvent*>(event);
        emit linkClicked(wtcEvent->href());
        return true;
    }
    QObject::eventFilter(object, event);
    return false;

}
