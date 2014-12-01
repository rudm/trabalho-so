#ifndef WDGPROCESSO_H
#define WDGPROCESSO_H

#include <QWidget>

namespace Ui {
class WdgProcesso;
}

class WdgProcesso : public QWidget
{
    Q_OBJECT

public:
    explicit WdgProcesso(QWidget *parent = 0);
    ~WdgProcesso();

private:
    Ui::WdgProcesso *ui;
};

#endif // WDGPROCESSO_H
