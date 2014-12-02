#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include "processador.h"
#include "filaaptos.h"
#include "updategui.h"

namespace Ui {
class MainWindow;
}

class WdgNucleo;
class WdgProcesso;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void initProcessador(int qtdNucleos);
    void initFilaAptos(int qtdProcessos);
    void initEscalonador();

private slots:
    void on_edtNucleos_valueChanged(int i);
    void on_edtQtdProc_valueChanged(int i);

    void on_btnAddProcesso_clicked();
    void on_btnIniciar_clicked();

private:
    Ui::MainWindow *ui;
    Processador m_processador;
    FilaAptos m_filaAptos;
    UpdateGUI m_update;
    QMap<qint64, WdgNucleo*> m_widgetsNucleo;
    QMap<qint64, WdgProcesso*> m_widgetsProcesso;
};

#endif // MAINWINDOW_H
