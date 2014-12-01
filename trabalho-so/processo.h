#ifndef PROCESSO_H
#define PROCESSO_H

#include <QObject>

class Processo : public QObject
{
    Q_OBJECT

public:
    enum Status {
        PRONTO,
        ESPERANDO,
        EXECUTANDO
    };

public:
    explicit Processo(qint64 a_id = 0, qint32 a_tempoTotal = 10, qint32 a_tempoRestante = 10,
                      Status a_status = PRONTO, QObject *parent = 0);

    qint64 getId() const;
    void setId(const qint64 &value);

    qint32 getTempoTotal() const;
    void setTempoTotal(const qint32 &value);

    Status getStatus() const;
    void setStatus(const Status &value);

    qint32 getTempoRestante() const;
    void setTempoRestante(const qint32 &value);

signals:

public slots:

private:
    qint64 m_id;
    qint32 m_tempoTotal;
    qint32 m_tempoRestante;
    Status m_status;
};

#endif // PROCESSO_H
