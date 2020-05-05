#include <QTimer>
#include <QTime>
#include <stdio.h>
#include <time.h>
#include <slalib.h>
#include <slamac.h>
#include <math.h>
#include <unistd.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <string>
#include <QDebug>
#include <QMessageBox>
#include <QThread>
#include "infinite_thread.h"


#define R2D 57.29577951308232   /* radians to degrees */
#define R2MAS 206264.806247096355e3 /* radians to mas */


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    infiniteCountRunning(false)
{
    ui->setupUi(this);
    connectSignalsSlots();



    setWindowTitle("Control Software");
    setMinimumSize(800, 450);
    // == MENU BAR ==
    QMenuBar * menuBar = new QMenuBar(this);
    setMenuBar(menuBar);
    // -- File menu --
    // -- File menu --
    QMenu * menu = menuBar->addMenu("&Config");
    QMenu * menu1 = menuBar->addMenu("&Mount");
    QMenu * menu2 = menuBar->addMenu("&Catalog");
    QMenu * menu3 = menuBar->addMenu("&Features");
    QMenu * menu4 = menuBar->addMenu("&Help");
    // New
    QAction * action = new QAction("&New", this);
   // connect(action, &QAction::triggered, this, &MainWindow::OnFileNew);
    menu->addAction(action);
    // Open
    action = new QAction("&Open", this);
    //connect(action, &QAction::triggered, this, &MainWindow::OnFileOpen);
    menu->addAction(action);
    // Save
    action = new QAction("&Save", this);
    //connect(action, &QAction::triggered, this, &MainWindow::OnFileSave);
    menu->addAction(action);
    // separator
    menu->addSeparator();
    // Exit
    action = new QAction("&Exit", this);
    connect(action, &QAction::triggered, this, &MainWindow::close);
    menu->addAction(action);
    // == STATUS BAR ==
    QStatusBar * statusBar = new QStatusBar(this);
    setStatusBar(statusBar);
   // ui->Altvalue->setText(QString::number(44));
   // ui->Azvalue->setText(QString::number(233));
   // ui->temp_lcdNumber->display(QString::number(233));
    //Coord( 360.6888, 189.356666666);
    timer_1s = new QTimer(this);
    QObject::connect(timer_1s, SIGNAL(timeout()), this, SLOT(systtime()));
    timer_1s->start(100);




}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateInfiniteCount(double ams ,int azd,int azm,int altd,int altm,double asec,double altsec, char signRA,char signDEC,int chour,int cminute,int csecond,int cdeg,int camin,int casec,char signha,char signde,int cehour,int ceminute,int cesecond,int cedeg,int ceamin,int ceasec,QString parsed_data,QString parsed_data2)
{
    ui->ams->setText(QString::number(ams) );
    ui->ad->setText(QString::number(azd )+ QString("°") );
    ui->am->setText(QString::number(azm)+ QString("'"));
     ui->as->setText(QString::number((double)asec, 'f', 2)+ QString("''"));
     ui->altd->setText(QString::number(altd)+ QString("°") );
     ui->altm->setText(QString::number(altm)+ QString("'"));
      ui->alts->setText(QString::number((double)altsec, 'f', 2)+ QString(" '' "));
    ui->signRA->setText(QString(signRA));
    ui->chour->setText(QString::number(chour));
    ui->cminute->setText(QString::number(cminute));
    ui->csecond->setText(QString::number(csecond));
    ui->signDEC->setText(QString(signDEC));
    ui->cdeg->setText(QString::number( cdeg));
    ui->camin->setText(QString::number(camin));
    ui->casec->setText(QString::number(casec));


    ui->signera->setText(QString(signha));
    ui->ehour->setText(QString::number(cehour));
    ui->eminute->setText(QString::number(ceminute));
    ui->esecond->setText(QString::number(cesecond));
    ui->signedec->setText(QString(signde));
    ui->cedeg->setText(QString::number( cedeg));
    ui->cdegmin->setText(QString::number(ceamin));
    ui->cdegsec->setText(QString::number(ceasec));


     ui->temp_lcdNumber->display(parsed_data);
      ui->temp_lcdNumber_2->display(parsed_data2);




}

void MainWindow::startInfiniteCount()
{
    QThread             *workerThread;
    InfiniteCountWorker *worker;

    if (infiniteCountRunning) {
        QMessageBox::critical(this, "Warning", "Telescope Slewing, Press Stop and then Start!");
        return;
    }

    ui->Status->setText(("Slewing"));
         double h = ui->hour->text().toDouble();
         double m = ui->minute->text().toDouble();
         double s = ui->second->text().toDouble();
         double de= ui->archour->text().toDouble();
         double am= ui->arcmin->text().toDouble();
         double as= ui->arcsec->text().toDouble();

         /*Convert RA dec to degree*/
         //double rad;
         //int j;
         //slaDtf2r( h, m, s, &rad, &j );

          RA=((h+(m/60)+(s/3600)));
          DEC= (de + (am/60) + (as/3600));


    workerThread = new QThread;
    worker       = new InfiniteCountWorker(RA, DEC);
    worker->moveToThread(workerThread);
    connect(workerThread, SIGNAL(started()), worker, SLOT(doWork()));
    connect(worker, SIGNAL(finished()), workerThread, SLOT(quit()));
    connect(worker, SIGNAL(finished()), worker, SLOT(deleteLater()));
    connect(workerThread, SIGNAL(finished()), workerThread, SLOT(deleteLater()));
    connect(worker, SIGNAL(finished()), this, SLOT(infiniteCountFinished()));
    connect(worker, SIGNAL(updateInfiniteCount(double,int,int,int,int,double,double,char,char,int,int,int,int,int,int,char,char,int,int,int,int,int,int,QString,QString)), this, SLOT(updateInfiniteCount(double,int,int,int,int,double,double,char,char,int,int,int,int,int,int,char,char,int,int,int,int,int,int,QString,QString)));
     connect(ui->infiniteCountNoGo, SIGNAL(clicked()), worker, SLOT(stopWork()));
    workerThread->start();

    infiniteCountRunning = true;
}

void MainWindow::infiniteCountFinished()
{
    infiniteCountRunning = false;
}

void MainWindow::connectSignalsSlots()
{

    connect(ui->infiniteCountGo, SIGNAL(clicked()), this, SLOT(startInfiniteCount()));



}

void MainWindow::systtime()
{
    ui->lbl_time->setText(QTime::currentTime().toString("hh:mm:ss"));

}

void MainWindow::on_GoButton_clicked()
{

}
void MainWindow::on_HomeButton_clicked()
{
ui->Status->setText(("Homing"));
//double home_value=360;
}
