#include <TFile.h>
#include <TTree.h>
#include <TBranch.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TString.h>
#include <TBenchmark.h>
#include <iostream>

using namespace std;

void createTreePU_noPU () {

gBenchmark->Start("running time");    
    
TFile *inputfile_noPU  = new TFile("flatTree_QCD_Pt-15to7000_TuneCP5_Flat2018_13TeV_pythia8_training_noPU_EXT_sorted.root", "READ" );

TFile *inputfile_PU  = new TFile("flatTree_QCD_Pt-15to7000_TuneCP5_Flat2018_13TeV_pythia8_training_PU_EXT_sorted.root", "READ" );

int runNo, evtNo, lumiSec, nPFCands_PU, nPFCands_noPU, nAK4PUPPIJets_PU, nAK4PUPPIJets_noPU, nAK4CHSJets_PU, nAK4CHSJets_noPU;
 vector <float> PFCandPt_PU, PFCandPt_noPU, PFCandEta_PU, PFCandEta_noPU, PFCandAbsEta_PU, PFCandPhi_PU, PFCandPhi_noPU, PFCandE_PU, PFCandE_noPU, PFCandpdgId_PU, PFCandCharge_PU, PFCandPUPPIw_PU, PFCandHCalFrac_PU, PFCandHCalFracCalib_PU, PFCandVtxAssQual_PU, PFCandFromPV_PU, PFCandLostInnerHits_PU, PFCandTrackHighPurity_PU, PFCandDZ_PU, PFCandDXY_PU, PFCandDZsig_PU, PFCandDXYsig_PU, PFCandNormChi2_PU, PFCandQuality_PU, AK4PUPPIJetPt_PU, AK4PUPPIJetRawPt_PU, AK4PUPPIJetEta_PU, AK4PUPPIJetPhi_PU, AK4PUPPIJetE_PU, AK4PUPPIJetRawE_PU, AK4PUPPIJetPt_noPU, AK4PUPPIJetRawPt_noPU, AK4PUPPIJetEta_noPU, AK4PUPPIJetPhi_noPU, AK4PUPPIJetE_noPU, AK4PUPPIJetRawE_noPU, AK4CHSJetPt_PU, AK4CHSJetRawPt_PU, AK4CHSJetEta_PU, AK4CHSJetPhi_PU, AK4CHSJetE_PU, AK4CHSJetRawE_PU, AK4CHSJetPt_noPU, AK4CHSJetRawPt_noPU, AK4CHSJetEta_noPU, AK4CHSJetPhi_noPU, AK4CHSJetE_noPU, AK4CHSJetRawE_noPU;

TFile * outputfile  = new TFile( "flatTree_QCD_Pt-15to7000_TuneCP5_Flat2018_13TeV_pythia8_training_PU+noPU_EXT.root", "RECREATE" );
// TFile * outputfile  = new TFile( "asdasd.root", "RECREATE" );
TTree * flatTree = new TTree( "events", "events" );
flatTree->Branch("runNo", &runNo, "runNo/I");
flatTree->Branch("evtNo", &evtNo, "evtNo/I");
flatTree->Branch("lumiSec", &lumiSec, "lumiSec/I");
flatTree->Branch("nPFCands_noPU", &nPFCands_noPU, "nPFCands_noPU/I");
flatTree->Branch("nPFCands_PU", &nPFCands_PU, "nPFCands_PU/I");
flatTree->Branch("PFCandPt_noPU", &PFCandPt_noPU);
flatTree->Branch("PFCandPt_PU", &PFCandPt_PU);
flatTree->Branch("PFCandEta_noPU", &PFCandEta_noPU);
flatTree->Branch("PFCandEta_PU", &PFCandEta_PU);
flatTree->Branch("PFCandEta_noPU", &PFCandEta_noPU);
flatTree->Branch("PFCandEta_PU", &PFCandEta_PU);
flatTree->Branch("PFCandAbsEta_PU", &PFCandAbsEta_PU);
flatTree->Branch("PFCandPhi_noPU", &PFCandPhi_noPU);
flatTree->Branch("PFCandPhi_PU", &PFCandPhi_PU);
flatTree->Branch("PFCandE_noPU", &PFCandE_noPU);
flatTree->Branch("PFCandE_PU", &PFCandE_PU);
flatTree->Branch("PFCandpdgId_PU", &PFCandpdgId_PU);
flatTree->Branch("PFCandCharge_PU", &PFCandCharge_PU);
flatTree->Branch("PFCandPUPPIw_PU", &PFCandPUPPIw_PU);
flatTree->Branch("PFCandHCalFrac_PU", &PFCandHCalFrac_PU);
flatTree->Branch("PFCandHCalFracCalib_PU", &PFCandHCalFracCalib_PU);
flatTree->Branch("PFCandVtxAssQual_PU", &PFCandVtxAssQual_PU);
flatTree->Branch("PFCandFromPV_PU", &PFCandFromPV_PU);
flatTree->Branch("PFCandLostInnerHits_PU", &PFCandLostInnerHits_PU);
flatTree->Branch("PFCandTrackHighPurity_PU", &PFCandTrackHighPurity_PU);
flatTree->Branch("PFCandDZ_PU", &PFCandDZ_PU);
flatTree->Branch("PFCandDXY_PU", &PFCandDXY_PU);
flatTree->Branch("PFCandDZsig_PU", &PFCandDZsig_PU);
flatTree->Branch("PFCandDXYsig_PU", &PFCandDXYsig_PU);
flatTree->Branch("PFCandNormChi2_PU", &PFCandNormChi2_PU);
flatTree->Branch("PFCandQuality_PU", &PFCandQuality_PU);
flatTree->Branch("nAK4PUPPIJets_PU", &nAK4PUPPIJets_PU);
flatTree->Branch("AK4PUPPIJetPt_PU", &AK4PUPPIJetPt_PU);
flatTree->Branch("AK4PUPPIJetRawPt_PU", &AK4PUPPIJetRawPt_PU);
flatTree->Branch("AK4PUPPIJetEta_PU", &AK4PUPPIJetEta_PU);
flatTree->Branch("AK4PUPPIJetPhi_PU", &AK4PUPPIJetPhi_PU);
flatTree->Branch("AK4PUPPIJetE_PU", &AK4PUPPIJetE_PU);
flatTree->Branch("AK4PUPPIJetRawE_PU", &AK4PUPPIJetRawE_PU);
flatTree->Branch("nAK4PUPPIJets_noPU", &nAK4PUPPIJets_noPU);
flatTree->Branch("AK4PUPPIJetPt_noPU", &AK4PUPPIJetPt_noPU);
flatTree->Branch("AK4PUPPIJetRawPt_noPU", &AK4PUPPIJetRawPt_noPU);
flatTree->Branch("AK4PUPPIJetEta_noPU", &AK4PUPPIJetEta_noPU);
flatTree->Branch("AK4PUPPIJetPhi_noPU", &AK4PUPPIJetPhi_noPU);
flatTree->Branch("AK4PUPPIJetE_noPU", &AK4PUPPIJetE_noPU);
flatTree->Branch("AK4PUPPIJetRawE_noPU", &AK4PUPPIJetRawE_noPU);
flatTree->Branch("nAK4CHSJets_PU", &nAK4CHSJets_PU);
flatTree->Branch("AK4CHSJetPt_PU", &AK4CHSJetPt_PU);
flatTree->Branch("AK4CHSJetRawPt_PU", &AK4CHSJetRawPt_PU);
flatTree->Branch("AK4CHSJetEta_PU", &AK4CHSJetEta_PU);
flatTree->Branch("AK4CHSJetPhi_PU", &AK4CHSJetPhi_PU);
flatTree->Branch("AK4CHSJetE_PU", &AK4CHSJetE_PU);
flatTree->Branch("AK4CHSJetRawE_PU", &AK4CHSJetRawE_PU);
flatTree->Branch("nAK4CHSJets_noPU", &nAK4CHSJets_noPU);
flatTree->Branch("AK4CHSJetPt_noPU", &AK4CHSJetPt_noPU);
flatTree->Branch("AK4CHSJetRawPt_noPU", &AK4CHSJetRawPt_noPU);
flatTree->Branch("AK4CHSJetEta_noPU", &AK4CHSJetEta_noPU);
flatTree->Branch("AK4CHSJetPhi_noPU", &AK4CHSJetPhi_noPU);
flatTree->Branch("AK4CHSJetE_noPU", &AK4CHSJetE_noPU);
flatTree->Branch("AK4CHSJetRawE_noPU", &AK4CHSJetRawE_noPU);

TTree *evt_noPU = (TTree*)inputfile_noPU->Get( "events_sorted" );

UInt_t myrunNo_noPU = 0;
evt_noPU->SetBranchAddress( "runNo", &myrunNo_noPU );

UInt_t myevtNo_noPU = 0;
evt_noPU->SetBranchAddress( "evtNo", &myevtNo_noPU );

UInt_t mylumiSec_noPU = 0;
evt_noPU->SetBranchAddress( "lumiSec", &mylumiSec_noPU );

UInt_t mynPFCands_noPU = 0;
evt_noPU->SetBranchAddress( "nPFCands", &mynPFCands_noPU );

vector<float> *myPFCandPt_noPU = 0;
evt_noPU->SetBranchAddress( "PFCandPt", &myPFCandPt_noPU );

vector<float> *myPFCandEta_noPU = 0;
evt_noPU->SetBranchAddress( "PFCandEta", &myPFCandEta_noPU );

vector<float> *myPFCandPhi_noPU = 0;
evt_noPU->SetBranchAddress( "PFCandPhi", &myPFCandPhi_noPU );

vector<float> *myPFCandE_noPU = 0;
evt_noPU->SetBranchAddress( "PFCandE", &myPFCandE_noPU );

UInt_t mynAK4PUPPIJets_noPU = 0;
evt_noPU->SetBranchAddress( "nAK4PUPPIJets", &mynAK4PUPPIJets_noPU );

vector<float> *myAK4PUPPIJetPt_noPU = 0;
evt_noPU->SetBranchAddress( "AK4PUPPIJetPt", &myAK4PUPPIJetPt_noPU );

vector<float> *myAK4PUPPIJetRawPt_noPU = 0;
evt_noPU->SetBranchAddress( "AK4PUPPIJetRawPt", &myAK4PUPPIJetRawPt_noPU );

vector<float> *myAK4PUPPIJetEta_noPU = 0;
evt_noPU->SetBranchAddress( "AK4PUPPIJetEta", &myAK4PUPPIJetEta_noPU );

vector<float> *myAK4PUPPIJetPhi_noPU = 0;
evt_noPU->SetBranchAddress( "AK4PUPPIJetPhi", &myAK4PUPPIJetPhi_noPU );

vector<float> *myAK4PUPPIJetE_noPU = 0;
evt_noPU->SetBranchAddress( "AK4PUPPIJetE", &myAK4PUPPIJetE_noPU );

vector<float> *myAK4PUPPIJetRawE_noPU = 0;
evt_noPU->SetBranchAddress( "AK4PUPPIJetRawE", &myAK4PUPPIJetRawE_noPU );

UInt_t mynAK4CHSJets_noPU = 0;
evt_noPU->SetBranchAddress( "nAK4CHSJets", &mynAK4CHSJets_noPU );

vector<float> *myAK4CHSJetPt_noPU = 0;
evt_noPU->SetBranchAddress( "AK4CHSJetPt", &myAK4CHSJetPt_noPU );

vector<float> *myAK4CHSJetRawPt_noPU = 0;
evt_noPU->SetBranchAddress( "AK4CHSJetRawPt", &myAK4CHSJetRawPt_noPU );

vector<float> *myAK4CHSJetEta_noPU = 0;
evt_noPU->SetBranchAddress( "AK4CHSJetEta", &myAK4CHSJetEta_noPU );

vector<float> *myAK4CHSJetPhi_noPU = 0;
evt_noPU->SetBranchAddress( "AK4CHSJetPhi", &myAK4CHSJetPhi_noPU );

vector<float> *myAK4CHSJetE_noPU = 0;
evt_noPU->SetBranchAddress( "AK4CHSJetE", &myAK4CHSJetE_noPU );

vector<float> *myAK4CHSJetRawE_noPU = 0;
evt_noPU->SetBranchAddress( "AK4CHSJetRawE", &myAK4CHSJetRawE_noPU );

Long64_t nevents_noPU = evt_noPU->GetEntries();





TTree *evt_PU = (TTree*)inputfile_PU->Get( "events_sorted" );

UInt_t myrunNo_PU = 0;
evt_PU->SetBranchAddress( "runNo", &myrunNo_PU );

UInt_t myevtNo_PU = 0;
evt_PU->SetBranchAddress( "evtNo", &myevtNo_PU);

UInt_t mylumiSec_PU = 0;
evt_PU->SetBranchAddress( "lumiSec", &mylumiSec_PU );

UInt_t mynPFCands_PU = 0;
evt_PU->SetBranchAddress( "nPFCands", &mynPFCands_PU );

vector<float> *myPFCandPt_PU = 0;
evt_PU->SetBranchAddress( "PFCandPt", &myPFCandPt_PU );

vector<float> *myPFCandEta_PU = 0;
evt_PU->SetBranchAddress( "PFCandEta", &myPFCandEta_PU );

vector<float> *myPFCandAbsEta_PU = 0;
evt_PU->SetBranchAddress( "PFCandAbsEta", &myPFCandAbsEta_PU );

vector<float> *myPFCandPhi_PU = 0;
evt_PU->SetBranchAddress( "PFCandPhi", &myPFCandPhi_PU );

vector<float> *myPFCandE_PU = 0;
evt_PU->SetBranchAddress( "PFCandE", &myPFCandE_PU );

vector<float> *myPFCandpdgId_PU = 0;
evt_PU->SetBranchAddress( "PFCandpdgId", &myPFCandpdgId_PU );

vector<float> *myPFCandCharge_PU = 0;
evt_PU->SetBranchAddress( "PFCandCharge", &myPFCandCharge_PU );

vector<float> *myPFCandPUPPIw_PU = 0;
evt_PU->SetBranchAddress( "PFCandPUPPIw", &myPFCandPUPPIw_PU );

vector<float> *myPFCandHCalFrac_PU = 0;
evt_PU->SetBranchAddress( "PFCandHCalFrac", &myPFCandHCalFrac_PU );

vector<float> *myPFCandHCalFracCalib_PU = 0;
evt_PU->SetBranchAddress( "PFCandHCalFracCalib", &myPFCandHCalFracCalib_PU );

vector<float> *myPFCandVtxAssQual_PU = 0;
evt_PU->SetBranchAddress( "PFCandVtxAssQual", &myPFCandVtxAssQual_PU );

vector<float> *myPFCandFromPV_PU = 0;
evt_PU->SetBranchAddress( "PFCandFromPV", &myPFCandFromPV_PU );

vector<float> *myPFCandLostInnerHits_PU = 0;
evt_PU->SetBranchAddress( "PFCandLostInnerHits", &myPFCandLostInnerHits_PU );

vector<float> *myPFCandTrackHighPurity_PU = 0;
evt_PU->SetBranchAddress( "PFCandTrackHighPurity", &myPFCandTrackHighPurity_PU );

vector<float> *myPFCandDZ_PU = 0;
evt_PU->SetBranchAddress( "PFCandDZ", &myPFCandDZ_PU );

vector<float> *myPFCandDXY_PU = 0;
evt_PU->SetBranchAddress( "PFCandDXY", &myPFCandDXY_PU );

vector<float> *myPFCandDZsig_PU = 0;
evt_PU->SetBranchAddress( "PFCandDZsig", &myPFCandDZsig_PU );

vector<float> *myPFCandDXYsig_PU = 0;
evt_PU->SetBranchAddress( "PFCandDXYsig", &myPFCandDXYsig_PU );

vector<float> *myPFCandNormChi2_PU = 0;
evt_PU->SetBranchAddress( "PFCandNormChi2", &myPFCandNormChi2_PU );

vector<float> *myPFCandQuality_PU = 0;
evt_PU->SetBranchAddress( "PFCandQuality", &myPFCandQuality_PU );

UInt_t mynAK4PUPPIJets_PU = 0;
evt_PU->SetBranchAddress( "nAK4PUPPIJets", &mynAK4PUPPIJets_PU );

vector<float> *myAK4PUPPIJetPt_PU = 0;
evt_PU->SetBranchAddress( "AK4PUPPIJetPt", &myAK4PUPPIJetPt_PU );

vector<float> *myAK4PUPPIJetRawPt_PU = 0;
evt_PU->SetBranchAddress( "AK4PUPPIJetRawPt", &myAK4PUPPIJetRawPt_PU );

vector<float> *myAK4PUPPIJetEta_PU = 0;
evt_PU->SetBranchAddress( "AK4PUPPIJetEta", &myAK4PUPPIJetEta_PU );

vector<float> *myAK4PUPPIJetPhi_PU = 0;
evt_PU->SetBranchAddress( "AK4PUPPIJetPhi", &myAK4PUPPIJetPhi_PU );

vector<float> *myAK4PUPPIJetE_PU = 0;
evt_PU->SetBranchAddress( "AK4PUPPIJetE", &myAK4PUPPIJetE_PU );

vector<float> *myAK4PUPPIJetRawE_PU = 0;
evt_PU->SetBranchAddress( "AK4PUPPIJetRawE", &myAK4PUPPIJetRawE_PU );

UInt_t mynAK4CHSJets_PU = 0;
evt_PU->SetBranchAddress( "nAK4CHSJets", &mynAK4CHSJets_PU );

vector<float> *myAK4CHSJetPt_PU = 0;
evt_PU->SetBranchAddress( "AK4CHSJetPt", &myAK4CHSJetPt_PU );

vector<float> *myAK4CHSJetRawPt_PU = 0;
evt_PU->SetBranchAddress( "AK4CHSJetRawPt", &myAK4CHSJetRawPt_PU );

vector<float> *myAK4CHSJetEta_PU = 0;
evt_PU->SetBranchAddress( "AK4CHSJetEta", &myAK4CHSJetEta_PU );

vector<float> *myAK4CHSJetPhi_PU = 0;
evt_PU->SetBranchAddress( "AK4CHSJetPhi", &myAK4CHSJetPhi_PU );

vector<float> *myAK4CHSJetE_PU = 0;
evt_PU->SetBranchAddress( "AK4CHSJetE", &myAK4CHSJetE_PU );

vector<float> *myAK4CHSJetRawE_PU = 0;
evt_PU->SetBranchAddress( "AK4CHSJetRawE", &myAK4CHSJetRawE_PU );


Long64_t nevents_PU = evt_PU->GetEntries();
  
  
    for ( Long64_t ievent_noPU = 0; ievent_noPU < nevents_noPU; ++ievent_noPU ){
        
        evt_noPU->GetEntry( ievent_noPU );
        evt_PU->GetEntry( ievent_noPU ); //input files are sorted, so take the same entry for both files, it should correspond to the same event in both files
        
//         if (ievent_noPU > 10 ) break;
            
            if(myrunNo_noPU == myrunNo_PU && myevtNo_noPU == myevtNo_PU && mylumiSec_noPU == mylumiSec_PU) { //make a check on runNo, evtNo, lumiSec, just to be sure.
                
                if (ievent_noPU % 1000 == 0) {
                cout << "ievent = " << ievent_noPU << endl;
                std::cout << "*** FILE NO PU *** runNo: " << myrunNo_noPU << "; evtNo: " << myevtNo_noPU << "; lumiSec: " << mylumiSec_noPU <<endl;
                std::cout << "*** FILE PU *** runNo: " << myrunNo_PU << "; evtNo: " << myevtNo_PU << "; lumiSec: " << mylumiSec_PU <<endl;
                
                }
                
                runNo = myrunNo_noPU;
                evtNo = myevtNo_noPU;
                lumiSec = mylumiSec_noPU;
                nPFCands_noPU = mynPFCands_noPU;
                nPFCands_PU = mynPFCands_PU;
                nAK4PUPPIJets_PU = mynAK4PUPPIJets_PU;
		nAK4PUPPIJets_noPU = mynAK4PUPPIJets_noPU;
		nAK4CHSJets_PU = mynAK4CHSJets_PU;
		nAK4CHSJets_noPU = mynAK4CHSJets_noPU;
                
                for (int i = 0; i < mynPFCands_noPU; i++) {
                    
                    PFCandPt_noPU.push_back(myPFCandPt_noPU->at(i));
                    PFCandEta_noPU.push_back(myPFCandEta_noPU->at(i));
                    PFCandPhi_noPU.push_back(myPFCandPhi_noPU->at(i));
                    PFCandE_noPU.push_back(myPFCandE_noPU->at(i));
                    
                }
                
                for (int i = 0; i < mynPFCands_PU; i++) {
                    
                    PFCandPt_PU.push_back(myPFCandPt_PU->at(i));
                    PFCandEta_PU.push_back(myPFCandEta_PU->at(i));
                    PFCandAbsEta_PU.push_back(myPFCandAbsEta_PU->at(i));
                    PFCandPhi_PU.push_back(myPFCandPhi_PU->at(i));
                    PFCandE_PU.push_back(myPFCandE_PU->at(i));
                    PFCandpdgId_PU.push_back(myPFCandpdgId_PU->at(i));
                    PFCandCharge_PU.push_back(myPFCandCharge_PU->at(i));
                    PFCandPUPPIw_PU.push_back(myPFCandPUPPIw_PU->at(i));
                    PFCandHCalFrac_PU.push_back(myPFCandHCalFrac_PU->at(i));
                    PFCandHCalFracCalib_PU.push_back(myPFCandHCalFracCalib_PU->at(i));
                    PFCandVtxAssQual_PU.push_back(myPFCandVtxAssQual_PU->at(i));
                    PFCandFromPV_PU.push_back(myPFCandFromPV_PU->at(i));
                    PFCandLostInnerHits_PU.push_back(myPFCandLostInnerHits_PU->at(i));
                    PFCandTrackHighPurity_PU.push_back(myPFCandTrackHighPurity_PU->at(i));
                    PFCandDZ_PU.push_back(myPFCandDZ_PU->at(i));
                    PFCandDXY_PU.push_back(myPFCandDXY_PU->at(i));
                    PFCandDZsig_PU.push_back(myPFCandDZsig_PU->at(i));
                    PFCandDXYsig_PU.push_back(myPFCandDXYsig_PU->at(i));
                    PFCandNormChi2_PU.push_back(myPFCandNormChi2_PU->at(i));
                    PFCandQuality_PU.push_back(myPFCandQuality_PU->at(i));
                    
                }
                
                for (int i = 0; i < mynAK4PUPPIJets_PU; i++) {
                    
                    AK4PUPPIJetPt_PU.push_back(myAK4PUPPIJetPt_PU->at(i));
		    AK4PUPPIJetRawPt_PU.push_back(myAK4PUPPIJetRawPt_PU->at(i));
                    AK4PUPPIJetEta_PU.push_back(myAK4PUPPIJetEta_PU->at(i));
                    AK4PUPPIJetPhi_PU.push_back(myAK4PUPPIJetPhi_PU->at(i));
                    AK4PUPPIJetE_PU.push_back(myAK4PUPPIJetE_PU->at(i));
		    AK4PUPPIJetRawE_PU.push_back(myAK4PUPPIJetRawE_PU->at(i));
                    
                }

		for (int i = 0; i < mynAK4PUPPIJets_noPU; i++) {
                    
                    AK4PUPPIJetPt_noPU.push_back(myAK4PUPPIJetPt_noPU->at(i));
		    AK4PUPPIJetRawPt_noPU.push_back(myAK4PUPPIJetRawPt_noPU->at(i));
                    AK4PUPPIJetEta_noPU.push_back(myAK4PUPPIJetEta_noPU->at(i));
                    AK4PUPPIJetPhi_noPU.push_back(myAK4PUPPIJetPhi_noPU->at(i));
                    AK4PUPPIJetE_noPU.push_back(myAK4PUPPIJetE_noPU->at(i));
		    AK4PUPPIJetRawE_noPU.push_back(myAK4PUPPIJetRawE_noPU->at(i));
                    
                }

		for (int i = 0; i < mynAK4CHSJets_PU; i++) {
                    
                    AK4CHSJetPt_PU.push_back(myAK4CHSJetPt_PU->at(i));
		    AK4CHSJetRawPt_PU.push_back(myAK4CHSJetRawPt_PU->at(i));
                    AK4CHSJetEta_PU.push_back(myAK4CHSJetEta_PU->at(i));
                    AK4CHSJetPhi_PU.push_back(myAK4CHSJetPhi_PU->at(i));
                    AK4CHSJetE_PU.push_back(myAK4CHSJetE_PU->at(i));
		    AK4CHSJetRawE_PU.push_back(myAK4CHSJetRawE_PU->at(i));
                    
                }

		for (int i = 0; i < mynAK4CHSJets_noPU; i++) {
                    
                    AK4CHSJetPt_noPU.push_back(myAK4CHSJetPt_noPU->at(i));
		    AK4CHSJetRawPt_noPU.push_back(myAK4CHSJetRawPt_noPU->at(i));
                    AK4CHSJetEta_noPU.push_back(myAK4CHSJetEta_noPU->at(i));
                    AK4CHSJetPhi_noPU.push_back(myAK4CHSJetPhi_noPU->at(i));
                    AK4CHSJetE_noPU.push_back(myAK4CHSJetE_noPU->at(i));
		    AK4CHSJetRawE_noPU.push_back(myAK4CHSJetRawE_noPU->at(i));
                    
                }
                
            }
            
            flatTree->Fill();
            PFCandPt_noPU.clear();
            PFCandEta_noPU.clear();
            PFCandPhi_noPU.clear();
            PFCandE_noPU.clear();
            PFCandPt_PU.clear();
            PFCandEta_PU.clear();
            PFCandAbsEta_PU.clear();
            PFCandPhi_PU.clear();
            PFCandE_PU.clear();
            PFCandpdgId_PU.clear();
            PFCandCharge_PU.clear();
            PFCandPUPPIw_PU.clear();
            PFCandHCalFrac_PU.clear();
            PFCandHCalFracCalib_PU.clear();
            PFCandVtxAssQual_PU.clear();
            PFCandFromPV_PU.clear();
            PFCandLostInnerHits_PU.clear();
            PFCandTrackHighPurity_PU.clear();
            PFCandDZ_PU.clear();
            PFCandDXY_PU.clear();
            PFCandDZsig_PU.clear();
            PFCandDXYsig_PU.clear();
            PFCandNormChi2_PU.clear();
            PFCandQuality_PU.clear();
            AK4PUPPIJetPt_PU.clear();
	    AK4PUPPIJetRawPt_PU.clear();
            AK4PUPPIJetEta_PU.clear();
            AK4PUPPIJetPhi_PU.clear();
            AK4PUPPIJetE_PU.clear();
	    AK4PUPPIJetRawE_PU.clear();
	    AK4PUPPIJetPt_noPU.clear();
	    AK4PUPPIJetRawPt_noPU.clear();
            AK4PUPPIJetEta_noPU.clear();
            AK4PUPPIJetPhi_noPU.clear();
            AK4PUPPIJetE_noPU.clear();
	    AK4PUPPIJetRawE_noPU.clear();
	    AK4CHSJetPt_PU.clear();
	    AK4CHSJetRawPt_PU.clear();
            AK4CHSJetEta_PU.clear();
            AK4CHSJetPhi_PU.clear();
            AK4CHSJetE_PU.clear();
	    AK4CHSJetRawE_PU.clear();
	    AK4CHSJetPt_noPU.clear();
	    AK4CHSJetRawPt_noPU.clear();
            AK4CHSJetEta_noPU.clear();
            AK4CHSJetPhi_noPU.clear();
            AK4CHSJetE_noPU.clear();
	    AK4CHSJetRawE_noPU.clear();
        

    }
    
flatTree->Write();
outputfile->Write();
gBenchmark->Show("running time");
outputfile->Close();
delete outputfile;

}
