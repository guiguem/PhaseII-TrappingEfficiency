#ifndef MAGNETICFIELD_H_
#define MAGNETICFIELD_H_

#include <iostream>
#include "TVector3.h"
#include "TF2.h"

#include "logger.hh"

LOGGER(magneticfieldlog, "MagneticField");

class FieldGenerator
{
  public:
    FieldGenerator()
    {
        fType = "FieldGenerator";
        fCurrent = 0;
    };

  public:
    virtual double getRadialMagneticField(double, double, double);
    virtual double getLongMagneticField(double, double, double);
    virtual double getMagneticFieldMag(double, double, double);
    virtual double getMagneticFieldMag(double, double);
    virtual double getMaxFieldAlongZ(double, double, double, double);

    virtual bool setCurrent(double I)
    {
        fCurrent = I;
        return true;
    };

    std::string getType() { return fType; }

  protected:
    std::string fType;
    double fCurrent;
};

class Solenoid : public FieldGenerator
{
  public:
    Solenoid(double r, double L, int n, double I, TVector3 position)
    {
        fType = "Solenoid";
        radius = r;
        length = L;
        numberTurns = n;
        fCurrent = I;
        solenoidCenter = position;
    };

  public:
    double getRadialMagneticField(double, double, double);
    double getLongMagneticField(double, double, double);

  private:
    double radius;
    double length;
    int numberTurns;
    TVector3 solenoidCenter;
};

class Coil : public FieldGenerator
{
  public:
    Coil(){};
    Coil(double r, int n, double I, TVector3 position)
    {
        fType = "Coil";
        radius = r;
        numberTurns = n;
        fCurrent = I;
        coilCenter = position;
    };

  public:
    double getRadialMagneticField(double, double, double);
    double getLongMagneticField(double, double, double);
    double getLongMagneticFieldOnAxis(double);

  private:
    double radius;
    int numberTurns;
    // double current;
    TVector3 coilCenter;
};

class Bathtub : public FieldGenerator
{
  public:
    Bathtub(double r, int n, double I, TVector3 position1, TVector3 position2)
    {
        fType = "Bathtub";
        radius = r;
        numberTurns = n;
        fCurrent = I;
        coil1Center = position1;
        coil2Center = position2;
        coil1 = Coil(radius, numberTurns, fCurrent, coil1Center);
        coil2 = Coil(radius, numberTurns, fCurrent, coil2Center);
    };

  public:
    double getRadialMagneticField(double, double, double);
    double getLongMagneticField(double, double, double);
    // double getMagneticFieldMag(double, double, double);
    // double getMagneticFieldMag(double, double);
    double getLongMagneticFieldOnAxis(double);

    virtual double getMaxFieldAlongZ(double, double, double, double);

    TF2 getFieldMagnitudeFunction();

    bool setCurrent(double I)
    {
        fCurrent = I;
        LDEBUG(magneticfieldlog, "Changing current in the coils");
        coil1 = Coil(radius, numberTurns, fCurrent, coil1Center);
        coil2 = Coil(radius, numberTurns, fCurrent, coil2Center);
        return true;
    };

  private:
    double radius;
    int numberTurns;
    // double current;
    TVector3 coil1Center;
    TVector3 coil2Center;
    Coil coil1;
    Coil coil2;
};

#endif