#include "view.h"

View::View(Controller &cont, QWidget *parent) : controller(cont), QMainWindow(parent) {

	// Central Widget

	QGroupBox *centralWidget = new QGroupBox();
	QVBoxLayout *centralWidgetLayout = new QVBoxLayout();
	centralWidget->setLayout(centralWidgetLayout);
	setCentralWidget(centralWidget);
	

	// Disable user window resize - however, dragging the top bar causes issues with the size
	// setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);

	setWindowTitle(QString::fromStdString(controller.VERSION));

	// MenuBar and Menu

	QMenuBar *menuBar = new QMenuBar();
	QMenu *fileMenu = new QMenu(tr("&File"));
	menuBar->addMenu(fileMenu);
	setMenuBar(menuBar);

	// Tabs

	QTabWidget *tabWidget = new QTabWidget();
	tabWidget->addTab(new ShipBoard(), tr("&Ship Board"));
	tabWidget->addTab(new AttackBoard(), tr("&Attack Board"));
	tabWidget->addTab(new ShipInventory(), tr("Ship &Inventory"));
	centralWidgetLayout->addWidget(tabWidget);

	// Labels and Buttons

	QGroupBox *buttonWidget = new QGroupBox();
	QBoxLayout *buttonWidgetLayout = new QHBoxLayout();
	buttonWidget->setLayout(buttonWidgetLayout);
	centralWidgetLayout->addWidget(buttonWidget);

	QComboBox *playerFlagComboBox = new QComboBox();
	playerFlagComboBox->setMaximumSize(QSize(150, 25));
	buttonWidgetLayout->addWidget(playerFlagComboBox);

	QLabel *playerName = new QLabel("Player");
	buttonWidgetLayout->addWidget(playerName);

	QPushButton *newGame = new QPushButton("New Game");
	buttonWidgetLayout->addWidget(newGame);

	QPushButton *startGame = new QPushButton("Start Game");
	buttonWidgetLayout->addWidget(startGame);
}

View::~View() {

}
