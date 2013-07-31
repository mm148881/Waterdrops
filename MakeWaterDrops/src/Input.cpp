/*
 * trjInput.cpp
 *
 *  Created on: May 22, 2012
 *      Author: marchi
 */

#include "Input.h"

namespace My {
Input::Input(int ntot,char ** v) {
	vector<string> in;

	inmap["-pdb"]=in;
	inmap["-no"]=in;
	inmap["-o"]=in;
	inmap["-nions"]=in;

	map<string,vector<string> >::iterator it=inmap.begin();
	for(int n=0;it!=inmap.end();++it,n++){
		Usage[n]=" ";
	}
	Usage[0]="\t -pdb file.pdb \n";
	Usage[1]="\t -no No. of water molecules of the final system \n";
	Usage[2]="\t -o output filename [Drop.pdb] \n";
	Usage[3]="\t -nions number of potisite sodium ions [0] \n";

	int n=1;
	string key;
	for(;n<ntot;){
		string tmp0(v[n]);
		if(v[n][0] =='-'){
			key.assign(v[n]);
			if(inmap.find(key) != inmap.end()){
				if(inmap[key].empty()) inmap[key].push_back(tmp0);
			} else{
				unknownC.push_back(key);
				inmap[key].push_back(tmp0);
			}
		}
		else{
			inmap[key].push_back(tmp0);
		}
		n++;
	}

}

vector<string> Input::getUsage(){
	vector<string> use;
	map<int,string>::iterator it=Usage.begin();
	for(;it!=Usage.end();++it){
		use.push_back(it->second);
	}
	return use;
}
Input::~Input() {
	// TODO Auto-generated destructor stub
}

} /* namespace trj */
