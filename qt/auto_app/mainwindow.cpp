#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("password");
    db.setDatabaseName("car_db");

    if(db.open()) {
        QMessageBox::information(this, "Connection", "Database Connected Successfully");
    } else {
        QMessageBox::information(this, "Not Connected", "Database is not connected");
    }
}






void MainWindow::on_pushButton_2_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT id, branch, model FROM car");
    model->setHeaderData(0, Qt::Horizontal, tr("id"));
    model->setHeaderData(1, Qt::Horizontal, tr("branch"));
    model->setHeaderData(2, Qt::Horizontal, tr("model"));

    QTableView  *view = new QTableView;
    view->setModel(model);
    view->show();


}


void MainWindow::on_tableView_activated(const QModelIndex &index)
{

}

