
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <BoxStorage.h>
#include <BoxListModel.h>

int main(int argc, char** argv){
	QGuiApplication app(argc,argv);
	BoxStorage storage;
	QQmlApplicationEngine engine;
	qmlRegisterSingletonInstance<BoxListModel>("StorageImpl",1,0,"BoxModel",storage.getBoxListModel());
	engine.load(QUrl("qrc:/UI/main.qml"));
	return app.exec();
}
