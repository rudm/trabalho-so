#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "nucleo.h"
#include "processo.h"
#include "wdgnucleo.h"
#include "wdgprocesso.h"
#include "util.h"
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initProcessador(ui->edtNucleos->value());
    initFilaAptos(ui->edtQtdProc->value());

    m_update.setWdgNucleo(&m_widgetsNucleo);
    m_update.setWdgProcesso(&m_widgetsProcesso);
    m_update.start(QThread::HighestPriority);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initProcessador(int qtdNucleos)
{
    m_processador.limpar();

    while (!m_widgetsNucleo.isEmpty())
        m_widgetsNucleo.take(m_widgetsNucleo.keys().takeFirst())->deleteLater();

    for (int i = 0 ; i < qtdNucleos ; ++i) {
        Nucleo* l_nucleo = new Nucleo(i, Nucleo::DISPONIVEL, this);
        m_processador.adicionarNucleo(l_nucleo);

        WdgNucleo* l_widget = new WdgNucleo(this);
        l_widget->setNucleo(l_nucleo);

        m_widgetsNucleo[i] = l_widget;

        ui->scrNucleosContents->layout()->addWidget(l_widget);

//        connect(l_nucleo, &Nucleo::estadoChanged(Nucleo::Status), this, &MainWindow::refreshUiNucleo);
    }
}

void MainWindow::initFilaAptos(int qtdProcessos)
{
    m_filaAptos.limpar();

    while (!m_widgetsProcesso.isEmpty())
        m_widgetsProcesso.take(m_widgetsProcesso.keys().takeFirst())->deleteLater();

    for (int i = 0 ; i < qtdProcessos ; ++i) {
        uint l_seed = (i+1) * QTime::currentTime().msec();
        qint32 l_tempoTotal = random(4, 20, l_seed);

        Processo* p = new Processo(i, l_tempoTotal, l_tempoTotal, Processo::PRONTO, this);
        m_filaAptos.adicionarProcesso(p);

        WdgProcesso* l_widget = new WdgProcesso(this);
        l_widget->setProcesso(p);

        m_widgetsProcesso[i] = l_widget;

        ui->scrAptosContents->layout()->addWidget(l_widget);
    }
}

void MainWindow::initEscalonador()
{
    Nucleo* nucleo = m_processador.getNucleoDisponivel();

    Processo* processo = m_filaAptos.takeFirst();

    m_widgetsNucleo[nucleo->id()]->setWdgProcesso(m_widgetsProcesso[processo->id()]);

//    QEventLoop l_loop;

//    for (int i = 0 ; i < m_processador.nucleos().size() ; ++i)
//        connect(m_processador.nucleos().at(i), &Nucleo::processamentoTerminado, &l_loop, &QEventLoop::quit);

//    Nucleo* l_nucleo = NULL;

//    int l_quantum = (ui->edtQuantum->value() - 1) * 1000;

//    QTimer* l_timer;
//    while (!m_filaAptos.isEmpty()) {
//        l_nucleo = m_processador.getNucleoDisponivel();

//        if (!l_nucleo) {
//            l_loop.exec();
//            continue;
//        }

//        Processo* l_processo = m_filaAptos.takeFirst();

//        l_timer = new QTimer(this);
//        l_timer->setSingleShot(true);

//        l_nucleo->setProcesso(l_processo);
////        connect(l_nucleo->processo(), SIGNAL(tempoRestanteChanged(qint32)), SLOT(refreshUiNucleo()));

//        ui->scrAptosContents->layout()->removeWidget(m_widgetsProcesso[l_processo->id()]);

//        m_widgetsProcesso[l_processo->id()]->setProcesso(l_processo);
//        m_widgetsNucleo[l_nucleo->id()]->setWdgProcesso(m_widgetsProcesso[l_processo->id()]);

//        m_widgetsProcesso[l_processo->id()]->hide();
//        l_nucleo->start();
//        l_timer->start(l_quantum);

//        connect(l_timer, &QTimer::timeout, [=](){
//            m_widgetsProcesso[l_processo->id()]->show();
//            ui->scrAptosContents->layout()->addWidget(m_widgetsProcesso[l_processo->id()]);

//            if (l_nucleo->processo()->tempoRestante() > 0) {
//                m_filaAptos.adicionarProcesso(l_nucleo->processo());
//            } else {
//                m_widgetsProcesso[l_processo->id()]->hide();
//                ui->scrNucleosContents->layout()->removeWidget(m_widgetsProcesso[l_processo->id()]);
//            }

//            l_nucleo->setStop(true);
//        });
//    }

//    while (!m_filaAptos.isEmpty()) {
//        l_nucleo = m_processador.getNucleoDisponivel();

//        if (!l_nucleo) {
//            l_loop.exec();
//            continue;
//        }

//        Processo* l_processo = m_filaAptos.takeFirst();

//        l_nucleo->setProcesso(l_processo);
//        connect(l_nucleo->processo(), SIGNAL(tempoRestanteChanged(qint32)), SLOT(refreshUiNucleo()));

//        ui->scrAptosContents->layout()->removeWidget(m_widgetsProcesso[l_processo->id()]);
//        m_widgetsNucleo[l_nucleo->id()]->setWdgProcesso(m_widgetsProcesso[l_processo->id()]);
//        m_widgetsProcesso[l_processo->id()]->hide();

//        l_nucleo->start();
//    }

//    while (!m_processador.isOcioso())
//        l_loop.exec();
}

void MainWindow::on_edtNucleos_valueChanged(int i)
{
    initProcessador(i);
}

void MainWindow::on_edtQtdProc_valueChanged(int i)
{
    initFilaAptos(i);
}

void MainWindow::on_btnAddProcesso_clicked()
{

}

void MainWindow::on_btnIniciar_clicked()
{
    initEscalonador();
}
