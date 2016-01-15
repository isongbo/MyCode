/********************************************************************************
** Form generated from reading UI file 'qqlogin.ui'
**
** Created: Mon Mar 30 09:52:31 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QQLOGIN_H
#define UI_QQLOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_QqLogin
{
public:
    QLineEdit *username;
    QLineEdit *userpasswd;
    QPushButton *blogin;
    QPushButton *bcancel;

    void setupUi(QDialog *QqLogin)
    {
        if (QqLogin->objectName().isEmpty())
            QqLogin->setObjectName(QString::fromUtf8("QqLogin"));
        QqLogin->resize(351, 263);
        username = new QLineEdit(QqLogin);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(170, 40, 113, 27));
        QFont font;
        font.setPointSize(20);
        username->setFont(font);
        userpasswd = new QLineEdit(QqLogin);
        userpasswd->setObjectName(QString::fromUtf8("userpasswd"));
        userpasswd->setGeometry(QRect(170, 90, 113, 27));
        userpasswd->setFont(font);
        userpasswd->setEchoMode(QLineEdit::Password);
        blogin = new QPushButton(QqLogin);
        blogin->setObjectName(QString::fromUtf8("blogin"));
        blogin->setGeometry(QRect(60, 180, 97, 27));
        bcancel = new QPushButton(QqLogin);
        bcancel->setObjectName(QString::fromUtf8("bcancel"));
        bcancel->setGeometry(QRect(200, 180, 97, 27));

        retranslateUi(QqLogin);

        QMetaObject::connectSlotsByName(QqLogin);
    } // setupUi

    void retranslateUi(QDialog *QqLogin)
    {
        QqLogin->setWindowTitle(QApplication::translate("QqLogin", "QqLogin", 0, QApplication::UnicodeUTF8));
        blogin->setText(QApplication::translate("QqLogin", "\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
        bcancel->setText(QApplication::translate("QqLogin", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QqLogin: public Ui_QqLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QQLOGIN_H
