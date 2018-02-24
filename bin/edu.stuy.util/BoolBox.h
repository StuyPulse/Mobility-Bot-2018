/*
 * BoolBox.h
 *
 *  Created on: Feb 22, 2018
 *      Author: evang
 */

#ifndef SRC_EDU_STUY_UTIL_BOOLBOX_H_
#define SRC_EDU_STUY_UTIL_BOOLBOX_H_

class BoolBox {
private:

	bool * _val;

public:
	BoolBox(bool initialVal);
	bool Get();
	void Set(bool newVal);
	virtual ~BoolBox();
};

#endif /* SRC_EDU_STUY_UTIL_BOOLBOX_H_ */
