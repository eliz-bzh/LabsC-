#include "unitwindow.h"
#include "ui_unitwindow.h"

Unitwindow::Unitwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Unitwindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Units");
    setupUnitsModel();
    connect(ui->pushButton_addunit, &QPushButton::clicked, this, &Unitwindow::slotAddUnits);
}

Unitwindow::~Unitwindow()
{
    delete ui;
}

void Unitwindow::setupUnitsModel()
{
    unitsmodel = new QSqlTableModel(this);
    unitsmodel->setTable("units");
    unitsmodel->select();
    ui->tableView->setModel(unitsmodel);
    ui->tableView->setColumnHidden(0,true);
    ui->tableView->verticalHeader()->setVisible(false);
}

void Unitwindow::slotAddUnits()
{
    if(!DataBase::insertIntoUnits(QList<QVariant>{QVariant(ui->lineEdit->text())}))
    {
        QMessageBox::information(this, "Error", "Error");
    }
    else {
        QMessageBox::information(this, "Info Window", "You added");
        unitsmodel->select();
    }
}
