#include "nucleo.h"
#include "processo.h"
#include <QDebug>

Nucleo::Nucleo(qint64 a_id, Nucleo::Status a_status, QObject *parent)
    : QThread(parent)
    , m_id(a_id)
    , m_status(a_status)
    , m_stop(false)
{

}

void Nucleo::run()
{
    while (m_processo->tempoRestante() > 0) {
        QMutex l_mutex;

        l_mutex.lock();
        if (m_stop) {
            qDebug() << "--------------------------------------------------------[INTERRUPÇÃO]";
            l_mutex.unlock();
            break;
        }
        l_mutex.unlock();

        qDebug() << QString("[NUCLEO(%1) - EXECUTANDO] Processo(%2) tem tempo restante %3/%4")
                    .arg(m_id)
                    .arg(m_processo->id())
                    .arg(m_processo->tempoRestante())
                    .arg(m_processo->tempoTotal());
        m_processo->setTempoRestante(m_processo->tempoRestante() - 1);
        msleep(1000);
    }

    m_stop = false;
    m_status = DISPONIVEL;
//    emit ProcessoChanged();
    emit processamentoTerminado();
}

bool Nucleo::isOcupado() const
{
    return m_status == OCUPADO;
}

bool Nucleo::isDisponivel() const
{
    return m_status == DISPONIVEL;
}

qint64 Nucleo::id() const
{
    return m_id;
}

void Nucleo::setId(const qint64 &id)
{
    m_id = id;
}

Nucleo::Status Nucleo::status() const
{
    return m_status;
}

void Nucleo::setStatus(const Status &status)
{
    m_status = status;
}

Processo* Nucleo::processo() const
{
    return m_processo;
}

void Nucleo::setProcesso(Processo *processo)
{
    m_processo = processo;
    m_status = OCUPADO;
    if (!processo)
        m_status = DISPONIVEL;
}

bool Nucleo::stop() const
{
    return m_stop;
}

void Nucleo::setStop(bool stop)
{
    m_stop = stop;
}
