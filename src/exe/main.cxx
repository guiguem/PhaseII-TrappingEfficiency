#include "TVector3.h"
#include "TGraph.h"
#include "TGraph2D.h"
#include "TCanvas.h"

#include "MagneticField.h"

#include "logger.hh"
LOGGER(mainlog, "Main");

int main()
{

    double cm = 0.01; //m
    TVector3 positionSolenoid(0, 0, 0);

    Solenoid solenoid(1, 1, 10, 1, positionSolenoid);

    // LINFO(mainlog, solenoid.getRadialMagneticField(0.5, 0, 0));
    // LINFO(mainlog, solenoid.getLongMagneticField(0, 0, 0));

    Coil coil(1, 10, 1, positionSolenoid);

    // LINFO(mainlog, coil.getRadialMagneticField(0.5, 0, 0));
    // LINFO(mainlog, coil.getLongMagneticField(0, 0, 0));
    // LINFO(mainlog, coil.getLongMagneticFieldOnAxis(0));
    // LINFO(mainlog, coil.getLongMagneticField(0, 0, 1));
    // LINFO(mainlog, coil.getLongMagneticFieldOnAxis(1));

    double Radius = 1 * cm;
    double distanceBetweenCoils = 8 * cm;

    TVector3 positionCoil1(0, 0, -distanceBetweenCoils / 2.);
    TVector3 positionCoil2(0, 0, distanceBetweenCoils / 2.);

    Bathtub bathtub15(Radius, 10, 1, positionCoil1, positionCoil2);
    // LINFO(mainlog, bathtub15.getLongMagneticField(0, 0, 0));
    // LINFO(mainlog, bathtub15.getLongMagneticFieldOnAxis(0));

    TGraph2D *gFieldMap = new TGraph2D();
    TGraph *gCoilPosition = new TGraph();
    TGraph *gFieldProfile = new TGraph();
    TGraph *gFieldProfileAnalytic = new TGraph();

    gCoilPosition->SetPoint(0, Radius, positionCoil1.Z());
    gCoilPosition->SetPoint(1, Radius, positionCoil2.Z());

    int iCount = 0;
    int nBinX = 1000;
    int nBinZ = 1000;

    LINFO(mainlog, "Creating 2D map");
    for (int iX = 0; iX < nBinX; iX++)
    {
        double x = Radius * iX / nBinX;
        for (int iZ = 0; iZ < nBinZ; iZ++)
        {
            double z = -distanceBetweenCoils + 2 * distanceBetweenCoils * iZ / nBinZ;
            gFieldMap->SetPoint(iCount, x, z, bathtub15.getLongMagneticField(x, 0, z));
            iCount++;
        }
    }

    LINFO(mainlog, "Creating profile");
    for (int iZ = 0; iZ < nBinZ; iZ++)
    {
        double z = -distanceBetweenCoils + 2 * distanceBetweenCoils * iZ / nBinZ;
        gFieldProfile->SetPoint(iZ, z, bathtub15.getLongMagneticField(0, 0, z));
        gFieldProfileAnalytic->SetPoint(iZ, z, bathtub15.getLongMagneticFieldOnAxis(z));
    }

    LINFO(mainlog, "Drawing");
    TCanvas *can = new TCanvas("can", "can", 20, 10, 600, 400);
    gFieldMap->Draw("colz");
    gCoilPosition->Draw("sameP");
    gCoilPosition->SetMarkerStyle(20);
    can->Draw();
    can->SaveAs("fieldMap.pdf");

    // TCanvas *can = new TCanvas("can", "can", 20, 10, 600, 400);
    gFieldProfile->Draw("AP");
    gFieldProfileAnalytic->Draw("sameL");
    gFieldProfileAnalytic->SetLineColor(2);
    // gCoilPosition->SetMarkerStyle(20);
    can->Draw();
    can->SaveAs("fieldProfile.pdf");

    LINFO(mainlog, "Calculating trapping efficiency");

    return 0;
}