#ifndef VIEW_H
#define VIEW_H

#include "constants.h"
#include "controller.h"
#include "shipinventory.h"
#include "shipboard.h"
#include "attackboard.h"
#include <QMainWindow>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QMenuBar>
#include <QMenu>
#include <qcombobox>
#include <QHBoxLayout>
#include <QTabWidget>
#include <qsize>
#include <qlabel>
#include <qpushbutton>

class View : public QMainWindow
{
    Q_OBJECT

    private:
        Controller &controller;

    public:
        View(Controller &ctrl, QWidget *parent = 0);
        ~View();
};

#endif // VIEW_H
