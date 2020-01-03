#ifndef LINKFILTER_H
#define LINKFILTER_H

#include <QObject>
#include <QEvent>

class LinkFilter : public QObject
{
    Q_OBJECT
public:
    explicit LinkFilter(QObject *parent = nullptr);

signals:
    void linkClicked(const QString&);

protected:
    bool eventFilter(QObject *object, QEvent *event);

public slots:
};

#endif // LINKFILTER_H
