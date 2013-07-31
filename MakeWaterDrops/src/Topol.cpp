/*
 * Topol.cpp
 *
 *  Created on: Jul 30, 2013
 *      Author: marchi
 */

#include "Topol.h"

Topol::Topol(const vector<string> & data) {
	vector<Dvect> xc;
	int nat=0;
	map<int,vector<int> > cidx0;
	Sequence WaterNo(0);
	for(size_t i=0;i<data.size();i++){
		if(data[i].find("ATOM") == 0 || data[i].find("HETATM") == 0 ) {
			string sub1=data[i].substr(11,5);
			string sub2=data[i].substr(17,4);
			string sub3=data[i].substr(21,5);
			string sub4=data[i].substr(76,2);
			Dvect tmp;
			int type;
			std::stringstream ss0(data[i].substr(21,5));
			ss0>> type;
			WaterNo=type;
			std::stringstream ss(data[i].substr(30,24));
			ss>> tmp;
			myW.Add(tmp,int(WaterNo));
			nat++;
		}	else if(data[i].find("CRYST1") == 0 ){
			Header.push_back(data[i]);
			string sub1=data[i].substr(6,9);
			std::stringstream ss0(sub1);
			ss0>> MaxRadius;
		}
	}
	MaxRadius*=0.5;
	int nwater=WaterNo;
	cout << "read " << nwater << " Water Molecules " <<endl;
}
vector<string> Topol::MySphere(int NWaters, int NIons){
	vector<vector<Dvect> > NewWaters=myW.MakeSphere(NWaters+NIons);
	vector<string> data1;
	string AtmLabs[3]={"OW ","HW1","HW2"};
	data1=Header;
	Dvect z=0.0;
	int AtmNo=0;
	for(int i=0;i<NWaters;i++){
		int ResNo=i+1;
		for(unsigned int m=0;m<NewWaters[i].size();m++){
			AtmNo++;
			string line="ATOM             SOL                                    1.00  0.00";
			Dvect xc=NewWaters[i][m];
			try{
				if(xc.Dist(z) > MaxRadius) throw string(" Required number of water molecules on a sphere exceeds box size. Abort!");
			} catch(const string & s){
				cout << s <<endl;
				exit(1);
			}
			line.replace(13,3,AtmLabs[m]);
			stringstream ss;
			ss<<setw(6) << fixed<< AtmNo;
			line.replace(5,6,ss.str());
			ss.str("");
			ss<<setw(5) << fixed<< ResNo;
			line.replace(21,5,ss.str());
			ss.str("");
			ss<< setw(8) << setprecision(3) << fixed << xc[0];
			ss<< setw(8) << setprecision(3) << fixed << xc[1];
			ss<< setw(8) << setprecision(3) << fixed << xc[2];

			line.replace(30,24,ss.str());
			data1.push_back(line);
		}
	}
	string IonLabs="NA ";
	for(int i=NWaters;i<NWaters+NIons;i++){
		int ResNo=i+1;
		AtmNo++;
		      //     012345678901234567890123456789012345678901234567890123456789
		string line="ATOM             SOL                                    1.00  0.00";
		Dvect xc=NewWaters[i][0];
		try{
			if(xc.Dist(z) > MaxRadius) throw string(" Required number of water molecules on a sphere exceeds box size. Abort!");
		} catch(const string & s){
			cout << s <<endl;
			exit(1);
		}
		line.replace(13,3,IonLabs);
		stringstream ss;
		ss<<setw(6) << fixed<< AtmNo;
		line.replace(5,6,ss.str());
		ss.str("");
		ss<<setw(5) << fixed<< ResNo;
		line.replace(21,5,ss.str());
		ss.str("");
		ss<< setw(8) << setprecision(3) << fixed << xc[0];
		ss<< setw(8) << setprecision(3) << fixed << xc[1];
		ss<< setw(8) << setprecision(3) << fixed << xc[2];
		line.replace(30,24,ss.str());
		line.replace(17,3,"NA ");
		data1.push_back(line);
	}

	return data1;
}

vector<string> Topol::getSphere(int NWaters){
	return MySphere(NWaters,0);
}
vector<string> Topol::getSphere(int NWaters, int NIons){
	return MySphere(NWaters,NIons);
}

Topol::~Topol() {
	// TODO Auto-generated destructor stub
}

