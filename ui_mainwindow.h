/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *UTC;
    QLabel *lbl_time;
    QLabel *ad;
    QLabel *Azimuth;
    QCheckBox *Tracking;
    QLabel *MOUNTSTATUS;
    QLabel *temp_label;
    QLabel *Status;
    QPushButton *HomeButton;
    QLabel *Connection;
    QPushButton *rightbutton;
    QPushButton *leftbutton;
    QPushButton *downbutton;
    QPushButton *upbutton;
    QLabel *UTC_2;
    QLabel *ams;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *archour;
    QLineEdit *arcmin;
    QLineEdit *arcsec;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *hour;
    QLineEdit *minute;
    QLineEdit *second;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *RA;
    QLabel *signRA;
    QLabel *chour;
    QLabel *cminute;
    QLabel *csecond;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *DEC;
    QLabel *signDEC;
    QLabel *cdeg;
    QLabel *camin;
    QLabel *casec;
    QPushButton *infiniteCountGo;
    QPushButton *infiniteCountNoGo;
    QLabel *as;
    QLabel *am;
    QLabel *altd;
    QLabel *Altitude;
    QLabel *alts;
    QLabel *altm;
    QLabel *MOUNTSTATUS_2;
    QLabel *MOUNTSTATUS_3;
    QLabel *MOUNTSTATUS_4;
    QLCDNumber *temp_lcdNumber_6;
    QLCDNumber *temp_lcdNumber_7;
    QLabel *temp_label_7;
    QLabel *temp_label_8;
    QLCDNumber *temp_lcdNumber_4;
    QLabel *temp_label_5;
    QLCDNumber *temp_lcdNumber_5;
    QLabel *temp_label_6;
    QLabel *eminute;
    QLabel *RA_2;
    QLabel *ehour;
    QLabel *esecond;
    QLabel *signera;
    QLabel *RA_3;
    QLabel *cdegsec;
    QLabel *signedec;
    QLabel *cdegmin;
    QLabel *cedeg;
    QLCDNumber *temp_lcdNumber;
    QLCDNumber *temp_lcdNumber_2;
    QLabel *temp_label_2;
    QLabel *temp_label_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1017, 672);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        UTC = new QLabel(centralWidget);
        UTC->setObjectName(QString::fromUtf8("UTC"));
        UTC->setGeometry(QRect(680, 100, 121, 16));
        lbl_time = new QLabel(centralWidget);
        lbl_time->setObjectName(QString::fromUtf8("lbl_time"));
        lbl_time->setGeometry(QRect(770, 100, 70, 17));
        ad = new QLabel(centralWidget);
        ad->setObjectName(QString::fromUtf8("ad"));
        ad->setGeometry(QRect(750, 191, 41, 16));
        Azimuth = new QLabel(centralWidget);
        Azimuth->setObjectName(QString::fromUtf8("Azimuth"));
        Azimuth->setGeometry(QRect(680, 190, 59, 16));
        Tracking = new QCheckBox(centralWidget);
        Tracking->setObjectName(QString::fromUtf8("Tracking"));
        Tracking->setGeometry(QRect(110, 310, 94, 23));
        MOUNTSTATUS = new QLabel(centralWidget);
        MOUNTSTATUS->setObjectName(QString::fromUtf8("MOUNTSTATUS"));
        MOUNTSTATUS->setGeometry(QRect(680, 160, 121, 20));
        temp_label = new QLabel(centralWidget);
        temp_label->setObjectName(QString::fromUtf8("temp_label"));
        temp_label->setGeometry(QRect(620, 370, 142, 23));
        Status = new QLabel(centralWidget);
        Status->setObjectName(QString::fromUtf8("Status"));
        Status->setGeometry(QRect(390, 460, 161, 17));
        HomeButton = new QPushButton(centralWidget);
        HomeButton->setObjectName(QString::fromUtf8("HomeButton"));
        HomeButton->setGeometry(QRect(430, 250, 91, 25));
        Connection = new QLabel(centralWidget);
        Connection->setObjectName(QString::fromUtf8("Connection"));
        Connection->setGeometry(QRect(120, 110, 142, 23));
        rightbutton = new QPushButton(centralWidget);
        rightbutton->setObjectName(QString::fromUtf8("rightbutton"));
        rightbutton->setGeometry(QRect(170, 190, 31, 25));
        leftbutton = new QPushButton(centralWidget);
        leftbutton->setObjectName(QString::fromUtf8("leftbutton"));
        leftbutton->setGeometry(QRect(110, 190, 31, 25));
        downbutton = new QPushButton(centralWidget);
        downbutton->setObjectName(QString::fromUtf8("downbutton"));
        downbutton->setGeometry(QRect(140, 220, 31, 25));
        upbutton = new QPushButton(centralWidget);
        upbutton->setObjectName(QString::fromUtf8("upbutton"));
        upbutton->setGeometry(QRect(140, 160, 31, 25));
        UTC_2 = new QLabel(centralWidget);
        UTC_2->setObjectName(QString::fromUtf8("UTC_2"));
        UTC_2->setGeometry(QRect(680, 120, 121, 16));
        ams = new QLabel(centralWidget);
        ams->setObjectName(QString::fromUtf8("ams"));
        ams->setGeometry(QRect(770, 120, 70, 17));
        layoutWidget_2 = new QWidget(centralWidget);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(370, 170, 214, 31));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        archour = new QLineEdit(layoutWidget_2);
        archour->setObjectName(QString::fromUtf8("archour"));

        horizontalLayout_4->addWidget(archour);

        arcmin = new QLineEdit(layoutWidget_2);
        arcmin->setObjectName(QString::fromUtf8("arcmin"));

        horizontalLayout_4->addWidget(arcmin);

        arcsec = new QLineEdit(layoutWidget_2);
        arcsec->setObjectName(QString::fromUtf8("arcsec"));

        horizontalLayout_4->addWidget(arcsec);

        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(371, 130, 207, 31));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        hour = new QLineEdit(layoutWidget);
        hour->setObjectName(QString::fromUtf8("hour"));

        horizontalLayout_2->addWidget(hour);

        minute = new QLineEdit(layoutWidget);
        minute->setObjectName(QString::fromUtf8("minute"));

        horizontalLayout_2->addWidget(minute);

        second = new QLineEdit(layoutWidget);
        second->setObjectName(QString::fromUtf8("second"));

        horizontalLayout_2->addWidget(second);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(390, 350, 171, 31));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        RA = new QLabel(layoutWidget1);
        RA->setObjectName(QString::fromUtf8("RA"));

        horizontalLayout_3->addWidget(RA);

        signRA = new QLabel(layoutWidget1);
        signRA->setObjectName(QString::fromUtf8("signRA"));

        horizontalLayout_3->addWidget(signRA);

        chour = new QLabel(layoutWidget1);
        chour->setObjectName(QString::fromUtf8("chour"));

        horizontalLayout_3->addWidget(chour);

        cminute = new QLabel(layoutWidget1);
        cminute->setObjectName(QString::fromUtf8("cminute"));

        horizontalLayout_3->addWidget(cminute);

        csecond = new QLabel(layoutWidget1);
        csecond->setObjectName(QString::fromUtf8("csecond"));

        horizontalLayout_3->addWidget(csecond);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(390, 380, 171, 31));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        DEC = new QLabel(layoutWidget2);
        DEC->setObjectName(QString::fromUtf8("DEC"));

        horizontalLayout_5->addWidget(DEC);

        signDEC = new QLabel(layoutWidget2);
        signDEC->setObjectName(QString::fromUtf8("signDEC"));

        horizontalLayout_5->addWidget(signDEC);

        cdeg = new QLabel(layoutWidget2);
        cdeg->setObjectName(QString::fromUtf8("cdeg"));

        horizontalLayout_5->addWidget(cdeg);

        camin = new QLabel(layoutWidget2);
        camin->setObjectName(QString::fromUtf8("camin"));

        horizontalLayout_5->addWidget(camin);

        casec = new QLabel(layoutWidget2);
        casec->setObjectName(QString::fromUtf8("casec"));

        horizontalLayout_5->addWidget(casec);

        infiniteCountGo = new QPushButton(centralWidget);
        infiniteCountGo->setObjectName(QString::fromUtf8("infiniteCountGo"));
        infiniteCountGo->setGeometry(QRect(380, 210, 91, 31));
        infiniteCountNoGo = new QPushButton(centralWidget);
        infiniteCountNoGo->setObjectName(QString::fromUtf8("infiniteCountNoGo"));
        infiniteCountNoGo->setGeometry(QRect(480, 210, 101, 31));
        infiniteCountNoGo->setStyleSheet(QString::fromUtf8("QPushButton:pressed {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,   stop:0 rgba(60, 186, 162, 255), stop:1 rgba(98, 211, 162, 255))\n"
"}\n"
"QPushButton {\n"
"     background-color: #3cbaa2; border: 1px solid black;\n"
"     border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: rgb(170, 170, 127)\n"
"}"));
        as = new QLabel(centralWidget);
        as->setObjectName(QString::fromUtf8("as"));
        as->setGeometry(QRect(830, 191, 91, 16));
        am = new QLabel(centralWidget);
        am->setObjectName(QString::fromUtf8("am"));
        am->setGeometry(QRect(790, 191, 40, 16));
        altd = new QLabel(centralWidget);
        altd->setObjectName(QString::fromUtf8("altd"));
        altd->setGeometry(QRect(750, 211, 28, 16));
        Altitude = new QLabel(centralWidget);
        Altitude->setObjectName(QString::fromUtf8("Altitude"));
        Altitude->setGeometry(QRect(680, 211, 58, 16));
        alts = new QLabel(centralWidget);
        alts->setObjectName(QString::fromUtf8("alts"));
        alts->setGeometry(QRect(830, 210, 101, 16));
        altm = new QLabel(centralWidget);
        altm->setObjectName(QString::fromUtf8("altm"));
        altm->setGeometry(QRect(790, 210, 27, 16));
        MOUNTSTATUS_2 = new QLabel(centralWidget);
        MOUNTSTATUS_2->setObjectName(QString::fromUtf8("MOUNTSTATUS_2"));
        MOUNTSTATUS_2->setGeometry(QRect(390, 320, 151, 20));
        MOUNTSTATUS_3 = new QLabel(centralWidget);
        MOUNTSTATUS_3->setObjectName(QString::fromUtf8("MOUNTSTATUS_3"));
        MOUNTSTATUS_3->setGeometry(QRect(680, 250, 121, 20));
        MOUNTSTATUS_4 = new QLabel(centralWidget);
        MOUNTSTATUS_4->setObjectName(QString::fromUtf8("MOUNTSTATUS_4"));
        MOUNTSTATUS_4->setGeometry(QRect(370, 100, 151, 20));
        temp_lcdNumber_6 = new QLCDNumber(centralWidget);
        temp_lcdNumber_6->setObjectName(QString::fromUtf8("temp_lcdNumber_6"));
        temp_lcdNumber_6->setGeometry(QRect(280, 430, 41, 23));
        QPalette palette;
        QBrush brush(QColor(0, 0, 94, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush);
        QBrush brush2(QColor(60, 60, 60, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush2);
        QBrush brush3(QColor(76, 76, 76, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        temp_lcdNumber_6->setPalette(palette);
        temp_lcdNumber_6->setDigitCount(7);
        temp_lcdNumber_7 = new QLCDNumber(centralWidget);
        temp_lcdNumber_7->setObjectName(QString::fromUtf8("temp_lcdNumber_7"));
        temp_lcdNumber_7->setGeometry(QRect(280, 470, 41, 23));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        temp_lcdNumber_7->setPalette(palette1);
        temp_lcdNumber_7->setDigitCount(7);
        temp_label_7 = new QLabel(centralWidget);
        temp_label_7->setObjectName(QString::fromUtf8("temp_label_7"));
        temp_label_7->setGeometry(QRect(100, 470, 138, 16));
        temp_label_8 = new QLabel(centralWidget);
        temp_label_8->setObjectName(QString::fromUtf8("temp_label_8"));
        temp_label_8->setGeometry(QRect(100, 430, 145, 16));
        temp_lcdNumber_4 = new QLCDNumber(centralWidget);
        temp_lcdNumber_4->setObjectName(QString::fromUtf8("temp_lcdNumber_4"));
        temp_lcdNumber_4->setGeometry(QRect(280, 350, 41, 23));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        temp_lcdNumber_4->setPalette(palette2);
        temp_lcdNumber_4->setDigitCount(7);
        temp_label_5 = new QLabel(centralWidget);
        temp_label_5->setObjectName(QString::fromUtf8("temp_label_5"));
        temp_label_5->setGeometry(QRect(100, 350, 161, 20));
        temp_lcdNumber_5 = new QLCDNumber(centralWidget);
        temp_lcdNumber_5->setObjectName(QString::fromUtf8("temp_lcdNumber_5"));
        temp_lcdNumber_5->setGeometry(QRect(280, 390, 41, 23));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Dark, brush);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        temp_lcdNumber_5->setPalette(palette3);
        temp_lcdNumber_5->setDigitCount(7);
        temp_label_6 = new QLabel(centralWidget);
        temp_label_6->setObjectName(QString::fromUtf8("temp_label_6"));
        temp_label_6->setGeometry(QRect(100, 390, 151, 16));
        eminute = new QLabel(centralWidget);
        eminute->setObjectName(QString::fromUtf8("eminute"));
        eminute->setGeometry(QRect(790, 280, 31, 17));
        RA_2 = new QLabel(centralWidget);
        RA_2->setObjectName(QString::fromUtf8("RA_2"));
        RA_2->setGeometry(QRect(681, 281, 23, 17));
        ehour = new QLabel(centralWidget);
        ehour->setObjectName(QString::fromUtf8("ehour"));
        ehour->setGeometry(QRect(760, 281, 31, 17));
        esecond = new QLabel(centralWidget);
        esecond->setObjectName(QString::fromUtf8("esecond"));
        esecond->setGeometry(QRect(830, 281, 51, 17));
        signera = new QLabel(centralWidget);
        signera->setObjectName(QString::fromUtf8("signera"));
        signera->setGeometry(QRect(740, 281, 16, 17));
        RA_3 = new QLabel(centralWidget);
        RA_3->setObjectName(QString::fromUtf8("RA_3"));
        RA_3->setGeometry(QRect(681, 311, 29, 17));
        cdegsec = new QLabel(centralWidget);
        cdegsec->setObjectName(QString::fromUtf8("cdegsec"));
        cdegsec->setGeometry(QRect(830, 310, 71, 17));
        signedec = new QLabel(centralWidget);
        signedec->setObjectName(QString::fromUtf8("signedec"));
        signedec->setGeometry(QRect(740, 310, 16, 17));
        cdegmin = new QLabel(centralWidget);
        cdegmin->setObjectName(QString::fromUtf8("cdegmin"));
        cdegmin->setGeometry(QRect(790, 310, 21, 17));
        cedeg = new QLabel(centralWidget);
        cedeg->setObjectName(QString::fromUtf8("cedeg"));
        cedeg->setGeometry(QRect(760, 310, 31, 17));
        temp_lcdNumber = new QLCDNumber(centralWidget);
        temp_lcdNumber->setObjectName(QString::fromUtf8("temp_lcdNumber"));
        temp_lcdNumber->setGeometry(QRect(660, 410, 241, 41));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Dark, brush);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Dark, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Dark, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        temp_lcdNumber->setPalette(palette4);
        temp_lcdNumber->setDigitCount(9);
        temp_lcdNumber_2 = new QLCDNumber(centralWidget);
        temp_lcdNumber_2->setObjectName(QString::fromUtf8("temp_lcdNumber_2"));
        temp_lcdNumber_2->setGeometry(QRect(660, 460, 241, 41));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Dark, brush);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Dark, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Dark, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        temp_lcdNumber_2->setPalette(palette5);
        temp_lcdNumber_2->setDigitCount(9);
        temp_label_2 = new QLabel(centralWidget);
        temp_label_2->setObjectName(QString::fromUtf8("temp_label_2"));
        temp_label_2->setGeometry(QRect(620, 420, 31, 17));
        temp_label_3 = new QLabel(centralWidget);
        temp_label_3->setObjectName(QString::fromUtf8("temp_label_3"));
        temp_label_3->setGeometry(QRect(620, 460, 21, 17));
        MainWindow->setCentralWidget(centralWidget);
        temp_label_2->raise();
        temp_label_3->raise();
        temp_lcdNumber_4->raise();
        temp_label_5->raise();
        temp_lcdNumber_5->raise();
        temp_label_6->raise();
        eminute->raise();
        RA_2->raise();
        ehour->raise();
        esecond->raise();
        signera->raise();
        RA_3->raise();
        cdegsec->raise();
        signedec->raise();
        cdegmin->raise();
        cedeg->raise();
        altd->raise();
        Altitude->raise();
        alts->raise();
        altm->raise();
        UTC->raise();
        lbl_time->raise();
        ad->raise();
        Azimuth->raise();
        Tracking->raise();
        MOUNTSTATUS->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        temp_label->raise();
        Status->raise();
        HomeButton->raise();
        Connection->raise();
        rightbutton->raise();
        leftbutton->raise();
        downbutton->raise();
        upbutton->raise();
        UTC_2->raise();
        ams->raise();
        layoutWidget_2->raise();
        layoutWidget->raise();
        infiniteCountGo->raise();
        infiniteCountNoGo->raise();
        as->raise();
        am->raise();
        MOUNTSTATUS_2->raise();
        MOUNTSTATUS_3->raise();
        MOUNTSTATUS_4->raise();
        temp_lcdNumber_6->raise();
        temp_lcdNumber_7->raise();
        temp_label_7->raise();
        temp_label_8->raise();
        temp_lcdNumber->raise();
        temp_lcdNumber_2->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1017, 20));
        menuBar->setDefaultUp(false);
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        UTC->setText(QApplication::translate("MainWindow", "UTC:", nullptr));
        lbl_time->setText(QApplication::translate("MainWindow", "lbl_time", nullptr));
        ad->setText(QApplication::translate("MainWindow", "d", nullptr));
        Azimuth->setText(QApplication::translate("MainWindow", "Azm", nullptr));
#ifndef QT_NO_TOOLTIP
        Tracking->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ef2929;\">Tracking</span></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        Tracking->setText(QApplication::translate("MainWindow", "Tracking", nullptr));
#ifndef QT_NO_TOOLTIP
        MOUNTSTATUS->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#fce94f;\">MOUNT STATUS</span></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        MOUNTSTATUS->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#8f5902;\">Mount Status</span></p></body></html>", nullptr));
        temp_label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ef2929;\">ENCODER VALUES</span></p></body></html>", nullptr));
        Status->setText(QString());
        HomeButton->setText(QApplication::translate("MainWindow", "Home", nullptr));
        Connection->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#4e9a06;\">Connected</span></p></body></html>", nullptr));
        rightbutton->setText(QApplication::translate("MainWindow", "\342\207\222", nullptr));
        leftbutton->setText(QApplication::translate("MainWindow", "\342\207\220", nullptr));
        downbutton->setText(QApplication::translate("MainWindow", "\342\207\223", nullptr));
        upbutton->setText(QApplication::translate("MainWindow", "\342\207\221", nullptr));
        UTC_2->setText(QApplication::translate("MainWindow", "Airmass", nullptr));
        ams->setText(QApplication::translate("MainWindow", "ams", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "DEC", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "RA", nullptr));
        RA->setText(QApplication::translate("MainWindow", "RA ", nullptr));
        signRA->setText(QApplication::translate("MainWindow", "si", nullptr));
        chour->setText(QApplication::translate("MainWindow", "h", nullptr));
        cminute->setText(QApplication::translate("MainWindow", "m", nullptr));
        csecond->setText(QApplication::translate("MainWindow", "s", nullptr));
        DEC->setText(QApplication::translate("MainWindow", "DEC ", nullptr));
        signDEC->setText(QApplication::translate("MainWindow", "si", nullptr));
        cdeg->setText(QApplication::translate("MainWindow", "d", nullptr));
        camin->setText(QApplication::translate("MainWindow", "m", nullptr));
        casec->setText(QApplication::translate("MainWindow", "s", nullptr));
        infiniteCountGo->setText(QApplication::translate("MainWindow", "Start", nullptr));
        infiniteCountNoGo->setText(QApplication::translate("MainWindow", "Stop", nullptr));
        as->setText(QApplication::translate("MainWindow", "s", nullptr));
        am->setText(QApplication::translate("MainWindow", "m", nullptr));
        altd->setText(QApplication::translate("MainWindow", "d", nullptr));
        Altitude->setText(QApplication::translate("MainWindow", "Alt", nullptr));
        alts->setText(QApplication::translate("MainWindow", "s", nullptr));
        altm->setText(QApplication::translate("MainWindow", "m", nullptr));
#ifndef QT_NO_TOOLTIP
        MOUNTSTATUS_2->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#fce94f;\">MOUNT STATUS</span></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        MOUNTSTATUS_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#8f5902;\">TARGET APPARENT</span></p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        MOUNTSTATUS_3->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#fce94f;\">MOUNT STATUS</span></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        MOUNTSTATUS_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#8f5902;\">Equitorial</span></p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        MOUNTSTATUS_4->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#fce94f;\">MOUNT STATUS</span></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        MOUNTSTATUS_4->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#8f5902;\">J2000</span></p></body></html>", nullptr));
        temp_label_7->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">Alt Target Velocity(&quot;/s)</span></p></body></html>", nullptr));
        temp_label_8->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">Azm Target Velocity(&quot;/s)</span></p></body></html>", nullptr));
        temp_label_5->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">Azm Sidereal Velocity(&quot;/s)</span></p></body></html>", nullptr));
        temp_label_6->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">Alt Sidereal Velocity(&quot;/s)</span></p></body></html>", nullptr));
        eminute->setText(QApplication::translate("MainWindow", "m", nullptr));
        RA_2->setText(QApplication::translate("MainWindow", "HA", nullptr));
        ehour->setText(QApplication::translate("MainWindow", "h", nullptr));
        esecond->setText(QApplication::translate("MainWindow", "s", nullptr));
        signera->setText(QApplication::translate("MainWindow", "si", nullptr));
        RA_3->setText(QApplication::translate("MainWindow", "DEC", nullptr));
        cdegsec->setText(QApplication::translate("MainWindow", "s", nullptr));
        signedec->setText(QApplication::translate("MainWindow", "si", nullptr));
        cdegmin->setText(QApplication::translate("MainWindow", "m", nullptr));
        cedeg->setText(QApplication::translate("MainWindow", "h", nullptr));
        temp_label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ef2929;\">Azm</span></p></body></html>", nullptr));
        temp_label_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ef2929;\">Alt</span></p></body></html>", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
