#include "wdgnucleo.h"
#include "ui_wdgnucleo.h"
#include "nucleo.h"
#include "util.h"

WdgNucleo::WdgNucleo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WdgNucleo)
    , m_nucleo(NULL)
{
    ui->setupUi(this);
}

WdgNucleo::~WdgNucleo()
{
    delete ui;
}

void WdgNucleo::refresh()
{
    if (m_nucleo) {
        ui->lblId->setText(QString::number(m_nucleo->id()));
        ui->lblStatus->setText(getTextForEnumNucleoEstado(m_nucleo->status()));
    }
}

Nucleo *WdgNucleo::nucleo() const
{
    return m_nucleo;
}

void WdgNucleo::setNucleo(Nucleo *nucleo)
{
    m_nucleo = nucleo;
}

