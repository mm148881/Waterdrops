/*
 * Waters.h
 *
 *  Created on: Jul 30, 2013
 *      Author: marchi
 */

#ifndef WATERS_H_
#define WATERS_H_
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include "MyUtilClass.h"
using namespace DVECT;
using namespace MATRIX;

using namespace std;

const int WDIM=3;
class MyComp{
public:
	bool operator()(vector<Dvect> x, vector<Dvect> y){
		Dvect z=0.0;
		double one=x[0].Dist(z);
		double two=y[0].Dist(z);
		return one<two;
	}
};
class Waters {
	vector<vector<Dvect> > x;
	vector<vector<Dvect> > sphere;
	void PutInCenter(Dvect);
public:
	Waters(){};
	vector<Dvect> & operator[](const int n){
		return x.at(n);
	}
	void Add(const Dvect & , const int);
	void Center(Dvect);
	void Center();
	vector<vector<Dvect> > & MakeSphere(int);
	~Waters(){};
};


#endif /* WATERS_H_ */
