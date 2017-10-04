#include "TF2.h"

#include "Constant.cpp"
#include "MagneticField.h"

double getCosThetaMin(double r, double z, double B0, double Br, double Bz, double Bmax)
{
    double Bztot = B0 + Bz;
    double Brtot = Br;
    // LDEBUG(magneticfieldlog, Bztot << "\t" << Bz << "\t" << Brtot);
    // double Bztot = B0 + generatorObject.getLongMagneticField(r, 0, z);
    // double Brtot = generatorObject.getRadialMagneticField(r, 0, z);
    double Btot = TMath::Sqrt(TMath::Power(Brtot, 2) + TMath::Power(Bztot, 2));
    // double Bmax = TMath::Max(B0, Btot);
    double cosTheta = TMath::Sqrt(1. - Btot / Bmax);
    // LDEBUG(magneticfieldlog, 1. - Btot / Bmax << "\t" << Btot << "\t" << Bmax);

    return cosTheta;
}

double getCosThetaMax(double r, double z, double B0, double Br, double Bz, double E, double waveguideRadius)
{
    double B = TMath::Sqrt(TMath::Power(B0 + Bz, 2) + TMath::Power(Br, 2));
    double gamma = 1 + E / ElectronMassIneV();
    double v = TMath::Sqrt(2 * E / ElectronMassIneV()) * LightSpeed();
    double cosTheta = TMath::Sqrt(TMath::Max(1. - TMath::Power(ElectronCharge() * B / (gamma * ElectronMassInKilogram() * v) * (waveguideRadius - r), 2), 0.));

    return cosTheta;
}