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
    QLabel *Altvalue;
    QLabel *Azvalue;
    QLabel *Altitute;
    QLabel *Azimuth;
    QCheckBox *Tracking;
    QLabel *MOUNTSTATUS;
    QLabel *temp_label;
    QLabel *Status;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *temp_label_2;
    QLCDNumber *temp_lcdNumber;
    QPushButton *GoButton;
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
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *hour;
    QLineEdit *minute;
    QLineEdit *second;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *RA;
    QLabel *signRA;
    QLabel *chour;
    QLabel *cminute;
    QLabel *csecond;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_5;
    QLabel *DEC;
    QLabel *signDEC;
    QLabel *cdeg;
    QLabel *camin;
    QLabel *casec;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(683, 467);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        UTC = new QLabel(centralWidget);
        UTC->setObjectName(QString::fromUtf8("UTC"));
        UTC->setGeometry(QRect(470, 10, 121, 16));
        lbl_time = new QLabel(centralWidget);
        lbl_time->setObjectName(QString::fromUtf8("lbl_time"));
        lbl_time->setGeometry(QRect(570, 10, 70, 17));
        Altvalue = new QLabel(centralWidget);
        Altvalue->setObjectName(QString::fromUtf8("Altvalue"));
        Altvalue->setGeometry(QRect(570, 120, 70, 17));
        Azvalue = new QLabel(centralWidget);
        Azvalue->setObjectName(QString::fromUtf8("Azvalue"));
        Azvalue->setGeometry(QRect(570, 100, 70, 17));
        Altitute = new QLabel(centralWidget);
        Altitute->setObjectName(QString::fromUtf8("Altitute"));
        Altitute->setGeometry(QRect(470, 120, 121, 16));
        Azimuth = new QLabel(centralWidget);
        Azimuth->setObjectName(QString::fromUtf8("Azimuth"));
        Azimuth->setGeometry(QRect(470, 100, 121, 16));
        Tracking = new QCheckBox(centralWidget);
        Tracking->setObjectName(QString::fromUtf8("Tracking"));
        Tracking->setGeometry(QRect(40, 40, 94, 23));
        MOUNTSTATUS = new QLabel(centralWidget);
        MOUNTSTATUS->setObjectName(QString::fromUtf8("MOUNTSTATUS"));
        MOUNTSTATUS->setGeometry(QRect(470, 70, 121, 20));
        temp_label = new QLabel(centralWidget);
        temp_label->setObjectName(QString::fromUtf8("temp_label"));
        temp_label->setGeometry(QRect(470, 260, 142, 23));
        Status = new QLabel(centralWidget);
        Status->setObjectName(QString::fromUtf8("Status"));
        Status->setGeometry(QRect(90, 360, 161, 17));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(470, 290, 151, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        temp_label_2 = new QLabel(layoutWidget);
        temp_label_2->setObjectName(QString::fromUtf8("temp_label_2"));

        horizontalLayout->addWidget(temp_label_2);

        temp_lcdNumber = new QLCDNumber(layoutWidget);
        temp_lcdNumber->setObjectName(QString::fromUtf8("temp_lcdNumber"));
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
        QBrush brush4(QColor(60, 60, 60, 128));
        brush4.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        QBrush brush5(QColor(60, 60, 60, 128));
        brush5.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QBrush brush6(QColor(60, 60, 60, 128));
        brush6.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
        temp_lcdNumber->setPalette(palette);
        temp_lcdNumber->setDigitCount(7);

        horizontalLayout->addWidget(temp_lcdNumber);

        GoButton = new QPushButton(centralWidget);
        GoButton->setObjectName(QString::fromUtf8("GoButton"));
        GoButton->setGeometry(QRect(100, 170, 91, 25));
        HomeButton = new QPushButton(centralWidget);
        HomeButton->setObjectName(QString::fromUtf8("HomeButton"));
        HomeButton->setGeometry(QRect(100, 200, 91, 25));
        Connection = new QLabel(centralWidget);
        Connection->setObjectName(QString::fromUtf8("Connection"));
        Connection->setGeometry(QRect(40, 10, 142, 23));
        rightbutton = new QPushButton(centralWidget);
        rightbutton->setObjectName(QString::fromUtf8("rightbutton"));
        rightbutton->setGeometry(QRect(150, 280, 31, 25));
        leftbutton = new QPushButton(centralWidget);
        leftbutton->setObjectName(QString::fromUtf8("leftbutton"));
        leftbutton->setGeometry(QRect(90, 280, 31, 25));
        downbutton = new QPushButton(centralWidget);
        downbutton->setObjectName(QString::fromUtf8("downbutton"));
        downbutton->setGeometry(QRect(120, 310, 31, 25));
        upbutton = new QPushButton(centralWidget);
        upbutton->setObjectName(QString::fromUtf8("upbutton"));
        upbutton->setGeometry(QRect(120, 250, 31, 25));
        UTC_2 = new QLabel(centralWidget);
        UTC_2->setObjectName(QString::fromUtf8("UTC_2"));
        UTC_2->setGeometry(QRect(470, 30, 121, 16));
        ams = new QLabel(centralWidget);
        ams->setObjectName(QString::fromUtf8("ams"));
        ams->setGeometry(QRect(570, 30, 70, 17));
        layoutWidget_2 = new QWidget(centralWidget);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(90, 130, 214, 31));
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

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(91, 90, 207, 31));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        hour = new QLineEdit(layoutWidget1);
        hour->setObjectName(QString::fromUtf8("hour"));

        horizontalLayout_2->addWidget(hour);

        minute = new QLineEdit(layoutWidget1);
        minute->setObjectName(QString::fromUtf8("minute"));

        horizontalLayout_2->addWidget(minute);

        second = new QLineEdit(layoutWidget1);
        second->setObjectName(QString::fromUtf8("second"));

        horizontalLayout_2->addWidget(second);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(470, 170, 171, 31));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        RA = new QLabel(layoutWidget2);
        RA->setObjectName(QString::fromUtf8("RA"));

        horizontalLayout_3->addWidget(RA);

        signRA = new QLabel(layoutWidget2);
        signRA->setObjectName(QString::fromUtf8("signRA"));

        horizontalLayout_3->addWidget(signRA);

        chour = new QLabel(layoutWidget2);
        chour->setObjectName(QString::fromUtf8("chour"));

        horizontalLayout_3->addWidget(chour);

        cminute = new QLabel(layoutWidget2);
        cminute->setObjectName(QString::fromUtf8("cminute"));

        horizontalLayout_3->addWidget(cminute);

        csecond = new QLabel(layoutWidget2);
        csecond->setObjectName(QString::fromUtf8("csecond"));

        horizontalLayout_3->addWidget(csecond);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(470, 200, 171, 31));
        horizontalLayout_5 = new QHBoxLayout(widget);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        DEC = new QLabel(widget);
        DEC->setObjectName(QString::fromUtf8("DEC"));

        horizontalLayout_5->addWidget(DEC);

        signDEC = new QLabel(widget);
        signDEC->setObjectName(QString::fromUtf8("signDEC"));

        horizontalLayout_5->addWidget(signDEC);

        cdeg = new QLabel(widget);
        cdeg->setObjectName(QString::fromUtf8("cdeg"));

        horizontalLayout_5->addWidget(cdeg);

        camin = new QLabel(widget);
        camin->setObjectName(QString::fromUtf8("camin"));

        horizontalLayout_5->addWidget(camin);

        casec = new QLabel(widget);
        casec->setObjectName(QString::fromUtf8("casec"));

        horizontalLayout_5->addWidget(casec);

        MainWindow->setCentralWidget(centralWidget);
        layoutWidget->raise();
        layoutWidget->raise();
        UTC->raise();
        lbl_time->raise();
        Altvalue->raise();
        Azvalue->raise();
        Altitute->raise();
        Azimuth->raise();
        Tracking->raise();
        MOUNTSTATUS->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        temp_label->raise();
        Status->raise();
        GoButton->raise();
        HomeButton->raise();
        Connection->raise();
        rightbutton->raise();
        leftbutton->raise();
        downbutton->raise();
        upbutton->raise();
        UTC_2->raise();
        ams->raise();
        layoutWidget_2->raise();
        signRA->raise();
        layoutWidget->raise();
        signDEC->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 683, 22));
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
        Altvalue->setText(QApplication::translate("MainWindow", "Altvalue", nullptr));
        Azvalue->setText(QApplication::translate("MainWindow", "Azvalue", nullptr));
        Altitute->setText(QApplication::translate("MainWindow", "Altitute", nullptr));
        Azimuth->setText(QApplication::translate("MainWindow", "Azimuth", nullptr));
#ifndef QT_NO_TOOLTIP
        Tracking->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ef2929;\">Tracking</span></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        Tracking->setText(QApplication::translate("MainWindow", "Tracking", nullptr));
#ifndef QT_NO_TOOLTIP
        MOUNTSTATUS->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#fce94f;\">MOUNT STATUS</span></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        MOUNTSTATUS->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#8f5902;\">MOUNT STATUS</span></p></body></html>", nullptr));
        temp_label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ef2929;\">ENCODER </span></p></body></html>", nullptr));
        Status->setText(QString());
        temp_label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ef2929;\">X-axis</span></p></body></html>", nullptr));
        GoButton->setText(QApplication::translate("MainWindow", "Go", nullptr));
        HomeButton->setText(QApplication::translate("MainWindow", "Home", nullptr));
        Connection->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#4e9a06;\">Not Connected</span></p></body></html>", nullptr));
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
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
