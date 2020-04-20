#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "lifeworld.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    LifeWorld world(10, 10);
    for (int x = 0; x < 2; x++)
        for (int y=0; y< 2; y++)
        {
            world.set(x, y, LifeWorld::CellStatus::Live);
        }

    world.step();
    //world.step();
    //world.step();

    return app.exec();
}
