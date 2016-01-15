/********************************************************************************
** Form generated from reading UI file 'qq.ui'
**
** Created: Fri Mar 27 17:10:37 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QQ_H
#define UI_QQ_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLineEdit *username;
    QLineEdit *userpasswd;
    QPushButton *blogin;
    QPushButton *bcancel;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(347, 259);
        username = new QLineEdit(Dialog);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(160, 60, 113, 27));
        QFont font;
        font.setPointSize(20);
        username->setFont(font);
        userpasswd = new QLineEdit(Dialog);
        userpasswd->setObjectName(QString::fromUtf8("userpasswd"));
        userpasswd->setGeometry(QRect(160, 110, 113, 27));
        userpasswd->setFont(font);
        userpasswd->setEchoMode(QLineEdit::Password);
        blogin = new QPushButton(Dialog);
        blogin->setObjectName(QString::fromUtf8("blogin"));
        blogin->setGeometry(QRect(60, 180, 97, 27));
        bcancel = new QPushButton(Dialog);
        bcancel->setObjectName(QString::fromUtf8("bcancel"));
        bcancel->setGeometry(QRect(200, 180, 97, 27));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        blogin->setText(QApplication::translate("Dialog", "\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
        bcancel->setText(QApplication::translate("Dialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QQ_H
