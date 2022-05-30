#define recTree_cxx
#include "recTree.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>



double recTree::MyAcos(double px,double py,double pz)
{
return acos(pz/sqrt(pow(px,2)+pow(py,2)+pow(pz,2)));
                                                               
}


void recTree::Loop()
{
//   In a ROOT session, you can do:
//      root> .L recTree.C
//      root> recTree t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//    This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//    Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
//    METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
//    METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//    by  b_branchname->GetEntry(ientry); //read only this branch

TTree * histTree=new TTree("histTree","histTree");

   if (fChain == 0) return;

	//COUNTER HISTOGRAMS
   TH1F * myprotonhist=new TH1F("Nprotons","Number of Protons Histogram;Number of Protons;Number of Events",11,-0.5,10.5);
   TH1F * myprotonhistwithE= new TH1F("Nprotons_withE","Nprotons_withE",11,-0.5,10.5);
   TH1F * myneutronhist=new TH1F("Nneutrons","Number of Neutrons Histogram;Number of Neutrons;Number of Events",11,-0.5,10.5);
   TH1F * myneutronhistwithE=new TH1F("Nneutrons_withE","Number of Neutrons Histogram;Number of Neutrons;Number of Events",11,-0.5,10.5);
   TH1F * mypion_n_hist=new TH1F("Npions_n","Number of Neutral Pions Histogram;Number of Neutral Pions;Number of Events",11,-0.5,10.5);
   TH1F * mypion_n_histwithE=new TH1F("Npions_n_withE","Npions_n_withE",11,-0.5,10.5);
   TH1F * mypion_c_hist=new TH1F("Npions_c","Number of Charged Pions Histogram;Number of Charged Pions;Number of Events",11,-0.5,10.5);
   TH1F * mypion_c_histwithE=new TH1F("Npions_c_withE","Npions_c_withE",11,-0.5,10.5);
   TH1F * mykaon_n_hist=new TH1F("Nkaon_n","Number of Neutral Kaons Histogram ;Number of Neutral Kaons;Number of Events",11,-0.5,10.5);
   TH1F * mykaon_n_histwithE=new TH1F("Nkaon_n_withE","Nkaon_n_withE",11,-0.5,10.5);
   TH1F * mykaon_c_hist=new TH1F("Nkaon_c","Number of Charged Kaons Histogram;Number of Charged Kaons;Number of Events",11,-0.5,10.5);
   TH1F * mykaon_c_histwithE=new TH1F("Nkaon_c_withE","Nkaon_c_withE",11,-0.5,10.5);
   TH1F * mymuon_hist=new TH1F("Nmuon","Number of Muons Histogram;Number of Muons;Number of Events",11,-0.5,10.5);
   TH1F * mymuon_histwithE=new TH1F("Nmuon_withE","Nmuon_withE",11,-0.5,10.5);
   TH1F * myelectron_hist=new TH1F("Nelectrons","Number of Electrons Histogram;Number of Electrons;Number of Events",11,-0.5,10.5);
   
  	//MULTIPLICITY HISTOGRAMS
   TH1F * new_electron_hist_50=new TH1F("Nelectrons_50","Number of Electrons (50>MeV);Number of Electrons; Number of Events",11,-0.5,10.5);
   TH1F * new_electron_hist_200=new TH1F("Nelectrons_200","Number of Electrons (200>MeV);Number of Electrons; Number of Events",11,-0.5,10.5);
   TH1F * new_pion_hist_50=new TH1F("Npions_50","Number of Neutral Pions (50MeV);Number of Pions; Number of Events",11,-0.5,10.5);
   TH1F * new_pion_hist_200=new TH1F("Npions_200","Number of Neutral Pions (200MeV);Number of Pions; Number of Events",11,-0.5,10.5);
   TH1F * new_gamma_hist_50=new TH1F("Ngamma_50","Number of Photons (50MeV);Number of Photons; Number of Events",11,-0.5,10.5);
   TH1F * new_gamma_hist_200=new TH1F("Ngamma_200","Number of Photons (200MeV);Number of Photons; Number of Events",11,-0.5,10.5);

	//CUT HISTOGRAMS
   TH1F * electron_energy_50_hist=new TH1F("electron_e_50_cut","Electron Energy Histogram (>50MeV) with volume,particle and shower cuts; Energy (GeV); Number of Events",20,0,2);
   TH1F * electron_energy_200_hist= new TH1F("electron_e_200_cut","Electron Energy Histogram (>200MeV) with volume,particle and shower cuts;Energy (GeV);Number of Events",20,0,2);
   TH1F * gamma_energy_50_hist=new TH1F("gamma_e_50_cut","Photon Energy Histogram (>50MeV) with volume,particle and shower cuts; Energy (GeV); Number of Events",20,0,2);
   TH1F * gamma_energy_200_hist=new TH1F("gamme_e_200_cut","Photon Energy Histogran(>200MeV) with volume,particle and shower cuts; Energy (GeV); Number of Events",20,0,2);

   TH1F * electron_angle_50_hist=new TH1F("electron_a_50_cut","Electron Angle Histogram (>50MeV) with volume,particle and shower cuts; Angle (rad); Number of Events",20,0,3.145);
   TH1F * electron_angle_200_hist=new TH1F("electron_a_200_cut","Electron Angle Histogram (>200MeV) with volume,particle and shower cuts; Angle (rad); Number of Events",20,0,3.145);
   TH1F * gamma_angle_50_hist=new TH1F("gamma_a_50_cut","Photon Angle Histogram (>50MeV) with volume,particle and shower cuts;Angle (rad);Number of Events",20,0,3.145);
   TH1F * gamma_angle_200_hist=new TH1F("gamma_a_200_cut","Photon Angle Histogram (>200MeV) with volume,particle and shower cuts;Angle (rad);Number of Events",20,0,3.145);

   //FINAL CUTS
     //VOLUME
   TH1F * electron_energy_50_v_hist=new TH1F("electron_e_v_50_cut","Electron Energy Histogram (>50MeV); Energies; Number of Events",20,0,2);
   TH1F * electron_energy_200_v_hist= new TH1F("electron_e_v_200_cut","Electron Energy Histogram (>200MeV) with volume,particle and shower cuts;Energy (GeV);Number of Events",20,0,2);
   TH1F * gamma_energy_50_v_hist=new TH1F("gamma_e_v_50_cut","Photon Energy Histogram (>50MeV); Energies; Number of Events",20,0,2);
   TH1F * gamma_energy_200_v_hist=new TH1F("gamme_e_v_200_cut","Photon Energy Histogran(>200MeV); Energies, Number of Events",20,0,2);

   TH1F * electron_angle_50_v_hist=new TH1F("electron_a_v_50_cut","Electron Angle Histogram (>50MeV); Angle; Number of Events",20,0,3.145);
   TH1F * electron_angle_200_v_hist=new TH1F("electron_a_v_200_cut","Electron Angle Histogram (>200MeV); Angle; Number of Events",20,0,3.145);
   TH1F * gamma_angle_50_v_hist=new TH1F("gamma_a_v_50_cut","Gamma Angle Histogram with cuts;Angle;Number of Events",20,0,3.145);
   TH1F * gamma_angle_200_v_hist=new TH1F("gamma_a_v_200_cut","Gamma Angle Histogram with cuts;Angle;Number of Events",20,0,3.145);

        //NPROTONS==0
   TH1F * electron_energy_50_proton_hist=new TH1F("electron_e_p_50_cut","Electron Energy Histogram (>50MeV); Energies; Number of Events",20,0,2);
   TH1F * electron_energy_200_proton_hist= new TH1F("electron_e_p_200_cut","Electron Energy Histogram (>200MeV);Energies,Number of Events",20,0,2);
   TH1F * gamma_energy_50_proton_hist=new TH1F("gamma_e_p_50_cut","Photon Energy Histogram (>50MeV); Energies; Number of Events",20,0,2);
   TH1F * gamma_energy_200_proton_hist=new TH1F("gamme_e_p_200_cut","Photon Energy Histogran(>200MeV); Energies, Number of Events",20,0,2);

   TH1F * electron_angle_50_proton_hist=new TH1F("electron_a_p_50_cut","Electron Angle Histogram (>50MeV); Angle; Number of Events",20,0,3.145);
   TH1F * electron_angle_200_proton_hist=new TH1F("electron_a_p_200_cut","Electron Angle Histogram (>200MeV); Angle; Number of Events",20,0,3.145);
   TH1F * gamma_angle_50_proton_hist=new TH1F("gamma_a_p_50_cut","Gamma Angle Histogram with cuts;Angle;Number of Events",20,0,3.145);
   TH1F * gamma_angle_200_proton_hist=new TH1F("gamma_a_p_200_cut","Gamma Angle Histogram with cuts;Angle;Number of Events",20,0,3.145);

        //NNEUTRON==0
   TH1F * electron_energy_50_neutron_hist=new TH1F("electron_e_n_50_cut","Electron Energy Histogram (>50MeV); Energies; Number of Events",20,0,2);
   TH1F * electron_energy_200_neutron_hist= new TH1F("electron_e_n_200_cut","Electron Energy Histogram (>200MeV);Energies,Number of Events",20,0,2);
   TH1F * gamma_energy_50_neutron_hist=new TH1F("gamma_e_n_50_cut","Photon Energy Histogram (>50MeV); Energies; Number of Events",20,0,2);
   TH1F * gamma_energy_200_neutron_hist=new TH1F("gamme_e_n_200_cut","Photon Energy Histogran(>200MeV); Energies, Number of Events",20,0,2);

   TH1F * electron_angle_50_neutron_hist=new TH1F("electron_a_n_50_cut","Electron Angle Histogram (>50MeV); Angle; Number of Events",20,0,3.145);
   TH1F * electron_angle_200_neutron_hist=new TH1F("electron_a_n_200_cut","Electron Angle Histogram (>200MeV); Angle; Number of Events",20,0,3.145);
   TH1F * gamma_angle_50_neutron_hist=new TH1F("gamma_a_n_50_cut","Gamma Angle Histogram with cuts;Angle;Number of Events",20,0,3.145);
   TH1F * gamma_angle_200_neutron_hist=new TH1F("gamma_a_n_200_cut","Gamma Angle Histogram with cuts;Angle;Number of Events",20,0,3.145);

        //NPIONS_C==0
   TH1F * electron_energy_50_pc_hist=new TH1F("electron_e_pc_50_cut","Electron Energy Histogram (>50MeV); Energies; Number of Events",20,0,2);
   TH1F * electron_energy_200_pc_hist= new TH1F("electron_e_pc_200_cut","Electron Energy Histogram (>200MeV);Energies,Number of Events",20,0,2);
   TH1F * gamma_energy_50_pc_hist=new TH1F("gamma_e_pc_50_cut","Photon Energy Histogram (>50MeV); Energies; Number of Events",20,0,2);
   TH1F * gamma_energy_200_pc_hist=new TH1F("gamme_e_pc_200_cut","Photon Energy Histogran(>200MeV); Energies, Number of Events",20,0,2);

   TH1F * electron_angle_50_pc_hist=new TH1F("electron_a_pc_50_cut","Electron Angle Histogram (>50MeV); Angle; Number of Events",20,0,3.145);
   TH1F * electron_angle_200_pc_hist=new TH1F("electron_a_pc_200_cut","Electron Angle Histogram (>200MeV); Angle; Number of Events",20,0,3.145);
   TH1F * gamma_angle_50_pc_hist=new TH1F("gamma_a_pc_50_cut","Gamma Angle Histogram with cuts;Angle;Number of Events",20,0,3.145);
   TH1F * gamma_angle_200_pc_hist=new TH1F("gamma_a_pc_200_cut","Gamma Angle Histogram with cuts;Angle;Number of Events",20,0,3.145);

          //NPIONS_N==0
   TH1F * electron_energy_50_pn_hist=new TH1F("electron_e_pn_50_cut","Electron Energy Histogram (>50MeV); Energies; Number of Events",20,0,2);
   TH1F * electron_energy_200_pn_hist= new TH1F("electron_e_pn_200_cut","Electron Energy Histogram (>200MeV);Energies,Number of Events",20,0,2);
   TH1F * gamma_energy_50_pn_hist=new TH1F("gamma_e_pn_50_cut","Photon Energy Histogram (>50MeV); Energies; Number of Events",20,0,2);
   TH1F * gamma_energy_200_pn_hist=new TH1F("gamme_e_pn_200_cut","Photon Energy Histogran(>200MeV); Energies, Number of Events",20,0,2);

   TH1F * electron_angle_50_pn_hist=new TH1F("electron_a_pn_50_cut","Electron Angle Histogram (>50MeV); Angle; Number of Events",20,0,3.145);
   TH1F * electron_angle_200_pn_hist=new TH1F("electron_a_pn_200_cut","Electron Angle Histogram (>200MeV); Angle; Number of Events",20,0,3.145);
   TH1F * gamma_angle_50_pn_hist=new TH1F("gamma_a_pn_50_cut","Gamma Angle Histogram with cuts;Angle;Number of Events",20,0,3.145);
   TH1F * gamma_angle_200_pn_hist=new TH1F("gamma_a_pn_200_cut","Gamma Angle Histogram with cuts;Angle;Number of Events",20,0,3.145);

          //KAONS_C==0
   TH1F * electron_energy_50_kc_hist=new TH1F("electron_e_kc_50_cut","Electron Energy Histogram (>50MeV); Energies; Number of Events",20,0,2);
   TH1F * electron_energy_200_kc_hist= new TH1F("electron_e_kc_200_cut","Electron Energy Histogram (>200MeV);Energies,Number of Events",20,0,2);
   TH1F * gamma_energy_50_kc_hist=new TH1F("gamma_e_kc_50_cut","Photon Energy Histogram (>50MeV); Energies; Number of Events",20,0,2);
   TH1F * gamma_energy_200_kc_hist=new TH1F("gamme_e_kc_200_cut","Photon Energy Histogran(>200MeV); Energies, Number of Events",20,0,2);

   TH1F * electron_angle_50_kc_hist=new TH1F("electron_a_kc_50_cut","Electron Angle Histogram (>50MeV); Angle; Number of Events",20,0,3.145);
   TH1F * electron_angle_200_kc_hist=new TH1F("electron_a_kc_200_cut","Electron Angle Histogram (>200MeV); Angle; Number of Events",20,0,3.145);
   TH1F * gamma_angle_50_kc_hist=new TH1F("gamma_a_kc_50_cut","Gamma Angle Histogram with cuts;Angle;Number of Events",20,0,3.145);
   TH1F * gamma_angle_200_kc_hist=new TH1F("gamma_a_kc_200_cut","Gamma Angle Histogram with cuts;Angle;Number of Events",20,0,3.145);

           //KAONS_N==0
   TH1F * electron_energy_50_kn_hist=new TH1F("electron_e_kn_50_cut","Electron Energy Histogram (>50MeV); Energies; Number of Events",20,0,2);
   TH1F * electron_energy_200_kn_hist= new TH1F("electron_e_kn_200_cut","Electron Energy Histogram (>200MeV);Energies,Number of Events",20,0,2);
   TH1F * gamma_energy_50_kn_hist=new TH1F("gamma_e_kn_50_cut","Photon Energy Histogram (>50MeV); Energies; Number of Events",20,0,2);
   TH1F * gamma_energy_200_kn_hist=new TH1F("gamme_e_kn_200_cut","Photon Energy Histogran(>200MeV); Energies, Number of Events",20,0,2);

   TH1F * electron_angle_50_kn_hist=new TH1F("electron_a_kn_50_cut","Electron Angle Histogram (>50MeV); Angle; Number of Events",20,0,3.145);
   TH1F * electron_angle_200_kn_hist=new TH1F("electron_a_kn_200_cut","Electron Angle Histogram (>200MeV); Angle; Number of Events",20,0,3.145);
   TH1F * gamma_angle_50_kn_hist=new TH1F("gamma_a_kn_50_cut","Gamma Angle Histogram with cuts;Angle;Number of Events",20,0,3.145);
   TH1F * gamma_angle_200_kn_hist=new TH1F("gamma_a_kn_200_cut","Gamma Angle Histogram with cuts;Angle;Number of Events",20,0,3.145);

         //MUON===0
   TH1F * electron_energy_50_m_hist=new TH1F("electron_e_kn_50_cut","Electron Energy Histogram (>50MeV); Energies; Number of Events",20,0,2);
   TH1F * electron_energy_200_m_hist= new TH1F("electron_e_kn_200_cut","Electron Energy Histogram (>200MeV);Energies,Number of Events",20,0,2);
   TH1F * gamma_energy_50_m_hist=new TH1F("gamma_e_kn_50_cut","Photon Energy Histogram (>50MeV); Energies; Number of Events",20,0,2);
   TH1F * gamma_energy_200_m_hist=new TH1F("gamme_e_kn_200_cut","Photon Energy Histogran(>200MeV); Energies, Number of Events",20,0,2);

   TH1F * electron_angle_50_m_hist=new TH1F("electron_a_m_50_cut","Electron Angle Histogram (>50MeV); Angle; Number of Events",20,0,3.145);
   TH1F * electron_angle_200_m_hist=new TH1F("electron_a_m_200_cut","Electron Angle Histogram (>200MeV); Angle; Number of Events",20,0,3.145);
   TH1F * gamma_angle_50_m_hist=new TH1F("gamma_a_m_50_cut","Gamma Angle Histogram with cuts;Angle;Number of Events",20,0,1.145);
   TH1F * gamma_angle_200_m_hist=new TH1F("gamma_a_m_200_cut","Gamma Angle Histogram with cuts;Angle;Number of Events",20,0,3.145);

        //GAMMA+ELEC==1
   TH1F * electron_energy_50_ge_hist=new TH1F("electron_e_ge_50_cut","Electron Energy Histogram (>50MeV) with vol, part and shower cuts; Energies; Number of Events",20,0,2);
   TH1F * electron_energy_200_ge_hist= new TH1F("electron_e_ge_200_cut","Electron Energy Histogram (>200MeV) with vol, part and shower cuts;Energies;Number of Events",20,0,2);
   TH1F * gamma_energy_50_ge_hist=new TH1F("gamma_e_ge_50_cut","Photon Energy Histogram (>50MeV) with vol, part and shower cuts; Energies; Number of Events",20,0,2);
   TH1F * gamma_energy_200_ge_hist=new TH1F("gamme_e_ge_200_cut","Photon Energy Histogran(>200MeV) with vol, part and shower cuts; Energies; Number of Events",20,0,2);

   TH1F * electron_angle_50_ge_hist=new TH1F("electron_a_ge_50_cut","Electron Angle Histogram (>50MeV) with vol, part and shower cuts; Angle; Number of Events",20,0,3.145);
   TH1F * electron_angle_200_ge_hist=new TH1F("electron_a_ge_200_cut","Electron Angle Histogram (>200MeV) with vol, part and shower cuts; Angle; Number of Events",20,0,3.145);
   TH1F * gamma_angle_50_ge_hist=new TH1F("gamma_a_ge_50_cut","Photon Angle Histogram (>50MeV) with vol, part and shower cuts;Angle;Number of Events",20,0,3.145);
   TH1F * gamma_angle_200_ge_hist=new TH1F("gamma_a_ge_200_cut","Photon Angle Histogram (>50MeV) with vol, part and shower cuts;Angle;Number of Events",20,0,3.145);

 //2212 is proton
 //2112 is neutron
 //+-211 is charged pion
 //111 is neutral pion
 //+- 321 charged kaon
 //311 neutral kaon
 //11 electron
 //31 muon
 //22 photon
 


 //HISTOGRAM CUTS
   double PROTONE_CUT=0.9682720882;
   double NEUTRON_CUT=0.9400442433;
   double PION_C_CUT=0.1399277846;
   double PION_N_CUT=0.1353467271;
   double KAON_C_CUT=0.4940819571;
   double KAON_N_CUT=0.4980127582;
   double MUON_CUT=0.1061574256;
 //MULTIPLICITY CUTS
   double PION_NEW_CUT_50=0.1849768;
   double PION_NEW_CUT_200=0.3349768;
   double ELECTRON_NEW_CUT_50=0.05051099895;
   double ELECTRON_NEW_CUT_200=0.200510999;
   double GAMMA_NEW_CUT_50=0.05;
   double GAMMA_NEW_CUT_200=0.2;

   int kept_elec_50=0;
   int kept_elec_200=0;
   int kept_gamma_50=0;
   int kept_gamma_200=0;



   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

      //HISTOGRAM COUNTERS
      int nprotons=0;
      int nprotons_withE=0;
      int nneutrons=0;
      int nneutrons_withE=0;
      int npion_n=0;
      int npion_n_withE=0;
      int npion_c=0;
      int npion_c_withE=0;
      int nelectron=0;
      int nkaon_n=0;
      int nkaon_n_withE=0;
      int nkaon_c=0;
      int nkaon_c_withE=0;
      int nmuon=0;
      int nmuon_withE=0;
      int nelectrons=0;

      //MULTIPLICITY COUNTERS
      int nelectron_50=0;
      int nelectron_200=0;
      int ngamma_50=0;
      int ngamma_200=0;
      int npion_50=0;
      int npion_200=0;

	      
      //LOOP FOR OVER THE RECTREE
      for(int ipart=0;ipart<true_particles_;ipart++)
      {
      if(true_particles_parent[ipart]==0)
      std::cout << "ipart " << ipart <<  " number of mc  " << true_particles_ << " pdg " << true_particles_pdg[ipart] << " parent " << true_particles_parent[ipart] << " genE " << true_particles_genE[ipart] << " genT " << true_particles_genT[ipart] << std::endl;
     
      if(true_particles_pdg[ipart]==2212 && true_particles_parent[ipart]==0)
      	{ nprotons ++; 
	if(true_particles_genE[ipart]> PROTONE_CUT)
	   nprotons_withE++;	
	}
      if(true_particles_pdg[ipart]==2112 && true_particles_parent[ipart]==0)
      	{ nneutrons++;
	if(true_particles_genE[ipart]> NEUTRON_CUT)
	   nneutrons_withE++;
	}
      if(true_particles_pdg[ipart]==111 && true_particles_parent[ipart]==0)
        { npion_n++;
        if(true_particles_genE[ipart]> PION_N_CUT)
         npion_n_withE++;
        }
      if((true_particles_pdg[ipart]==211 &&  true_particles_parent[ipart]==0) || (true_particles_pdg[ipart]==-211 && true_particles_parent[ipart]==0))
        { npion_c++;
        if(true_particles_genE[ipart]> PION_C_CUT)
          npion_c_withE++;
        }
      if((true_particles_pdg[ipart]==321 &&  true_particles_parent[ipart]==0) || (true_particles_pdg[ipart]==-321 && true_particles_parent[ipart]==0))
        { nkaon_c++;
        if(true_particles_genE[ipart]> KAON_C_CUT)
          nkaon_c_withE++;
        }
      if(true_particles_pdg[ipart]==311 && true_particles_parent[ipart]==0)
        { nkaon_c++;
        if(true_particles_genE[ipart]> KAON_N_CUT)
          nkaon_n_withE++;
        }
      if(true_particles_pdg[ipart]==31 && true_particles_parent[ipart]==0)
        { nmuon++;
        if(true_particles_genE[ipart]> MUON_CUT)
          nmuon_withE++;
        }
      if(true_particles_pdg[ipart]==11 && true_particles_parent[ipart]==0)
	{ nelectron++;
	}
      }
	//LOOP FOR THE ENERGY HISTOGRAM
   for(int thispart=0;thispart<true_particles_;thispart++)
      {

     double PartAcos=MyAcos(true_particles_genp_x[thispart],true_particles_genp_y[thispart],true_particles_genp_z[thispart]);

      if(true_particles_pdg[thispart]==22 && true_particles_parent[thispart]==0)
      {if(true_particles_genE[thispart]>GAMMA_NEW_CUT_50)
	{ ngamma_50++;
        if(true_particles_genE[thispart]>GAMMA_NEW_CUT_200)
	  ngamma_200++;
	}
      }
    else if(true_particles_pdg[thispart]==22 && true_particles_parent[thispart]!=0)
        {
         for(int innerpart=0;innerpart<true_particles_;innerpart++)
           {
              if(true_particles_pdg[innerpart]==111 && true_particles_G4ID[innerpart]==true_particles_parent[thispart]) // && true_particles_id[innerpart]== true_particles_parent[thispart])
	      {    	      
              std::cout << "gamma G4ID: " << true_particles_G4ID[thispart] << " gamma Interaction ID "<<  true_particles_interaction_id[thispart] << " gamma parent ID " <<  true_particles_parent[thispart]  << std::endl;
	     std::cout << "pion G4ID: " << true_particles_G4ID[innerpart] << " pion Interaction ID "<<  true_particles_interaction_id[innerpart] << std::endl;             std::cout << "pion daughters " << true_particles_daughters[innerpart].size();
	      for(int ii=0;ii<true_particles_daughters[innerpart].size();ii++)
                         std::cout << " " << true_particles_daughters[innerpart][ii];
	      std::cout << endl;
	      std::cout << endl;
	      std::cout << endl;
              }
	      else if(true_particles_G4ID[innerpart]==true_particles_parent[thispart] && true_particles_genE[thispart]>GAMMA_NEW_CUT_50 )
	      { 
	     std::cout << "parent G4ID: " << true_particles_G4ID[innerpart] << " parent pdg "<<  true_particles_pdg[innerpart] << " gamma energy " << true_particles_genE[thispart] << std::endl;
	     ngamma_50++;
	      }   
	      else if(true_particles_G4ID[innerpart]==true_particles_parent[thispart] && true_particles_genE[thispart]>GAMMA_NEW_CUT_200 )
		{
			ngamma_200++;
		
	   }
	   } 
	}

     if((true_particles_pdg[thispart]==11 && true_particles_parent[thispart]==0) || (true_particles_pdg[thispart]==-11 && true_particles_parent[thispart]==0))
       if(true_particles_genE[thispart]>ELECTRON_NEW_CUT_50)
       { nelectron_50++;
	 if(true_particles_genE[thispart]>ELECTRON_NEW_CUT_200)
	 nelectron_200++;
       }
     if((abs(true_particles_pdg[thispart])==11 && true_particles_parent[thispart]==0) && (true_particles_genE[thispart]>ELECTRON_NEW_CUT_50))
     {electron_angle_50_hist->Fill(PartAcos);
      electron_energy_50_hist->Fill(true_particles_genE[thispart]);
                if((-180<true_particles_start_x[thispart] && true_particles_start_x[thispart]<180) && (-180<true_particles_start_y[thispart] && true_particles_start_y[thispart]<180) && (20<true_particles_start_z[thispart] && true_particles_start_z[thispart]<480))
                {electron_energy_50_v_hist->Fill(true_particles_genE[thispart]);
                 electron_angle_50_v_hist->Fill(PartAcos);
                if(nprotons_withE==0)
                {electron_energy_50_proton_hist->Fill(true_particles_genE[thispart]);
                 electron_angle_50_proton_hist->Fill(PartAcos);
                if(npion_c_withE==0)
                {electron_energy_50_pc_hist->Fill(true_particles_genE[thispart]);
                 electron_angle_50_pc_hist->Fill(PartAcos);
                if(nkaon_n_withE==0)
                {electron_energy_50_kn_hist->Fill(true_particles_genE[thispart]);
                 electron_angle_50_kn_hist->Fill(PartAcos);
                if(nkaon_c_withE==0)
                {electron_energy_50_kc_hist->Fill(true_particles_genE[thispart]);
                 electron_angle_50_kc_hist->Fill(PartAcos);
                if(nmuon_withE==0)
                {electron_energy_50_m_hist->Fill(true_particles_genE[thispart]);
                 electron_angle_50_m_hist->Fill(PartAcos);
		if(ngamma_50+nelectron_50==1)
                {electron_energy_50_ge_hist->Fill(true_particles_genE[thispart]);
                 electron_angle_50_ge_hist->Fill(PartAcos);
		 kept_elec_50++;
                                 }}}}}}}
	if(true_particles_genE[thispart]>ELECTRON_NEW_CUT_200)
	{electron_angle_200_hist->Fill(PartAcos);
         electron_energy_200_hist->Fill(true_particles_genE[thispart]);          
             if((-180<true_particles_start_x[thispart] && true_particles_start_x[thispart]<180) && (-180<true_particles_start_y[thispart] && true_particles_start_y[thispart]<180) && (20<true_particles_start_z[thispart] && true_particles_start_z[thispart]<480))
                {electron_energy_200_v_hist->Fill(true_particles_genE[thispart]);
                 electron_angle_200_v_hist->Fill(PartAcos);
                if(nprotons_withE==0)
                {electron_energy_200_proton_hist->Fill(true_particles_genE[thispart]);
                 electron_angle_200_proton_hist->Fill(PartAcos);
                if(npion_c_withE==0)
                {electron_energy_200_pc_hist->Fill(true_particles_genE[thispart]);
                 electron_angle_200_pc_hist->Fill(PartAcos);
                if(nkaon_n_withE==0)
                {electron_energy_200_kn_hist->Fill(true_particles_genE[thispart]);
                 electron_angle_200_kn_hist->Fill(PartAcos);
                if(nkaon_c_withE==0)
                {electron_energy_200_kc_hist->Fill(true_particles_genE[thispart]);
                 electron_angle_200_kc_hist->Fill(PartAcos);
                if(nmuon_withE==0)
                {electron_energy_200_m_hist->Fill(true_particles_genE[thispart]);
                 electron_angle_200_m_hist->Fill(PartAcos);
                if(ngamma_200+nelectron_200==1)
                {electron_energy_200_ge_hist->Fill(true_particles_genE[thispart]);
                 electron_angle_200_ge_hist->Fill(PartAcos);
		 kept_elec_200++;
		}}}}}}}
	}
       	}
   if((true_particles_pdg[thispart]==22 && true_particles_parent[thispart]==0) && (true_particles_genE[thispart]>GAMMA_NEW_CUT_50))
      {gamma_angle_50_hist->Fill(PartAcos);
       gamma_energy_50_hist->Fill(true_particles_genE[thispart]);
	     if((-180<true_particles_start_x[thispart] && true_particles_start_x[thispart]<180) && (-180<true_particles_start_y[thispart] && true_particles_start_y[thispart]<180) && (20<true_particles_start_z[thispart] && true_particles_start_z[thispart]<480))
                {gamma_energy_50_v_hist->Fill(true_particles_genE[thispart]);
                 gamma_angle_50_v_hist->Fill(PartAcos);
                if(nprotons_withE==0)
                {gamma_energy_50_proton_hist->Fill(true_particles_genE[thispart]);
                 gamma_angle_50_proton_hist->Fill(PartAcos);
                if(npion_c_withE==0)
                {gamma_energy_50_pc_hist->Fill(true_particles_genE[thispart]);
                 gamma_angle_50_pc_hist->Fill(PartAcos);
                if(nkaon_n_withE==0)
                {gamma_energy_50_kn_hist->Fill(true_particles_genE[thispart]);
                 gamma_angle_50_kn_hist->Fill(PartAcos);
                if(nkaon_c_withE==0)
                {gamma_energy_50_kc_hist->Fill(true_particles_genE[thispart]);
                 gamma_angle_50_kc_hist->Fill(PartAcos);
                if(nmuon_withE==0)
                {gamma_energy_50_m_hist->Fill(true_particles_genE[thispart]);
                 gamma_angle_50_m_hist->Fill(PartAcos);
                if(ngamma_50+nelectron_50==1)
                {gamma_energy_50_ge_hist->Fill(true_particles_genE[thispart]);
                 gamma_angle_50_ge_hist->Fill(PartAcos);
		 kept_gamma_50++;
                                 }}}}}}}
        if(true_particles_genE[thispart]>GAMMA_NEW_CUT_200)
        {gamma_angle_200_hist->Fill(PartAcos);
         gamma_energy_200_hist->Fill(true_particles_genE[thispart]);
	     if((-180<true_particles_start_x[thispart] && true_particles_start_x[thispart]<180) && (-180<true_particles_start_y[thispart] && true_particles_start_y[thispart]<180) && (20<true_particles_start_z[thispart] && true_particles_start_z[thispart]<480))			
                {gamma_energy_200_v_hist->Fill(true_particles_genE[thispart]);
                 gamma_angle_200_v_hist->Fill(PartAcos);
                if(nprotons_withE==0)
                {gamma_energy_200_proton_hist->Fill(true_particles_genE[thispart]);
                 gamma_angle_200_proton_hist->Fill(PartAcos);
                if(npion_c_withE==0)
                {gamma_energy_200_pc_hist->Fill(true_particles_genE[thispart]);
                 gamma_angle_200_pc_hist->Fill(PartAcos);
                if(nkaon_n_withE==0)
                {gamma_energy_200_kn_hist->Fill(true_particles_genE[thispart]);
                 gamma_angle_200_kn_hist->Fill(PartAcos);
                if(nkaon_c_withE==0)
                {gamma_energy_200_kc_hist->Fill(true_particles_genE[thispart]);
                 gamma_angle_200_kc_hist->Fill(PartAcos);
                if(nmuon_withE==0)
                {gamma_energy_200_m_hist->Fill(true_particles_genE[thispart]);
                 gamma_angle_200_m_hist->Fill(PartAcos);
                if(ngamma_200+nelectron_200==1)
                {gamma_energy_200_ge_hist->Fill(true_particles_genE[thispart]);
                 gamma_angle_200_ge_hist->Fill(PartAcos);
		 kept_gamma_200++;
		}}}}}}}
        }
        }
      else if(true_particles_pdg[thispart]==22 && true_particles_parent[thispart]!=0)
        {
         for(int innerpart=0;innerpart<true_particles_;innerpart++)
           {
              if(true_particles_pdg[innerpart]==111 && true_particles_G4ID[innerpart]==true_particles_parent[thispart]) // && true_particles_id[innerpart]== true_particles_parent[thispart])
              {
            
              }
              else if(true_particles_G4ID[innerpart]==true_particles_parent[thispart] && true_particles_genE[thispart]>GAMMA_NEW_CUT_50 )
              {gamma_angle_50_hist->Fill(PartAcos);
               gamma_energy_50_hist->Fill(true_particles_genE[thispart]);
             if((-180<true_particles_start_x[thispart] && true_particles_start_x[thispart]<180) && (-180<true_particles_start_y[thispart] && true_particles_start_y[thispart]<180) && (20<true_particles_start_z[thispart] && true_particles_start_z[thispart]<480))
                {gamma_energy_50_v_hist->Fill(true_particles_genE[thispart]);
                 gamma_angle_50_v_hist->Fill(PartAcos);
                if(nprotons_withE==0)
                {gamma_energy_50_proton_hist->Fill(true_particles_genE[thispart]);
                 gamma_angle_50_proton_hist->Fill(PartAcos);
                if(npion_c_withE==0)
                {gamma_energy_50_pc_hist->Fill(true_particles_genE[thispart]);
                 gamma_angle_50_pc_hist->Fill(PartAcos);
                if(nkaon_n_withE==0)
                {gamma_energy_50_kn_hist->Fill(true_particles_genE[thispart]);
                 gamma_angle_50_kn_hist->Fill(PartAcos);
                if(nkaon_c_withE==0)
                {gamma_energy_50_kc_hist->Fill(true_particles_genE[thispart]);
                 gamma_angle_50_kc_hist->Fill(PartAcos);
                if(nmuon_withE==0)
                {gamma_energy_50_m_hist->Fill(true_particles_genE[thispart]);
                 gamma_angle_50_m_hist->Fill(PartAcos);
                if(ngamma_50+nelectron_50==1)
                {gamma_energy_50_ge_hist->Fill(true_particles_genE[thispart]);
                 gamma_angle_50_ge_hist->Fill(PartAcos);
		 kept_gamma_50++;
                                 }}}}}}}

              }
              else if(true_particles_G4ID[innerpart]==true_particles_parent[thispart] && true_particles_genE[thispart]>GAMMA_NEW_CUT_200 )
                {gamma_angle_200_hist->Fill(PartAcos);
         gamma_energy_200_hist->Fill(true_particles_genE[thispart]);
             if((-180<true_particles_start_x[thispart] && true_particles_start_x[thispart]<180) && (-180<true_particles_start_y[thispart] && true_particles_start_y[thispart]<180) && (20<true_particles_start_z[thispart] && true_particles_start_z[thispart]<480))
                {gamma_energy_200_v_hist->Fill(true_particles_genE[thispart]);
                 gamma_angle_200_v_hist->Fill(PartAcos);
                if(nprotons_withE==0)
                {gamma_energy_200_proton_hist->Fill(true_particles_genE[thispart]);
                 gamma_angle_200_proton_hist->Fill(PartAcos);
                if(npion_c_withE==0)
                {gamma_energy_200_pc_hist->Fill(true_particles_genE[thispart]);
                 gamma_angle_200_pc_hist->Fill(PartAcos);
                if(nkaon_n_withE==0)
                {gamma_energy_200_kn_hist->Fill(true_particles_genE[thispart]);
                 gamma_angle_200_kn_hist->Fill(PartAcos);
                if(nkaon_c_withE==0)
                {gamma_energy_200_kc_hist->Fill(true_particles_genE[thispart]);
                 gamma_angle_200_kc_hist->Fill(PartAcos);
                if(nmuon_withE==0)
                {gamma_energy_200_m_hist->Fill(true_particles_genE[thispart]);
                 gamma_angle_200_m_hist->Fill(PartAcos);
                if(ngamma_200+nelectron_200==1)
                {gamma_energy_200_ge_hist->Fill(true_particles_genE[thispart]);
                 gamma_angle_200_ge_hist->Fill(PartAcos);
		 kept_gamma_200++;
                                 }}}}}}}

                }
           }

        }

      }  

      
	//FILLING THE COUNTER HISTOGRAMS
     myprotonhist->Fill(nprotons);
     myprotonhistwithE->Fill(nprotons_withE);
     myneutronhist->Fill(nneutrons);
     myneutronhistwithE->Fill(nneutrons_withE);
     mypion_n_hist->Fill(npion_n);
     mypion_n_histwithE->Fill(npion_n_withE);
     mypion_c_hist->Fill(npion_c);
     mypion_c_histwithE->Fill(npion_c_withE);
     mykaon_c_hist->Fill(nkaon_c);
     mykaon_c_histwithE->Fill(nkaon_c_withE);
     mykaon_n_hist->Fill(nkaon_n);
     mykaon_n_histwithE->Fill(nkaon_n_withE);
     mymuon_hist->Fill(nmuon);
     mymuon_histwithE->Fill(nmuon_withE);
     myelectron_hist->Fill(nelectron);
	
     //MULTIPLICITY HISTOGRAM
     new_electron_hist_50->Fill(nelectron_50);
     new_electron_hist_200->Fill(nelectron_200);
     new_pion_hist_50->Fill(npion_50);
     new_pion_hist_200->Fill(npion_200);
     new_gamma_hist_50->Fill(ngamma_50);
     new_gamma_hist_200->Fill(ngamma_200);

     // if (ientry >100) break;
      // if (Cut(ientry) < 0) continue;
      }
 

//COUNTER HISTOGRAM PLOTTING
{
TCanvas * one=new TCanvas("one");
myprotonhist->DrawCopy();
myprotonhistwithE->SetLineColor(kRed);
myprotonhistwithE->DrawCopy("same");

TLegend* legend = new TLegend(0.5,0.7,0.9,0.9);
legend->AddEntry(myprotonhist,"Number of Protons","l");
legend->AddEntry(myprotonhistwithE,"Number of Protons with E>30MeV","l");
legend->Draw();
}
{
TCanvas * two=new TCanvas("two");
myneutronhistwithE->SetLineColor(kRed);
myneutronhistwithE->DrawCopy();
myneutronhist->DrawCopy("same");

TLegend* legend = new TLegend(0.5,0.7,0.9,0.9);
legend->AddEntry(myneutronhist,"Number of Neutrons","l");
legend->AddEntry(myneutronhistwithE,"Number of Neutrons with E>30MeV","l");
legend->Draw();
}
{
TCanvas * three=new TCanvas("three");
mypion_n_hist->DrawCopy();
mypion_n_histwithE->SetLineColor(kRed);
mypion_n_histwithE->DrawCopy("same");

TLegend* legend = new TLegend(0.5,0.7,0.9,0.9);
legend->AddEntry(mypion_n_hist,"Number of Neutral Pions","l");
legend->AddEntry(mypion_n_histwithE,"Number of Neutral Pions with E>10MeV","l");
legend->Draw();
}
{
TCanvas * four=new TCanvas("four");
mypion_c_hist->DrawCopy();
mypion_c_histwithE->SetLineColor(kRed);
mypion_c_histwithE->DrawCopy("same");

TLegend* legend = new TLegend(0.5,0.7,0.9,0.9);
legend->AddEntry(mypion_c_hist,"Number of Charged Pions","l");
legend->AddEntry(mypion_c_histwithE,"Number of Charged Pions with E>10MeV","l");
legend->Draw();
}
{
TCanvas * five=new TCanvas("five");
mykaon_n_hist->DrawCopy();
mykaon_n_histwithE->SetLineColor(kRed);
mykaon_n_histwithE->DrawCopy("same");

TLegend* legend = new TLegend(0.5,0.7,0.9,0.9);
legend->AddEntry(mykaon_n_hist,"Number of Neutral Kaons","l");
legend->AddEntry(mykaon_n_histwithE,"Number of Neutral Kaons with E>10MeV","l");
legend->Draw();
}
{
TCanvas * six=new TCanvas("six");
mykaon_c_hist->DrawCopy();
mykaon_c_histwithE->SetLineColor(kRed);
mykaon_c_histwithE->DrawCopy("same");

TLegend* legend = new TLegend(0.5,0.7,0.9,0.9);
legend->AddEntry(mykaon_c_hist,"Number of Charged Kaons","l");
legend->AddEntry(mykaon_c_histwithE,"Number of Charged Kaons with E>10MeV","l");
legend->Draw();
}
{
TCanvas * seven=new TCanvas("seven");
mymuon_hist->DrawCopy();
mymuon_histwithE->SetLineColor(kRed);
mymuon_histwithE->DrawCopy("same");

TLegend* legend = new TLegend(0.5,0.7,0.9,0.9);
legend->AddEntry(mymuon_hist,"Number of Muons","l");
legend->AddEntry(mymuon_histwithE,"Number of Muons with E>10MeV","l");
legend->Draw();
}
{
TCanvas * eight=new TCanvas("eight");
myelectron_hist->DrawCopy();

TLegend* legend = new TLegend(0.5,0.7,0.9,0.9);
legend->AddEntry(myelectron_hist,"Number of Electrons","l");
legend->Draw();
}

//MULTIPLICITY HISTOGRAM PLOTTING
//TCanvas * nine=new TCanvas("nine");
//new_electron_hist_50->DrawCopy();
//new_electron_hist_200->SetLineColor(kRed);
//new_electron_hist_200->DrawCopy("same");
//TCanvas * ten=new TCanvas("ten");
//new_gamma_hist_50->DrawCopy();
//new_gamma_hist_200->SetLineColor(kRed);
//new_gamma_hist_200->DrawCopy("same");
//TCanvas * eleven=new TCanvas("eleven");
//new_pion_hist_50->DrawCopy();
//new_pion_hist_200->SetLineColor(kRed);
//new_pion_hist_200->DrawCopy("same");
gStyle->SetOptStat(0);


// ENERGY AND ANGLE HISTOGRAMS
	//energy
{
TCanvas * twelve=new TCanvas("twelve");
electron_energy_50_hist->Draw();
electron_energy_50_hist->SetFillColorAlpha(kBlue-7,0.35);
electron_energy_50_v_hist->SetLineColor(kRed);
electron_energy_50_v_hist->SetFillColorAlpha(kRed-7,0.35);
electron_energy_50_v_hist->Draw("same");
electron_energy_50_m_hist->SetLineColor(kGreen);
electron_energy_50_m_hist->SetFillColorAlpha(kGreen-7,0.35);
electron_energy_50_m_hist->Draw("same");
electron_energy_50_ge_hist->SetLineColor(kOrange);
electron_energy_50_ge_hist->SetFillColorAlpha(kOrange-7,0.35);
electron_energy_50_ge_hist->Draw("same");


TLegend* legend = new TLegend(0.5,0.7,0.9,0.9);
legend->AddEntry(electron_energy_50_hist,"Electron Energy with E>50MeV","f");
legend->AddEntry(electron_energy_50_v_hist,"Electron Energy with fid.Vol cut","f");
legend->AddEntry(electron_energy_50_m_hist,"Electron Energy with particle cuts","f");
legend->AddEntry(electron_energy_50_ge_hist,"Electron Energy with one shower event","f");
legend->Draw();
}


{
TCanvas * thirteen=new TCanvas("thirteen");
electron_energy_200_hist->Draw();
electron_energy_200_hist->SetFillColorAlpha(kBlue-7,0.35);
electron_energy_200_v_hist->SetLineColor(kRed);
electron_energy_200_v_hist->SetFillColorAlpha(kRed-7,0.35);
electron_energy_200_v_hist->Draw("same");
electron_energy_200_m_hist->SetLineColor(kGreen);
electron_energy_200_m_hist->SetFillColorAlpha(kGreen-7,0.35);
electron_energy_200_m_hist->Draw("same");
electron_energy_200_ge_hist->SetLineColor(kOrange);
electron_energy_200_ge_hist->SetFillColorAlpha(kOrange-7,0.35);
electron_energy_200_ge_hist->Draw("same");

TLegend* legend = new TLegend(0.5,0.7,0.9,0.9);
legend->AddEntry(electron_energy_200_hist,"Electron Energy with E>200MeV","f");
legend->AddEntry(electron_energy_200_v_hist,"Electron Energy with fid.Vol cut","f");
legend->AddEntry(electron_energy_200_m_hist,"Electron Energy with particle cuts","f");
legend->AddEntry(electron_energy_200_ge_hist,"Electron Energy with one shower event","f");
legend->Draw();
}

{
TCanvas * fourteen=new TCanvas("fourteen");
gamma_energy_50_hist->Draw();
gamma_energy_50_hist->SetFillColorAlpha(kBlue-7,0.35);
gamma_energy_50_v_hist->SetLineColor(kRed);
gamma_energy_50_v_hist->SetFillColorAlpha(kRed-7,0.35);
gamma_energy_50_v_hist->Draw("same");
gamma_energy_50_m_hist->SetLineColor(kGreen);
gamma_energy_50_m_hist->SetFillColorAlpha(kGreen-7,0.35);
gamma_energy_50_m_hist->Draw("same");
gamma_energy_50_ge_hist->SetLineColor(kOrange);
gamma_energy_50_ge_hist->SetFillColorAlpha(kOrange-7,0.35);
gamma_energy_50_ge_hist->Draw("same");

TLegend* legend = new TLegend(0.5,0.7,0.9,0.9);
legend->AddEntry(gamma_energy_50_hist,"Photon Energy with E>50MeV","f");
legend->AddEntry(gamma_energy_50_v_hist,"Photon Energy with fid.Vol cut","f");
legend->AddEntry(gamma_energy_50_m_hist,"Photon Energy with particle cuts","f");
legend->AddEntry(gamma_energy_50_ge_hist,"Photon Energy with one shower event","f");
legend->Draw();
}

{
TCanvas * fifteen=new TCanvas("fifteen");
gamma_energy_200_hist->Draw();
gamma_energy_200_hist->SetFillColorAlpha(kBlue-7,0.35);
gamma_energy_200_v_hist->SetLineColor(kRed);
gamma_energy_200_v_hist->SetFillColorAlpha(kRed-7,0.35);
gamma_energy_200_v_hist->Draw("same");
gamma_energy_200_m_hist->SetLineColor(kGreen);
gamma_energy_200_m_hist->SetFillColorAlpha(kGreen-7,0.35);
gamma_energy_200_m_hist->Draw("same");
gamma_energy_200_ge_hist->SetLineColor(kOrange);
gamma_energy_200_ge_hist->SetFillColorAlpha(kOrange-7,0.35);
gamma_energy_200_ge_hist->Draw("same");

TLegend* legend = new TLegend(0.5,0.7,0.9,0.9);
legend->AddEntry(gamma_energy_50_hist,"Photon Energy with E>200MeV","f");
legend->AddEntry(gamma_energy_50_v_hist,"Photon Energy with fid.Vol cut","f");
legend->AddEntry(gamma_energy_50_m_hist,"Photon Energy with particle cuts","f");
legend->AddEntry(gamma_energy_50_ge_hist,"Photon Energy with one shower event","f");
legend->Draw();
}


	//angle
{
TCanvas * sixteen=new TCanvas("sixteen");
electron_angle_50_hist->Draw();
electron_angle_50_hist->SetFillColorAlpha(kBlue-7,0.35);
electron_angle_50_v_hist->SetLineColor(kRed);
electron_angle_50_v_hist->SetFillColorAlpha(kRed-7,0.35);
electron_angle_50_v_hist->Draw("same");
electron_angle_50_m_hist->SetLineColor(kGreen);
electron_angle_50_m_hist->SetFillColorAlpha(kGreen-7,0.35);
electron_angle_50_m_hist->Draw("same");
electron_angle_50_ge_hist->SetLineColor(kOrange);
electron_angle_50_ge_hist->SetFillColorAlpha(kOrange-7,0.35);
electron_angle_50_ge_hist->Draw("same");

TLegend* legend = new TLegend(0.5,0.7,0.9,0.9);
legend->AddEntry(electron_angle_50_hist,"Electron Angle with E>50MeV","f");
legend->AddEntry(electron_angle_50_v_hist,"Electron Angle with fid.Vol cut","f");
legend->AddEntry(electron_angle_50_m_hist,"Electron Angle with particle cuts","f");
legend->AddEntry(electron_angle_50_ge_hist,"Electron Angle with one shower event","f");
legend->Draw();
}

{
TCanvas * seventeen=new TCanvas("seventeen");
electron_angle_200_hist->Draw();
electron_angle_200_hist->SetFillColorAlpha(kBlue-7,0.35);
electron_angle_200_v_hist->SetLineColor(kRed);
electron_angle_200_v_hist->SetFillColorAlpha(kRed-7,0.35);
electron_angle_200_v_hist->Draw("same");
electron_angle_200_m_hist->SetLineColor(kGreen);
electron_angle_200_m_hist->SetFillColorAlpha(kGreen-7,0.35);
electron_angle_200_m_hist->Draw("same");
electron_angle_200_ge_hist->SetLineColor(kOrange);
electron_angle_200_ge_hist->SetFillColorAlpha(kOrange-7,0.35);
electron_angle_200_ge_hist->Draw("same");

TLegend* legend = new TLegend(0.5,0.7,0.9,0.9);
legend->AddEntry(electron_angle_200_hist,"Electron Angle with E>200MeV","f");
legend->AddEntry(electron_angle_200_v_hist,"Electron Angle with fid.Vol cut","f");
legend->AddEntry(electron_angle_200_m_hist,"Electron Angle with particle cuts","f");
legend->AddEntry(electron_angle_200_ge_hist,"Electron Angle with one shower event","f");
legend->Draw();
}

{
TCanvas * eighteen=new TCanvas("eighteen");
gamma_angle_50_hist->Draw();
gamma_angle_50_hist->SetFillColorAlpha(kBlue-7,0.35);
gamma_angle_50_v_hist->SetLineColor(kRed);
gamma_angle_50_v_hist->SetFillColorAlpha(kRed-7,0.35);
gamma_angle_50_v_hist->Draw("same");
gamma_angle_50_m_hist->SetLineColor(kGreen);
gamma_angle_50_m_hist->SetFillColorAlpha(kGreen-7,0.35);
gamma_angle_50_m_hist->Draw("same");
gamma_angle_50_ge_hist->SetLineColor(kOrange);
gamma_angle_50_ge_hist->SetFillColorAlpha(kOrange-7,0.35);
gamma_angle_50_ge_hist->Draw("same");

TLegend* legend = new TLegend(0.5,0.7,0.9,0.9);
legend->AddEntry(gamma_angle_50_hist,"Photon Angle with E>50MeV","f");
legend->AddEntry(gamma_angle_50_v_hist,"Photon Angle with fid.Vol cut","f");
legend->AddEntry(gamma_angle_50_m_hist,"Photon Angle with particle cuts","f");
legend->AddEntry(gamma_angle_50_ge_hist,"Photon Angle with one shower event","f");
legend->Draw();
}

{
TCanvas * nineteen=new TCanvas("nineteen");
gamma_angle_200_hist->Draw();
gamma_angle_200_hist->SetFillColorAlpha(kBlue-7,0.35);
gamma_angle_200_v_hist->SetLineColor(kRed);
gamma_angle_200_v_hist->SetFillColorAlpha(kRed-7,0.35);
gamma_angle_200_v_hist->Draw("same");
gamma_angle_200_m_hist->SetLineColor(kGreen);
gamma_angle_200_m_hist->SetFillColorAlpha(kGreen-7,0.35);
gamma_angle_200_m_hist->Draw("same");
gamma_angle_200_ge_hist->SetLineColor(kOrange);
gamma_angle_200_ge_hist->SetFillColorAlpha(kOrange-7,0.35);
gamma_angle_200_ge_hist->Draw("same");

TLegend* legend = new TLegend(0.5,0.7,0.9,0.9);
legend->AddEntry(gamma_angle_200_hist,"Photon Angle with E>200MeV","f");
legend->AddEntry(gamma_angle_200_v_hist,"Photon Angle with fid.Vol cut","f");
legend->AddEntry(gamma_angle_200_m_hist,"Photon Angle with particle cuts","f");
legend->AddEntry(gamma_angle_200_ge_hist,"Photon Angle with one shower event","f");
legend->Draw();
}

//File stuff

TFile * myRootFile=new TFile("histTree.root","RECREATE");

electron_energy_50_ge_hist->Write();
electron_energy_200_ge_hist->Write();
gamma_energy_50_ge_hist->Write();
gamma_energy_200_ge_hist->Write();
electron_angle_50_ge_hist->Write();
electron_angle_200_ge_hist->Write();
gamma_angle_50_ge_hist->Write();
gamma_angle_200_ge_hist->Write();


std::cout << "kept_elec_50 " << kept_elec_50 << " kept_elec_200" << kept_elec_200 <<" kept_gamma_50 "<<  kept_gamma_50 << " kept_gamma_200 " << kept_gamma_200 << std::endl;
myRootFile->Close();


}

