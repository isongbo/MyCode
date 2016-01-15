/********************************************************************************
** Form generated from reading UI file 'testevent.ui'
**
** Created: Mon Mar 30 14:36:06 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTEVENT_H
#define UI_TESTEVENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_TestEvent
{
public:

    void setupUi(QDialog *TestEvent)
    {
        if (TestEvent->objectName().isEmpty())
            TestEvent->setObjectName(QString::fromUtf8("TestEvent"));
        TestEvent->resize(400, 300);

        retranslateUi(TestEvent);

        QMetaObject::connectSlotsByName(TestEvent);
    } // setupUi

    void retranslateUi(QDialog *TestEvent)
    {
        TestEvent->setWindowTitle(QApplication::translate("TestEvent", "TestEvent", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TestEvent: public Ui_TestEvent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTEVENT_H
