#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include <QObject>
#include <QHttpServer>
#include <QDirIterator>

#include "core/tobject.h"

#define HOST "0.0.0.0"
#define PORT 80

class HttpServer : public TObject
{
    Q_OBJECT
public:
    explicit HttpServer(QString workingDirectory, QObject *parent = nullptr);
    void QMLPath( QString );
    void Uploads( QString );

private:
    QString m_workingDirectory;
    QString m_qmlSources;
    QHttpServer m_server;

private slots:
    QHttpServerResponse FileServer( const QHttpServerRequest&, const QString );
    QJsonObject HandleConnection();
    QJsonObject SendData( QVariant data, int statusCode = 200 );

};

#endif // HTTPSERVER_H
