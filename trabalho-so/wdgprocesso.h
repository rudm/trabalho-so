#ifndef WDGPROCESSO_H
#define WDGPROCESSO_H

#include <QWidget>

namespace Ui {
class WdgProcesso;
}

class Processo;
class WdgProcesso : public QWidget
{
    Q_OBJECT

public:
    explicit WdgProcesso(QWidget *parent = 0);
    ~WdgProcesso();

    void refresh();

    Processo *processo() const;
    void setProcesso(Processo *processo);

private:
    Ui::WdgProcesso *ui;
    Processo* m_processo;
};

#endif // WDGPROCESSO_H
