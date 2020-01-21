#ifndef PSTATUS_H
#define PSTATUS_H

#include "core.h"

class PStatus : public QThread {
	Q_OBJECT
public:
	PStatus();
	void run();

	void PrintStatus(QString);
	void PrintDescription(QString);

	QString first;
	QString second;
	QString third;
	bool isClient;
	bool isDecimal;

private:
	void SetPos(int, int);
	void CursorToInput();

public slots:
	void PrintStat(QString);
	void PrintDescr(QString);
	void PrintClients(QString, QString, int);

signals:
	void KeyPress(QString);
	void Recconect();
	void Disconnect();
};

#endif // PSTATUS_H
