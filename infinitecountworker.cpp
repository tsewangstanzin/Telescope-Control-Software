#include <QApplication>

#include "infinitecountworker.h"
#include "portablesleep.h"
#include "slalib.h"
#include "slamac.h"
#define R2D 57.29577951308232   /* radians to degrees */
#define R2MAS 206264.806247096355e3 /* radians to mas */

   static double cra,cdec,arc,aa=11;
       volatile double jk=10;
InfiniteCountWorker::InfiniteCountWorker()
    : m_running(true)
{
}

void InfiniteCountWorker::doWork()
{




    int i =jk;

    //doWork();
    while (m_running) {
        Coord(230,190);


        emit updateCount(jk);
        qApp->processEvents();
        PortableSleep::msleep(100);
    }
    emit finished();
}

void InfiniteCountWorker::stopWork()
{
    m_running = false;
}

void InfiniteCountWorker::Coord(double Gorc, double Godc)
{

    jk++;
     Gorc=cra++;
     Godc=cdec++;
    time_t T= time(NULL);
    struct  tm tm = *localtime(&T);
    double djm;
    int j;

    //jk=   ( (tm.tm_min/double(60)+tm.tm_hour)/double(24)); //Julian Time
    slaCldj(tm.tm_year+1900,tm.tm_mon+1,tm.tm_mday, &djm,&j); //Julian Date

    CIpars ciprms;

    double rc, dc, pr, pd, px, rv, date, xp, yp, dut, dx, dy,
    elong, phi, hm, tk, pmb, rh, wl, tlr, eo,
    ri, di, aob, zob, hob, dob, rob, ra, da,
    ra1, da1, aob1, zob1, elong1, phi1, daz ,zd;
    /* Date (UTC, but also used as approximate TDB). */
    // date = djm+jt;   /* 2005 July 18 09:36, as an MJD */

    /* A star (phi Peg). */
    rc = (Gorc*15)/R2D;                  /*RA (ICRS, radians) , Gorc taken as user input , R2D used for degree conversion to radian*/
    dc = Godc/R2D;                  /*Dec (ICRS, radians) , Godc taken as user input*/
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

    //slaEpv( date, ph, vh, pb, vb );

    /* Compute the ICRS-to-CIRS parameters. */
    slaC2ipa ( date, dx, dy, &ciprms, &eo );
    /* Perform the transformation to CIRS. */
    slaC2iqk ( rc, dc, pr, pd, px, rv, &ciprms, &ri, &di );
    /* Perform the transformation from CIRS to observed direction. */
    slaI2o ( ri, di, date, dut, elong, phi, hm, xp, yp,tk, pmb, rh, wl, tlr, &aob, &zob, &hob, &dob, &rob );


    double d = slaAirmas(zob);
    //ui->ams->setText(QString::number(d));

      double lst = slaGmst(date );


    /* Determine also the equinox-based apparent place. */
    ra = slaDranrm ( ri - eo );
    da = di;
    /* Do the same transformations using the earlier classical functions. */
    slaMap ( rc, dc, pr, pd, px, rv, 2000.0, date, &ra1, &da1 );
    slaAop ( ra1, da1, date, dut, elong, phi, hm, xp, yp,
    tk, pmb, rh, wl, tlr, &aob1, &zob1, &hob, &dob, &rob );
    slaPolmo ( elong, phi, xp, yp, &elong1, &phi1, &daz );
    aob1 += daz;

    // ui->Altvalue->setText(QString::number(90.0-zob*R2D));
    // ui->Azvalue->setText(QString::number(slaDranrm(aob)*R2D));
     // Converted ra and dec

   double converted_ra= slaDranrm(ra);

    double converted_dec=da;
     char sign1, sign2;
     int idmsf[4];
     int ihmsf[4];

     slaDr2tf( 2,converted_ra, &sign1,ihmsf);
     slaDr2af( 2 ,converted_dec, &sign2,idmsf);

   //  double ad= idmsf[3]/10000;
     //printf("fshhhadsfjas       %f \n ", ad);
   // printf("fshhhadsfjas       %f \n ", idmsf[3]);
    // printf("fshhhadsfjas       %f \n ", ihmsf[3]);

     /*ui->signRA->setText(QString(sign1));
     ui->chour->setText(QString::number(ihmsf[0]));
     ui->cminute->setText(QString::number(ihmsf[1]));
     ui->csecond->setText(QString::number(ihmsf[2]));

     ui->signDEC->setText(QString(sign2));
     ui->cdeg->setText(QString::number( idmsf[0]));
     ui->camin->setText(QString::number(idmsf[1]));
     ui->casec->setText(QString::number(idmsf[2]));
*/
   // ui->Azvalue_lcd->display(QString::number(slaDranrm(rc)*R2D ));
     //converted_ra=1000;



    //arc=jt;



}




