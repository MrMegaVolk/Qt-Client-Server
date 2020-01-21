#include "tserver.h"

TServer::TServer() {
	// load Settings
	QString strlog, strdata;

	fsettings = new QFile("settings.txt");
	if (fsettings->exists()) {
		if (fsettings->open(QIODevice::ReadOnly | QIODevice::Text)) {
			QTextStream in (fsettings);

			in >> Serverport >> strlog;
		}
	}
	else {
		if (fsettings->open(QIODevice::WriteOnly | QIODevice::Text)) {
			QTextStream out (fsettings);

			Serverport = 32094;
			strlog = "log.txt";

			out << Serverport << "\n" << strlog;
		}
	}

	flog = new QFile(strlog);
	fsettings->close();

	// Set Settings
	if (!this->listen(QHostAddress::AnyIPv4, Serverport)){
		PrintStat("Error: Unable to start the server. The port is busy.");
		this->close();
		LogToFile("Server is not started");

		SomeError();
	 }
	LogToFile("Server started");


	// null's
	TSocketList = new QList<TSocket*>();

	// connects
	connect(this, SIGNAL(newConnection()), SLOT(NewConnection()));
}

//slots
void TServer::aboutToQuit() {
	for (int i = TSocketList->length() - 1; i > 0; i--) {
		// Завершения сокет
		TSocketList->at(i)->Disconnect();

		TSocketList->pop_back();
	}
}
void TServer::NewConnection() {
	TSocket* nsock = new TSocket(this->nextPendingConnection());
	nsock->pos = TSocketList->length();
	TSocketList->push_back(nsock);

	//nsock->start(); // а смысл?
	connect(nsock, SIGNAL(PrintClients(QString, QString, int)), this, SIGNAL(PrintClients(QString, QString, int)));
	connect(nsock, SIGNAL(ClosedSocket(TSocket*)), this, SLOT(ClosedSocket(TSocket*)));

	PrintDescr("New Connectrion from: " + nsock->GetIP());
}

void TServer::ClosedSocket(TSocket *socket) {
	for (int i = 0; i < TSocketList->length(); i++) {
		if (TSocketList->at(i)->pos == socket->pos) {
			TSocketList->removeAt(i);
			break;
		}
	}

	for (int i = 0; i < TSocketList->length(); i++) {
		TSocketList->at(i)->pos = i;
	}
}
void TServer::LogToFile(QString str) {
	if (!flog->exists())
		PrintStat("log file does not exist");
	 if (!flog->open(QIODevice::Append | QIODevice::Text)) {
		PrintStat("Failed write to log file");

		if (!flog->open(QIODevice::WriteOnly | QIODevice::Text))
		    return;
	 }

	  QTextStream out(flog);
	  out << QDateTime::currentDateTime().date().year() << "." <<
			QDateTime::currentDateTime().date().month() << "." <<
			QDateTime::currentDateTime().date().day() << "-" <<
			QDateTime::currentDateTime().time().hour() << ":" <<
			QDateTime::currentDateTime().time().minute() << ":" <<
		   QDateTime::currentDateTime().time().second() << "	" <<
			str << "\n";
	  flog->close();

}
