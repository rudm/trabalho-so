#ifndef FILAAPTOS_H
#define FILAAPTOS_H

#include <QObject>

class Processo;
class FilaAptos : public QObject
{
    Q_OBJECT

public:
    explicit FilaAptos(QObject *parent = 0);

    QList<Processo*> processos() const;

    void adicionarProcesso(Processo* arg);
    void removerProcesso(Processo* arg);

    Processo* takeFirst();

    bool isEmpty() const;

signals:

public slots:

private:
    QList<Processo*> m_fila;
};

#endif // FILAAPTOS_H
