#ifndef MODEL_H
#define MODEL_H
#include <QObject>
#include <QRect>

class Model : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QRect* m_model READ getModel WRITE setModel NOTIFY modelChanged)
private:
    QRect * m_model;
public:
Model(QRect *rect = nullptr) : m_model(rect){}
~Model(){delete this->m_model;}
bool operator==(Model * model){
    if(this->m_model == model->m_model) return true;
    return false;
}
QRect * getModel() const
{
    return m_model;
}
public slots:
void setModel(QRect * model)
{
    if (m_model == model)
        return;

    m_model = model;
    emit modelChanged(model);
}
signals:
void modelChanged(QRect * model);
};

#endif // MODEL_H
