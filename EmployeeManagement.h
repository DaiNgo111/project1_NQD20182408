#pragma once
#ifndef EMPLOYEEMANAGEMENT_H
#define EMPLOYEEMANAGEMENT_H
#include"Employee.h"
#include"BusinessIO.h"
#include"Manager.h"
#include"NailTechnician.h"
#include<map>
#include"Date.h"
#include<Windows.h>
class EmployeeManagement
{
private:
	map<string, Employee*> mEmployeeList;
	BusinessIO mBusinessIO;
	EmployeeManagement();
public:
	static EmployeeManagement& instance()
	{
		static EmployeeManagement INSTANCE;
		return INSTANCE;
	}
	void addEmp(Employee*);
	void deleteEmp(string id);
	void updateEmp(string id);
	void updateEmpDetail(string id);
	void printEmployeeList();
	void searchEmp(string id);
	Employee* empExist(string id);
	Employee* jsonToEmp(string id);
};
#endif
