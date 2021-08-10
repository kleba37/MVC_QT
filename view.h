#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include "model.h"
#include "controller.h"

class View : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(Model* model READ model WRITE setModel NOTIFY modelChanged)

private:
    Model* m_model;
    Controller * m_controller;

public:
    View(QWidget * parent = nullptr): QWidget(parent){

    }
    void setModel(Model * model){
        this->m_model = model;
        this->m_controller->setModel(this->m_model);
    }
    void setController(Controller * controller){
        this->m_controller = controller;
        this->m_controller->setView(this);
    }
    // QWidget interface
    Model* model() const
    {
        return m_model;
    }

signals:
    void modelChanged(Model* model);

protected:
    void paintEvent(QPaintEvent *event)
    {
        QPainter p(this);
        p.drawEllipse(*(this->model()->getModel()));
    }
};

#endif // VIEW_H
