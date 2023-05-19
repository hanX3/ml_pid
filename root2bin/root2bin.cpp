#include "TString.h"
#include "TFile.h" 
#include "TTree.h"

#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::ofstream;

const int SIZE = 2000;


void root2bin(int run, int event_start, int event_stop)
{
    TString str(TString::Format("../../data/data_C1_%04d_wave.root", run).Data());
    TFile* fi = new TFile(str);
    if (!fi) {
        cout << "cannot open " << str << endl;
        return ;
    }

    TTree* tr = (TTree*)fi->Get("tree");

    UShort_t data[SIZE];

    tr->SetBranchAddress("data", data);

    ofstream data_file;
    data_file.open(TString::Format("../../data/R%04d.bin", run), std::ofstream::out|std::ofstream::binary);
    for(int i=event_start;i<event_stop;i++) {
        tr->GetEntry(i);
        data_file.write((char*)data, 2*SIZE);
    }
    data_file.close();
}

