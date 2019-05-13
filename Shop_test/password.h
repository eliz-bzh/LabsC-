#ifndef PASSWORD_H
#define PASSWORD_H

#include <QDialog>
#include <QMessageBox>
#include "genderwindow.h"

namespace Ui {
class Password;
}

class Password : public QDialog
{
    Q_OBJECT

public:
    explicit Password(QWidget *parent = nullptr);
    ~Password();


private:
    Ui::Password *ui;
    Genderwindow *gender;

private slots:
    void on_buttonSignIn_clicked();
};

#endif // PASSWORD_H
