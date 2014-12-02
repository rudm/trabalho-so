#ifndef UPDATEGUI_H
#define UPDATEGUI_H

#include <QThread>
#include <QMap>

class WdgNucleo;
class WdgProcesso;
class UpdateGUI : public QThread
{
    Q_OBJECT

public:
    explicit UpdateGUI(QObject *parent = 0);

    void setWdgNucleo(QMap<qint64, WdgNucleo*>* widgetsNucleo);
    void setWdgProcesso(QMap<qint64, WdgProcesso*>* widgetsProcesso);

    void run();

signals:

public slots:

private:
    QMap<qint64, WdgNucleo*>* m_widgetsNucleo;
    QMap<qint64, WdgProcesso*>* m_widgetsProcesso;
};

#endif // UPDATEGUI_H
