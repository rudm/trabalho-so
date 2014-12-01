#include "processador.h"
#include "nucleo.h"

Processador::Processador(QObject *parent)
    : QObject(parent)
{
}

void Processador::adicionarNucleo(Nucleo *arg)
{
    m_nucleos.append(arg);
}

bool Processador::isOcioso()
{
    foreach (Nucleo* n, m_nucleos)
        if (!n->isDisponivel())
            return false;
    return true;
}

QList<Nucleo*> Processador::nucleos() const
{
    return m_nucleos;
}

Nucleo *Processador::getNucleoDisponivel()
{
    for (int i = 0 ; i < m_nucleos.size() ; ++i)
        if (m_nucleos.at(i)->isDisponivel())
            return m_nucleos[i];
    return NULL;
}

Nucleo *Processador::getNucleo(qint64 a_id)
{
    for (int i = 0 ; i < m_nucleos.size() ; ++i)
        if (m_nucleos.at(i)->id() == a_id)
            return m_nucleos[i];
    return NULL;
}

void Processador::limpar()
{
    while (!m_nucleos.isEmpty())
        m_nucleos.takeFirst()->deleteLater();
}
