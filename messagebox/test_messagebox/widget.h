#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QHBoxLayout;
class QPushButton;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QHBoxLayout *layout_;
    QPushButton *button_;

private slots:
    void OnButton();
};

#endif // WIDGET_H
