#include "downloader.h"

Downloader::Downloader(QObject *parent) : QObject(parent)
{

}

void Downloader::doDownload()
{

    manager = new QNetworkAccessManager(this);

    connect (manager, &QNetworkAccessManager::finished, this, &Downloader::replyFinished);

    manager->get(QNetworkRequest(QUrl("https://www.google.it")));

}

void Downloader::replyFinished(QNetworkReply *reply)
{
    if(reply->error())
      {
          qDebug() << "ERROR!";
          qDebug() << reply->errorString();
          qDebug() << "sslLibraryBuildVersionString " << QSslSocket::sslLibraryBuildVersionString();
          qDebug() << "sslLibraryVersionString " << QSslSocket::sslLibraryVersionString();

      }
      else
      {
          qDebug() << "Header "   << reply->header(QNetworkRequest::ContentTypeHeader).toString();
          qDebug() << "Modified " << reply->header(QNetworkRequest::LastModifiedHeader).toDateTime().toString();;
          qDebug() << "Type "     << reply->header(QNetworkRequest::ContentTypeHeader).toString();
          qDebug() << "Size "     << reply->header(QNetworkRequest::ContentLengthHeader).toLongLong();
          qDebug() << "Status "   << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
          qDebug() << "Reply "    << reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();

      }

      reply->deleteLater();
}
