/********************************************************************************
** Form generated from reading UI file 'jfq.ui'
**
** Created: Fri Mar 27 16:10:21 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef JFQ_H
#define JFQ_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLineEdit *add;
    QLineEdit *added;
    QLineEdit *res;
    QLabel *oper;
    QPushButton *equ;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(683, 197);
        add = new QLineEdit(Dialog);
        add->setObjectName(QString::fromUtf8("add"));
        add->setGeometry(QRect(40, 80, 113, 27));
        added = new QLineEdit(Dialog);
        added->setObjectName(QString::fromUtf8("added"));
        added->setGeometry(QRect(217, 80, 120, 27));
        res = new QLineEdit(Dialog);
        res->setObjectName(QString::fromUtf8("res"));
        res->setGeometry(QRect(520, 80, 113, 27));
        oper = new QLabel(Dialog);
        oper->setObjectName(QString::fromUtf8("oper"));
        oper->setGeometry(QRect(173, 76, 31, 31));
        QFont font;
        font.setPointSize(20);
        oper->setFont(font);
        equ = new QPushButton(Dialog);
        equ->setObjectName(QString::fromUtf8("equ"));
        equ->setGeometry(QRect(381, 80, 97, 27));
        equ->setFont(font);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        oper->setText(QApplication::translate("Dialog", "+", 0, QApplication::UnicodeUTF8));
        equ->setText(QApplication::translate("Dialog", "=", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // JFQ_H
