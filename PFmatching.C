#include <TFile.h>
#include <TTree.h>
#include <TBranch.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TString.h>
#include <iostream>
#include <TBenchmark.h>

using namespace std;

void PFmatching (float a, float b) {

gBenchmark->Start("running time");    
    
TFile *inputfile  = new TFile("flatTree_QCD_Pt-15to7000_TuneCP5_Flat2018_13TeV_pythia8_training_PU+noPU_EXT.root", "READ" );

 int runNo, evtNo, lumiSec, nPFCands, nPFCands_noPU, nAK4PUPPIJets, nAK4PUPPIJets_noPU, nAK4CHSJets, nAK4CHSJets_noPU;
 vector <float> PFCandPt, PFCandEta, PFCandAbsEta, PFCandPhi, PFCandE, PFCandPt_noPU, PFCandEta_noPU, PFCandPhi_noPU, PFCandE_noPU, PFCandpdgId, PFCandCharge, PFCandPUPPIw, PFCandHCalFrac, PFCandHCalFracCalib, PFCandVtxAssQual, PFCandFromPV, PFCandLostInnerHits, PFCandTrackHighPurity, PFCandDZ, PFCandDXY, PFCandDZsig, PFCandDXYsig, PFCandNormChi2, PFCandQuality, AK4PUPPIJetPt, AK4PUPPIJetRawPt, AK4PUPPIJetEta, AK4PUPPIJetPhi, AK4PUPPIJetE, AK4PUPPIJetRawE, AK4PUPPIJetPt_noPU, AK4PUPPIJetRawPt_noPU, AK4PUPPIJetEta_noPU, AK4PUPPIJetPhi_noPU, AK4PUPPIJetE_noPU, AK4PUPPIJetRawE_noPU, AK4CHSJetPt, AK4CHSJetRawPt, AK4CHSJetEta, AK4CHSJetPhi, AK4CHSJetE, AK4CHSJetRawE, AK4CHSJetPt_noPU, AK4CHSJetRawPt_noPU, AK4CHSJetEta_noPU, AK4CHSJetPhi_noPU, AK4CHSJetE_noPU, AK4CHSJetRawE_noPU;
vector <int> PFCandIsPU;
TFile * outputfile  = new TFile( "flatTree_QCD_Pt-15to7000_TuneCP5_Flat2018_13TeV_pythia8_ABCnet_training.root", "RECREATE" );

TTree * flatTree = new TTree( "events", "events" );
flatTree->SetAutoSave(30000); // do not autosave tree until 30k events

flatTree->Branch("runNo", &runNo, "runNo/I");
flatTree->Branch("evtNo", &evtNo, "evtNo/I");
flatTree->Branch("lumiSec", &lumiSec, "lumiSec/I");
flatTree->Branch("nPFCands", &nPFCands, "nPFCands/I");
flatTree->Branch("PFCandPt", &PFCandPt);
flatTree->Branch("PFCandEta", &PFCandEta);
flatTree->Branch("PFCandAbsEta", &PFCandAbsEta);
flatTree->Branch("PFCandPhi", &PFCandPhi);
flatTree->Branch("PFCandE", &PFCandE);
flatTree->Branch("nPFCands_noPU", &nPFCands_noPU, "nPFCands_noPU/I");
flatTree->Branch("PFCandPt_noPU", &PFCandPt_noPU);
flatTree->Branch("PFCandEta_noPU", &PFCandEta_noPU);
flatTree->Branch("PFCandPhi_noPU", &PFCandPhi_noPU);
flatTree->Branch("PFCandE_noPU", &PFCandE_noPU);
flatTree->Branch("PFCandpdgId", &PFCandpdgId);
flatTree->Branch("PFCandCharge", &PFCandCharge);
flatTree->Branch("PFCandPUPPIw", &PFCandPUPPIw);
flatTree->Branch("PFCandHCalFrac", &PFCandHCalFrac);
flatTree->Branch("PFCandHCalFracCalib", &PFCandHCalFracCalib);
flatTree->Branch("PFCandVtxAssQual", &PFCandVtxAssQual);
flatTree->Branch("PFCandFromPV", &PFCandFromPV);
flatTree->Branch("PFCandLostInnerHits", &PFCandLostInnerHits);
flatTree->Branch("PFCandTrackHighPurity", &PFCandTrackHighPurity);
flatTree->Branch("PFCandDZ", &PFCandDZ);
flatTree->Branch("PFCandDXY", &PFCandDXY);
flatTree->Branch("PFCandDZsig", &PFCandDZsig);
flatTree->Branch("PFCandDXYsig", &PFCandDXYsig);
flatTree->Branch("PFCandNormChi2", &PFCandNormChi2);
flatTree->Branch("PFCandQuality", &PFCandQuality);
flatTree->Branch("PFCandIsPU", &PFCandIsPU);
flatTree->Branch("nAK4PUPPIJets", &nAK4PUPPIJets);
flatTree->Branch("AK4PUPPIJetPt", &AK4PUPPIJetPt);
flatTree->Branch("AK4PUPPIJetRawPt", &AK4PUPPIJetRawPt);
flatTree->Branch("AK4PUPPIJetEta", &AK4PUPPIJetEta);
flatTree->Branch("AK4PUPPIJetPhi", &AK4PUPPIJetPhi);
flatTree->Branch("AK4PUPPIJetE", &AK4PUPPIJetE);
flatTree->Branch("AK4PUPPIJetRawE", &AK4PUPPIJetRawE);
flatTree->Branch("nAK4PUPPIJets_noPU", &nAK4PUPPIJets_noPU);
flatTree->Branch("AK4PUPPIJetPt_noPU", &AK4PUPPIJetPt_noPU);
flatTree->Branch("AK4PUPPIJetRawPt_noPU", &AK4PUPPIJetRawPt_noPU);
flatTree->Branch("AK4PUPPIJetEta_noPU", &AK4PUPPIJetEta_noPU);
flatTree->Branch("AK4PUPPIJetPhi_noPU", &AK4PUPPIJetPhi_noPU);
flatTree->Branch("AK4PUPPIJetE_noPU", &AK4PUPPIJetE_noPU);
flatTree->Branch("AK4PUPPIJetRawE_noPU", &AK4PUPPIJetRawE_noPU);
flatTree->Branch("nAK4CHSJets", &nAK4CHSJets);
flatTree->Branch("AK4CHSJetPt", &AK4CHSJetPt);
flatTree->Branch("AK4CHSJetRawPt", &AK4CHSJetRawPt);
flatTree->Branch("AK4CHSJetEta", &AK4CHSJetEta);
flatTree->Branch("AK4CHSJetPhi", &AK4CHSJetPhi);
flatTree->Branch("AK4CHSJetE", &AK4CHSJetE);
flatTree->Branch("AK4CHSJetRawE", &AK4CHSJetRawE);
flatTree->Branch("nAK4CHSJets_noPU", &nAK4CHSJets_noPU);
flatTree->Branch("AK4CHSJetPt_noPU", &AK4CHSJetPt_noPU);
flatTree->Branch("AK4CHSJetRawPt_noPU", &AK4CHSJetRawPt_noPU);
flatTree->Branch("AK4CHSJetEta_noPU", &AK4CHSJetEta_noPU);
flatTree->Branch("AK4CHSJetPhi_noPU", &AK4CHSJetPhi_noPU);
flatTree->Branch("AK4CHSJetE_noPU", &AK4CHSJetE_noPU);
flatTree->Branch("AK4CHSJetRawE_noPU", &AK4CHSJetRawE_noPU);

TTree *evt = (TTree*)inputfile->Get( "events" );

int myrunNo = 0;
evt->SetBranchAddress( "runNo", &myrunNo );

int myevtNo = 0;
evt->SetBranchAddress( "evtNo", &myevtNo );

int mylumiSec = 0;
evt->SetBranchAddress( "lumiSec", &mylumiSec );

int mynPFCands_noPU = 0;
evt->SetBranchAddress( "nPFCands_noPU", &mynPFCands_noPU );

int mynPFCands_PU = 0;
evt->SetBranchAddress( "nPFCands_PU", &mynPFCands_PU );
  
vector<float> *myPFCandPt_noPU = 0;
evt->SetBranchAddress( "PFCandPt_noPU", &myPFCandPt_noPU );

vector<float> *myPFCandPt_PU = 0;
evt->SetBranchAddress( "PFCandPt_PU", &myPFCandPt_PU );

vector<float> *myPFCandEta_noPU = 0;
evt->SetBranchAddress( "PFCandEta_noPU", &myPFCandEta_noPU );

vector<float> *myPFCandEta_PU = 0;
evt->SetBranchAddress( "PFCandEta_PU", &myPFCandEta_PU );

vector<float> *myPFCandAbsEta_PU = 0;
evt->SetBranchAddress( "PFCandAbsEta_PU", &myPFCandAbsEta_PU );

vector<float> *myPFCandPhi_noPU = 0;
evt->SetBranchAddress( "PFCandPhi_noPU", &myPFCandPhi_noPU );

vector<float> *myPFCandPhi_PU = 0;
evt->SetBranchAddress( "PFCandPhi_PU", &myPFCandPhi_PU );

vector<float> *myPFCandE_noPU = 0;
evt->SetBranchAddress( "PFCandE_noPU", &myPFCandE_noPU );

vector<float> *myPFCandE_PU = 0;
evt->SetBranchAddress( "PFCandE_PU", &myPFCandE_PU );

vector<float> *myPFCandpdgId_PU = 0;
evt->SetBranchAddress( "PFCandpdgId_PU", &myPFCandpdgId_PU );

vector<float> *myPFCandCharge_PU = 0;
evt->SetBranchAddress( "PFCandCharge_PU", &myPFCandCharge_PU );

vector<float> *myPFCandPUPPIw_PU = 0;
evt->SetBranchAddress( "PFCandPUPPIw_PU", &myPFCandPUPPIw_PU );

vector<float> *myPFCandHCalFrac_PU = 0;
evt->SetBranchAddress( "PFCandHCalFrac_PU", &myPFCandHCalFrac_PU );

vector<float> *myPFCandHCalFracCalib_PU = 0;
evt->SetBranchAddress( "PFCandHCalFracCalib_PU", &myPFCandHCalFracCalib_PU );

vector<float> *myPFCandVtxAssQual_PU = 0;
evt->SetBranchAddress( "PFCandVtxAssQual_PU", &myPFCandVtxAssQual_PU );

vector<float> *myPFCandFromPV_PU = 0;
evt->SetBranchAddress( "PFCandFromPV_PU", &myPFCandFromPV_PU );

vector<float> *myPFCandLostInnerHits_PU = 0;
evt->SetBranchAddress( "PFCandLostInnerHits_PU", &myPFCandLostInnerHits_PU );

vector<float> *myPFCandTrackHighPurity_PU = 0;
evt->SetBranchAddress( "PFCandTrackHighPurity_PU", &myPFCandTrackHighPurity_PU );

vector<float> *myPFCandDZ_PU = 0;
evt->SetBranchAddress( "PFCandDZ_PU", &myPFCandDZ_PU );

vector<float> *myPFCandDXY_PU = 0;
evt->SetBranchAddress( "PFCandDXY_PU", &myPFCandDXY_PU );

vector<float> *myPFCandDZsig_PU = 0;
evt->SetBranchAddress( "PFCandDZsig_PU", &myPFCandDZsig_PU );

vector<float> *myPFCandDXYsig_PU = 0;
evt->SetBranchAddress( "PFCandDXYsig_PU", &myPFCandDXYsig_PU );

vector<float> *myPFCandNormChi2_PU = 0;
evt->SetBranchAddress( "PFCandNormChi2_PU", &myPFCandNormChi2_PU );

vector<float> *myPFCandQuality_PU = 0;
evt->SetBranchAddress( "PFCandQuality_PU", &myPFCandQuality_PU );

int mynAK4PUPPIJets_PU = 0;
evt->SetBranchAddress( "nAK4PUPPIJets_PU", &mynAK4PUPPIJets_PU );

vector<float> *myAK4PUPPIJetPt_PU = 0;
evt->SetBranchAddress( "AK4PUPPIJetPt_PU", &myAK4PUPPIJetPt_PU );

vector<float> *myAK4PUPPIJetRawPt_PU = 0;
evt->SetBranchAddress( "AK4PUPPIJetRawPt_PU", &myAK4PUPPIJetRawPt_PU );

vector<float> *myAK4PUPPIJetEta_PU = 0;
evt->SetBranchAddress( "AK4PUPPIJetEta_PU", &myAK4PUPPIJetEta_PU );

vector<float> *myAK4PUPPIJetPhi_PU = 0;
evt->SetBranchAddress( "AK4PUPPIJetPhi_PU", &myAK4PUPPIJetPhi_PU );

vector<float> *myAK4PUPPIJetE_PU = 0;
evt->SetBranchAddress( "AK4PUPPIJetE_PU", &myAK4PUPPIJetE_PU );

vector<float> *myAK4PUPPIJetRawE_PU = 0;
evt->SetBranchAddress( "AK4PUPPIJetRawE_PU", &myAK4PUPPIJetRawE_PU );

int mynAK4PUPPIJets_noPU = 0;
evt->SetBranchAddress( "nAK4PUPPIJets_noPU", &mynAK4PUPPIJets_noPU );

vector<float> *myAK4PUPPIJetPt_noPU = 0;
evt->SetBranchAddress( "AK4PUPPIJetPt_noPU", &myAK4PUPPIJetPt_noPU );

vector<float> *myAK4PUPPIJetRawPt_noPU = 0;
evt->SetBranchAddress( "AK4PUPPIJetRawPt_noPU", &myAK4PUPPIJetRawPt_noPU );

vector<float> *myAK4PUPPIJetEta_noPU = 0;
evt->SetBranchAddress( "AK4PUPPIJetEta_noPU", &myAK4PUPPIJetEta_noPU );

vector<float> *myAK4PUPPIJetPhi_noPU = 0;
evt->SetBranchAddress( "AK4PUPPIJetPhi_noPU", &myAK4PUPPIJetPhi_noPU );

vector<float> *myAK4PUPPIJetE_noPU = 0;
evt->SetBranchAddress( "AK4PUPPIJetE_noPU", &myAK4PUPPIJetE_noPU );

vector<float> *myAK4PUPPIJetRawE_noPU = 0;
evt->SetBranchAddress( "AK4PUPPIJetRawE_noPU", &myAK4PUPPIJetRawE_noPU );

int mynAK4CHSJets_PU = 0;
evt->SetBranchAddress( "nAK4CHSJets_PU", &mynAK4CHSJets_PU );

vector<float> *myAK4CHSJetPt_PU = 0;
evt->SetBranchAddress( "AK4CHSJetPt_PU", &myAK4CHSJetPt_PU );

vector<float> *myAK4CHSJetRawPt_PU = 0;
evt->SetBranchAddress( "AK4CHSJetRawPt_PU", &myAK4CHSJetRawPt_PU );

vector<float> *myAK4CHSJetEta_PU = 0;
evt->SetBranchAddress( "AK4CHSJetEta_PU", &myAK4CHSJetEta_PU );

vector<float> *myAK4CHSJetPhi_PU = 0;
evt->SetBranchAddress( "AK4CHSJetPhi_PU", &myAK4CHSJetPhi_PU );

vector<float> *myAK4CHSJetE_PU = 0;
evt->SetBranchAddress( "AK4CHSJetE_PU", &myAK4CHSJetE_PU );

vector<float> *myAK4CHSJetRawE_PU = 0;
evt->SetBranchAddress( "AK4CHSJetRawE_PU", &myAK4CHSJetRawE_PU );

int mynAK4CHSJets_noPU = 0;
evt->SetBranchAddress( "nAK4CHSJets_noPU", &mynAK4CHSJets_noPU );

vector<float> *myAK4CHSJetPt_noPU = 0;
evt->SetBranchAddress( "AK4CHSJetPt_noPU", &myAK4CHSJetPt_noPU );

vector<float> *myAK4CHSJetRawPt_noPU = 0;
evt->SetBranchAddress( "AK4CHSJetRawPt_noPU", &myAK4CHSJetRawPt_noPU );

vector<float> *myAK4CHSJetEta_noPU = 0;
evt->SetBranchAddress( "AK4CHSJetEta_noPU", &myAK4CHSJetEta_noPU );

vector<float> *myAK4CHSJetPhi_noPU = 0;
evt->SetBranchAddress( "AK4CHSJetPhi_noPU", &myAK4CHSJetPhi_noPU );

vector<float> *myAK4CHSJetE_noPU = 0;
evt->SetBranchAddress( "AK4CHSJetE_noPU", &myAK4CHSJetE_noPU );

vector<float> *myAK4CHSJetRawE_noPU = 0;
evt->SetBranchAddress( "AK4CHSJetRawE_noPU", &myAK4CHSJetRawE_noPU );

Long64_t nevents = evt->GetEntries();
  
  
    for ( Long64_t ievent = 0; ievent < nevents; ++ievent ){
      
//         if (ievent > 11) break;

    
    //get i-th entry in tree
    evt->GetEntry( ievent );
    
    runNo = myrunNo;
    evtNo = myevtNo;
    lumiSec = mylumiSec;
    nPFCands = mynPFCands_PU;
    nPFCands_noPU = mynPFCands_noPU;
    nAK4PUPPIJets = mynAK4PUPPIJets_PU;
    nAK4PUPPIJets_noPU = mynAK4PUPPIJets_noPU;
    nAK4CHSJets = mynAK4CHSJets_PU;
    nAK4CHSJets_noPU = mynAK4CHSJets_noPU;
    
    float number_of_PVPFCands_found = 0;
    float number_of_PVPFCands_found_relptcut = 0;
    
    for (int i = 0; i < mynPFCands_PU; i++) {
        
        PFCandIsPU.push_back(1); //at the beginning, loop over particles in the PU file and assign pileup label to all particles...
        PFCandPt.push_back(myPFCandPt_PU->at(i));
        PFCandEta.push_back(myPFCandEta_PU->at(i));
        PFCandAbsEta.push_back(myPFCandAbsEta_PU->at(i));
        PFCandPhi.push_back(myPFCandPhi_PU->at(i));
        PFCandE.push_back(myPFCandE_PU->at(i));
        PFCandpdgId.push_back(myPFCandpdgId_PU->at(i));
        PFCandCharge.push_back(myPFCandCharge_PU->at(i));
        PFCandPUPPIw.push_back(myPFCandPUPPIw_PU->at(i));
        PFCandHCalFrac.push_back(myPFCandHCalFrac_PU->at(i));
        PFCandHCalFracCalib.push_back(myPFCandHCalFracCalib_PU->at(i));
        PFCandVtxAssQual.push_back(myPFCandVtxAssQual_PU->at(i));
        PFCandFromPV.push_back(myPFCandFromPV_PU->at(i));
        PFCandLostInnerHits.push_back(myPFCandLostInnerHits_PU->at(i));
        PFCandTrackHighPurity.push_back(myPFCandTrackHighPurity_PU->at(i));
        PFCandDZ.push_back(myPFCandDZ_PU->at(i));
        PFCandDXY.push_back(myPFCandDXY_PU->at(i));
        PFCandDZsig.push_back(myPFCandDZsig_PU->at(i));
        PFCandDXYsig.push_back(myPFCandDXYsig_PU->at(i));
        PFCandNormChi2.push_back(myPFCandNormChi2_PU->at(i));
        PFCandQuality.push_back(myPFCandQuality_PU->at(i));
        
        
        
    }
    
    for (int PFCand_noPU = 0; PFCand_noPU < mynPFCands_noPU; PFCand_noPU++) {
        
        //if (PFCand_noPU%100 == 0) cout << "PFCand_noPU # " << PFCand_noPU << endl;
        
        PFCandPt_noPU.push_back(myPFCandPt_noPU->at(PFCand_noPU));
        PFCandEta_noPU.push_back(myPFCandEta_noPU->at(PFCand_noPU));
        PFCandPhi_noPU.push_back(myPFCandPhi_noPU->at(PFCand_noPU));
        PFCandE_noPU.push_back(myPFCandE_noPU->at(PFCand_noPU));
        

        double deltaRmin = 10.0;
        int whichPFCand = -1;
        double pt_rel_change = 0.0;
        
        for (int PFCand_PU = 0; PFCand_PU < mynPFCands_PU; PFCand_PU++) {
            
        float deltaEta = fabs(myPFCandEta_noPU->at(PFCand_noPU) - myPFCandEta_PU->at(PFCand_PU));
        float deltaPhi = fabs(myPFCandPhi_noPU->at(PFCand_noPU) - myPFCandPhi_PU->at(PFCand_PU));
        
        if (deltaPhi > 3.14159265358979323846) deltaPhi = 2*3.14159265358979323846 - deltaPhi;
        
        float deltaR = sqrt(pow(deltaEta, 2) + pow(deltaPhi,2));
        float deltaPt = myPFCandPt_PU->at(PFCand_PU) - myPFCandPt_noPU->at(PFCand_noPU);
        
        if (deltaR < deltaRmin) {
            
            deltaRmin = deltaR;
            pt_rel_change = deltaPt/myPFCandPt_noPU->at(PFCand_noPU);
            whichPFCand = PFCand_PU;
            
        }
        
        }
        
        if ( deltaRmin < a ) {
            
            number_of_PVPFCands_found++;
            
            if ( pt_rel_change < b ) {
                
                number_of_PVPFCands_found_relptcut++;
                PFCandIsPU.at(whichPFCand) = 0;
                
            }
        }
        
        
    }
    
    for (int AK4PUPPIJet = 0; AK4PUPPIJet  < mynAK4PUPPIJets_PU; AK4PUPPIJet++) {
        
        AK4PUPPIJetPt.push_back(myAK4PUPPIJetPt_PU->at(AK4PUPPIJet));
	AK4PUPPIJetRawPt.push_back(myAK4PUPPIJetRawPt_PU->at(AK4PUPPIJet));
        AK4PUPPIJetEta.push_back(myAK4PUPPIJetEta_PU->at(AK4PUPPIJet));
        AK4PUPPIJetPhi.push_back(myAK4PUPPIJetPhi_PU->at(AK4PUPPIJet));
        AK4PUPPIJetE.push_back(myAK4PUPPIJetE_PU->at(AK4PUPPIJet));
	AK4PUPPIJetRawE.push_back(myAK4PUPPIJetRawE_PU->at(AK4PUPPIJet));
    }

    for (int AK4PUPPIJet_noPU = 0; AK4PUPPIJet_noPU  < mynAK4PUPPIJets_noPU; AK4PUPPIJet_noPU++) {
        
        AK4PUPPIJetPt_noPU.push_back(myAK4PUPPIJetPt_noPU->at(AK4PUPPIJet_noPU));
	AK4PUPPIJetRawPt_noPU.push_back(myAK4PUPPIJetRawPt_noPU->at(AK4PUPPIJet_noPU));
        AK4PUPPIJetEta_noPU.push_back(myAK4PUPPIJetEta_noPU->at(AK4PUPPIJet_noPU));
        AK4PUPPIJetPhi_noPU.push_back(myAK4PUPPIJetPhi_noPU->at(AK4PUPPIJet_noPU));
        AK4PUPPIJetE_noPU.push_back(myAK4PUPPIJetE_noPU->at(AK4PUPPIJet_noPU));
	AK4PUPPIJetRawE_noPU.push_back(myAK4PUPPIJetRawE_noPU->at(AK4PUPPIJet_noPU));
    }

    for (int AK4CHSJet = 0; AK4CHSJet  < mynAK4CHSJets_PU; AK4CHSJet++) {

      AK4CHSJetPt.push_back(myAK4CHSJetPt_PU->at(AK4CHSJet));
      AK4CHSJetRawPt.push_back(myAK4CHSJetRawPt_PU->at(AK4CHSJet));
      AK4CHSJetEta.push_back(myAK4CHSJetEta_PU->at(AK4CHSJet));
      AK4CHSJetPhi.push_back(myAK4CHSJetPhi_PU->at(AK4CHSJet));
      AK4CHSJetE.push_back(myAK4CHSJetE_PU->at(AK4CHSJet));
      AK4CHSJetRawE.push_back(myAK4CHSJetRawE_PU->at(AK4CHSJet));
    }

    for (int AK4CHSJet_noPU = 0; AK4CHSJet_noPU  < mynAK4CHSJets_noPU; AK4CHSJet_noPU++) {

      AK4CHSJetPt_noPU.push_back(myAK4CHSJetPt_noPU->at(AK4CHSJet_noPU));
      AK4CHSJetRawPt_noPU.push_back(myAK4CHSJetRawPt_noPU->at(AK4CHSJet_noPU));
      AK4CHSJetEta_noPU.push_back(myAK4CHSJetEta_noPU->at(AK4CHSJet_noPU));
      AK4CHSJetPhi_noPU.push_back(myAK4CHSJetPhi_noPU->at(AK4CHSJet_noPU));
      AK4CHSJetE_noPU.push_back(myAK4CHSJetE_noPU->at(AK4CHSJet_noPU));
      AK4CHSJetRawE_noPU.push_back(myAK4CHSJetRawE_noPU->at(AK4CHSJet_noPU));
    }
    
    if ( !( ievent % 1000 ) ) {
        
    cout << "ievent = " << ievent << endl;
    cout << "Number of LV PF candidates: " << mynPFCands_noPU << endl;
    cout << "Number of LV PF candidates found: " << number_of_PVPFCands_found << endl;
    cout << "Percentage of LV PF candidates found: " << number_of_PVPFCands_found/mynPFCands_noPU*100.0 << "%" << endl;
    cout << "Number of LV PF candidates found after relptcut: " << number_of_PVPFCands_found_relptcut << endl;
    cout << "Percentage of LV PF candidates found after relptcut: " << number_of_PVPFCands_found_relptcut/mynPFCands_noPU*100.0 << "%" << endl;
    
        
    }
    
    flatTree->Fill();
    PFCandIsPU.clear(); 
    PFCandPt.clear();
    PFCandEta.clear();
    PFCandAbsEta.clear();
    PFCandPhi.clear();
    PFCandE.clear();
    PFCandPt_noPU.clear();
    PFCandEta_noPU.clear();
    PFCandPhi_noPU.clear();
    PFCandE_noPU.clear();
    PFCandpdgId.clear();
    PFCandCharge.clear();
    PFCandPUPPIw.clear();
    PFCandHCalFrac.clear();
    PFCandHCalFracCalib.clear();
    PFCandVtxAssQual.clear();
    PFCandFromPV.clear();
    PFCandLostInnerHits.clear();
    PFCandTrackHighPurity.clear();
    PFCandDZ.clear();
    PFCandDXY.clear();
    PFCandDZsig.clear();
    PFCandDXYsig.clear();
    PFCandNormChi2.clear();
    PFCandQuality.clear();
    AK4PUPPIJetPt.clear();
    AK4PUPPIJetRawPt.clear();
    AK4PUPPIJetEta.clear();
    AK4PUPPIJetPhi.clear();
    AK4PUPPIJetE.clear();
    AK4PUPPIJetRawE.clear();
    AK4PUPPIJetPt_noPU.clear();
    AK4PUPPIJetRawPt_noPU.clear();
    AK4PUPPIJetEta_noPU.clear();
    AK4PUPPIJetPhi_noPU.clear();
    AK4PUPPIJetE_noPU.clear();
    AK4PUPPIJetRawE_noPU.clear();
    AK4CHSJetPt.clear();
    AK4CHSJetRawPt.clear();
    AK4CHSJetEta.clear();
    AK4CHSJetPhi.clear();
    AK4CHSJetE.clear();
    AK4CHSJetRawE.clear();
    AK4CHSJetPt_noPU.clear();
    AK4CHSJetRawPt_noPU.clear();
    AK4CHSJetEta_noPU.clear();
    AK4CHSJetPhi_noPU.clear();
    AK4CHSJetE_noPU.clear();
    AK4CHSJetRawE_noPU.clear();
    }

flatTree->Write();
gBenchmark->Show("running time");
outputfile->Close();
delete outputfile;

}
