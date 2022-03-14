#include "TString.h"
#include "TFile.h" 
#include "TTree.h"

#include <iostream>
#include <fstream>

// g++ get_root_data.cpp -o get_root_data -Wall  `root-config --cflags --libs`

using std::cout;
using std::endl;
using std::ofstream;

const int SIZE = 20000;


void get_train_data(int run, int event_start, int event_stop)
{
    TString str(TString::Format("/mnt/hgfs/vm_hanX/run_R%04d.root", run).Data());
    TFile* fi = new TFile(str);
    if (!fi) {
        cout << "cannot open " << str << endl;
        return ;
    }

    TTree* tr = (TTree*)fi->Get("tree");

    UShort_t data[SIZE];
    UShort_t dt[SIZE];

    tr->SetBranchAddress("data", data);
    tr->SetBranchAddress("dt", dt);

    ofstream data_file;
    data_file.open(TString::Format("../../data/R%04d_%d.bin", run, event_stop-event_start), std::ofstream::out|std::ofstream::binary);
    for(int i=event_start;i<event_stop;i++) {
        tr->GetEntry(i);
        data_file.write((char*)data, 2*SIZE);
    }
    data_file.close();
}

//
void get_test_data(int run, int event_start, int event_stop)
{
    TString str(TString::Format("/mnt/hgfs/vm_hanX/run_R%04d.root", run).Data());
    TFile* fi = new TFile(str);
    if (!fi) {
        cout << "cannot open " << str << endl;
        return ;
    }

    TTree* tr = (TTree*)fi->Get("tree");

    UShort_t data[SIZE];
    UShort_t dt[SIZE];

    tr->SetBranchAddress("data", data);
    tr->SetBranchAddress("dt", dt);

    ofstream data_file;
    data_file.open(TString::Format("../../data/R%04d_%d_test.bin", run, event_stop-event_start), std::ofstream::out|std::ofstream::binary);
    for(int i=event_start;i<event_stop;i++) {
        tr->GetEntry(i);
        data_file.write((char*)data, 2*SIZE);
    }
    data_file.close();
}

