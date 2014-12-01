#ifndef WDGNUCLEO_H
#define WDGNUCLEO_H

#include <QWidget>

namespace Ui {
class WdgNucleo;
}

class Nucleo;
class WdgNucleo : public QWidget
{
    Q_OBJECT

public:
    explicit WdgNucleo(QWidget *parent = 0);
    ~WdgNucleo();

    void refresh();

    Nucleo *nucleo() const;
    void setNucleo(Nucleo *nucleo);

private:
    Ui::WdgNucleo *ui;
    Nucleo* m_nucleo;
};

#endif // WDGNUCLEO_H
