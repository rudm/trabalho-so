#include "util.h"
#include "nucleo.h"
#include "processo.h"
#include <QDateTime>

qint32 random(qint32 a_min, qint32 a_max, uint a_seed)
{
    if (a_min > a_max) {
        qint32 l_temp = a_min;
        a_min = a_max;
        a_max = l_temp;
    }

    if (a_seed == 0)
        a_seed = QDateTime::currentMSecsSinceEpoch();

    qsrand(a_seed * qrand());
    return qrand() % (a_max - a_min + 1) + a_min;
}

QString getTextForEnumNucleoEstado(Nucleo::Status a_status)
{
    switch (a_status) {
        case Nucleo::DISPONIVEL:
            return QString("Disponível");
        case Nucleo::OCUPADO:
            return QString("Ocupado");
        default:
            return QString("Desconhecido");
    }
}

QString getTextForEnumProcessoEstado(Processo::Status a_status)
{
    switch (a_status) {
        case Processo::PRONTO:
            return QString("Pronto");
        case Processo::ESPERANDO:
            return QString("Esperando");
        case Processo::EXECUTANDO:
            return QString("Executando");
        default:
            return QString("");
    }
}
