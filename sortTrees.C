#include <TFile.h>
#include <TTree.h>
#include <TBranch.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TString.h>
#include <TBenchmark.h>
#include <TTreeIndex.h>
#include <iostream>

using namespace std;

void sortTrees () {
    
gBenchmark->Start("running time");    
    
TFile *inputfile  = new TFile("/afs/cern.ch/user/f/fiemmi/JetMET/CMSSW_10_6_4/src/flatTree_QCD_Pt-15to7000_TuneCP5_Flat2018_13TeV_pythia8_training_PU_EXT.root", "READ" );

TTree *evt = (TTree*)inputfile->Get( "events" );

Int_t idx = evt->BuildIndex("evtNo");
TTreeIndex *att_index = (TTreeIndex*)evt->GetTreeIndex();
TFile * outputfile  = new TFile( "flatTree_QCD_Pt-15to7000_TuneCP5_Flat2018_13TeV_pythia8_training_PU_EXT_sorted.root", "RECREATE" );
TTree* evt_sorted = (TTree*)evt->CloneTree(0);
evt_sorted->SetName("events_sorted");

for( Long64_t i = 0; i < att_index->GetN(); i++ ) {
if (i%1000 == 0) cout << "ievt = " << i << endl;
evt->GetEntry( att_index->GetIndex()[i] );
evt_sorted->Fill();
}
evt_sorted->Write();
gBenchmark->Show("running time");
}
