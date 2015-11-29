#include <QHBoxLayout>
#include <QPushButton>

#include <messagebox.h>

#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    layout_ = new QHBoxLayout(NULL);
    button_ = new QPushButton(tr("click"), this);

    layout_->addWidget(button_);
    QObject::connect(button_, SIGNAL(clicked()), this, SLOT(OnButton()));
}

Widget::~Widget()
{

}

void Widget::OnButton()
{
    //LEONANA::MessageBox::warningMessage(tr("Warn"), tr("WARN"));
    //LEONANA::MessageBox::informationMessage(tr("Info"), tr("INFO"));

    LEONANA::MessageBox msg(this, "Test", "TEST");
    //msg.ask();
    //msg.warning();
    msg.information();
}
