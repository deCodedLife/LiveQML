#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <qlive.h>
#include <httpserver.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

#ifdef Q_OS_MAC
//    HttpServer server( "server" );
    QLive client( &engine, QLIVE_EXTERN );
    client.SetServer( "https://codedlife.ru/" );
#else
    QLive client( &engine, QLIVE_EXTERN );
    client.SetServer( "https://codedlife.ru" );
#endif

    client.SetErrorPage( "qrc:/qml/ErrorPage.qml" );

    return app.exec();
}
