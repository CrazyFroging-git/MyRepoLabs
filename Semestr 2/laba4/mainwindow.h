#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <Qfile>
#include <QTextStream>


class Product {
public:
    QString cargo;
    QString country;
    int weight;
    double price;
    QString delivery;
    QString markers;

    Product(QString c, QString cnt, int w, double p, QString del, QString m)
        : cargo(c), country(cnt), weight(w), price(p), delivery(del), markers(m) {}

    bool saveToFile(QString filename) {
        QFile file(filename);
        if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&file);
            out << "Груз: " << cargo << "\n";
            out << "Страна: " << country << "\n";
            out << "Вес: " << weight << " кг\n";
            out << "Цена: " << price << " руб\n";
            out << "Доставка: " << delivery << "\n";
            out << "Маркеры: " << (markers.isEmpty() ? "Нет" : markers) << "\n";
            out << "---------------------------\n";
            file.close();
            return true;
        }
        return false;
    }
};

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonReset_clicked();

    void on_pushButtonSave_clicked();

private:
    Ui::MainWindow *ui;
};
#endif
