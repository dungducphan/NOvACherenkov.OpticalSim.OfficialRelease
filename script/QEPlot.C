#include <fstream>
#include <vector>

#include "Style.C"

void QEPlot() {
  GeneralStyle();

  std::ifstream QE_file("../Ham_8in_5912-100.csv");
  std::vector<double> wavelength_nm, qe;
  double x, y;
  while (QE_file >> x >> y) {
    wavelength_nm.push_back(x);
    qe.push_back(y);
  }
  QE_file.close();

  std::ifstream QE_wrong_file("../M16Corrected2-3.csv");
  std::vector<double> wavelength_nm_wrong, qe_wrong;
  while (QE_wrong_file >> x >> y) {
    wavelength_nm_wrong.push_back(x);
    qe_wrong.push_back(y);
  }
  QE_wrong_file.close();

  const unsigned int Npoints = wavelength_nm.size();
  double* wvlength = (double*) malloc(Npoints * sizeof(double));
  double* QE     = (double*) malloc(Npoints * sizeof(double));
  for (unsigned int i = 0; i < Npoints; i++) {
    wvlength[i] = wavelength_nm.at(i);
    QE[i] = qe.at(i);
  }

  const unsigned int Npoints_wrong = wavelength_nm_wrong.size();
  double* wvlength_wrong = (double*) malloc(Npoints_wrong * sizeof(double));
  double* QE_wrong     = (double*) malloc(Npoints_wrong * sizeof(double));
  for (unsigned int i = 0; i < Npoints_wrong; i++) {
    wvlength_wrong[i] = wavelength_nm_wrong.at(i);
    QE_wrong[i] = qe_wrong.at(i);
  }

  TGraph* gr = new TGraph(Npoints, wvlength, QE);
  TGraph* gr_wrong = new TGraph(Npoints_wrong, wvlength_wrong, QE_wrong);
  TCanvas* c = new TCanvas();
  StyleLinearLinear(c);
  gr->GetXaxis()->SetRangeUser(200, 800);
  gr->GetXaxis()->SetTitle("Wavelength (nm)");
  gr->GetXaxis()->CenterTitle();
  gr->GetYaxis()->SetRangeUser(0.01, 100);
  gr->GetYaxis()->SetTitle("QE (%)");
  gr->GetYaxis()->CenterTitle();
  gr->SetTitle("");
  gr->SetLineWidth(3);
  gr->SetLineColor(kRed);
  gr->SetMarkerColor(kRed);

  gr_wrong->GetXaxis()->SetRangeUser(200, 800);
  gr_wrong->GetXaxis()->SetTitle("Wavelength (nm)");
  gr_wrong->GetXaxis()->CenterTitle();
  gr_wrong->GetYaxis()->SetRangeUser(0, 30);
  gr_wrong->GetYaxis()->SetTitle("QE (%)");
  gr_wrong->GetYaxis()->CenterTitle();
  gr_wrong->SetTitle("");
  gr_wrong->SetLineWidth(3);
  gr_wrong->SetLineColor(kRed);
  gr_wrong->SetMarkerColor(kRed);
  gr_wrong->SetLineWidth(3);
  gr_wrong->SetLineColor(kBlue);
  gr_wrong->SetMarkerColor(kBlue);

  // gr->Draw("AL");
  gr_wrong->Draw("AL");

  TLegend* leg = new TLegend(0.5, 0.6, 0.8, 0.8);
  // leg->AddEntry(gr, "Ham. 5912-100 (8in)", "l");
  leg->AddEntry(gr_wrong, "Ham. R10754-M16", "l");
  leg->SetBorderSize(0);
  leg->Draw();

  c->SaveAs("QE-Log.pdf");
}
