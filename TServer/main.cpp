#include <QCoreApplication>

#include "core.h"

#include "pstatus.h"
#include "tserver.h"

int main(int argc, char *argv[]) {
	QCoreApplication app(argc, argv);

	PStatus *Status = new PStatus();
	Status->isClient = false;
	Status->start();
	QObject::connect(Status, SIGNAL(finished()), &app, SLOT(quit()));

	TServer *Serv = new TServer();
	QObject::connect(&app, SIGNAL(aboutToQuit()), Serv, SLOT(aboutToQuit()));
	QObject::connect(Serv, SIGNAL(PrintStat(QString)), Status, SLOT(PrintStat(QString)));
	QObject::connect(Serv, SIGNAL(PrintDescr(QString)), Status, SLOT(PrintDescr(QString)));
	QObject::connect(Serv, SIGNAL(SomeError()), &app, SLOT(quit()));
	QObject::connect(Serv, SIGNAL(PrintClients(QString, QString, int)), Status, SLOT(PrintClients(QString, QString, int)));

	Serv->PrintStat("Working");
	Serv->PrintDescr("Waiting for connects");

	return app.exec();
}
