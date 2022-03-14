{
  gROOT->ProcessLine(".L get_root_data.cpp");

  gROOT->ProcessLine("get_train_data(48, 0, 100)");
  gROOT->ProcessLine("get_train_data(48, 0, 1000)");
  gROOT->ProcessLine("get_train_data(48, 0, 10000)");
  gROOT->ProcessLine("get_train_data(48, 0, 100000)");

  gROOT->ProcessLine("get_train_data(50, 0, 100)");
  gROOT->ProcessLine("get_train_data(50, 0, 1000)");
  gROOT->ProcessLine("get_train_data(50, 0, 10000)");
  gROOT->ProcessLine("get_train_data(50, 0, 100000)");

  gROOT->ProcessLine("get_test_data(48, 120000, 121000)");
  gROOT->ProcessLine("get_test_data(50, 120000, 121000)");

  gROOT->ProcessLine(".q");
}
