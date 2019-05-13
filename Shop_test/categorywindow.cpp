#include "categorywindow.h"
#include "ui_category.h"
#include "goodswindow.h"


CategoryWindow::CategoryWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Category)
{
    ui->setupUi(this);
    this->setWindowTitle("Categories");
    setupCategoryModel();
    connect(ui->pushButton_Add, &QPushButton::clicked, this, &CategoryWindow::slotAddCategory);
    //connect(ui->pushButton_delete, &QPushButton::clicked, this, &CategoryWindow::slotdeleteCategory);
}

CategoryWindow::~CategoryWindow()
{
    delete ui;
}

void CategoryWindow::setupCategoryModel()
{
   // categorymodel = new BaseListModel(QSqlQuery("SELECT id, c_name from categories"), this);
    //ui->listView_Category->setModel(categorymodel);
    categorymodel = new QSqlTableModel(this);
    categorymodel->setTable("categories");
    categorymodel->select();
    ui->tableView->setModel(categorymodel);
    ui->tableView->setColumnHidden(0,true);
    ui->tableView->verticalHeader()->setVisible(false);
}

void CategoryWindow::changeModelSlotGoods()
{
    //ui->tableView->setModel(goodsmodel);
}

void CategoryWindow::Aon_pushButton_clicked()
{
    hide();
    GoodsWindow gooodswindow;
    gooodswindow.setModal(true);
    gooodswindow.exec();
}

void CategoryWindow::slotAddCategory()
{
    if(!DataBase::insertIntoCategories(ui->lineEdit->text()))
    {
        QMessageBox::information(this, "Error", "Error");
    }
    else {
        QMessageBox::information(this, "Info Window", "You added");
        categorymodel->select();
    }
}

void CategoryWindow::slotDeleteCategory()
{
    /*if(!DataBase::deleteCategory(ui->listView_Category->cur))
    {
        QMessageBox::information(this, "Error", "Error");
    }
    else {
        QMessageBox::information(this, "Info Window", "You delete");
        //ui->listView_Category->setModel(categorymodel);
        categorymodel->select();
    }*/
}

