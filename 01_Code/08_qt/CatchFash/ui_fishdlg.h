/********************************************************************************
** Form generated from reading UI file 'fishdlg.ui'
**
** Created: Tue Jan 20 20:12:06 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FISHDLG_H
#define UI_FISHDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_FishDlg
{
public:

    void setupUi(QDialog *FishDlg)
    {
        if (FishDlg->objectName().isEmpty())
            FishDlg->setObjectName(QString::fromUtf8("FishDlg"));
        FishDlg->resize(400, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/bullet.png"), QSize(), QIcon::Normal, QIcon::Off);
        FishDlg->setWindowIcon(icon);
        FishDlg->setAutoFillBackground(false);

        retranslateUi(FishDlg);

        QMetaObject::connectSlotsByName(FishDlg);
    } // setupUi

    void retranslateUi(QDialog *FishDlg)
    {
        FishDlg->setWindowTitle(QApplication::translate("FishDlg", "\346\215\225\351\261\274\350\276\276\344\272\272", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FishDlg: public Ui_FishDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FISHDLG_H
