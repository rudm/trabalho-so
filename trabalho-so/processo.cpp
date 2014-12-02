#include "processo.h"


Processo::Processo(qint64 a_id, qint32 a_tempoTotal, qint32 a_tempoRestante, Processo::Status a_status, QObject *parent)
    : QObject(parent)
    , m_id(a_id)
    , m_tempoTotal(a_tempoTotal)
    , m_tempoRestante(a_tempoRestante)
    , m_status(a_status)
{

}

qint64 Processo::id() const
{
    return m_id;
}

void Processo::setId(const qint64 &value)
{
    m_id = value;
}

qint32 Processo::tempoTotal() const
{
    return m_tempoTotal;
}

void Processo::setTempoTotal(const qint32 &value)
{
    m_tempoTotal = value;
}

Processo::Status Processo::status() const
{
    return m_status;
}

void Processo::setStatus(const Status &value)
{
    m_status = value;
}

qint32 Processo::tempoRestante() const
{
    return m_tempoRestante;
}

void Processo::setTempoRestante(const qint32 &value)
{
    m_tempoRestante = value;
}
