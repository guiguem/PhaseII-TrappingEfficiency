#include "TROOT.h"
#include "TVector3.h"
#include "TGraph.h"
#include "TGraph2D.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "TStyle.h"

#include "MagneticField.h"
#include "TrappingEfficiency.cpp"

#include "logger.hh"
LOGGER(mainlog, "Main");

const double rightMargin = 0.02;
const double leftMargin = 0.09;
const double botMargin = 0.11;
const double topMargin = 0.03;
const double legWidth = 0.2;
const double legHeight = 0.3;

void SetROOTStyle()
{

    // TStyle *gStyle = new TStyle();
    gROOT->SetStyle("Modern");
    gStyle->SetOptStat("nem");
    gStyle->SetStatY(1. - topMargin);
    gStyle->SetStatX(1. - rightMargin);
    gStyle->SetStatW(0.2);
    gStyle->SetStatH(0.2);
    gStyle->SetLabelOffset(0, "xy");
    gStyle->SetLabelSize(0.05, "xy");
    gStyle->SetTitleOffset(0.9, "y");
    gStyle->SetTitleSize(0.05, "y");
    gStyle->SetLabelSize(0.05, "y");
    gStyle->SetLabelOffset(0, "y");
    gStyle->SetTitleSize(0.05, "x");
    gStyle->SetLabelSize(0.05, "x");
    gStyle->SetTitleOffset(1.02, "x");
    gStyle->SetPadRightMargin(rightMargin);
    gStyle->SetPadTopMargin(topMargin);
    gStyle->SetPadBottomMargin(botMargin);
    gStyle->SetPadLeftMargin(leftMargin);
    gStyle->cd();
}

int main()
{

    SetROOTStyle();

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

    Bathtub bathtub15(Radius, 50, 1, positionCoil1, positionCoil2);
    LDEBUG(mainlog, bathtub15.getType());
    // LINFO(mainlog, bathtub15.getLongMagneticField(0, 0, 0));
    // LINFO(mainlog, bathtub15.getLongMagneticFieldOnAxis(0));

    TGraph2D *gRadialFieldMap = new TGraph2D();
    TGraph2D *gLongFieldMap = new TGraph2D();
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
            gLongFieldMap->SetPoint(iCount, x, z, bathtub15.getLongMagneticField(x, 0, z));
            gRadialFieldMap->SetPoint(iCount, x, z, bathtub15.getRadialMagneticField(x, 0, z));
            iCount++;
        }
    }

    LINFO(mainlog, "Creating profile");
    for (int iZ = 0; iZ < nBinZ; iZ++)
    {
        double z = -distanceBetweenCoils + 2 * distanceBetweenCoils * iZ / nBinZ;
        gFieldProfile->SetPoint(iZ, z * 100., bathtub15.getLongMagneticField(0, 0, z) * 1000);
        gFieldProfileAnalytic->SetPoint(iZ, z * 100., bathtub15.getLongMagneticFieldOnAxis(z) * 1000);
    }

    LINFO(mainlog, "Drawing");
    TCanvas *can = new TCanvas("can", "can", 20, 10, 600, 400);
    gLongFieldMap->Draw("colz");
    gCoilPosition->Draw("sameP");
    gCoilPosition->SetMarkerStyle(20);
    can->Draw();
    can->SaveAs("longFieldMap.pdf");
    // TCanvas *can = new TCanvas("can", "can", 20, 10, 600, 400);
    gRadialFieldMap->Draw("colz");
    gCoilPosition->Draw("sameP");
    gCoilPosition->SetMarkerStyle(20);
    can->Draw();
    can->SaveAs("radialFieldMap.pdf");

    // TCanvas *can = new TCanvas("can", "can", 20, 10, 600, 400);
    gFieldProfile->GetXaxis()->SetRangeUser(-distanceBetweenCoils * 100, distanceBetweenCoils * 100);
    gFieldProfile->GetXaxis()->SetTitle("Position along z [cm]");
    gFieldProfile->GetYaxis()->SetTitle("Magnetic field [mT]");
    gFieldProfile->Draw("AP");
    gFieldProfile->SetMarkerStyle(8);
    // gFieldProfile->SetMarkerSize(3);
    gFieldProfileAnalytic->Draw("sameL");
    gFieldProfileAnalytic->SetLineColor(2);
    gFieldProfileAnalytic->SetLineWidth(2);
    // gCoilPosition->SetMarkerStyle(20);
    can->Draw();
    can->SaveAs("fieldProfile.pdf");

    // TF2 *magneticMap = bathtub15.getRadialMagneticFieldMap(1);
    // magneticMap->Draw("colz");
    // can->SaveAs("fieldProfileTF2.pdf");

    LINFO(mainlog, "Calculating trapping efficiency");

    double B0Field = 1; //T
    int nCurrent = 100;

    TGraph *gTrappingEfficiencyCenter = new TGraph();
    for (int iCurrent = 0; iCurrent < nCurrent; iCurrent++)
    {
        double current = (iCurrent + 0.01) * 2. / nCurrent;
        bathtub15.setCurrent(current);
        double Br = bathtub15.getRadialMagneticField(0, 0, 0);
        double Bz = bathtub15.getLongMagneticField(0, 0, 0);
        double BAtPosition = TMath::Sqrt(TMath::Power(B0Field + Bz, 2) + TMath::Power(Br, 2));
        double Bmax = bathtub15.getMaxFieldAlongZ(0, 0, 0, 1.);
        LDEBUG(mainlog, Br << "\t" << Bz);
        double cosThetaMin = TMath::Sqrt(1. - BAtPosition / Bmax);
        gTrappingEfficiencyCenter->SetPoint(iCurrent, current, cosThetaMin);
        // LDEBUG(mainlog, getCosThetaMin(0, 0, 1., Br, Bz));
        // gFieldProfileAnalytic->SetPoint(iZ, z, bathtub15.getLongMagneticFieldOnAxis(z));
    }

    TCanvas *canCurrentScan = new TCanvas("canCurrentScan", "canCurrentScan", 20, 10, 600, 400);
    canCurrentScan->SetLogy();
    canCurrentScan->SetLogx();
    gTrappingEfficiencyCenter->Draw("APL");
    canCurrentScan->SaveAs("currentScan.pdf");

    return 0;
}