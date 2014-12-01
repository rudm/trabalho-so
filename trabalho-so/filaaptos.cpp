#include "filaaptos.h"

FilaAptos::FilaAptos(QObject *parent)
    : QObject(parent)
{
}

QList<Processo*> FilaAptos::processos() const
{
    return m_fila;
}

void FilaAptos::adicionarProcesso(Processo *arg)
{
    m_fila.append(arg);
//    emit processoAdicionado(arg);
}

void FilaAptos::removerProcesso(Processo *arg)
{
    m_fila.removeOne(arg);
//    emit removerProcesso(arg);

//    if (m_fila.isEmpty())
//        emit filaAptosVazia();
}

Processo* FilaAptos::takeFirst()
{
    return m_fila.takeFirst();
}

bool FilaAptos::isEmpty() const
{
    return m_fila.isEmpty();
}
