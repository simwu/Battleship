#pragma once

#include "constants.h"
#include <QWidget>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QTableWidgetItem>

class ShipBoard : public QWidget {
	
	Q_OBJECT

	private:
		QTableWidget *tableWidget;
		int rows;
		int cols;

		const int TABLE_COL_WIDTH = 30;
		const int TABLE_ROW_HEIGHT = 30;

	public:
		ShipBoard(QWidget *parent = 0);
		~ShipBoard();

	signals:

	public slots:

};

