/*
 * Waters.cpp
 *
 *  Created on: Jul 30, 2013
 *      Author: marchi
 */

#include "Waters.h"


void Waters::Add(const Dvect & y, const int n){
		vector<Dvect> tmp=vector<Dvect>(1,y);
		if(n > static_cast<int> (x.size()))
			x.push_back(tmp);
		else x[n-1].push_back(y);
}

void Waters::Center(){
	Dvect y=0.0;
	PutInCenter(y);
}
void Waters::Center(Dvect y){
	PutInCenter(y);
}
void Waters::PutInCenter(Dvect y){
	Dvect xcm=0.0;
	for(unsigned int i=0;i<x.size();i++){
		Dvect xc=x[i][0];	// Takes oxygen
		xcm+=xc;
	}
	xcm/=static_cast<double> (x.size());
	for(unsigned int i=0;i<x.size();i++){
		for(int n=0;n<WDIM;n++)
			x[i][n]=x[i][n]-xcm;
	}

}

vector<vector<Dvect> > & Waters::MakeSphere(int n){
	Center();
	MyComp comp;
	sort(x.begin(),x.end(),comp);
	for(int o=0;o<n;o++)
		sphere.push_back(x[o]);

	return sphere;
}
