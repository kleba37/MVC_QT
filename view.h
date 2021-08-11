#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include "model.h"

class View : public QWidget
{
    Q_OBJECT

private:

    Model * m_model;

public:
    View(QWidget * parent = nullptr): QWidget(parent){

    }

    ~View(){delete this->m_model;}

    void setModel(Model * model){
        this->m_model = model;
    }

protected:
    void paintEvent(QPaintEvent *event)
    {
        QPainter p(this);
        p.drawEllipse(*this->m_model->getModel());
    }
};

#endif // VIEW_H
