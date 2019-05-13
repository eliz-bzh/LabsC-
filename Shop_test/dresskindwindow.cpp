#include "dresskindwindow.h"
#include "ui_dresskindwindow.h"

DressKindWindow::DressKindWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DressKindWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Dress Kinds");
    setupDressKindModel();
    setupDressKindUi();
    connect(ui->add_dresskind, &QPushButton::clicked, this, &DressKindWindow::slotAddDressKind);
}

DressKindWindow::~DressKindWindow()
{
    delete ui;
}

void DressKindWindow::setupDressKindModel()
{
    dresskindmodel = new QSqlTableModel(this);
    gendercomboxmodel = new ComboBoxModel(QSqlQuery("SELECT id, gen_name from Genders"));
    categorycomboxmodel = new ComboBoxModel(QSqlQuery("SELECT id, c_name from categories"));
    dresskindmodel->setTable("Dress_kinds");
    dresskindmodel->select();
    ui->comboBox_Gender->setModel(gendercomboxmodel);
    ui->comboBox_Category->setModel(categorycomboxmodel);
}

void DressKindWindow::setupDressKindUi()
{
    ui->tableView->setModel(dresskindmodel);
    ui->tableView->setColumnHidden(0,true);
    ui->tableView->verticalHeader()->setVisible(false);
}

void DressKindWindow::slotAddDressKind()
{
    if(!DataBase::insertIntoDressKind(QList<QVariant>{QVariant(ui->lineEdit->text()),
                                      QVariant(ui->comboBox_Category->currentData()),
                                      QVariant(ui->comboBox_Gender->currentData())}))
    {
        QMessageBox::information(this, "Error", "Error");
    }
    else {
        QMessageBox::information(this, "Info Window", "You added");
        dresskindmodel->select();
    }
}


