#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>
#include "view.h"
#include "model.h"

class Controller : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Model* model READ model WRITE setModel NOTIFY modelChanged)
    Q_PROPERTY(View* view READ view WRITE setView NOTIFY viewChanged)
protected:
    Model* m_model;
    View* m_view;

public:
//    Controller(Model * model = new Model(), View * view = new View()) : m_view(view), m_model(model){}
    Controller(){
        QObject::connect(this, &Controller::modelChanged, this, &Controller::sizeTo);
    }
    ~Controller(){delete this->m_model; delete this->m_view;}
    Model *model() const
    {
        return this->m_model;
    }
    View *view() const
    {
        return this->m_view;
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
            this->view()->setFixedSize(this->model()->getModel()->width(), this->model()->getModel()->height());
    }
signals:
    void modelChanged();
    void viewChanged();
};

#endif // CONTROLLER_H
