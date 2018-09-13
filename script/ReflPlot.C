#include <fstream>
#include <vector>

#include "Style.C"

void ReflPlot() {
  GeneralStyle();

  std::ifstream refl_file("ESR-Anna.csv");
  std::vector<double> wavelength_nm, mylar_relf;
  double x, y;
  while (refl_file >> x >> y) {
    wavelength_nm.push_back(x);
    mylar_relf.push_back(y);
  }

  const unsigned int Npoints = wavelength_nm.size();
  double* wvlength = (double*) malloc(Npoints * sizeof(double));
  double* refl     = (double*) malloc(Npoints * sizeof(double));
  for (unsigned int i = 0; i < Npoints; i++) {
    wvlength[i] = wavelength_nm.at(i);
    refl[i] = mylar_relf.at(i);
  }

  TGraph* gr = new TGraph(Npoints, wvlength, refl);
  TCanvas* c = new TCanvas();
  StyleLinearLinear(c);
  c->SetGrid();
  gr->GetXaxis()->SetRangeUser(300, 800);
  gr->GetXaxis()->SetTitle("Wavelength (nm)");
  gr->GetXaxis()->CenterTitle();
  gr->GetYaxis()->SetRangeUser(0, 100);
  gr->GetYaxis()->SetTitle("Reflectance (%)");
  gr->GetYaxis()->CenterTitle();
  gr->SetTitle("");
  gr->SetLineWidth(3);
  gr->SetLineColor(kRed);
  gr->SetMarkerColor(kRed);
  gr->Draw("APL");
  c->SaveAs("MirrorRelf.pdf");
}
