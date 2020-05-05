#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QSerialPort>
#include <QByteArray>
static double RA,DEC;
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

    void on_HomeButton_clicked();
    void updateInfiniteCount(double,int,int,int,int,double,double,char,char,int,int,int,int,int,int,char,char,int,int,int,int,int,int,QString,QString);
    void startInfiniteCount();
    void infiniteCountFinished();

private:



    Ui::MainWindow *ui;
    QTimer *timer_1s;
    QTimer *timer_refreshrate;
    int a = 0;
    void connectSignalsSlots();
    void on_GoButton_clicked();
    bool countRunning;
    bool infiniteCountRunning;
};

#endif // MAINWINDOW_H
