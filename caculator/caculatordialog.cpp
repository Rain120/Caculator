#include "caculatordialog.h"
#include "ui_caculatordialog.h"
#include "QDebug"
#include "QSize"
#include "QDesktopWidget"
#include "QPlainTextEdit"

int dotTime;
caculatorDialog::caculatorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::caculatorDialog)
{
    //CenterPosition
    QDesktopWidget *desktop = QApplication::desktop();
    move( (desktop->width() - this->width()) / 2,
          (desktop->height() - this->height()) / 2 );
    ui->setupUi(this);

    //LineEdit Setting
    ui->exp_edt->setEnabled(false);
    ui->exp_edt->setAlignment(Qt::AlignRight | Qt::AlignBottom);
    ui->exp_edt->setStyleSheet("font-size:18px");
    ui->exp_edt->setText("0");


    qDebug() << "ui->exp_edt->text:" << ui->exp_edt->text();

    //PlainTextEdit Setting
    ui->conclude_pedt->setReadOnly(true);
    ui->conclude_pedt->setStyleSheet("font:18px;");

    lefts = 0;
    connect(this, &caculatorDialog::whichBtn, &caculatorDialog::enableOP );
    connect(this, &caculatorDialog::whichBtn, &caculatorDialog::enableEqual );
    connect(this, &caculatorDialog::whichBtn, &caculatorDialog::enableLeft );
    connect(this, &caculatorDialog::whichBtn, &caculatorDialog::enableRight );
    connect(this, &caculatorDialog::whichBtn, &caculatorDialog::enableDigit );
    init();
}
caculatorDialog::~caculatorDialog()
{
    delete ui;
}

void caculatorDialog::init()
{
    if(!expStack.isEmpty()){
        expStack.clear();
    }
    if(!opStack.isEmpty()){
        opStack.clear();
    }
    opStack.push('#');
    complete = true;
    emit whichBtn(INIT);
}

int caculatorDialog::getPriority(const QChar &oper)
{
    switch (oper.cell()) {
    case '#':
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    }
    return 0;
}

void caculatorDialog::toPostfix()
{
    QString exp = ui->exp_edt->text();
    qDebug() << "Exp:" <<exp;
    if(exp.length() < 0){
        qDebug() << "Input Error!!!";
    }
    else if(exp.length() == 1 && exp[0].isDigit()){
        postfix.push_back(exp[0]);
    }
    else
    {
        if(isOperator(exp[0])){
            postfix.push_back("0");
        }
        for(int i = 0; i < exp.length(); i++){
            qDebug() << "toPost" << i << exp[i];
            if(exp[i].isDigit() || exp[i] == '.'){
                postfix.push_back(exp[i]);
            }
            else if(exp[i] == '('){
                opStack.push(exp[i]);
            }
            else if(exp[i] == ')'){

                postfix.push_back(' ');
                while(opStack.top() != '('){
                    postfix.push_back(opStack.pop());
                    //qDebug() << "toPost" << postfix;
                }
                opStack.pop();
            }
            else if(getPriority(exp[i]) > getPriority(opStack.top())){
                postfix.push_back(' ');
                //qDebug() << "toPost--Prority" << postfix;
                opStack.push(exp[i]);
            }
            else{
                postfix.push_back(' ');
                //qDebug() << postfix;
                while( getPriority(exp[i]) <= getPriority(opStack.top()) ){
                    postfix.push_back(opStack.pop());
                }
                opStack.push(exp[i]);
            }
        }
    }
    while(opStack.top() != '#'){
        QChar ch = opStack.pop();
        postfix.push_back(' ');
        postfix.push_back(ch);
    }
    qDebug() << "Postfix:" << postfix;
}

void caculatorDialog::evaluation()
{
    QString valueStr;
    QStack<double> arithmeticStack;
    if(postfix.size() < 0){
        qDebug() << "Postfix Error!!!";
    }
    else if(postfix.size() == 1 && postfix[0].isDigit()){
        if(postfix[0].isDigit() || postfix[0] == '.'){
            valueStr.push_back(postfix[0]);
        }
        arithmeticStack.push(arithmeticStack.pop());
    }
    else{
        for (int i = 0; i < postfix.size(); i++){
            //qDebug() << "evaluation" << i << postfix[i];
            if(postfix[i].isDigit() || postfix[i] == '.'){
                valueStr.push_back(postfix[i]);
            }
            else if(postfix[i] == ' ')
            {
                if(!valueStr.isEmpty()){
                    arithmeticStack.push(valueStr.toDouble());
                    valueStr.clear();
                }
                //qDebug() << "Arithemtic:" << arithmeticStack.top() << valueStr.isEmpty();
            }
            else
            {
                double firstNum;
                double secondNum;
                firstNum = arithmeticStack.pop();
                //qDebug() << "evaluation" << "FirstNum:" << firstNum;
                secondNum = arithmeticStack.pop();
                //qDebug() << "evaluation" << "SecondNum:" << secondNum;
                switch (postfix[i].cell())
                {
                case '+':
                    arithmeticStack.push(secondNum + firstNum);
                    break;
                case '-':
                    arithmeticStack.push(secondNum - firstNum);
                    break;
                case '*':
                    arithmeticStack.push(secondNum * firstNum);
                    break;
                case '/':
                    arithmeticStack.push(secondNum / firstNum);
                    break;
                }
                //qDebug() << "evaluation" << "Top:" << arithmeticStack.top();
            }
        }
    }
    show2Conclude(QString::number(arithmeticStack.top()));
    ui->exp_edt->setText(QString::number(arithmeticStack.top()));
}

void caculatorDialog::show2Conclude(QString conclude)
{
    QString concludeStr = "";
    concludeStr.append(ui->exp_edt->text());
    concludeStr.append("=");
    concludeStr.append(conclude);
    ui->conclude_pedt->appendPlainText(concludeStr);
    //ui->conclude_pedt->setPlainText(concludeStr);
}
void caculatorDialog::digitBtn(char ch)
{
    QString expStr = ui->exp_edt->text();
    if(!complete){
        ui->exp_edt->setText(expStr + ch);
    }
    else{
        ui->exp_edt->setText(expStr + QString(ch));
        complete = false;
    }
    emit whichBtn(DIGIT);
}

bool caculatorDialog::isOperator(QChar ch)
{
    if(ch == '+' || ch == '-' || ch == '*'  || ch == '/'){
        return true;
    }
    else{
        return false;
    }
}

void caculatorDialog::enableDigit(int type)
{
    bool enable = true;
    if (RIGHT == type){
        enable = false;
    }

    ui->v0_pbt->setEnabled(enable);
    ui->v1_pbt->setEnabled(enable);
    ui->v2_pbt->setEnabled(enable);
    ui->v3_pbt->setEnabled(enable);
    ui->v4_pbt->setEnabled(enable);
    ui->v5_pbt->setEnabled(enable);
    ui->v6_pbt->setEnabled(enable);
    ui->v7_pbt->setEnabled(enable);
    ui->v8_pbt->setEnabled(enable);
    ui->v9_pbt->setEnabled(enable);

    ui->sub_pbt->setEnabled(enable);
}

void caculatorDialog::enableOP(int type)
{
    bool enable = false;
    switch (type) {
    case RIGHT:
    case DIGIT:
        enable = true;
        break;
    case INIT:
    case OPERA:
    case LEFT:
        enable = false;
        break;
    default:
        return;
    }
    ui->add_pbt->setEnabled(enable);
    ui->sub_pbt->setEnabled(enable);
    ui->mul_pbt->setEnabled(enable);
    ui->dev_pbt->setEnabled(enable);
    ui->dot_pbt->setEnabled(enable);
}

void caculatorDialog::enableLeft(int type)
{
    bool enable = false;
    switch (type) {
    case RIGHT:
    case DIGIT:
        break;
    case INIT:
    case LEFT:
    case OPERA:
        enable = true;
        break;
    default:
        return;
    }
    ui->left_pbt->setEnabled(enable);
}

void caculatorDialog::enableRight(int type)
{
    bool enable = false;
    switch (type) {
    case INIT:
    case OPERA:
        break;
    case LEFT:
        enable = true;
    case RIGHT:
    case DIGIT:
        if(lefts){
            enable = true;
        }
        break;
    default:
        return;
    }
    ui->right_pbt->setEnabled(enable);
}

void caculatorDialog::enableEqual(int type)
{
    bool enable = false;
    switch (type) {
    case OPERA:
    case LEFT:
        break;
    case RIGHT:
    case DIGIT:
        enable = true;
        break;
    default:
        return;
    }
    ui->equal_pbt->setEnabled(enable);
}

void caculatorDialog::on_v0_pbt_clicked()
{
    if(ui->exp_edt->text() != "0"){
        digitBtn('0');
    }
    else{
        ui->exp_edt->setText("0");
    }
}

void caculatorDialog::on_v1_pbt_clicked()
{
    digitBtn('1');
}

void caculatorDialog::on_v2_pbt_clicked()
{
    digitBtn('2');
}

void caculatorDialog::on_v3_pbt_clicked()
{
    digitBtn('3');
}

void caculatorDialog::on_v4_pbt_clicked()
{
    digitBtn('4');
}

void caculatorDialog::on_v5_pbt_clicked()
{
    digitBtn('5');
}

void caculatorDialog::on_v6_pbt_clicked()
{
    digitBtn('6');
}

void caculatorDialog::on_v7_pbt_clicked()
{
    digitBtn('7');
}

void caculatorDialog::on_v8_pbt_clicked()
{
    digitBtn('8');
}

void caculatorDialog::on_v9_pbt_clicked()
{
    digitBtn('9');
}

void caculatorDialog::on_dot_pbt_clicked()
{
    QString dotStr = ui->exp_edt->text();
    if(!complete && dotTime == 0){
        ui->exp_edt->setText(dotStr + ".");
        dotTime++;
    }
}
void caculatorDialog::on_add_pbt_clicked()
{
    QString addStr = ui->exp_edt->text();
    ui->exp_edt->setText(addStr + "+");
    emit whichBtn(OPERA);
}

void caculatorDialog::on_sub_pbt_clicked()
{
    QString subStr = ui->exp_edt->text();
    //ui->exp_edt->setText(subStr + "-");
    subStr.append("-");
    ui->exp_edt->setText(subStr);
    qDebug() << subStr;
    emit whichBtn(OPERA);
}

void caculatorDialog::on_mul_pbt_clicked()
{
    QString mulStr = ui->exp_edt->text();
    ui->exp_edt->setText(mulStr + "*");
    emit whichBtn(OPERA);
}

void caculatorDialog::on_dev_pbt_clicked()
{
    QString divStr = ui->exp_edt->text();
    ui->exp_edt->setText(divStr + "/");
    emit whichBtn(OPERA);
}

void caculatorDialog::on_left_pbt_clicked()
{
    QString leftStr = ui->exp_edt->text();
    if(!complete){
        ui->exp_edt->setText(leftStr + "(");
        complete = false;
    }
    emit whichBtn(LEFT);
    lefts++;
}

void caculatorDialog::on_right_pbt_clicked()
{
    QString rightStr = ui->exp_edt->text();
    if(!complete){
        ui->exp_edt->setText(rightStr + ")");
    }
    lefts--;
    emit whichBtn(RIGHT);
}

void caculatorDialog::on_clear_pbt_clicked()
{
    init();
    ui->exp_edt->setText("0");
}

void caculatorDialog::on_equal_pbt_clicked()
{
    QString exp = ui->exp_edt->text();
    if(exp == "0"){
        return;
    }
    if(exp.length() < 0){
        qDebug() << "Input Error!!!";
    }
    else if(exp.length() == 1 && exp[0].isDigit()){
        show2Conclude(QString::number(exp.toDouble()));
        ui->exp_edt->setText(QString::number(exp.toDouble()));
    }
    else{
        toPostfix();
        evaluation();
        init();
    }

//    toPostfix();
//    evaluation();
//    init();
    postfix = "";
}

void caculatorDialog::on_del_pbt_clicked()
{
    QString str = ui->exp_edt->text();
    str = str.mid(0, str.size() - 1);
    ui->exp_edt->setText(str);
}


void caculatorDialog::on_clearTextPlainEdit_pbt_clicked()
{
    ui->conclude_pedt->clear();
}
