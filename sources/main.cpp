#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <qlive.h>
#include <httpserver.h>

#define SERVER false

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

#if SERVER
    HttpServer server( "server" );
#else

#ifdef Q_OS_MAC
    QLive client( &engine, QLIVE_LOCAL );
    client.SetServer( "https://codedlife.ru" );
#else
    QLive client( &engine, QLIVE_EXTERN );
    client.SetServer( "https://codedlife.ru" );
    client.SetErrorPage( "qrc:/qml/ErrorPage.qml" );
#endif
#endif

    return app.exec();
}
