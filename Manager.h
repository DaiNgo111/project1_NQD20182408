#pragma once
#ifndef MANAGER_H
#define MANAGER_H
#include"Employee.h"
#include"Date.h"
class Manager : public Employee {
private:
	float mCsSalary;
public:
	float getCsSalary();
	void setCsSalary(float);
	Manager();
	Manager(string id);
	Manager(string id, string name, string address, Date doB, string phoneNum, float csSalary);
	void inputInformation();
	json toJsonObj();
	void print();
	void inputPayroll(Date);
};
#endif
