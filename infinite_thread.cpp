#include <QApplication>

#include "infinite_thread.h"
#include "portablesleep.h"
#include "slalib.h"
#include "slamac.h"
#include<string.h>
#include<iostream>
#include <QDebug>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QFile>
#include <QDateTime>


#define R2D 57.29577951308232   /* radians to degrees */
#define R2MAS 206264.806247096355e3 /* radians to mas */

using namespace std;

InfiniteCountWorker::InfiniteCountWorker(double Gora, double Godec)
    :m_running(true)

{
    current_time= QTime::currentTime().toString("hhmmss");
    current_date= QDate::currentDate().toString();
    filename=current_time+current_date+"DECLogging";
    filename2=current_time+current_date+"RALogging";




    rr=Gora;
    dd=Godec;
    serial = new QSerialPort(this);
        serialBuffer = "";
        parsed_data = "";
        bool usb_is_available = false;
           QString usb_port_name;
           //
           //  For each available serial port



           foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
               //  check if the serialport has both a product identifier and a vendor identifier
               if(serialPortInfo.serialNumber()=="WWW66476") {
                   //  check if the product ID and the vendor ID match those of the arduino uno
                  // if((serialPortInfo.productIdentifier() == '846e')
                    //       && (serialPortInfo.vendorIdentifier() == '10c4')){
                        usb_is_available = true; //    arduino uno is available on this port
                        usb_port_name = serialPortInfo.portName();
                   }
               }

          if(usb_is_available)
          {
        serial->setPortName("/dev/ttyUSB0");
        serial->open(QIODevice::ReadWrite);
           serial->setBaudRate(QSerialPort::Baud115200);
           serial->setDataBits(QSerialPort::Data8);
           serial->setParity(QSerialPort::NoParity);
           serial->setStopBits(QSerialPort::OneStop);
           serial->setFlowControl(QSerialPort::NoFlowControl);
            while(!serial->isOpen()) serial->open(QIODevice::ReadWrite);

           if (serial->isOpen() && serial->isWritable())
           {
             //ui->Connection->setText((" Controller Connected"));
               //printf("COnnected");
               //qDebug() << "Found the device.\n";

               //QMessageBox::information("Serial Port Error", "Couldn't open serial port to arduino.");

           }

          }
           else{ QMessageBox msgBox;
              msgBox.setText("The document has been modified.");
                       //ui->Connection->setText(("Not Connected"));
                        //qDebug() << "Couldn't find the correct port\n";

                   }    // == WINDOW SETTINGS ==


}

void InfiniteCountWorker::doWork()
{

    while(m_running){

        Coord(rr,dd);

        sendSerialData("$0R2\r");
        sendSerialData2("$0R1\r");


        emit updateInfiniteCount(ams,azd,azm,altd,altm,asec,altsec,signRA,signDEC,chour,cminute,csecond,cdeg,camin,casec, signha, signde, ihmsfha[0],ihmsfha[1],ihmsfha[2],idmsfdec[0],idmsfdec[1],idmsfdec[2],parsed_data,parsed_data2);

        qApp->processEvents();
        PortableSleep::msleep(10);
     }

    emit finished();

}
void InfiniteCountWorker::stopWork()
{
    m_running = false;
}
void InfiniteCountWorker::Coord(double Gora, double Godec)
{
    time_t T= time(NULL);
    struct  tm tm = *localtime(&T);
    double djm;
    int j;
    double jt;
    jt=   ( (tm.tm_min/double(60)+tm.tm_hour)/double(24)); //Julian Time
    slaCldj(tm.tm_year+1900,tm.tm_mon+1,tm.tm_mday, &djm,&j); //Julian Date
    CIpars ciprms;
    double rc, dc, pr, pd, px, rv, date, xp, yp, dut, dx, dy,
    elong, phi, hm, tk, pmb, rh, wl, tlr, eo,
    ri, di, aob, zob, hob, dob, rob, ra, da,
    ra1, da1, aob1, zob1, elong1, phi1, daz ,zd;
    /* Date (UTC, but also used as approximate TDB). */
     date = djm+jt;   /* 2005 July 18 09:36, as an MJD */
     //double eq, amprms[21];
     //eq=2000;
     //slaMappa(eq,date, amprms);
     //printf("\n MAPPPPPPPAaaaaa %.30f", amprms[1]);
    /*User input conversion to degree*/
    /* A star (phi Peg). */
    rc = (Gora*15)/R2D;                  /*RA (ICRS, radians) , Gorc taken as user input , R2D used for degree conversion to radian*/
    dc = Godec/R2D;                  /*Dec (ICRS, radians) , Godc taken as user input*/
    pr = -7.27/cos(dc)/R2MAS;       /* RA proper motion (radians/year) */
    pd = -35.40/R2MAS;              /* Dec proper motion (radians/year) */
    px = 0.00705;                   /*parallax (arcsec) */
    rv = -14.1;                     /*radial velocity (km/s) */

    /* Earth orientation parameters/EOP data (from IERS Bulletin B). */
    //  Values Added from: https://datacenter.iers.org/data/latestVersion/207_BULLETIN_B207.txt
    //  165.338  280.270 -159.1866    0.070  0.221
    //  xp(mas)  yp(mas) UT1-UTC(ms)  dx    dy
    xp = 165.338/R2MAS;
    /* polar motion x (radians) */
    yp = 280.270/R2MAS;
    /* polar motion y (radians) */
    dut = -0.15918;
    /* UT1-UTC (s) */
    dx = 0.070/R2MAS;
    /* nutation adjustment dX */
    dy = 0.221/R2MAS;
    /* nutation adjustment dY */

    /* Local circumstances (IAO hanle). */
    // Hanle Long. 78.95917   or 1.37 radain   Lat.   32.77953 or 0.57184

    elong = 78.95917/R2D;

    /* east longitude (radians) */

    phi = 32.77953/R2D;
    /* latitude (radians) */
    hm = 4500;
    /* height a.s.l. (m) */
    tk = 278;
    /* temperature (K) */
    pmb = 253.15;
    /* pressure (hPa) */
    rh = 0.09;
    /* relative humidity (0-1) */
    wl = 1.2;
    /* observing wavelength (microns) */
    tlr = 0.0065;
    /* lapse rate (K/m) */



    /* Aberration correction */
    //slaGeoc( p, h, &r, &z );
    //slaEvp( date, deqx, dvb, dpb, dvh, dph );
    //slaEpv( date, ph, vh, pb, vb );

    /* Compute the ICRS-to-CIRS parameters. */
    slaC2ipa ( date, dx, dy, &ciprms, &eo );
    /* Perform the transformation to CIRS. */
    slaC2iqk ( rc, dc, pr, pd, px, rv, &ciprms, &ri, &di );
    /* Perform the transformation from CIRS to observed direction. */
    slaI2o ( ri, di, date, dut, elong, phi, hm, xp, yp,tk, pmb, rh, wl, tlr, &aob, &zob, &hob, &dob, &rob );
    ams = slaAirmas(zob);
    // ui->ams->setText(QString::number(d));

    //Transformation from Universal Time to sidereal time, IAU 1982
    //d = slaGmsta( date, ut1 );
    //Transformation from Universal Time to sidereal time, IAU 1982, rounding errors mini-
    //mized
    //d = slaGst( date, utdate, ut1 );
    //Greenwich apparent sidereal time, IAU 2006

    /* Determine also the equinox-based apparent place. */
    ra = slaDranrm ( ri - eo );
    da = di;
    /* Do the same transformations using the earlier classical functions. */
    //slaMap ( rc, dc, pr, pd, px, rv, 2000.0, date, &ra1, &da1 );
    // slaAop ( ra1, da1, date, dut, elong, phi, hm, xp, yp,
    //tk, pmb, rh, wl, tlr, &aob1, &zob1, &hob, &dob, &rob );
    slaPolmo ( elong, phi, xp, yp, &elong1, &phi1, &daz );
    aob1 += daz;


     // Converted ra and dec
     double altvalue=(90.0-zob*R2D);
     double azvalue=(slaDranrm(aob)*R2D);


     //Horizon to equatorial coordinates (double precision)
     //slaDh2e( azvalue, altvalue, phi, &hourangle, &equi_dec);

     slaDr2tf( 2,hob, &signha,ihmsfha);
     slaDr2af( 2 ,da, &signde,idmsfdec);




       //string dmg;
       //dmg=DegreesMinutesSeconds(azvalue) ;
       //cout<< "\n"<< dmg<<"\n";
       bool neg(false) ;
       if (azvalue < 0.0)
       {
         neg = true ;
         azvalue = -azvalue ;
       }
       int deg = (int)azvalue ;
       double frac = azvalue - (double)deg ;
       frac *= 60.0 ;
       int min = (int)frac ;
       frac = frac - (double)min ;
       // fix the DDD MM 60 case
       // TODO: nearbyint isn’t alway available (Visual C++,
       //       for example)
       double sec = nearbyint(frac * 600000.0) ;
       sec /= 10000.0 ;
       if (sec >= 60.0)
       {
         min++ ;
         sec -= 60.0 ;
       }

       if (neg)
       {
         deg=-deg;
       }

       azd = deg;
       azm = min;
       asec = sec;




      //string dmg2;
      //dmg2=DegreesMinutesSeconds(altvalue) ;
     //cout<< "\n"<< dmg2<<"\n";
     bool neg2(false) ;
     if (altvalue < 0.0)
     {
       neg2 = true ;
       altvalue = -altvalue ;
     }
     int deg2 = (int)altvalue ;
     double frac2 = altvalue - (double)deg2 ;
     frac2 *= 60.0 ;
     int min2 = (int)frac2 ;
     frac2 = frac2 - (double)min2 ;
     // fix the DDD MM 60 case
     // TODO: nearbyint isn’t alway available (Visual C++,
     //       for example)
     double sec2 = nearbyint(frac2 * 600000.0) ;
     sec2 /= 10000.0 ;
     if (sec2 >= 60.0)
     {
       min2++ ;
       sec2 -= 60.0 ;
     }

     if (neg2)
     {
       deg2=-deg2;
     }

    altd = deg2;
     altm = min2;
     altsec= sec2;


     char sign1, sign2;
     int idmsf[4];
     int ihmsf[4];

     converted_ra= slaDranrm(ra);
     converted_dec=da;
     slaDr2tf( 2,converted_ra, &sign1,ihmsf);
     slaDr2af( 2 ,converted_dec, &sign2,idmsf);

     signRA=sign1;
     signDEC=sign2;
     chour=ihmsf[0];
     cminute=ihmsf[1];
     csecond=ihmsf[2];
     cdeg=idmsf[0];
     camin=idmsf[1];
     casec=idmsf[2];
      /*printf("\nRA from main %f",Gora);
       printf("\nDEC from main %f",Godec);
       printf("\nApparent RA %f",(converted_ra*R2D/15));
       printf("\nApparent DA %f",(converted_dec*R2D));*/
    rr=Gora;
    dd=Godec;
      // rr=converted_ra*R2D/15;
       //dd=converted_dec*R2D;
       //pointingCorrection(slaDranrm(aob)*R2D, 90.0-zob*R2D);

    double  az,azd,azdd,el,eld,eldd,pa,pad,padd;
    slaAltaz(hob, da, phi,&az, &azd, &azdd, &el, &eld, &eldd, &pa, &pad, &padd);


    //printf("\n azz  %f",azd);
    //printf("\n elll %f",eld);
    //printf("\n paral angle %f",pad);
}


void InfiniteCountWorker::sendSerialData(QByteArray data)
{
    //double target=data;
    serial->waitForBytesWritten(100);

    QByteArray buffer = data;
    //printf(data);

    serial->write(buffer);

   // arduino->write(data.toUtf8(), 24);
     serial->flush();


     readSerialAzimuthEncoder();

}

void InfiniteCountWorker::readSerialAzimuthEncoder()
{
    serial->waitForReadyRead(100);
    //const QByteArray input = serial->readAll();
     parsed_data= serial->readAll();
    //input = serial.readAll();
     QFile file(filename);
           if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
           {
               // We're going to streaming text to the file
               QTextStream stream(&file);

               stream<< current_time<<"\t"<<parsed_data[4]<< parsed_data[5]<< parsed_data[6]<< parsed_data[7]<< parsed_data[8]<< parsed_data[9]<< parsed_data[10]<< parsed_data[11]<<'\n';

               file.close();
               //qDebug() << "Writing finished";
           }


    //qDebug()<<parsed_data;

}


void InfiniteCountWorker::sendSerialData2(QByteArray data2)
{
    //double target=data;
    serial->waitForBytesWritten(100);

    QByteArray buffer2 = data2;
    //printf(data);

    serial->write(buffer2);

   // arduino->write(data.toUtf8(), 24);
     serial->flush();

     readSerialAzimuthEncoder2();

}

void InfiniteCountWorker::readSerialAzimuthEncoder2()
{
    serial->waitForReadyRead(100);
    //const QByteArray input = serial->readAll();
    parsed_data2= serial->readAll();



    QFile file(filename2);

    //QFile file("/home/tsewang/encoder2-data-log.txt");

          if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
          {
              // We're going to streaming text to the file
              QTextStream stream(&file);

              stream<< current_time<<"\t"<<parsed_data2[4]<< parsed_data2[5]<< parsed_data2[6]<< parsed_data2[7]<< parsed_data2[8]<< parsed_data2[9]<< parsed_data2[10]<< parsed_data2[11]<<'\n';

              file.close();
              //qDebug() << "Writing finished"<<parsed_data<<"\n";
          }


    //input = serial.readAll();

     //qDebug()<<parsed_data2;
}












