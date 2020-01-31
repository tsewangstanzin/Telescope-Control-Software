#ifndef INFINITE_THREAD_H
#define INFINITE_THREAD_H

#include <QObject>

class InfiniteCountWorker : public QObject
{
    Q_OBJECT

    public:
        InfiniteCountWorker(double, double);
        void Coord(double,double);

    public slots:
        void doWork();
        void stopWork();
   signals:

        void updateInfiniteCount(double,int,int,int,int,double,double,char,char,int,int,int,int,int,int,char,char,int,int,int,int,int,int);
        void finished();
    private:
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
