/*
 * trjInput.h
 *
 *  Created on: May 22, 2012
 *      Author: marchi
 */

#ifndef TRJINPUT_H_
#define TRJINPUT_H_
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using std::map;
using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::set;

namespace My {
enum myinput {pdb,no,o,nions};
class Input {
	map<string,vector<string> > inmap;
	vector<string> unknownC;
	map<int,string> Usage;
public:
	Input(int nv,char ** v);
	virtual ~Input();
	vector<string> & operator[](const char * y){return inmap[y];}
	vector<string> & bTest(){return unknownC;};
	vector<string> getUsage();
};

} /* namespace trj */
#endif /* TRJINPUT_H_ */
