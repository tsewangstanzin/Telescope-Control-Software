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


#define R2D 57.29577951308232   /* radians to degrees */
#define R2MAS 206264.806247096355e3 /* radians to mas */

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->temp_lcdNumber->display("-------");
    arduino = new QSerialPort(this);
    serialBuffer = "";
    parsed_data = "";
    currentazimuth_value = 0.0;
    bool arduino_is_available = false;
    QString arduino_uno_port_name;
    //
    //  For each available serial port
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        //  check if the serialport has both a product identifier and a vendor identifier
        if(serialPortInfo.hasProductIdentifier() && serialPortInfo.hasVendorIdentifier()){
            //  check if the product ID and the vendor ID match those of the arduino uno
            if((serialPortInfo.productIdentifier() == arduino_uno_product_id)
                    && (serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id)){
                arduino_is_available = true; //    arduino uno is available on this port
                arduino_uno_port_name = serialPortInfo.portName();
            }
        }
    }
    if(arduino_is_available){
        ui->Connection->setText((" Connected"));
        qDebug() << "Found the arduino port...\n";
        arduino->setPortName(arduino_uno_port_name);
        arduino->open(QSerialPort::ReadWrite);
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        QObject::connect(arduino, SIGNAL(readyRead()), this, SLOT(readSerialAzimuth()));
    }else{
        ui->Connection->setText(("Not Connected"));
        qDebug() << "Couldn't find the correct port for the arduino.\n";
        QMessageBox::information(this, "Serial Port Error", "Couldn't open serial port to arduino.");
    }    // == WINDOW SETTINGS ==



    setWindowTitle("TCS");

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

    ui->Altvalue->setText(QString::number(44));
    ui->Azvalue->setText(QString::number(233));
   // ui->temp_lcdNumber->display(QString::number(233));
    //Coord( 360.6888, 189.356666666);

    timer_refreshrate = new QTimer(this);
    connect(timer_refreshrate, SIGNAL(timeout()), this, SLOT(test()));
    timer_refreshrate->start(1000);

    timer_1s = new QTimer(this);
    QObject::connect(timer_1s, SIGNAL(timeout()), this, SLOT(systtime()));
    timer_1s->start(100);


}
void MainWindow::test()
{

    //ui->ams->setText(QString::number(3));
//printf("\n fadsfdsaf");
a++;
 //ui->ams->setText( QString("%1").arg(a) );
}

MainWindow::~MainWindow()
{   if(arduino->isOpen()){
        arduino->close(); //    Close the serial port if it's open.
    }
    delete ui;
}


void MainWindow::updateAzimuthvalue(QString sensor_reading)
{
    int j =sensor_reading.toInt();
   //qDebug() << "fffffffffffffffff " << temp<< "\n";

     //parsed_data = QString::number(currentazimuth_value, 'g', 4); //

      // QString::number(da*R2D)
    //  update the value displayed on the lcdNumber
    ui->temp_lcdNumber->display(sensor_reading);
    if(j==360 || j==359 || j==358)
     {
       ui->Status->setText("Homing Done");
   }
    //else if(j==temp || j==temp+1 || j==temp-1)
     //{
       //ui->Status->setText("Slew Done");
   //}


}

void MainWindow::systtime()
{
    ui->lbl_time->setText(QTime::currentTime().toString("hh:mm:ss"));

}


void MainWindow::Coord(double Gorc, double Godc)
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
    rc = (Gorc*15)/R2D;                  /*RA (ICRS, radians) , Gorc taken as user input , R2D used for degree conversion to radian*/
    dc = Godc/R2D;                  /*Dec (ICRS, radians) , Godc taken as user input*/
    printf("\n %.10f", rc);
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

    printf("\n LOng %.10f",elong);
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


    double d = slaAirmas(zob);
    ui->ams->setText(QString::number(d));

      double lst = slaGmst(date );
      printf("\n LST %.5f",lst);

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
    slaMap ( rc, dc, pr, pd, px, rv, 2000.0, date, &ra1, &da1 );
    slaAop ( ra1, da1, date, dut, elong, phi, hm, xp, yp,
    tk, pmb, rh, wl, tlr, &aob1, &zob1, &hob, &dob, &rob );
    slaPolmo ( elong, phi, xp, yp, &elong1, &phi1, &daz );
    aob1 += daz;
    printf ( "new         old          diff\n\n "


             "ICRS RA %+15.9f\n", slaDranrm(rc)*R2D );
    printf ( "Dec %+15.9f\n\n", dc*R2D );

    printf ( "CIRS RA %+15.9f\n", slaDranrm(ri)*R2D );
    printf ( "Dec %+15.9f\n\n", di*R2D );


    printf ( "appt RA %+15.9f", slaDranrm(ra)*R2D );
     printf ( "%+16.9f", slaDranrm(ra1)*R2D );
     printf ( "%+9.3f\n", slaDrange(ra1-ra)*R2MAS );
    printf ( "Dec %+15.9f", da*R2D );
     printf ( "%+16.9f", da1*R2D );
     printf ( "%+9.3f\n\n", (da1-da)*R2MAS );


    printf ( "obs Az %+15.9f", slaDranrm(aob)*R2D );
      printf ( "%+16.9f", slaDranrm(aob1)*R2D );
      printf ( "%+9.3f\n", slaDrange(aob1-aob)*R2MAS );
    printf ( "Alt %+15.9f", 90.0-zob*R2D );
      printf ( "%+16.9f", 90.0-zob1*R2D );
      printf ( "%+9.3f\n\n", (zob-zob1)*R2MAS );


    //printf ( "deg          deg            mas\n");
     ui->Altvalue->setText(QString::number(90.0-zob*R2D));
     ui->Azvalue->setText(QString::number(slaDranrm(aob)*R2D));
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

     ui->signRA->setText(QString(sign1));
     ui->chour->setText(QString::number(ihmsf[0]));
     ui->cminute->setText(QString::number(ihmsf[1]));
     ui->csecond->setText(QString::number(ihmsf[2]));

     ui->signDEC->setText(QString(sign2));
     ui->cdeg->setText(QString::number( idmsf[0]));
     ui->camin->setText(QString::number(idmsf[1]));
     ui->casec->setText(QString::number(idmsf[2]));

     pointingCorrection(slaDranrm(aob)*R2D, 90.0-zob*R2D);
    // Coord(converted_ra,converted_dec);
    // temp=slaDranrm(aob)*R2D;
     sendSerialAzimuth((slaDranrm(aob)*R2D));
   // ui->Azvalue_lcd->display(QString::number(slaDranrm(rc)*R2D ));

}
void MainWindow::pointingCorrection(double A, double E)
{
    double delA, delE, AOFF= 38.86, BNP= -90.1+8.3, NPAE= 11.2+7.0, AN=-9.2+0.95,AE=10.6,EOFF= 71.56+0.39,TF=-27.88+2.2,AN2=6.28+0.49,AE2=19.28-0.51;
    delA=AOFF-AN*sin(A)*tan(E)-AE*cos(A)*tan(E)-NPAE*tan(E)+BNP*(1/cos(E));
    delE=EOFF-AN2*cos(A)*tan(E)-AE2*sin(A)+TF*cos(E);

    printf("Az. off  %f \n", delA);
    printf("E. off   %f \n", delE);


}

void MainWindow::on_GoButton_clicked()
{ //ui->temp_lcdNumber->display(QString::number(111));
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
double R=((h+(m/60)+(s/3600)));
double D= (de + (am/60) + (as/3600));
Coord(R,D);

}
void MainWindow::on_HomeButton_clicked()
{
 //ui->temp_lcdNumber->display(QString::number(333));
//QString home_value=233;
ui->Status->setText(("Homing"));

double home_value=360;
sendSerialAzimuth(home_value);

}


void MainWindow::sendSerialAzimuth(double data)
{   /* double target=data;

     qDebug() << "tttttttttt: " <<target<< "\n";
    double array[] = {target};
    double array_elements = sizeof(array) / sizeof(double);


    for(int n = 0; n < array_elements; n++)
            {//arduino->write((char*)(array + n * sizeof(int)), sizeof(int));
            //
        arduino->write((char*)(array + n * sizeof(int)), sizeof(int));
        qDebug() << "Eeeeeeeeeeffffff: " <<array[n]<< "\n";
    }*/
    //char *buf; //creation of a buffer
      //*buf = 360;

      //for messages longer than 1 character :
      /*
      char *buf[255]; //buffer size = 255char;
      sprintf(buf,"%c",value);
      */
    // qDebug() << "Eeeeeeeeeeffffff: " <<buf<< "\n";
     // arduino->write(buf); //send the buffer
//

  // arduino->flush();



    /*QByteArray setOut;
        setOut.resize(11);
        setOut[0] = 360;            //Start $
        setOut[1] = 0x44;           //Digital
        setOut[2] = 0x57;           //Write
        setOut[3] = '!';               //DATA START
        setOut[4] = db0;            //S
        setOut[5] = state;          //H
        setOut[6] = db1;            //P
        setOut[7] = pin;            //CR for pin 13
        setOut[8] = 0x43;           //C
        setOut[9] = 0x43;           //C
        setOut[10] = '#';           //End #

        serial->write(setOut);  //Send string over to arduino*/

    // double target=QString::number(100);
   // QString m_allData = data;
    //int i = 0;
    //int size = m_allData.size();

    //parsed_data = QString::number(currentazimuth_value, 'g', 4);
   /*QByteArray bbl;
    bbl.resize(1);
    bbl[0]=target;
    qDebug() << "Eeeeeeeeeeffffff: " <<bbl<< "\n";
    arduino->write(bbl);*/
    double target=data;

    QByteArray buffer = QByteArray::number(target) ;
     qDebug() << "Eeeeeeeeeeffffff: " <<buffer<< "\n";

     arduino->write(buffer);

   // arduino->write(data.toUtf8(), 24);
     arduino->flush();


    /*QString line = "";
    int c = 0;
    while(i < size){
        line.append(m_allData[i]);
        if(c == 24){
            int sended = arduino->write("HOME", 3);
            arduino->flush();
            line.clear();
            c = 0;
        }
        i++;
        c++;
    }*/
   // if(c > 0){
     //   arduino->write(line.toUtf8(), c);
    //}
    //arduino->flush();
}

void MainWindow::readSerialAzimuth()
{


        /*int c = 0;
        char * dataBuffer;
        int size = arduino->bytesAvailable();
        //dataBuffer = new char[size];
        //c = arduino->read(dataBuffer, size);
        dataBuffer = new char[size + 1];            // + 1 byte for '\0'
        c = arduino->read(dataBuffer, size);
        qDebug() << "Eeeeeeeeee: " << size<< "\n";
        parsed_data = QString::fromUtf8(dataBuffer);
        qDebug() << "Eeeeeeeeee: " <<parsed_data<< "\n"; // format precision of currentazimuth_value to 4 digits or fewer
         MainWindow::updateAzimuthvalue(parsed_data);
        //m_receiveEdit->setText(m_receiveEdit->toPlainText() + QString::fromUtf8(dataBuffer));
           // delete dataBuffer;
        dataBuffer[c] = '\0';                       // terminate the string
*/
 QStringList buffer_split = serialBuffer.split(","); //  split the serialBuffer string, parsing with ',' as the separator

    //  Check to see if there less than 3 tokens in buffer_split.
    //  If there are at least 3 then this means there were 2 commas,
    //  means there is a parsed temperature value as the second token (between 2 commas)
    if(buffer_split.length() < 3 ){
        // no parsed value yet so continue accumulating bytes from serial in the buffer.
        serialData = arduino->readAll();
        serialBuffer = serialBuffer + QString::fromStdString(serialData.toStdString());
        serialData.clear();
    }else{
        // the second element of buffer_split is parsed correctly, update the temperature value on temp_lcdNumber
        serialBuffer = "";
        qDebug() << buffer_split << "\n";
        parsed_data = buffer_split[1];
        //currentazimuth_value = (9/5.0) * (parsed_data.toDouble()) + 32; // convert to fahrenheit
        currentazimuth_value =parsed_data.toDouble()+2;
        qDebug() << "Encoder Value: " << parsed_data << "\n";
        parsed_data = QString::number(currentazimuth_value, 'g', 4); // format precision of currentazimuth_value to 4 digits or fewer
         MainWindow::updateAzimuthvalue(parsed_data);


        //}
    }

}




