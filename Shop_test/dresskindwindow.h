#ifndef DRESSKINDWINDOW_H
#define DRESSKINDWINDOW_H

#include <QPushButton>
#include <QSqlTableModel>
#include <QDialogButtonBox>
#include <QMainWindow>
#include <QStringListModel>
#include "database.h"
#include <QDialog>
#include <QMessageBox>
#include "comboboxmodel.h"

namespace Ui {
class DressKindWindow;
}

class DressKindWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DressKindWindow(QWidget *parent = nullptr);
    ~DressKindWindow();

public slots:
    void slotAddDressKind();
private slots:


private:
    Ui::DressKindWindow *ui;
    QSqlTableModel *dresskindmodel;
    ComboBoxModel *gendercomboxmodel;
    ComboBoxModel *categorycomboxmodel;

    void setupDressKindModel();
    void setupDressKindUi();
};

#endif // DRESSKINDWINDOW_H
