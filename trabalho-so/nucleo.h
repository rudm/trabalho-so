#ifndef NUCLEO_H
#define NUCLEO_H

#include <QThread>

class Processo;
class Nucleo : public QThread
{
    Q_OBJECT

public:
    enum Status {
        DISPONIVEL,
        OCUPADO
    };

public:
    explicit Nucleo(qint64 a_id = 0, Status a_status = DISPONIVEL, QObject *parent = 0);

    void run();

    bool isOcupado() const;
    bool isDisponivel() const;

    qint64 id() const;
    void setId(const qint64 &id);

    Status status() const;
    void setStatus(const Status &status);

    Processo* processo() const;
    void setProcesso(Processo *processo);

    bool stop() const;
    void setStop(bool stop);

signals:
    void processamentoTerminado();

public slots:

private:
    qint64 m_id;
    Status m_status;
    Processo* m_processo;
    bool m_stop;
};

#endif // NUCLEO_H
