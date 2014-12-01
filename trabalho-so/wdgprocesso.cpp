#include "wdgprocesso.h"
#include "ui_wdgprocesso.h"

WdgProcesso::WdgProcesso(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WdgProcesso)
{
    ui->setupUi(this);
}

WdgProcesso::~WdgProcesso()
{
    delete ui;
}
