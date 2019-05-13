#include "genderwindow.h"
#include "ui_genderwindow.h"

Genderwindow::Genderwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Genderwindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Genders");
    setupGendersModel();
}

Genderwindow::~Genderwindow()
{
    delete ui;
}

void Genderwindow::setupGendersModel()
{
    gendermodel = new QSqlTableModel(this);
    gendermodel->setTable("Genders");
    gendermodel->select();
    ui->tableView->setModel(gendermodel);
    ui->tableView->setColumnHidden(0,true);
    ui->tableView->verticalHeader()->setVisible(false);
}

void Genderwindow::changeModelSlotCategory()
{
    ui->tableView->setModel(categorymodel);
}

void Genderwindow::on_pushButton_clicked()
{
    hide();
    CategoryWindow categorywindow;
    categorywindow.setModal(true);
    categorywindow.exec();
}

void Genderwindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    hide();
    category->show();
}
