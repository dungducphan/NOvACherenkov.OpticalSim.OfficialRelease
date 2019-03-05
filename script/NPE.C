#include "Style.C"
#include "HitAnalysis.C"
#include "TCanvas.h"

void NPE() {
  GeneralStyle();

  // 8in QE
  // double length[5]   = {1.5, 2, 2.5, 3, 3.5};
  // double lengther[5] = {0, 0, 0, 0, 0};
  // double npe[5]      = {32, 42, 53, 61, 70};
  // double npeer[5]    = {5, 6, 7, 8, 8};

  // M16 QE
  // double length[5]   = {1.5, 2, 2.5, 3, 3.5};
  // double lengther[5] = {0, 0, 0, 0, 0};
  // double npe[5]      = {16, 21, 25, 29, 32};
  // double npeer[5]    = {4, 6, 7, 9, 9};
  //
  // TGraphErrors* gr = new TGraphErrors(5, length, npe, lengther, npeer);
  // TCanvas* c = new TCanvas();
  // StyleLinearLinear(c);
  // gr->SetTitle("");
  // gr->GetXaxis()->SetTitle("Length (m)");
  // gr->GetXaxis()->CenterTitle();
  // gr->GetYaxis()->SetTitle("NPE");
  // gr->GetYaxis()->CenterTitle();
  // gr->SetLineWidth(2);
  // gr->SetLineColor(kRed);
  // gr->SetMarkerColor(kRed);
  // gr->GetXaxis()->SetLimits(1, 4);
  // gr->GetYaxis()->SetRangeUser(0, 50);
  // gr->Draw("APL");


  double length[5]   = {10, 20, 30, 40, 50};
  double eff_N2[5]      = {99.4643, 97.6162, 92.3262, 83.4269, 65.9018};
  double eff_CO2[5]     = {99.6145, 98.5662, 96.4172, 91.9684, 84.4544};

//  for (unsigned int i = 10; i < 60; i += 10) {
//    HitAnalysis ha;
//    length[i/10 - 1] = i;
//    eff_CO2[i/10 - 1] = ha.Loop(i);
//  }


  TGraphErrors* gr = new TGraphErrors(5, length, eff_N2);
  TGraphErrors* gr2 = new TGraphErrors(5, length, eff_CO2);
  TCanvas* c = new TCanvas();
  StyleLinearLinear(c);
  gr->SetTitle("");
  gr->GetXaxis()->SetTitle("NPE Threshold");
  gr->GetXaxis()->CenterTitle();
  gr->GetYaxis()->SetTitle("Detection Eff. (%)");
  gr->GetYaxis()->CenterTitle();

  gr->SetLineWidth(2);
  gr->SetLineColor(kRed);
  gr->SetMarkerColor(kRed);
  gr->GetXaxis()->SetLimits(0, 60);
  gr->GetYaxis()->SetRangeUser(100, 60);

  gr2->SetLineWidth(2);
  gr2->SetLineColor(kBlue);
  gr2->SetMarkerColor(kBlue);
  gr2->SetMarkerStyle(kOpenSquare);

  gr->Draw("APL");
  gr2->Draw("SAME PL");

  TLegend* leg = new TLegend(0.3, 0.4, 0.4, 0.5);
  leg->AddEntry(gr, "N2", "lp");
  leg->AddEntry(gr2, "CO2", "lp");
  leg->Draw();
}
