#include "mainwindow.h"
#include "qtableview.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("password");
    db.setDatabaseName("car_db");
    db.open();

}

MainWindow::~MainWindow()
{
    delete ui;

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







void MainWindow::on_pushButton_clicked()
{

    QString lineEdit0 = ui->lineEdit->text();
    QString lineEdit1 = ui->lineEdit_2->text();
    QLineEdit();


    QSqlQuery query;
    query.prepare("INSERT INTO car (branch, model) VALUES (:branch, :model)");
    query.bindValue(":branch", lineEdit0);
    query.bindValue(":model", lineEdit1);
    query.exec();

}

