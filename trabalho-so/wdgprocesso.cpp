#include "wdgprocesso.h"
#include "ui_wdgprocesso.h"
#include "processo.h"
#include "util.h"
#include <QDebug>

WdgProcesso::WdgProcesso(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WdgProcesso)
    , m_processo(NULL)
{
    ui->setupUi(this);
}

WdgProcesso::~WdgProcesso()
{
    delete ui;
}

void WdgProcesso::refresh()
{
    if (m_processo) {
        ui->lblId->setText(QString::number(m_processo->id()));
        ui->lblTempo->setText(QString("%1/%2").arg(m_processo->tempoRestante()).arg(m_processo->tempoTotal()));
        ui->lblStatus->setText(getTextForEnumProcessoEstado(m_processo->status()));
    }
}

Processo *WdgProcesso::processo() const
{
    return m_processo;
}

void WdgProcesso::setProcesso(Processo *processo)
{
    m_processo = processo;
}



