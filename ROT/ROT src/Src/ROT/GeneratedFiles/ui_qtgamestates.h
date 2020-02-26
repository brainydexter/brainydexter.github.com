/********************************************************************************
** Form generated from reading UI file 'qtgamestates.ui'
**
** Created: Mon Apr 12 04:15:10 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGAMESTATES_H
#define UI_QTGAMESTATES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qtGameStatesClass
{
public:

    void setupUi(QWidget *qtGameStatesClass)
    {
        if (qtGameStatesClass->objectName().isEmpty())
            qtGameStatesClass->setObjectName(QString::fromUtf8("qtGameStatesClass"));
        qtGameStatesClass->resize(600, 400);

        retranslateUi(qtGameStatesClass);

        QMetaObject::connectSlotsByName(qtGameStatesClass);
    } // setupUi

    void retranslateUi(QWidget *qtGameStatesClass)
    {
        qtGameStatesClass->setWindowTitle(QApplication::translate("qtGameStatesClass", "qtGameStates", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class qtGameStatesClass: public Ui_qtGameStatesClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGAMESTATES_H
