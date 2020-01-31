#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QSerialPort>
#include <QByteArray>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void systtime();
       void Coord(double, double);

    void on_GoButton_clicked();
    void on_HomeButton_clicked();
    void readSerialAzimuth();
    void sendSerialAzimuth(double);
    void updateAzimuthvalue(QString);
    void pointingCorrection(double,double);
    void test();



private:
    Ui::MainWindow *ui;

    QTimer *timer_1s;
    QTimer *timer_refreshrate;
    QSerialPort *arduino;
    static const quint16 arduino_uno_vendor_id = 9025;
    static const quint16 arduino_uno_product_id = 67;
    QByteArray serialData;
    QString serialBuffer;
    QString parsed_data;
    double currentazimuth_value;
     QByteArray writeData;

     int a = 0;


};

#endif // MAINWINDOW_H
