#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include "heading.h"
#include "velocity.h"
#include "rpm_bar_gauge.h"
#include "velocitygauge.h"
#include "vehicle.h"

// 0164 145 75 30 kai mobil
// git remote add origin https://github.com/veolpa/PKW_HUD.git
//            repo state info:
// git status
//            adding all changed/new files to the current stage:
// git add .
// git status
//            commiting staged files / preparing changes to merge/push:
// git commit -m "short commit message - describe changes"
//            pushes changes to github / local and server repo have the same state:
// git -u push origin main


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);


    qmlRegisterType<Heading>        ("volvera.de", 1,0, "Heading");
    qmlRegisterType<Velocity>       ("volvera.de", 1,0, "Velocity");
    qmlRegisterType<RPM_Bar_Gauge>  ("volvera.de", 1,0, "RPM_Bar_Gauge");
    qmlRegisterType<VelocityGauge>  ("volvera.de", 1,0, "VelocityGauge");
    qmlRegisterType<Vehicle>        ("volvera.de", 1,0, "Vehicle");


//    QQuickView view;
//    view.setResizeMode(QQuickView::SizeRootObjectToView);
//    view.setSource(QUrl(u"qrc:/PKW_HUD/main.qml"_qs));
//    view.show();


    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/PKW_HUD/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated, &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
