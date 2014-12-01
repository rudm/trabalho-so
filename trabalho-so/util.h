#ifndef UTIL_H
#define UTIL_H

#include <QtGlobal>
#include "nucleo.h"
#include "processo.h"

qint32 random(qint32 a_min, qint32 a_max, uint a_seed = 0);
QString getTextForEnumNucleoEstado(Nucleo::Status a_status);
QString getTextForEnumProcessoEstado(Processo::Status a_status);

#endif // UTIL_H
