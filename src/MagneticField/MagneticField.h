#ifndef SOLENOID_H_
#define SOLENOID_H_

#include <iostream>
#include "TVector3.h"

#include "logger.hh"

LOGGER(magneticfieldlog, "MagneticField");

class Solenoid
{
  public:
    Solenoid(double r, double L, int n, double I, TVector3 position)
    {
        radius = r;
        length = L;
        numberTurns = n;
        current = I;
        solenoidCenter = position;
    };

  public:
    double getRadialMagneticField(double, double, double);
    double getLongMagneticField(double, double, double);

  private:
    double radius;
    double length;
    int numberTurns;
    double current;
    TVector3 solenoidCenter;
};

class Coil
{
  public:
    Coil(){};
    Coil(double r, int n, double I, TVector3 position)
    {
        radius = r;
        numberTurns = n;
        current = I;
        coilCenter = position;
    };

  public:
    double getRadialMagneticField(double, double, double);
    double getLongMagneticField(double, double, double);
    double getLongMagneticFieldOnAxis(double);

  private:
    double radius;
    int numberTurns;
    double current;
    TVector3 coilCenter;
};

class Bathtub
{
  public:
    Bathtub(double r, int n, double I, TVector3 position1, TVector3 position2)
    {
        radius = r;
        numberTurns = n;
        current = I;
        coil1Center = position1;
        coil2Center = position2;
        coil1 = Coil(radius, numberTurns, current, coil1Center);
        coil2 = Coil(radius, numberTurns, current, coil2Center);
    };

  public:
    double getRadialMagneticField(double, double, double);
    double getLongMagneticField(double, double, double);
    double getLongMagneticFieldOnAxis(double);

  private:
    double radius;
    int numberTurns;
    double current;
    TVector3 coil1Center;
    TVector3 coil2Center;
    Coil coil1;
    Coil coil2;
};

#endif