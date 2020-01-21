#ifndef TSERVER_H
#define TSERVER_H

#include "core.h"
#include "tsocket.h"

#include <QTcpServer>
class TServer : public QTcpServer {
	Q_OBJECT
public:
	TServer();

private:
	quint16 Serverport;
	QList<TSocket*> *TSocketList;

	QFile *flog;
	QFile *fsettings;

public slots:
	void aboutToQuit();
	void NewConnection();
	void ClosedSocket(TSocket*);

	void LogToFile(QString);

signals:
	void PrintStat(QString);
	void PrintDescr(QString);
	void PrintClients(QString, QString, int);

	void SomeError();
};

#endif // TSERVER_H
