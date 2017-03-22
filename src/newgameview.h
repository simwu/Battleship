#ifndef NEWGAMEVIEW_H
#define NEWGAMEVIEW_H

#include <QDialog>
#include <QWidget>

class NewGameView : public QDialog {
    Q_OBJECT

    private:

    public:
        NewGameView(QWidget *parent = 0);
        ~NewGameView();

        const int NEW_GAME_VIEW_WIDTH = 250;
        const int NEW_GAME_VIEW_HEIGHT = 300;
};

#endif // NEWGAMEVIEW_H
