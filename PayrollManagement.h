#pragma once
#ifndef PAYROLLMANAGEMENT
#define PAYROLLMANAGEMENT
#include"BusinessIO.h"
#include"Date.h"
class PayrollManagement
{
private:
	float calSalaryEmp(string id, json);
	PayrollManagement() {};
public:

	void calculateSalaryAndProfit(Date, Date);
	static PayrollManagement& instance()
	{
		static PayrollManagement INSTANCE;
		return INSTANCE;
	}
};
#endif

