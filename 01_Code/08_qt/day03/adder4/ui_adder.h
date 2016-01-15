/********************************************************************************
** Form generated from reading UI file 'adder.ui'
**
** Created: Mon Mar 30 09:20:39 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDER_H
#define UI_ADDER_H

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

class Ui_Adder
{
public:
    QPushButton *equ;
    QLineEdit *add;
    QLineEdit *added;
    QLineEdit *res;
    QLabel *oper;

    void setupUi(QDialog *Adder)
    {
        if (Adder->objectName().isEmpty())
            Adder->setObjectName(QString::fromUtf8("Adder"));
        Adder->resize(690, 199);
        equ = new QPushButton(Adder);
        equ->setObjectName(QString::fromUtf8("equ"));
        equ->setGeometry(QRect(420, 80, 97, 27));
        QFont font;
        font.setPointSize(15);
        equ->setFont(font);
        add = new QLineEdit(Adder);
        add->setObjectName(QString::fromUtf8("add"));
        add->setGeometry(QRect(20, 80, 113, 27));
        add->setFont(font);
        added = new QLineEdit(Adder);
        added->setObjectName(QString::fromUtf8("added"));
        added->setGeometry(QRect(240, 80, 113, 27));
        added->setFont(font);
        res = new QLineEdit(Adder);
        res->setObjectName(QString::fromUtf8("res"));
        res->setGeometry(QRect(550, 80, 113, 27));
        res->setFont(font);
        oper = new QLabel(Adder);
        oper->setObjectName(QString::fromUtf8("oper"));
        oper->setGeometry(QRect(170, 80, 41, 21));
        QFont font1;
        font1.setPointSize(20);
        oper->setFont(font1);

        retranslateUi(Adder);

        QMetaObject::connectSlotsByName(Adder);
    } // setupUi

    void retranslateUi(QDialog *Adder)
    {
        Adder->setWindowTitle(QApplication::translate("Adder", "Adder", 0, QApplication::UnicodeUTF8));
        equ->setText(QApplication::translate("Adder", "=", 0, QApplication::UnicodeUTF8));
        oper->setText(QApplication::translate("Adder", "+", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Adder: public Ui_Adder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDER_H
