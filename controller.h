#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>
#include "./view.h"
#include "model.h"

class Controller : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Model* model READ model WRITE setModel NOTIFY modelChanged)
    Q_PROPERTY(View* view READ view WRITE setView NOTIFY viewChanged)
    //QObject::connect(this, &Controller::modelChanged, this, &Controller::sizeTo);
private:
    Model* m_model;
    View* m_view;

public:
//    Controller(Model * model = new Model(), View * view = new View()) : m_view(view), m_model(model){}
    Controller(Model * model = nullptr, View * view = nullptr) : m_view(view), m_model(model){}

    Model* model() const
    {
        return m_model;
    }
    View* view() const
    {
        return m_view;
    }

public slots:
    void setModel(Model* model)
    {
        if (m_model == model)
            return;

        m_model = model;
        emit modelChanged();
    }
    void setView(View* view)
    {
        if (m_view == view)
            return;

        m_view = view;
        emit viewChanged();
    }
    void sizeTo(){
        if(this->m_model && this->m_view)
            this->view->setMinimumSize(this->m_model->getModel()->width(), this->model()->getModel()->height());
    }
signals:
    void modelChanged();
    void viewChanged();
};

#endif // CONTROLLER_H
