#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include "view.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    View * view;

    MainWindow(QWidget *parent = nullptr): QMainWindow(parent){

    }
    ~MainWindow(){}
    void setView(View * view){
        this->view =  view;
        this->setCentralWidget(this->view);
        this->repaint();
    }

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event)
    {

    }
};

#endif // MAINWINDOW_H
