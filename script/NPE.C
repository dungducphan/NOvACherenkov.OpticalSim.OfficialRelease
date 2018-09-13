#include "Style.C"
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


  double length[5]   = {1.5, 2, 2.5, 3, 3.5};
  double eff[5]      = {98.74, 99.02, 99.16, 99.22, 99.23};

  TGraphErrors* gr = new TGraphErrors(5, length, eff);
  TCanvas* c = new TCanvas();
  StyleLinearLinear(c);
  gr->SetTitle("");
  gr->GetXaxis()->SetTitle("Length (m)");
  gr->GetXaxis()->CenterTitle();
  gr->GetYaxis()->SetTitle("Detection Eff. (%)");
  gr->GetYaxis()->CenterTitle();
  gr->SetLineWidth(2);
  gr->SetLineColor(kRed);
  gr->SetMarkerColor(kRed);
  gr->GetXaxis()->SetLimits(1, 4);
  gr->GetYaxis()->SetRangeUser(98.5, 99.5);
  gr->Draw("APL");
}
