#ifndef SINGLEINSTANCE_H
#define SINGLEINSTANCE_H

#include <QObject>
#include <QDebug>
#include <QLocalServer>
#include <QLocalSocket>

class SingleInstance : public QObject
{
    Q_OBJECT
public:
    explicit SingleInstance(QObject *parent = nullptr);
    ~SingleInstance();

    /**
     * @brief Listen for a connection
     * @param name
     */
    void Listen(QString name);

    /**
     * @brief Determine if a previous instance exists
     * @param name
     * @param arg
     * @return
     */
    bool HasPrevoious(QString name, QStringList arg);

signals:

    /**
     * @brief Emitted when new instance is launched
     */
    void newInstance();

public slots:

    /**
     * @brief Called when a new instance is opened
     */
    void newConnection();

    /**
     * @brief Read from the socked
     */
    void readyRead();

private:

    /**
     * @brief Local socket
     */
    QLocalSocket* mSocket;

    /**
     * @brief The server
     */
    QLocalServer mServer;

};

#endif // SINGLEINSTANCE_H
