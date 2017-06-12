#ifndef CACULATORDIALOG_H
#define CACULATORDIALOG_H

#include <QDialog>
#include <QStack>

const int INIT = 0;
const int DIGIT = 1;
const int OPERA = 2;
const int LEFT = 3;
const int RIGHT = 4;


namespace Ui {
class caculatorDialog;
}

class caculatorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit caculatorDialog(QWidget *parent = 0);
    ~caculatorDialog();

    void init();
    int getPriority(const QChar& oper);  //Operator Priority
    void toPostfix();  //Converted Postfix expressions
    void evaluation();
    void show2Conclude(QString conclude);
    void digitBtn(char ch);
    bool isOperator(QChar ch);

signals:
    void whichBtn(int type);
private slots:

    //Enable
    void enableDigit(int type);
    void enableOP(int type);
    void enableLeft(int type);
    void enableRight(int type);
    void enableEqual(int type);

    //Digits
    void on_v0_pbt_clicked();
    void on_v1_pbt_clicked();
    void on_v2_pbt_clicked();
    void on_v3_pbt_clicked();
    void on_v4_pbt_clicked();
    void on_v5_pbt_clicked();
    void on_v6_pbt_clicked();
    void on_v7_pbt_clicked();
    void on_v8_pbt_clicked();
    void on_v9_pbt_clicked();

    //Operators
    void on_add_pbt_clicked();
    void on_sub_pbt_clicked();
    void on_mul_pbt_clicked();
    void on_dev_pbt_clicked();
    void on_left_pbt_clicked();  //  (
    void on_right_pbt_clicked();  //  )
    void on_equal_pbt_clicked();
    void on_clear_pbt_clicked(); //Clear
    void on_del_pbt_clicked();  //Delete

    void on_dot_pbt_clicked();

    void on_clearTextPlainEdit_pbt_clicked();

private:
    Ui::caculatorDialog *ui;
    QStack<QChar> expStack;
    QStack<QChar> opStack;
    QString postfix;
    bool complete;
    int lefts;
};

#endif // CACULATORDIALOG_H
