void countPOT()
{

long double NrTotalPOT=0;

TFile * input0=new TFile("concat_caf_0-b70120bf-fe82-40e5-8fff-2ab9117324e5.root","READ");
TH1F * POTHist0=(TH1F*)input0->Get("TotalPOT");
NrTotalPOT+=POTHist0->GetBinContent(1);
std::cout << "POT now: " << NrTotalPOT << std::endl;



TFile * input1=new TFile("concat_caf_1-900aadd1-df60-4d86-9ccf-20a08c11c6d4.root","READ");
TH1F * POTHist1=(TH1F*)input1->Get("TotalPOT");
NrTotalPOT+=POTHist1->GetBinContent(1);
std::cout << "POT now: " << NrTotalPOT << std::endl;


TFile * input2=new TFile("concat_caf_2-bad55df4-16df-4dc9-b71e-4e5fd5b4ae3f.root","READ");
TH1F * POTHist2=(TH1F*)input2->Get("TotalPOT");
NrTotalPOT+=POTHist2->GetBinContent(1);
std::cout << "POT now: " << NrTotalPOT << std::endl;


TFile * input3=new TFile("concat_caf_3-50b34461-e956-42a2-ae27-6c90f90a2182.root","READ");
TH1F * POTHist3=(TH1F*)input3->Get("TotalPOT");
NrTotalPOT+=POTHist3->GetBinContent(1);
std::cout << "POT now: " << NrTotalPOT << std::endl;


}
