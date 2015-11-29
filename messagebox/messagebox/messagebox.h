#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <QWidget>
#include <QMessageBox>
#include <QtQml/QQmlEngine>

#include "messagebox_global.h"

namespace LEONANA {

class MESSAGEBOXSHARED_EXPORT MessageBox : QWidget
{

public:
    explicit MessageBox();
    Q_OBJECT
    Q_PROPERTY(QString mode READ mode WRITE setMode NOTIFY modeChanged)
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged)
    Q_PROPERTY(bool canelButtonVisiable READ canelButtonVisiable WRITE setCanelButtonVisiable NOTIFY canelButtonVisiableChanged)
    Q_PROPERTY(bool messageMode READ messageMode WRITE setMessageMode NOTIFY messageModeChanged)

public:
    explicit MessageBox(QWidget *parent, QString title, QString message);
    ~MessageBox();
    QMessageBox::StandardButton ask();
    QMessageBox::StandardButton warning();
    QMessageBox::StandardButton information();
    QMessageBox::StandardButton error();

    static void warningMessage(QString title, QString message,qint32 show_time = 5000);
    static void informationMessage(QString title, QString message,qint32 show_time = 5000);
    static void errorMessage(QString title, QString message,qint32 show_time = 5000);
    QString mode() const
    {
        return m_mode;
    }

    QString title() const
    {
        return m_title;
    }

    QString message() const
    {
        return m_message;
    }

    bool canelButtonVisiable() const
    {
        return m_canelButtonVisiable;
    }

    qint32 showTime() const
    {
        return m_showTime;
    }

    bool messageMode() const
    {
        return m_messageMode;
    }

signals:

    void modeChanged(QString arg);

    void titleChanged(QString arg);

    void messageChanged(QString arg);

    void canelButtonVisiableChanged(bool arg);

    void messageModeChanged(bool arg);

public slots:
    void onButtonClicked(int buttonId);
        void setMode(QString arg)
        {
            if (m_mode != arg) {
                m_mode = arg;
                emit modeChanged(arg);
            }
        }

        void setTitle(QString arg)
        {
            if (m_title != arg) {
                m_title = arg;
                emit titleChanged(arg);
            }
        }

        void setMessage(QString arg)
        {
            if (m_message != arg) {
                m_message = arg;
                emit messageChanged(arg);
            }
        }

        void setCanelButtonVisiable(bool arg)
        {
            if (m_canelButtonVisiable != arg) {
                m_canelButtonVisiable = arg;
                emit canelButtonVisiableChanged(arg);
            }
        }
        void setShowTime(qint32 arg)
        {
            m_showTime = arg;
        }

        void setMessageMode(bool arg)
        {
            if (m_messageMode != arg) {
                m_messageMode = arg;
                emit messageModeChanged(arg);
            }
        }

private slots:
    void OnTimer();
private:
    void autoDestoryShow(const QString& mode,qint32 show_time);
    void showWindow();
    void hideWindow();
    void doEventLoop();
private:
    QQmlEngine qml_engine_;
    QQmlContext *qml_context_;
    QQmlComponent* qml_component_;
    QObject* root_object_;

    QMessageBox::StandardButton return_button_;
    QString m_mode;
    QString m_title;
    QString m_message;
    bool m_canelButtonVisiable;
    bool hint_mode_;
    qint32 m_showTime;
    QTimer* timer_;
    bool m_messageMode;

};

}  // LEO_TOOLKIT

#endif // MESSAGEBOX_H
