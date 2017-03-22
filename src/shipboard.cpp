#include "shipboard.h"


ShipBoard::ShipBoard(QWidget *parent) : QWidget(parent) {
	
	// QWidget Layout
	QVBoxLayout *widgetLayout = new QVBoxLayout();
	setLayout(widgetLayout);

	// Table Widget
	tableWidget = new QTableWidget;
	QVBoxLayout *tableWidgetLayout = new QVBoxLayout();
	tableWidget->setLayout(tableWidgetLayout);
	rows = BOARD_ROWS;
	cols = BOARD_COLS;
	tableWidget->setRowCount(rows);
	tableWidget->setColumnCount(cols);

	for (int index = 0; index < cols; index++) {
		tableWidget->setColumnWidth(index, TABLE_COL_WIDTH);
	}

	for (int index = 0; index < rows; index++) {
		tableWidget->setRowHeight(index, TABLE_ROW_HEIGHT);
	}


	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {

			QTableWidgetItem *item = new QTableWidgetItem();
			item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable);
			tableWidget->setItem(row, col, item);
		}
	}

	tableWidget->setMouseTracking(true);
	tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
	tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	tableWidget->setShowGrid(true);


	widgetLayout->addWidget(tableWidget);	
}


ShipBoard::~ShipBoard() {

}
