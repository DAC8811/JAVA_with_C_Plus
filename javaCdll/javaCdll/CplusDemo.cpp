#include "pch.h"
#include "CplusDemo.h"

CplusDemo::CplusDemo() {
	age = 0;
}

void CplusDemo::init() {
}

void CplusDemo::setAge(int age) {
	this->age = age;
}

int CplusDemo::getAge() {
	return this->age;
}
