#include "pstatus.h"

#include <iostream>
#include <conio.h>
#include "Windows.h"

// Output
#include <QString>
#include <QTextStream>
QTextStream cout(stdout);
//QTextStream cin(stdin); //ха-ха нету readkey


PStatus::PStatus() {
	cout << endl << "	Status: "
		<< endl << "	" << endl << endl << endl
		<< endl << "	#> ";
	cout.flush();
}

void PStatus::run() {
	PrintStatus("loading");
	PrintDescription("Load: make threads");
	isDecimal = false;

	char key;
	QString SInp;
	QRegExp en("^[a-zA-Z0-9]+$");
	QRegExp ip("((25[0-5]|2[0-4]\d|[01]?\d\d?)\.){3}(25[0-5]|2[0-4]\d|[01]?\d\d?)");
	while (true) {

		CursorToInput();
		cout << "                                                                                                                                ";
		cout.flush();
		CursorToInput();
		cout << SInp;
		cout.flush();

		key = _getch();
		QString Skey(key);

		if (!isDecimal) {
			if (en.exactMatch(Skey))
				SInp += Skey;
		}
		else if (ip.exactMatch(Skey))
			SInp += Skey;

		if (key == 8)
			SInp.chop(1);
		else if (key == 13) {
			if (SInp == "exit") {
				PrintDescription("Stop: Press Enter to exit");
				break;
			}
			else if (isClient && (SInp == "recconect" || SInp == "connect"))
				Recconect();
			else if (isClient && (SInp == "disconnect"))
				Disconnect();
			else {
				PrintDescription("Uncnown command " + SInp);
			}
			SInp = "";
		}
		else if (key == 27) {
			PrintDescription("Stop: Press Enter to exit");
			break;
		}


		if (isClient)
			KeyPress(SInp);
	}
}

void PStatus::PrintStatus(QString str) {
	SetPos(16, 1);
	cout << str;
	cout.flush();
	CursorToInput();
}
void PStatus::PrintDescription(QString str) {
	third = second;
	second = first;
	first = str;

	SetPos(8, 2);
	cout << first << endl;
	cout << "	" << second << endl;
	cout << "	" << third << endl;
	cout.flush();

	CursorToInput();
}
void PStatus::SetPos(int x, int y) {
	COORD hpos;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	hpos.X = x;
	hpos.Y = y;

	SetConsoleCursorPosition(hConsole, hpos);
}
void PStatus::CursorToInput() {
	SetPos(11, 6);
}

// slots
void PStatus::PrintStat(QString str) {
	PrintStatus(str);
}
void PStatus::PrintDescr(QString str) {
	PrintDescription(str);
}
void PStatus::PrintClients(QString ip, QString txt, int pos) {
	SetPos(4, pos + 8);
	char* str;
	itoa(pos, str, 10);
	QString pos2(str);
	cout << "From " + pos2 + " "
		   + ip + ": " + txt << endl;
}

