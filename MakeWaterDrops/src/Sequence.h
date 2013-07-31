/*
 * Sequence.h
 *
 *  Created on: Jul 30, 2013
 *      Author: marchi
 */

#ifndef SEQUENCE_H_
#define SEQUENCE_H_

class Sequence {
	int n;
	int n_p;
public:
	Sequence() {n=0;n_p=0;};
	Sequence(int m) {n=m;n_p=0;};
	operator int() const {return n;}
	Sequence & operator=(int m){
		if(m != n_p){
			n++;
			n_p=m;
		}
		return *this;
	}
	virtual ~Sequence();
};

#endif /* SEQUENCE_H_ */
