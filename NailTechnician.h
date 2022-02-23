#pragma once
#ifndef	NAILTECHNICIAN_H
#define NAILTECHNICIAN_H
#include"Employee.h"
using namespace std;
class NailTechnician : public Employee {
public:

	NailTechnician(string id, string name, string address, Date doB, string phone);
	NailTechnician();
	NailTechnician(string id);
	json toJsonObj();
	void inputPayroll(Date);
	void print();
};
#endif

