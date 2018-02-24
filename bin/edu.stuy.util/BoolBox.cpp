/*
 * BoolBox.cpp
 *
 *  Created on: Feb 22, 2018
 *      Author: evang
 */

#include <edu.stuy.util/BoolBox.h>

BoolBox::BoolBox(bool initialVal) {
	_val = initialVal;
}

bool BoolBox::Get(){
	return _val;
}

void BoolBox::Set(bool newVal){
	_val = newVal;
}

BoolBox::~BoolBox() {
}

