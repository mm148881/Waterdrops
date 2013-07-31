/*
 * Topol.h
 *
 *  Created on: Jul 30, 2013
 *      Author: marchi
 */

#ifndef TOPOL_H_
#define TOPOL_H_
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include "MyUtilClass.h"
#include "Sequence.h"
#include "Waters.h"
using namespace DVECT;
using namespace MATRIX;

using namespace std;
class Topol {
	Waters myW;
	vector<string> Header;
	double MaxRadius;
	vector<string> MySphere(int,int);
public:
	Topol(const vector<string> &);
	vector<string> getSphere(int);
	vector<string> getSphere(int,int);
	virtual ~Topol();
};

#endif /* TOPOL_H_ */
