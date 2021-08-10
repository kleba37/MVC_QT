#include "mainwindow.h"
#include <QApplication>
#include "view.h"
#include "model.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Model * model = new Model(new QRect(0,0, 150,150));
    View *view = new View();
    Controller *controller = new Controller(model);
    controller->setModel(model);
    controller->setView(view);
    view->setController(controller);
    view->setModel(model);
    w.setView(view);
    w.show();

    return a.exec();
}
