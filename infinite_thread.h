#ifndef INFINITE_THREAD_H
#define INFINITE_THREAD_H

#include <QObject>
#include <QDialog>
#include <QSerialPort>
#include <QByteArray>

class InfiniteCountWorker : public QObject
{
    Q_OBJECT

    public:
        InfiniteCountWorker(double, double);
        void Coord(double,double);
        void readSerialAzimuthEncoder();
        void sendSerialData(QByteArray);
        void readSerialAzimuthEncoder2();
        void sendSerialData2(QByteArray);


    public slots:
        void doWork();
        void stopWork();
   signals:

        void updateInfiniteCount(double,int,int,int,int,double,double,char,char,int,int,int,int,int,int,char,char,int,int,int,int,int,int,QString,QString);
        void finished();




    private:


        QSerialPort *serial;
        QByteArray serialData;
        QString serialBuffer;
        QString parsed_data;
        QByteArray serialData2;
        QString serialBuffer2;
        QString parsed_data2;
        QString filename;
        QString filename2;
        QString current_time;
        QString current_date;

            bool m_running;
            int azd,azm,altd,altm;
            double asec,altsec;
            double ams,converted_ra,converted_dec;
            char signRA, signDEC;
            int chour,cminute,csecond,cdeg,camin,casec;
            double rr,dd;

            char signha, signde;
            int idmsfdec[4];
            int ihmsfha[4];
};
#endif // INFINITE_THREAD_H
