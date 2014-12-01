#ifndef PROCESSADOR_H
#define PROCESSADOR_H

#include <QObject>

class Nucleo;
class Processador : public QObject
{
    Q_OBJECT

public:
    explicit Processador(QObject *parent = 0);

    void adicionarNucleo(Nucleo* arg);
    bool isOcioso();

    QList<Nucleo*> nucleos() const;

    Nucleo* getNucleoDisponivel();
    Nucleo* getNucleo(qint64 a_id);

    void limpar();

signals:

public slots:

private:
    QList<Nucleo*> m_nucleos;
};

#endif // PROCESSADOR_H
