#include "updategui.h"
#include "wdgnucleo.h"
#include "wdgprocesso.h"
#include <QDebug>
#include <QTime>

UpdateGUI::UpdateGUI(QObject *parent)
    : QThread(parent)
    , m_widgetsNucleo(NULL)
    , m_widgetsProcesso(NULL)
{
}

void UpdateGUI::setWdgNucleo(QMap<qint64, WdgNucleo *> *widgetsNucleo)
{
    m_widgetsNucleo = widgetsNucleo;
}

void UpdateGUI::setWdgProcesso(QMap<qint64, WdgProcesso *> *widgetsProcesso)
{
    m_widgetsProcesso = widgetsProcesso;
}

void UpdateGUI::run()
{
    while (true) {
        qDebug() << "updating" << QTime::currentTime().toString("HH:mm:ss.zzz");

        if (m_widgetsNucleo)
            foreach (qint64 id, m_widgetsNucleo->keys())
                m_widgetsNucleo->value(id)->refresh();

        if (m_widgetsProcesso)
            foreach (qint64 id, m_widgetsProcesso->keys())
                m_widgetsProcesso->value(id)->refresh();

        msleep(1000);
    }
}
