#include <QCoreApplication>
#include "../TServer/core.h"

#include "../TServer/pstatus.h"
#include "../TServer/tsocket.h"

static QFile *fsettings;

static QString Serverip;
static quint16 Serverport;

void LoadSettings() {
	fsettings = new QFile("settings.txt");
	if (fsettings->exists()) {
		if (fsettings->open(QIODevice::ReadOnly | QIODevice::Text)) {
			QTextStream in (fsettings);

			in >> Serverip >> Serverport;
		}
	}
	else {
		if (fsettings->open(QIODevice::WriteOnly | QIODevice::Text)) {
			QTextStream out (fsettings);

			Serverip = "localhost";
			Serverport = 32094;

			out << Serverip << "\n" << Serverport;
		}
	}

	fsettings->close();
}

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);
	LoadSettings();

	PStatus *Status = new PStatus();
	Status->isClient = true;
	Status->start();
	QObject::connect(Status, SIGNAL(finished()), &app, SLOT(quit()));

	Status->PrintStat("Connectiong...              ");
	//Status->PrintDescr("Waiting for connect");

	TSocket *socket = new TSocket(Serverip, Serverport);
	QObject::connect(Status, SIGNAL(KeyPress(QString)), socket, SLOT(SendMsg(QString)));
	QObject::connect(socket, SIGNAL(PrintStat(QString)), Status, SLOT(PrintStat(QString)));
	QObject::connect(socket, SIGNAL(PrintDescr(QString)), Status, SLOT(PrintDescr(QString)));
	QObject::connect(Status, SIGNAL(Recconect()), socket, SLOT(Reconnect()));
	QObject::connect(Status, SIGNAL(Disconnect()), socket, SLOT(Disconnect()));

	socket->ConnectToHost(Serverip, Serverport);

	return app.exec();
}
