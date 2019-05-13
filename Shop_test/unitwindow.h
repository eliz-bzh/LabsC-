#ifndef UNITWINDOW_H
#define UNITWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QSqlTableModel>
#include <QDialogButtonBox>
#include <QStringListModel>
#include "database.h"
#include <QDialog>
#include <QMessageBox>

namespace Ui {
class Unitwindow;
}

class Unitwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit Unitwindow(QWidget *parent = nullptr);
    ~Unitwindow();

public slots:
    void setupUnitsModel();
    void slotAddUnits();

private:
    Ui::Unitwindow *ui;
    QSqlTableModel *unitsmodel;
};

#endif // UNITWINDOW_H
