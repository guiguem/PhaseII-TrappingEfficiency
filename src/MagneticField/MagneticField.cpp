#include "MagneticField.h"

// ----------------------------------------------------------
// GENERIC FUNCTIONS

double k2(double a, double rho, double chi)
{
    return 4 * a * rho / (TMath::Power(a + rho, 2) + TMath::Power(chi, 2));
}

double mu0()
{
    return 1.2566370614e-6;
}

double EllipticE(double m)
{
    if (m > 1 || m < 0)
    {
        LWARN(magneticfieldlog, "Argument of EllipticK not in [0;1]");
    }
    double result = TMath::Pi() / 2.;
    result += -(TMath::Pi() * m) / 8.;
    result += -(3 * TMath::Pi() * TMath::Power(m, 2)) / 128;
    result += -(5 * TMath::Pi() * TMath::Power(m, 3)) / 512;
    result += -(175 * TMath::Pi() * TMath::Power(m, 4)) / 32768;
    result += -(441 * TMath::Pi() * TMath::Power(m, 5)) / 131072;
    result += -(4851 * TMath::Pi() * TMath::Power(m, 6)) / 2097152;
    return result;
}

double EllipticK(double m)
{
    if (m > 1 || m < -1)
    {
        LWARN(magneticfieldlog, "Argument of EllipticK not in [-1;1]");
    }
    double result = TMath::Pi() / 2.;
    result += +(TMath::Pi() * m) / 8.;
    result += +(9 * TMath::Pi() * TMath::Power(m, 2)) / 128;
    result += +(25 * TMath::Pi() * TMath::Power(m, 3)) / 512;
    result += +(1225 * TMath::Pi() * TMath::Power(m, 4)) / 32768;
    result += +(3969 * TMath::Pi() * TMath::Power(m, 5)) / 131072;
    result += +(53361 * TMath::Pi() * TMath::Power(m, 6)) / 2097152;
    return result;
}

double EllipticPi(double n, double m)
{
    double result = TMath::Pi() / 2. + TMath::Pi() * n / 4 + 3 / 16 * TMath::Pi() * TMath::Power(n, 2);
    result += m * (TMath::Pi() / 8. + 3 / 32 * TMath::Pi() * n + 5 / 64 * TMath::Pi() * TMath::Power(n, 2));
    result += TMath::Power(m, 2) * (TMath::Pi() * 9 / 128. + 15 / 256 * TMath::Pi() * n + 105 / 2048 * TMath::Pi() * TMath::Power(n, 2));
    return result;
}

// ----------------------------------------------------------
// FIELDGENERATOR BASE METHODS

double FieldGenerator::getRadialMagneticField(double x0, double x1, double x2)
{
    LWARN(magneticfieldlog, "Using FieldGenerator::getRadialMagneticField...");
    return 0;
}

double FieldGenerator::getLongMagneticField(double x0, double x1, double x2)
{
    LWARN(magneticfieldlog, "Using FieldGenerator::getLongMagneticField...");
    return 0;
}

double FieldGenerator::getMagneticFieldMag(double x0, double x1, double x2)
{
    double Br = getRadialMagneticField(x0, x1, x2);
    double Bz = getLongMagneticField(x0, x1, x2);
    return TMath::Sqrt(TMath::Power(Br, 2) + TMath::Power(Bz, 2));
}

double FieldGenerator::getMagneticFieldMag(double r, double z)
{
    double Br = getRadialMagneticField(r, 0, z);
    double Bz = getLongMagneticField(r, 0, z);
    return TMath::Sqrt(TMath::Power(Br, 2) + TMath::Power(Bz, 2));
}

double FieldGenerator::getMaxFieldAlongZ(double x, double y, double z, double B0)
{
    LWARN(magneticfieldlog, "Using FieldGenerator::getMaxFieldAlongZ...");
    return 0;
}

// ----------------------------------------------------------
// SOLENOID METHODS

double Solenoid::getRadialMagneticField(double x0, double x1, double x2)
{
    TVector3 tPosition(x0, x1, x2);
    tPosition += solenoidCenter;

    double rho = tPosition.Perp();
    double z = tPosition.Z();

    double chiPlus = z + length / 2.;
    double chiMinus = z - length / 2.;
    double h2 = k2(radius, rho, 0.);

    double k2Plus = k2(radius, rho, chiPlus);
    double k2Minus = k2(radius, rho, chiMinus);

    double tContribPlus = (k2Plus - 2) / TMath::Sqrt(k2Plus) * EllipticK(k2Plus) + 2 / TMath::Sqrt(k2Plus) * EllipticE(k2Plus);
    double tContribMinus = (k2Minus - 2) / TMath::Sqrt(k2Minus) * EllipticK(k2Minus) + 2 / TMath::Sqrt(k2Minus) * EllipticE(k2Minus);

    double B = mu0() * fCurrent * numberTurns / (4 * TMath::Pi() * length) * TMath::Sqrt(radius / rho);
    B *= (tContribPlus - tContribMinus);

    return B;
}

double Solenoid::getLongMagneticField(double x0, double x1, double x2)
{

    TVector3 tPosition(x0, x1, x2);
    tPosition += solenoidCenter;

    double rho = tPosition.Perp();
    double z = tPosition.Z();

    double chiPlus = z + length / 2.;
    double chiMinus = z - length / 2.;
    double h2 = k2(radius, rho, 0.);

    double k2Plus = k2(radius, rho, chiPlus);
    double k2Minus = k2(radius, rho, chiMinus);

    LDEBUG(magneticfieldlog, k2Plus << "\t" << k2Minus);

    double tContribPlus = chiPlus * TMath::Sqrt(k2Plus) * (EllipticK(k2Plus) + (radius - rho) / (radius + rho) * EllipticPi(h2, k2Plus));
    double tContribMinus = chiMinus * TMath::Sqrt(k2Minus) * (EllipticK(k2Minus) + (radius - rho) / (radius + rho) * EllipticPi(h2, k2Minus));

    LDEBUG(magneticfieldlog, tContribPlus << "\t" << tContribMinus);

    double B = -mu0() * fCurrent * numberTurns / (4 * TMath::Pi() * 2 * length) / TMath::Sqrt(radius * rho);
    B *= (tContribPlus - tContribMinus);

    return B;
}

// ----------------------------------------------------------
// COIL METHODS

double Coil::getRadialMagneticField(double x0, double x1, double x2)
{
    TVector3 tPosition(x0, x1, x2);
    tPosition += coilCenter;

    double x = tPosition.X();
    double y = tPosition.Y();
    double rho = tPosition.Perp();
    if (rho == 0)
    {
        return 0;
    }
    double z = tPosition.Z();

    double r = tPosition.Mag();
    double alpha2 = TMath::Power(radius, 2) + TMath::Power(r, 2) - 2 * radius * rho;
    double beta2 = TMath::Power(radius, 2) + TMath::Power(r, 2) + 2 * radius * rho;
    double k2 = 1 - alpha2 / beta2;
    double C = mu0() * numberTurns * fCurrent / TMath::Pi();

    double Bx = C * x * z / (2 * alpha2 * TMath::Sqrt(beta2) * TMath::Power(rho, 2));
    Bx *= (TMath::Power(radius, 2) + TMath::Power(r, 2)) * EllipticE(k2) - alpha2 * EllipticK(k2);
    double By = C * y * z / (2 * alpha2 * TMath::Sqrt(beta2) * TMath::Power(rho, 2));
    By *= (TMath::Power(radius, 2) + TMath::Power(r, 2)) * EllipticE(k2) - alpha2 * EllipticK(k2);

    return x / rho * Bx + y / rho * By;
}

double Coil::getLongMagneticField(double x0, double x1, double x2)
{
    TVector3 tPosition(x0, x1, x2);
    tPosition += coilCenter;

    double x = tPosition.X();
    double y = tPosition.Y();
    double rho = tPosition.Perp();
    double z = tPosition.Z();

    double r = tPosition.Mag();
    double alpha2 = TMath::Power(radius, 2) + TMath::Power(r, 2) - 2 * radius * rho;
    double beta2 = TMath::Power(radius, 2) + TMath::Power(r, 2) + 2 * radius * rho;
    double k2 = 1 - alpha2 / beta2;
    double C = mu0() * numberTurns * fCurrent / TMath::Pi();

    double Bz = C / (2 * alpha2 * TMath::Sqrt(beta2)) * ((TMath::Power(radius, 2) - TMath::Power(r, 2)) * EllipticE(k2) + alpha2 * EllipticK(k2));
    return Bz;
}

double Coil::getLongMagneticFieldOnAxis(double z)
{
    double zCoil = coilCenter.Z();
    return mu0() * numberTurns * fCurrent / 2. * TMath::Power(radius, 2) / TMath::Power(TMath::Power(z - zCoil, 2) + radius * radius, 1.5);
}

// ----------------------------------------------------------
// BATHTUB METHODS

double Bathtub::getRadialMagneticField(double x0, double x1, double x2)
{
    return coil1.getRadialMagneticField(x0, x1, x2) + coil2.getRadialMagneticField(x0, x1, x2);
}

double Bathtub::getLongMagneticField(double x0, double x1, double x2)
{
    return coil1.getLongMagneticField(x0, x1, x2) + coil2.getLongMagneticField(x0, x1, x2);
}

double Bathtub::getLongMagneticFieldOnAxis(double z)
{
    return coil1.getLongMagneticFieldOnAxis(z) + coil2.getLongMagneticFieldOnAxis(z);
}

double Bathtub::getMaxFieldAlongZ(double x, double y, double z, double B0)
{
    //Simple version: Bmax = sqrt((B0+Bz)^2 + Br^2) when z = coilPosition.Z()
    double zCoil1 = coil1Center.Z();
    double zCoil2 = coil2Center.Z();
    if (!(zCoil1 <= z && z <= zCoil2) && !(zCoil2 <= z && z <= zCoil1))
    {
        LDEBUG(magneticfieldlog, "Electron out of trapping region: " << zCoil1 << "\t" << z << "\t" << zCoil2);
        double Br = getRadialMagneticField(x, y, z);
        double Bz = getLongMagneticField(x, y, z);
        return TMath::Sqrt(TMath::Power(Bz + B0, 2) + TMath::Power(Br, 2));
    }
    double Br = getRadialMagneticField(x, y, zCoil1);
    double Bz = getLongMagneticField(x, y, zCoil1);

    return TMath::Sqrt(TMath::Power(Bz + B0, 2) + TMath::Power(Br, 2));
}