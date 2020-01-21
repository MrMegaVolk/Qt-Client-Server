#ifndef TSOCKET_H
#define TSOCKET_H

#include <QTcpSocket>
#include "core.h"

//#include "echo.h"
//#include <omnithread.h>

class TSocket : public QThread {
	Q_OBJECT
public:
	TSocket(QString, int);
	TSocket(QTcpSocket*);
	void run();

	void ConnectToHost(QString, qint64);
	QString GetIP();
	int pos;

private:
	QTcpSocket* socket;
	quint16 iNextBlockSize;
	quint8 NBlockSize;

	QString ip;
	int port;

public slots:
	void ReciveMsg();
	void SendMsg(QString);
	void Disconnect();
	void disconnected();
	void Connect();
	void Reconnect();
	void Err(QAbstractSocket::SocketError);

signals:
	void PrintStat(QString);
	void PrintDescr(QString);
	void PrintClients(QString, QString, int);
	void ClosedSocket(TSocket*);
};

#endif // TSOCKET_H
