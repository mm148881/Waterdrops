//============================================================================
// Name        : MakeWaterDrops.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iterator>
#include <iomanip>
#include "Input.h"
#include "Topol.h"
using namespace std;
ifstream fpdb;
ofstream fout;
string filepdb,fileout="Drop.pdb";
int nwaters=0;
int nions=0;
int main(int argc, char ** argv){
	My::Input MyInput(argc,argv);

	string comm0(argv[0]);
	size_t mypos=comm0.find_last_of("/")+1;
	size_t length=comm0.size()-mypos;
	string command=comm0.substr(mypos,length);
	string errmsg;
	string Usage="Usage:\t"+ command + "\n";
	vector<string> use=MyInput.getUsage();
	for(unsigned int n=0;n<use.size();n++)
		Usage+=use[n];
	Usage+="\n\t Default values in square brackets []\n";
	try{
		if(argc == 1) throw Usage;
		if(int m=MyInput.bTest().size()) {
			errmsg=" Command(s) not found: ";
			for(int n=0;n<m;n++)
				errmsg+=MyInput.bTest()[n]+"  ";
			errmsg+="\n"+Usage;
			throw errmsg;
			}
		}
	catch(const string & s){
		cout << s << endl;
		return 0;
	}
	try{
		if(!MyInput["-pdb"].empty()) {
			if(MyInput["-pdb"].size() != 2) throw string(" filename expected for " + MyInput["-pdb"][0] + " option ");
			filepdb=MyInput["-pdb"][1];
			fpdb.open(filepdb.c_str(),ios::in);
			if(!fpdb) throw string("\n Cannot open " + filepdb + "!!\n");
		}
		if(!MyInput["-o"].empty()) {
			if(MyInput["-o"].size() != 2) throw string(" filename expected for " + MyInput["-o"][0] + " option ");
			fileout=MyInput["-o"][1];
		}
		if(!MyInput["-no"].empty()) {
			if(MyInput["-no"].size() != 2) throw string(" Number of water molecules needed for " + MyInput["-no"][0] + " option ");
			stringstream(MyInput["-no"][1])>> nwaters;
		} else throw string(" Number of waters are required! Abort.");
		if(!MyInput["-nions"].empty()) {
			if(MyInput["-nions"].size() != 2) throw string(" Number of water molecules needed for " + MyInput["-nions"][0] + " option ");
			stringstream(MyInput["-nions"][1])>> nions;
		}
	}catch(const string & s){
		cout << s << endl;
		return 0;
	}

	fout.open(fileout.c_str(),ios::out);
	if(!fout) throw string("\n Cannot open " + fileout + "!!\n");

	// read pdb file to construct topology
	vector<string> data;
	for(string str;getline(fpdb,str);){
		data.push_back(str);
	}
	Topol MyTop(data);
	data.clear();
	data=MyTop.getSphere(nwaters,nions);
	data.push_back("END");
	for(unsigned int n=0;n<data.size();n++)
		fout << data[n] <<endl;
	cout << data.size() << " records have been written to file " + fileout <<endl;
	return 0;
}
