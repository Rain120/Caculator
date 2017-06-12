/********************************************************************************
** Form generated from reading UI file 'caculatordialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CACULATORDIALOG_H
#define UI_CACULATORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_caculatorDialog
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *del_pbt;
    QPushButton *dot_pbt;
    QPushButton *v0_pbt;
    QPushButton *v2_pbt;
    QPushButton *dev_pbt;
    QPushButton *v5_pbt;
    QPushButton *v9_pbt;
    QPushButton *v3_pbt;
    QPushButton *v4_pbt;
    QPushButton *sub_pbt;
    QPushButton *v6_pbt;
    QPushButton *v7_pbt;
    QPushButton *add_pbt;
    QPushButton *mul_pbt;
    QPushButton *equal_pbt;
    QPushButton *v1_pbt;
    QPushButton *v8_pbt;
    QPushButton *right_pbt;
    QPushButton *left_pbt;
    QPushButton *clear_pbt;
    QLineEdit *exp_edt;
    QPlainTextEdit *conclude_pedt;
    QPushButton *clearTextPlainEdit_pbt;

    void setupUi(QDialog *caculatorDialog)
    {
        if (caculatorDialog->objectName().isEmpty())
            caculatorDialog->setObjectName(QStringLiteral("caculatorDialog"));
        caculatorDialog->resize(642, 302);
        gridLayoutWidget = new QWidget(caculatorDialog);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 100, 419, 201));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        del_pbt = new QPushButton(gridLayoutWidget);
        del_pbt->setObjectName(QStringLiteral("del_pbt"));

        gridLayout->addWidget(del_pbt, 5, 3, 1, 1);

        dot_pbt = new QPushButton(gridLayoutWidget);
        dot_pbt->setObjectName(QStringLiteral("dot_pbt"));

        gridLayout->addWidget(dot_pbt, 5, 1, 1, 1);

        v0_pbt = new QPushButton(gridLayoutWidget);
        v0_pbt->setObjectName(QStringLiteral("v0_pbt"));

        gridLayout->addWidget(v0_pbt, 5, 2, 1, 1);

        v2_pbt = new QPushButton(gridLayoutWidget);
        v2_pbt->setObjectName(QStringLiteral("v2_pbt"));

        gridLayout->addWidget(v2_pbt, 4, 2, 1, 1);

        dev_pbt = new QPushButton(gridLayoutWidget);
        dev_pbt->setObjectName(QStringLiteral("dev_pbt"));

        gridLayout->addWidget(dev_pbt, 1, 4, 1, 1);

        v5_pbt = new QPushButton(gridLayoutWidget);
        v5_pbt->setObjectName(QStringLiteral("v5_pbt"));

        gridLayout->addWidget(v5_pbt, 3, 2, 1, 1);

        v9_pbt = new QPushButton(gridLayoutWidget);
        v9_pbt->setObjectName(QStringLiteral("v9_pbt"));

        gridLayout->addWidget(v9_pbt, 2, 3, 1, 1);

        v3_pbt = new QPushButton(gridLayoutWidget);
        v3_pbt->setObjectName(QStringLiteral("v3_pbt"));

        gridLayout->addWidget(v3_pbt, 4, 3, 1, 1);

        v4_pbt = new QPushButton(gridLayoutWidget);
        v4_pbt->setObjectName(QStringLiteral("v4_pbt"));

        gridLayout->addWidget(v4_pbt, 3, 1, 1, 1);

        sub_pbt = new QPushButton(gridLayoutWidget);
        sub_pbt->setObjectName(QStringLiteral("sub_pbt"));

        gridLayout->addWidget(sub_pbt, 3, 4, 1, 1);

        v6_pbt = new QPushButton(gridLayoutWidget);
        v6_pbt->setObjectName(QStringLiteral("v6_pbt"));

        gridLayout->addWidget(v6_pbt, 3, 3, 1, 1);

        v7_pbt = new QPushButton(gridLayoutWidget);
        v7_pbt->setObjectName(QStringLiteral("v7_pbt"));

        gridLayout->addWidget(v7_pbt, 2, 1, 1, 1);

        add_pbt = new QPushButton(gridLayoutWidget);
        add_pbt->setObjectName(QStringLiteral("add_pbt"));

        gridLayout->addWidget(add_pbt, 4, 4, 1, 1);

        mul_pbt = new QPushButton(gridLayoutWidget);
        mul_pbt->setObjectName(QStringLiteral("mul_pbt"));

        gridLayout->addWidget(mul_pbt, 2, 4, 1, 1);

        equal_pbt = new QPushButton(gridLayoutWidget);
        equal_pbt->setObjectName(QStringLiteral("equal_pbt"));

        gridLayout->addWidget(equal_pbt, 5, 4, 1, 1);

        v1_pbt = new QPushButton(gridLayoutWidget);
        v1_pbt->setObjectName(QStringLiteral("v1_pbt"));

        gridLayout->addWidget(v1_pbt, 4, 1, 1, 1);

        v8_pbt = new QPushButton(gridLayoutWidget);
        v8_pbt->setObjectName(QStringLiteral("v8_pbt"));

        gridLayout->addWidget(v8_pbt, 2, 2, 1, 1);

        right_pbt = new QPushButton(gridLayoutWidget);
        right_pbt->setObjectName(QStringLiteral("right_pbt"));

        gridLayout->addWidget(right_pbt, 1, 3, 1, 1);

        left_pbt = new QPushButton(gridLayoutWidget);
        left_pbt->setObjectName(QStringLiteral("left_pbt"));

        gridLayout->addWidget(left_pbt, 1, 2, 1, 1);

        clear_pbt = new QPushButton(gridLayoutWidget);
        clear_pbt->setObjectName(QStringLiteral("clear_pbt"));
        QFont font;
        font.setPointSize(13);
        clear_pbt->setFont(font);

        gridLayout->addWidget(clear_pbt, 1, 1, 1, 1);

        exp_edt = new QLineEdit(caculatorDialog);
        exp_edt->setObjectName(QStringLiteral("exp_edt"));
        exp_edt->setGeometry(QRect(0, 0, 421, 101));
        conclude_pedt = new QPlainTextEdit(caculatorDialog);
        conclude_pedt->setObjectName(QStringLiteral("conclude_pedt"));
        conclude_pedt->setGeometry(QRect(420, 0, 221, 301));
        conclude_pedt->setTextInteractionFlags(Qt::TextEditorInteraction);
        clearTextPlainEdit_pbt = new QPushButton(caculatorDialog);
        clearTextPlainEdit_pbt->setObjectName(QStringLiteral("clearTextPlainEdit_pbt"));
        clearTextPlainEdit_pbt->setGeometry(QRect(610, 280, 31, 23));

        retranslateUi(caculatorDialog);

        QMetaObject::connectSlotsByName(caculatorDialog);
    } // setupUi

    void retranslateUi(QDialog *caculatorDialog)
    {
        caculatorDialog->setWindowTitle(QApplication::translate("caculatorDialog", "Rainy Caculator", 0));
        del_pbt->setText(QApplication::translate("caculatorDialog", "Del", 0));
        dot_pbt->setText(QApplication::translate("caculatorDialog", ".", 0));
        v0_pbt->setText(QApplication::translate("caculatorDialog", "0", 0));
        v2_pbt->setText(QApplication::translate("caculatorDialog", "2", 0));
        dev_pbt->setText(QApplication::translate("caculatorDialog", "/", 0));
        v5_pbt->setText(QApplication::translate("caculatorDialog", "5", 0));
        v9_pbt->setText(QApplication::translate("caculatorDialog", "9", 0));
        v3_pbt->setText(QApplication::translate("caculatorDialog", "3", 0));
        v4_pbt->setText(QApplication::translate("caculatorDialog", "4", 0));
        sub_pbt->setText(QApplication::translate("caculatorDialog", "-", 0));
        v6_pbt->setText(QApplication::translate("caculatorDialog", "6", 0));
        v7_pbt->setText(QApplication::translate("caculatorDialog", "7", 0));
        add_pbt->setText(QApplication::translate("caculatorDialog", "+", 0));
        mul_pbt->setText(QApplication::translate("caculatorDialog", "*", 0));
        equal_pbt->setText(QApplication::translate("caculatorDialog", "=", 0));
        v1_pbt->setText(QApplication::translate("caculatorDialog", "1", 0));
        v8_pbt->setText(QApplication::translate("caculatorDialog", "8", 0));
        right_pbt->setText(QApplication::translate("caculatorDialog", ")", 0));
        left_pbt->setText(QApplication::translate("caculatorDialog", "(", 0));
        clear_pbt->setText(QApplication::translate("caculatorDialog", "C", 0));
        exp_edt->setPlaceholderText(QString());
        clearTextPlainEdit_pbt->setText(QApplication::translate("caculatorDialog", "C", 0));
    } // retranslateUi

};

namespace Ui {
    class caculatorDialog: public Ui_caculatorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CACULATORDIALOG_H
