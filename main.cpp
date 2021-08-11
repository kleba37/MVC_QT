#include "mainwindow.h"
#include <QApplication>
#include "view.h"
#include "model.h"
#include "controller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Model * model = new Model(new QRect(0,0, 500,500));
    View *view = new View();
    view->setModel(model);
    Controller *controller = new Controller();
    controller->setView(view);
    controller->setModel(model);
    w.setView(view);
    w.show();
    return a.exec();
}
