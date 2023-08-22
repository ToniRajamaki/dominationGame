#include "dialog.h"
#include "ui_dialog.h"
#include <QString>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)

{
    ui->setupUi(this);
    ui->TimerspinBox->setValue(45);
}


Dialog::~Dialog()
{
    delete ui;
}

int Dialog::exec()
{
    int dialog = QDialog::exec();


    if(dialog == QDialog::Accepted)
    {
        QString name1 = ui->pl1_text->text();
        QString name2 = ui->pl2_text->text();
        int interval = ui->TimerspinBox->value();
        emit sendSettings(name1.toStdString(),name2.toStdString(), interval);
    }

    return dialog;
}
