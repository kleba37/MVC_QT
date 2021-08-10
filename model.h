#ifndef MODEL_H
#define MODEL_H
#include <QObject>
#include <QRect>

class Model : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QRect* model READ getModel WRITE setModel NOTIFY modelChanged)
private:
    QRect * m_model;
public:
Model(QRect *rect = nullptr) : m_model(rect){}
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
