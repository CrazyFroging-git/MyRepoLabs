#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QRegularExpression>

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

void MainWindow::on_pushButtonReset_clicked()
{
    ui->lineEditName->clear();
    ui->lineEditCountry->clear();
    ui->lineEditWeight->clear();
    ui->lineEditPrice->clear();


    ui->planeButtonDot->setChecked(false);
    ui->shipButtonDot->setChecked(false);

    ui->checkDamage->setChecked(false);
    ui->checkNew->setChecked(false);
    ui->checkReturn->setChecked(false);
}


void MainWindow::on_pushButtonSave_clicked()
{
    QString name = ui->lineEditName->text().trimmed();
    QString country = ui->lineEditCountry->text().trimmed();
    QString weightStr = ui->lineEditWeight->text().trimmed();
    QString priceStr = ui->lineEditPrice->text().trimmed();

    if (name.isEmpty() || country.isEmpty() || weightStr.isEmpty() || priceStr.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Все поля (кроме маркеров) обязательны для заполнения!");
        return;
    }
    QRegularExpression regName("^[A-ZА-Я][a-zа-яё]*$");
    if (!regName.match(name).hasMatch()) {
        QMessageBox::warning(this, "Ошибка", "Поле 'Груз' должно начинаться с заглавной буквы (далее - строчные).");
        return;
    }
    QRegularExpression regCountry("^[A-ZА-Я][a-zа-яё]*$|^[A-ZА-Я]+$");
    if (!regCountry.match(country).hasMatch()) {
        QMessageBox::warning(this, "Ошибка", "Поле 'Страна' должно быть либо 'С большой буквы', либо 'ВЕСЬ КАПС'.");
        return;
    }
    bool okWeight;
    int weight = weightStr.toInt(&okWeight);
    if (!okWeight || weight <= 0) {
        QMessageBox::warning(this, "Ошибка", "Вес должен быть целым положительным числом!");
        return;
    }
    bool okPrice;
    double price = priceStr.toDouble(&okPrice);
    if (!okPrice || price <= 0) {
        QMessageBox::warning(this, "Ошибка", "Введите корректную цену!");
        return;
    }
    if ((price / weight) > 100000) {
        QMessageBox::warning(this, "Ошибка", "Цена за кг не может превышать 100 000 руб.");
        return;
    }
    if (!ui->planeButtonDot->isChecked() && !ui->shipButtonDot->isChecked()) {
        QMessageBox::warning(this, "Ошибка", "Выберите способ доставки (Самолет или Корабль)!");
        return;
    }
    //QMessageBox::information(this, "Успех", "Данные корректны и сохранены!");




    QString deliveryMethod = ui->planeButtonDot->isChecked() ? "Самолет" : "Корабль";
    QStringList markersList;
    if (ui->checkDamage->isChecked()) markersList << "Повреждение";
    if (ui->checkNew->isChecked()) markersList << "Новинка";
    if (ui->checkReturn->isChecked()) markersList << "Безвозвратное";
    QString allMarkers = markersList.join(", ");
    Product newProduct(name, country, weight, price, deliveryMethod, allMarkers);

    if (newProduct.saveToFile("..\\..\\result.txt")) {
        QMessageBox::information(this, "Успех", "Данные успешно записаны в result.txt");
    } else {
        QMessageBox::critical(this, "Ошибка", "Не удалось открыть файл для записи!");
    }


}


















