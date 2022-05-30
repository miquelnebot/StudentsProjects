

void thestacker()
{


//TFile * input0=new TFile("concat_caf_0-b70120bf-fe82-40e5-8fff-2ab9117324e5.root","READ");
//TH1F * POTHist0=(TH1F*)input0->Get("TotalPOT");
//NrTotalPOT+=POTHist0->GetBinContent(1);
//std::cout << "POT now: " << NrTotalPOT << std::endl;



TFile * myhistfile=new TFile("histTree.root","READ");
TH1F * electron_e_ge_50_hist = (TH1F*)myhistfile->Get("electron_e_ge_50_cut");
TH1F * electron_e_ge_200_hist = (TH1F*)myhistfile->Get("electron_e_ge_200_cut");
TH1F * gamma_e_ge_50_hist = (TH1F*)myhistfile->Get("gamma_e_ge_50_cut");
TH1F * gamma_e_ge_200_hist = (TH1F*)myhistfile->Get("gamme_e_ge_200_cut");
TH1F * electron_a_ge_50_hist = (TH1F*)myhistfile->Get("electron_a_ge_50_cut");
TH1F * electron_a_ge_200_hist = (TH1F*)myhistfile->Get("electron_a_ge_200_cut");
TH1F * gamma_a_ge_50_hist = (TH1F*)myhistfile->Get("gamma_a_ge_50_cut");
TH1F * gamma_a_ge_200_hist = (TH1F*)myhistfile->Get("gamma_a_ge_200_cut");

TFile * sigfile=new TFile("signalfile.root","READ");
TH1F * signal_e_50_hist = (TH1F*)sigfile->Get("weighteE_aftercuts_50");
TH1F * signal_e_200_hist = (TH1F*)sigfile->Get("weighteE_aftercuts_200");
TH1F * signal_a_50_hist = (TH1F*)sigfile->Get("weightedACos_aftercuts_50");
TH1F * signal_a_200_hist = (TH1F*)sigfile->Get("weightedACos_aftercuts_200");

signal_e_50_hist->GetEntries();

//STacking
{
   THStack *energy_50 = new THStack("energy_50","Energy Histogram (>50MeV) with e+/-, photons and signal;Energy (GeV);Number of Events");
   signal_e_50_hist->SetLineColor(kRed);
   signal_e_50_hist->SetFillColor(kRed);
   energy_50->Add(signal_e_50_hist);
   gamma_e_ge_50_hist->SetLineColor(kBlue);
   gamma_e_ge_50_hist->SetFillColor(kBlue);
   energy_50->Add(gamma_e_ge_50_hist);
   electron_e_ge_50_hist->SetLineColor(kViolet);
   electron_e_ge_50_hist->SetFillColor(kViolet);
   energy_50->Add(electron_e_ge_50_hist);
   TCanvas *csenergy_50 = new TCanvas("csenergy_50","csenergy_50",10,10,700,900);
   TText T; T.SetTextFont(42); T.SetTextAlign(21);
   energy_50->Draw();
  
  
   TLegend* legend = new TLegend(0.5,0.7,0.9,0.9);
   legend->AddEntry(signal_e_50_hist,"Signal Energy (>50MeV)","f");
   legend->AddEntry(gamma_e_ge_50_hist,"Gamma Energy (>50MeV)","f");
   legend->AddEntry(electron_e_ge_50_hist,"Electron Energy (>50MeV)","f");
   legend->Draw(); 


}
{
   THStack *energy_200 = new THStack("energy_200","Energy Histogram (>200MeV) with e+/-, photons and signal;Energy (GeV);Number of Events");
   signal_e_200_hist->SetLineColor(kRed);
   signal_e_200_hist->SetFillColor(kRed);
   energy_200->Add(signal_e_200_hist);
   gamma_e_ge_200_hist->SetLineColor(kBlue);
   gamma_e_ge_200_hist->SetFillColor(kBlue);
   energy_200->Add(gamma_e_ge_200_hist);
   electron_e_ge_200_hist->SetLineColor(kViolet);
   electron_e_ge_200_hist->SetFillColor(kViolet);
   energy_200->Add(electron_e_ge_200_hist);
   TCanvas *csenergy_200 = new TCanvas("csenergy_200","csenergy_200",10,10,700,900);
   TText T; T.SetTextFont(42); T.SetTextAlign(21);
   energy_200->Draw();

   TLegend* legend = new TLegend(0.5,0.7,0.9,0.9);
   legend->AddEntry(signal_e_50_hist,"Signal Energy (>200MeV)","f");
   legend->AddEntry(gamma_e_ge_50_hist,"Gamma Energy (>200MeV)","f");
   legend->AddEntry(electron_e_ge_50_hist,"Electron Energy (>200MeV)","f");
   legend->Draw();


}
{
   THStack *angle_50 = new THStack("angle_50","Angle Histogram (>50MeV) with e+/-, photons and signal;Angle (rad);Number of Events");
   signal_a_50_hist->SetLineColor(kRed);
   signal_a_50_hist->SetFillColor(kRed);
   angle_50->Add(signal_a_50_hist);
   gamma_a_ge_50_hist->SetLineColor(kBlue);
   gamma_a_ge_50_hist->SetFillColor(kBlue);
   angle_50->Add(gamma_a_ge_50_hist);
   electron_a_ge_50_hist->SetLineColor(kViolet);
   electron_a_ge_50_hist->SetFillColor(kViolet);
   angle_50->Add(electron_a_ge_50_hist);
   TCanvas *csangle_50 = new TCanvas("csangle_50","csangle_50",10,10,700,900);
   TText T; T.SetTextFont(42); T.SetTextAlign(21);
   angle_50->Draw();

   TLegend* legend = new TLegend(0.5,0.7,0.9,0.9);
   legend->AddEntry(signal_e_50_hist,"Signal Angle (>50MeV)","f");
   legend->AddEntry(gamma_e_ge_50_hist,"Gamma Angle (>50MeV)","f");
   legend->AddEntry(electron_e_ge_50_hist,"Electron Angle (>50MeV)","f");
   legend->Draw();

}

{
   THStack *angle_200 = new THStack("angle_200","Angle Histogram (>200MeV) with e+/-, photons and signal ;Angle (rad);Number of Events");
   signal_a_200_hist->SetLineColor(kRed);
   signal_a_200_hist->SetFillColor(kRed);
   angle_200->Add(signal_a_200_hist);
   gamma_a_ge_200_hist->SetLineColor(kBlue);
   gamma_a_ge_200_hist->SetFillColor(kBlue);
   angle_200->Add(gamma_a_ge_200_hist);
   electron_a_ge_200_hist->SetLineColor(kViolet);
   electron_a_ge_200_hist->SetFillColor(kViolet);
   angle_200->Add(electron_a_ge_200_hist);
   TCanvas *csangle_200 = new TCanvas("csangle_200","csangle_200",10,10,700,900);
   TText T; T.SetTextFont(42); T.SetTextAlign(21);
   angle_200->Draw();

   TLegend* legend = new TLegend(0.5,0.7,0.9,0.9);
   legend->AddEntry(signal_e_50_hist,"Signal Angle (>200MeV)","f");
   legend->AddEntry(gamma_e_ge_50_hist,"Gamma Angle (>200MeV)","f");
   legend->AddEntry(electron_e_ge_50_hist,"Electron Angle (>200MeV)","f");
   legend->Draw();



}


}

