#include "TROOT.h"
#include "TVector3.h"
#include "TGraph.h"
#include "TGraph2D.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "TStyle.h"
#include "TFile.h"
#include "TPaveText.h"

#include "MagneticField.h"
#include "TrappingEfficiency.cpp"

#include "logger.hh"
LOGGER(mainlog, "Main");

// const double rightMargin = 0.02;
// const double leftMargin = 0.09;
// const double botMargin = 0.11;
// const double topMargin = 0.03;
// const double legWidth = 0.2;
// const double legHeight = 0.3;

int ColorPalette(int n, int ColorNumber)
{
    return 51 + 48 * n / (ColorNumber - 1);
}

void SetROOTStyle(double rightMargin = 0.02, double leftMargin = 0.09, double botMargin = 0.11, double topMargin = 0.06)
{

    // TStyle *gStyle = new TStyle();
    gROOT->SetStyle("Modern");
    gStyle->SetOptStat("nem");
    gStyle->SetStatY(1. - topMargin);
    gStyle->SetStatX(1. - rightMargin);
    gStyle->SetStatW(0.2);
    gStyle->SetStatH(0.2);
    gStyle->SetLabelOffset(0, "xy");
    gStyle->SetLabelSize(0.05, "xyz");
    gStyle->SetTitleOffset(0.9, "y");
    gStyle->SetTitleOffset(1.02, "x");
    gStyle->SetTitleSize(0.05, "xyz");
    // gStyle->SetTitleSize(0.05, "x");
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
    double mm = 1e-3; //m
    // TVector3 positionSolenoid(0, 0, 0);

    // Solenoid solenoid(1, 1, 10, 1, positionSolenoid);

    // LINFO(mainlog, solenoid.getRadialMagneticField(0.5, 0, 0));
    // LINFO(mainlog, solenoid.getLongMagneticField(0, 0, 0));

    // Coil coil(1, 10, 1, positionSolenoid);

    // LINFO(mainlog, coil.getRadialMagneticField(0.5, 0, 0));
    // LINFO(mainlog, coil.getLongMagneticField(0, 0, 0));
    // LINFO(mainlog, coil.getLongMagneticFieldOnAxis(0));
    // LINFO(mainlog, coil.getLongMagneticField(0, 0, 1));
    // LINFO(mainlog, coil.getLongMagneticFieldOnAxis(1));

    double Rmin = 0.0074;
    double Radius = Rmin + 2 * mm;
    // double distanceBetweenCoils = 8 * cm;

    double length = 7.62 * mm;
    double space = 14.6 * mm;
    double distanceBetweenCoils = 4 * (length + space);

    TVector3 positionCoil1(0, 0, -distanceBetweenCoils / 2.);
    TVector3 positionCoil2(0, 0, distanceBetweenCoils / 2.);

    Bathtub bathtub15(Radius, 1, 1, positionCoil1, positionCoil2);
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

    // --------------------------------
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
    SetROOTStyle(0.15);
    TCanvas *can = new TCanvas("can", "can", 20, 10, 600, 400);
    gLongFieldMap->Draw("colz");
    gLongFieldMap->SetTitle("");
    gCoilPosition->Draw("sameP");
    gCoilPosition->SetMarkerStyle(20);
    can->Draw();
    can->SaveAs("longFieldMap.pdf");
    // TCanvas *can = new TCanvas("can", "can", 20, 10, 600, 400);
    gRadialFieldMap->Draw("colz");
    gRadialFieldMap->SetTitle("");
    gCoilPosition->Draw("sameP");
    gCoilPosition->SetMarkerStyle(20);
    can->Draw();
    can->SaveAs("radialFieldMap.pdf");
    SetROOTStyle();

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

    // ------------------------------------------------
    LINFO(mainlog, "Optimizing current for profile");

    TFile *file = new TFile("../FieldProfile.root", "OPEN");
    auto gExactFieldProfile = (TGraph *)file->Get("Graph");
    gExactFieldProfile->Draw("AP");
    gExactFieldProfile->GetXaxis()->SetTitle("Position along z [cm]");
    gExactFieldProfile->GetYaxis()->SetTitle("Magnetic field [mT]");
    can->SaveAs("exactFieldProfile.pdf");

    double xmin = gExactFieldProfile->GetXaxis()->GetXmin();
    double xmax = gExactFieldProfile->GetXaxis()->GetXmax();
    LDEBUG(mainlog, "xmin = " << xmin << "; xmax = " << xmax);

    TF1 *f = new TF1("f", [&](double *x, double *p) { return p[0] * gExactFieldProfile->Eval(x[0] + p[1]); }, -distanceBetweenCoils * 100, distanceBetweenCoils * 100, 2);
    f->SetParameter(0, 1);
    f->SetParameter(1, 5);

    gFieldProfile->Draw("AP");
    gFieldProfile->Fit("f", "R");
    can->SaveAs("fitResult.pdf");

    LDEBUG(mainlog, "Number of turns required: " << 1. / f->GetParameter(0));
    LINFO(mainlog, "Recreating bathutb object");
    bathtub15 = Bathtub(Radius, 60, 1, positionCoil1, positionCoil2);

    LINFO(mainlog, "Calculating trapping efficiency");

    double B0Field = 1; //T
    int nCurrent = 20;

    TGraph *gTrappingEfficiencyCenter = new TGraph();
    for (int iCurrent = 0; iCurrent < nCurrent; iCurrent++)
    {
        double current = (iCurrent + 0.01) * 5. / nCurrent;
        bathtub15.setCurrent(current);
        double Br = bathtub15.getRadialMagneticField(0, 0, 0);
        double Bz = bathtub15.getLongMagneticField(0, 0, 0);
        double BAtPosition = TMath::Sqrt(TMath::Power(B0Field + Bz, 2) + TMath::Power(Br, 2));
        double Bmax = bathtub15.getMaxFieldAlongZ(0, 0, 0, 1.);
        double cosThetaMin = TMath::Sqrt(1. - BAtPosition / Bmax);
        gTrappingEfficiencyCenter->SetPoint(iCurrent, current, cosThetaMin * 100);
    }

    TCanvas *canCurrentScan = new TCanvas("canCurrentScan", "canCurrentScan", 20, 10, 600, 400);
    canCurrentScan->SetLogy();
    canCurrentScan->SetLogx();
    canCurrentScan->SetGridy();
    canCurrentScan->SetGridx();
    gTrappingEfficiencyCenter->Draw("APL");
    gTrappingEfficiencyCenter->SetLineWidth(2);
    gTrappingEfficiencyCenter->GetXaxis()->SetRangeUser(0.02, 2.);
    gTrappingEfficiencyCenter->GetYaxis()->SetRangeUser(0.2, 10.);
    gTrappingEfficiencyCenter->GetXaxis()->SetTitle("Current [A]");
    gTrappingEfficiencyCenter->GetYaxis()->SetTitle("Trapping efficiency in the center of the trap [%]");
    canCurrentScan->SaveAs("currentScan.pdf");

    // ---------------------------------------------
    LINFO(mainlog, "Profile as a function of radius");

    bathtub15.setCurrent(1.);
    TCanvas *canProfileVsRadius = new TCanvas("canProfileVsRadius", "canProfileVsRadius", 20, 10, 600, 400);
    int NProfile = 10;
    TGraph **gFieldProfileVsRadius = new TGraph *[NProfile];
    for (int i = 0; i < NProfile; i++)
    {
        // TGraph* graph
        gFieldProfileVsRadius[i] = new TGraph();
        double rho = Radius * i / NProfile;
        for (int iZ = 0; iZ < nBinZ; iZ++)
        {

            double z = -distanceBetweenCoils + 2 * distanceBetweenCoils * iZ / nBinZ;
            gFieldProfileVsRadius[i]->SetPoint(iZ, z * 100., bathtub15.getLongMagneticField(rho, 0, z) * 1000);
            // gFieldProfileAnalytic->SetPoint(iZ, z * 100., bathtub15.getLongMagneticFieldOnAxis(z) * 1000);
        }
        gFieldProfileVsRadius[i]->SetMarkerColor(ColorPalette(i, NProfile));
        gFieldProfileVsRadius[i]->SetLineColor(ColorPalette(i, NProfile));
        if (i == 0)
        {
            gFieldProfileVsRadius[i]->Draw("AL");
            gFieldProfileVsRadius[i]->GetYaxis()->SetRangeUser(0, 10);
            gFieldProfileVsRadius[i]->GetXaxis()->SetTitle("Position along z [cm]");
            gFieldProfileVsRadius[i]->GetYaxis()->SetTitle("Magnetic field [mT]");
        }
        else
        {
            gFieldProfileVsRadius[i]->Draw("sameL");
        }
    }
    canProfileVsRadius->SaveAs("profileVsRadius.pdf");

    // ------------------------------------------------------------------
    LINFO(mainlog, "Calculating trapping efficiency over trapping volume");

    double integral = 0;
    double integralThetaMax = 0;
    int nR = 500;
    int nZ = 100;

    double waveguideRadius = 6.7945 * mm;
    double mainFieldValue = 1.; //T
    double KE = 18e3;           //eV
    bathtub15.setCurrent(1.);

    TGraph2D *gTrappingEfficiencyMap = new TGraph2D();
    TGraph *gCosThetaMinProfile = new TGraph();
    TGraph *gCosThetaMaxProfile = new TGraph();

    for (int iR = 0; iR < nR; iR++)
    {
        double rho = waveguideRadius * iR / nR;
        double Bmax = bathtub15.getMaxFieldAlongZ(rho, 0, 0, 1.);
        // LDEBUG(mainlog, Bmax);
        double z = 0;
        double Brho = bathtub15.getRadialMagneticField(rho, 0, z);
        double Bz = bathtub15.getLongMagneticField(rho, 0, z);
        double BAtPosition = TMath::Sqrt(TMath::Power(Brho, 2) + TMath::Power(Bz + mainFieldValue, 2));
        double cosThetaMin = getCosThetaMin(rho, z, mainFieldValue, Brho, Bz, Bmax);
        double cosThetaMax = getCosThetaMax(rho, z, mainFieldValue, Brho, Bz, KE, waveguideRadius);
        gCosThetaMinProfile->SetPoint(iR, rho * 100, cosThetaMin);
        gCosThetaMaxProfile->SetPoint(iR, rho * 100, cosThetaMax);

        for (int iZ = 0; iZ < nZ; iZ++)
        {
            z = -distanceBetweenCoils / 2. + distanceBetweenCoils * (iZ + 0.5) / nZ;
            Brho = bathtub15.getRadialMagneticField(rho, 0, z);
            Bz = bathtub15.getLongMagneticField(rho, 0, z);
            BAtPosition = TMath::Sqrt(TMath::Power(Brho, 2) + TMath::Power(Bz + mainFieldValue, 2));
            cosThetaMin = getCosThetaMin(rho, z, mainFieldValue, Brho, Bz, Bmax);
            cosThetaMax = getCosThetaMax(rho, z, mainFieldValue, Brho, Bz, KE, waveguideRadius);
            // double cosThetaMin = TMath::Sqrt(1. - BAtPosition / Bmax);
            integralThetaMax += rho * TMath::Max(cosThetaMin - cosThetaMax, 0.);
            integral += rho * TMath::Max(cosThetaMin, 0.);
            gTrappingEfficiencyMap->SetPoint(iZ + iR * nZ, rho * 100, z * 100, TMath::Max(cosThetaMin - cosThetaMax, 0.) * 100.);
        }
    }
    integral *= waveguideRadius / nR * distanceBetweenCoils / nZ;
    integral *= 2 / (TMath::Power(waveguideRadius, 2) * distanceBetweenCoils);
    integralThetaMax *= waveguideRadius / nR * distanceBetweenCoils / nZ;
    integralThetaMax *= 2 / (TMath::Power(waveguideRadius, 2) * distanceBetweenCoils);
    LDEBUG(mainlog, "Trapping efficiency: " << integral);
    LDEBUG(mainlog, "Trapping efficiency including wall effects: " << integralThetaMax);
    SetROOTStyle(0.15);

    TCanvas *canTrapEff = new TCanvas("canTrapEff", "canTrapEff", 20, 10, 600, 400);
    gTrappingEfficiencyMap->SetTitle("");
    gTrappingEfficiencyMap->GetXaxis()->SetTitle("Radial position [cm]");
    gTrappingEfficiencyMap->GetXaxis()->SetRangeUser(0., waveguideRadius * 100);
    gTrappingEfficiencyMap->GetYaxis()->SetTitle("Longitudinal position [cm]");
    gTrappingEfficiencyMap->GetZaxis()->SetTitle("Trapping efficiency [%]");
    gTrappingEfficiencyMap->Draw("PCol");
    canTrapEff->Draw();
    canTrapEff->SaveAs("trappingEfficiencyMap.pdf");

    SetROOTStyle();
    gCosThetaMaxProfile->Draw("AL");
    gCosThetaMaxProfile->GetXaxis()->SetTitle("Radius [cm]");
    gCosThetaMaxProfile->GetYaxis()->SetTitle("cos#theta ");
    gCosThetaMaxProfile->SetLineWidth(2);
    gCosThetaMaxProfile->SetLineColor(2);
    gCosThetaMinProfile->Draw("sameL");
    gCosThetaMinProfile->SetLineWidth(2);
    canTrapEff->SaveAs("trappingEfficiencyProfile.pdf");

    return 0;
}