#include <QtQml/QQmlContext>
#include <QtQml/QQmlComponent>
#include <QTimer>
#include <QEventLoop>

#include "messagebox.h"

namespace LEONANA {

MessageBox::MessageBox(QWidget *parent,QString title,QString message) :
    QWidget(parent),
    m_mode("alter"),
    m_title(title),
    m_message(message),
    m_canelButtonVisiable(false),
    hint_mode_(false),
    m_showTime(3000),
    timer_(NULL),
    m_messageMode(false)
{
    setGeometry(-100, -100, 1, 1);
    qml_context_ = new QQmlContext(&qml_engine_,this);
    qml_context_->setContextProperty("mainwindow", this);

    qml_component_ = new QQmlComponent(&qml_engine_,this);
    qml_component_->loadUrl(QUrl("qrc:/QML/QML/MessageBox.qml"));
    root_object_ = qml_component_->create(qml_context_);

    connect(root_object_,SIGNAL(buttonClicked(int)),this,SLOT(onButtonClicked(int)));
}

MessageBox::~MessageBox()
{
    if(root_object_)
        delete root_object_;
}

QMessageBox::StandardButton MessageBox::ask()
{
    setMode("ask");
    setCanelButtonVisiable(true);
    doEventLoop();
    return return_button_;
}


QMessageBox::StandardButton MessageBox::warning()
{
    setMode("warning");
    doEventLoop();
    return return_button_;
}

QMessageBox::StandardButton MessageBox::information()
{
    setMode("information");
    doEventLoop();
    return return_button_;
}

QMessageBox::StandardButton MessageBox::error()
{
    setMode("error");
    doEventLoop();
    return return_button_;
}

void MessageBox::warningMessage(QString title, QString message,qint32 show_time)
{
    MessageBox* box = new MessageBox(NULL,title,message);
    box->autoDestoryShow("warning",show_time);
}

void MessageBox::informationMessage(QString title, QString message,qint32 show_time)
{
    MessageBox* box = new MessageBox(NULL,title,message);
    box->autoDestoryShow("information",show_time);
}

void MessageBox::errorMessage(QString title, QString message,qint32 show_time)
{
    MessageBox* box = new MessageBox(NULL,title,message);
    box->autoDestoryShow("error",show_time);
}

void MessageBox::onButtonClicked(int buttonId)
{
    if(hint_mode_) {
        if(timer_ != NULL) {
            timer_->stop();
        }
        close();
        return;
    }

    if(buttonId == 1) {
        return_button_ = QMessageBox::Ok;
    } else if (buttonId == 2) {
        return_button_ = QMessageBox::No;
    }
}

void MessageBox::autoDestoryShow(const QString& mode,qint32 show_time)
{
    hint_mode_ = true;
    setMode(mode);
    setMessageMode(true);
    setShowTime(show_time);
    setAttribute(Qt::WA_DeleteOnClose);
    if(timer_ == NULL) {
        timer_ = new QTimer(this);
        timer_->setInterval(show_time);
        connect(timer_,SIGNAL(timeout()),this,SLOT(OnTimer()));
    }
    showWindow();
    timer_->start();
}

void MessageBox::OnTimer()
{
    if(hint_mode_) {
        if(timer_ != NULL) {
            timer_->stop();
        }
        hideWindow();
        close();
    }
}

void MessageBox::doEventLoop()
{
    showWindow();
    QEventLoop loop;
    loop.connect(root_object_, SIGNAL(buttonClicked(int)), SLOT(quit()));
    loop.exec();
    hideWindow();
}

void MessageBox::showWindow()
{
    if(root_object_) {
        root_object_->setProperty("visible", true);
    }
}

void MessageBox::hideWindow()
{
    if(root_object_) {
        root_object_->setProperty("visible", false);
    }
}

}


