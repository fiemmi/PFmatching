
#include <TFile.h>
#include <TTree.h>
#include <TBranch.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TString.h>
#include <TCanvas.h>
#include <TEfficiency.h>
#include <TLatex.h>
#include <TStyle.h>
#include <sstream>
#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#include <Math/Math.h>
#include <TLorentzVector.h>
#include <Math/Vector3D.h>
#include <Math/DisplacementVector3D.h>
#include <Math/Vector3Dfwd.h>
#include <TBenchmark.h>

#include <iostream>




using namespace std;

void printEvents () {
    
gBenchmark->Start("running time");

 
ofstream file0;
file0.open ("events_noPU.txt");
ofstream file1;
file1.open ("events_PU.txt");

TString fileName[2] = {
            
    "flatTree_QCD_Pt-15to7000_TuneCP5_Flat2018_13TeV_pythia8_training_noPU_EXT_sorted",    
    "flatTree_QCD_Pt-15to7000_TuneCP5_Flat2018_13TeV_pythia8_training_PU_EXT_sorted",
        };

     
for (int k = 0; k < 2; k++) {
      
    TFile *inputfile  = new TFile( fileName[k] + ".root", "READ" );
    cout << "Processing file " << inputfile->GetName() << "..." << endl;

    //addressing branches
    TTree *evt = (TTree*)inputfile->Get( "events_sorted" );

    UInt_t myevtNo = 0;
    evt->SetBranchAddress("evtNo", &myevtNo);

    UInt_t myrunNo = 0;
    evt->SetBranchAddress("runNo", &myrunNo);

    UInt_t mylumiSec = 0;
    evt->SetBranchAddress("lumiSec", &mylumiSec);

    Long64_t nevents = evt->GetEntries();
    

    for ( Long64_t ievent = 0; ievent < nevents; ++ievent ){
  
        if ( !(ievent % 100 ) ) cout << "ievent  =  " << ievent << endl;
        //get i-th entry in tree
        evt->GetEntry( ievent );
	
        if (k == 0) file0 << myrunNo << ":" << mylumiSec << ":" << myevtNo << "\n";
        if (k == 1) file1 << myrunNo << ":" << mylumiSec << ":" << myevtNo << "\n";
  
     }// end loop over events 

       
    inputfile->Close();
    delete inputfile;
        
}//end loop over input files

file0.close();
file1.close();
        
gBenchmark->Show("running time");

}
