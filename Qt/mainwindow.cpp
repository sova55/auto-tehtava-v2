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


void MainWindow::on_btnShowCars_clicked()
{
    QString site_url="http://localhost:3000/car/";
    QNetworkRequest request((site_url));


    getManager = new QNetworkAccessManager(this);

    connect(getManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getCarSlot(QNetworkReply*)));

    reply = getManager->get(request);

}

void MainWindow::on_pushCarAdd_clicked()
{
    QJsonObject jsonObj;

    QString branch = ui->lineBranch->text();
    QString model =  ui->lineModel->text();

    jsonObj.insert("branch",  branch);
    jsonObj.insert("model", model);


    QJsonDocument doc(jsonObj);
    QByteArray dataBody = doc.toJson();


    ui->lineBranch->clear();
    ui->lineModel->clear();



    QString site_url="http://localhost:3000/car";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");


    postManager = new QNetworkAccessManager(this);
    connect(postManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(addCarSlot(QNetworkReply*)));

    reply = postManager->post(request, dataBody);

}





void MainWindow::getCarSlot (QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<"DATA : " +response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString car;
    foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        car+=QString::number(json_obj["id"].toInt())+", "+json_obj["branch"].toString()+", "+json_obj["model"].toString()+"\r";
    }



    ui->textCars->setText(car);


    reply->deleteLater();
    getManager->deleteLater();
}


void MainWindow::addCarSlot (QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    reply->deleteLater();
    postManager->deleteLater();
}



