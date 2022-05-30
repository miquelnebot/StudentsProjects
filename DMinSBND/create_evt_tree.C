
double MyAcos(double px,double py,double pz)
{
return acos(pz/sqrt(pow(px,2)+pow(py,2)+pow(pz,2)));

}

void create_evt_tree()
{
 
    ifstream inputfile("SBND_gammas_per_POT_scalar_unit_couplings.txt");
    
    TTree * signalTree=new TTree("signalTree","signalTree");
    
    
    
    double energy=0,px=0,py=0,pz=0;
    long double ctPOT=0;
    double x,y,z=0;
    int PDG=22;
    long double totalPOTsum=0;
    
    signalTree->Branch("GenE",&energy,"GenE/D");
    signalTree->Branch("px",&px,"px/D");
    signalTree->Branch("py",&py,"py/D");
    signalTree->Branch("pz",&pz,"pz/D");
    signalTree->Branch("POT",&ctPOT,"POT/D");
    signalTree->Branch("x",&x,"x/D");
    signalTree->Branch("y",&y,"y/D");
    signalTree->Branch("z",&z,"z/D");
    signalTree->Branch("PDG",&PDG,"PDG/I");
    
    int counter=0;
    TRandom3 genXYZ;
    
    //TH1D * nonweighted= new TH1D("nonweighted","nonweighted",100,0,2500);
    TH1F * weighted= new TH1F("weighteE","weightedE",20,0,2);
    TH1F * weightedACos= new TH1F("weightedACos","weightedACos",20,0,3.145);
    
    TH1F * weighted_50= new TH1F("weighteE_50","weightedE_50",20,0,2);
    TH1F * weightedACos_50= new TH1F("weightedACos_50","weightedACos_50",20,0,3.145);
    TH1F * weighted_aftercuts_50= new TH1F("weighteE_aftercuts_50","weightedE_aftercuts_50",20,0,2);
    TH1F * weightedACos_aftercuts_50= new TH1F("weightedACos_aftercuts_50","weightedACos_aftercuts_50",20,0,3.145);
    
    TH1F * weighted_200= new TH1F("weighteE_200","weightedE_200",20,0,2);
    TH1F * weightedACos_200= new TH1F("weightedACos_200","weightedACos_200",20,0,3.145);
    TH1F * weighted_aftercuts_200= new TH1F("weighteE_aftercuts_200","weightedE_aftercuts_200",20,0,2);
    TH1F * weightedACos_aftercuts_200= new TH1F("weightedACos_aftercuts_200","weightedACos_aftercuts_200",20,0,3.145);
   
   int kept_e_50=0;
   int kept_e_200=0;
   int kept_a_50=0;
   int kept_a_200=0; 
   int sign_total=0;
    
    
    weighted->SetLineColor(kRed);
    
    while(!inputfile.eof())
    {
        
     inputfile >> energy >> px >> py>>pz >> ctPOT;   
             
    totalPOTsum+=ctPOT;

    double CalcAcos=MyAcos(px,py,pz); //put function value here
    
    x=genXYZ.Rndm()*540-270;
    y=genXYZ.Rndm()*400-200;
    z=genXYZ.Rndm()*500-250;
    
    counter++;
    
    if(ctPOT > 1.e-9)
    std::cout << "event " << counter << " energy " << energy << " ctPOT " << ctPOT << " sum " << totalPOTsum << " " << x << " " << CalcAcos << std::endl;
     
    //nonweighted->Fill(energy);
    weighted->Fill(energy/1000,ctPOT);
    weightedACos->Fill(CalcAcos,ctPOT);   
    
    sign_total++;
    
    if(energy>50)
    {
    weighted_50->Fill(energy/1000,ctPOT);
    weightedACos_50->Fill(CalcAcos,ctPOT); 
      
        if((-180<x && x<180) && (-180< y &&  y<180) && (20< z &&  z<480))
        {
        weighted_aftercuts_50->Fill(energy/1000,ctPOT);
        weightedACos_aftercuts_50->Fill(CalcAcos,ctPOT);
	kept_e_50++;
        kept_a_50++;

        }
    }
    
    if(energy>200)
    {
    weighted_200->Fill(energy/1000,ctPOT);
    weightedACos_200->Fill(CalcAcos,ctPOT);        
      
        if((-180<x && x<180) && (-180< y &&  y<180) && (20< z &&  z<480))
        {
        weighted_aftercuts_200->Fill(energy/1000,ctPOT);
        weightedACos_aftercuts_200->Fill(CalcAcos,ctPOT);
	kept_e_200++;
        kept_a_200++;

        }
    }
    
    
    
    
    
    signalTree->Fill();
        
   // if (counter >100)
     //   break;
    }
    
    TFile * myRootFile=new TFile("signalfile.root","RECREATE");

    signalTree->Write();
    
      weighted->Scale(1.5586e+19*2.2e-12);
      weightedACos->Scale(1.5586e+19*2.2e-12);
    
      weighted_50->Scale(1.5586e+19*2.2e-12);
      weightedACos_50->Scale(1.5586e+19*2.2e-12);
      weighted_aftercuts_50->Scale(1.5586e+19*2.2e-12);
      weightedACos_aftercuts_50->Scale(1.5586e+19*2.2e-12);
    
      weighted_200->Scale(1.5586e+19*2.2e-12);
      weightedACos_200->Scale(1.5586e+19*2.2e-12);
      weighted_aftercuts_200->Scale(1.5586e+19*2.2e-12);
      weightedACos_aftercuts_200->Scale(1.5586e+19*2.2e-12);
    
     weighted->Sumw2(false);
      weightedACos->Sumw2(false);
    
      weighted_50->Sumw2(false);
      weightedACos_50->Sumw2(false);
      weighted_aftercuts_50->Sumw2(false);
      weightedACos_aftercuts_50->Sumw2(false);
    
      weighted_200->Sumw2(false);
      weightedACos_200->Sumw2(false);
      weighted_aftercuts_200->Sumw2(false);
      weightedACos_aftercuts_200->Sumw2(false);
    
   
         weighted->Write();
      weightedACos->Write();
    
      weighted_50->Write();
      weightedACos_50->Write();
      weighted_aftercuts_50->Write();
      weightedACos_aftercuts_50->Write();
    
      weighted_200->Write();
      weightedACos_200->Write();
      weighted_aftercuts_200->Write();
      weightedACos_aftercuts_200->Write();
      
      gStyle->SetOptStat(111111111); 
    
 TCanvas * cpc=new TCanvas("scaled to POT","scaled to POT");

  // weighted->Scale(1.5586e+19*2.2e-8);
    // weighted->Sumw2(false);
   weighted->DrawCopy();


TCanvas * a=new TCanvas("angle 200");
weightedACos_aftercuts_200->Draw();
TCanvas * b=new TCanvas("energy 200");
weighted_aftercuts_200->Draw();

TCanvas * c=new TCanvas("angle 50");
weightedACos_aftercuts_50->Draw();
TCanvas * d=new TCanvas("energy 50");
weighted_aftercuts_50->Draw();




std::cout << "kept 50 e " << kept_e_50  << "kept 200 e " << kept_e_200 << " kept_a_50 " << kept_a_50 << " kept_a_200 " << kept_a_200 <<  "total sig" << sign_total << std::endl;

	    
myRootFile->Close();

   
    
}
