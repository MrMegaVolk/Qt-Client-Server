#include "tsocket.h"

TSocket::TSocket(QString IP, int PORT) {
	socket = new QTcpSocket();
	ip = IP;
	port = PORT;

	connect(socket, SIGNAL(readyRead()), SLOT(ReciveMsg()));
	connect(socket, SIGNAL(connected()), SLOT(Connect()));
	connect(socket, SIGNAL(disconnected()), SLOT(disconnected()));
	connect(socket, SIGNAL(error(QAbstractSocket::SocketError)),
				 SLOT(Err(QAbstractSocket::SocketError)));
}
TSocket::TSocket(QTcpSocket* skt) {
	socket = skt;
	ip = skt->peerAddress().toString();
	port = skt->peerPort();

	connect(socket, SIGNAL(readyRead()), SLOT(ReciveMsg()));
	connect(socket, SIGNAL(disconnected()), SLOT(Disconnect()));
}
void TSocket::run() {
	//????? а нужен ли тут поток?
}

void TSocket::ConnectToHost(QString address, qint64 port) {
	socket->connectToHost(address, port);
}
QString TSocket::GetIP() {
	return socket->peerAddress().toString();
}

void TSocket::ReciveMsg() {
	QDataStream in(socket);
	in.setVersion(QDataStream::Qt_5_5);

	QString Msg;
	NBlockSize = 0;
	while (true) {
		if (!NBlockSize) {
			if (socket->bytesAvailable() < sizeof(quint8))
				break;

			in >> NBlockSize;
		}

		if (socket->bytesAvailable() < NBlockSize)
			break;

		in >> Msg;
		NBlockSize = 0;
	}

	PrintClients(ip, Msg, pos);
}
void TSocket::SendMsg(QString str) {
	if (socket->state() == QAbstractSocket::ConnectedState) {
		QByteArray  arrBlock;
		QDataStream out(&arrBlock, QIODevice::WriteOnly);
		out.setVersion(QDataStream::Qt_5_5);

		out << quint8(0) << str;

		out.device()->seek(0);
		out << quint8(arrBlock.size() - sizeof(quint8));
		socket->write(arrBlock);
		socket->flush();
	}
}
void TSocket::Disconnect() {
	PrintStat("Disconnection                  ");
	PrintDescr("Waiting for disconnection     ");

	if (socket->state() == QAbstractSocket::ConnectedState)
		socket->disconnectFromHost();
}

void TSocket::disconnected() {
	ClosedSocket(this);
	socket->close();
}
void TSocket::Connect() {
	PrintStat("Connected                      ");
	PrintDescr("Connection estabilished       ");
}

void TSocket::Reconnect() {
	if (socket->state() != QAbstractSocket::ConnectedState)
		ConnectToHost(ip, port);
}
void TSocket::Err(QAbstractSocket::SocketError) {
	socket->waitForConnected();
	PrintStat("Disconected                    ");
	PrintDescr("failed to connect             ");
}


