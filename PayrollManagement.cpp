#include "PayrollManagement.h"
void PayrollManagement::calculateSalaryAndProfit(Date d, Date d1)
{
	json calculatePayroll;
	BusinessIO mPayrollBussinessIO;
	int size = mPayrollBussinessIO.getJsonPayroll().size();
	float income = 0;
	float totalSalary = 0;
	Date* date = new Date[size];
	for (int i = 0; i < size; i++)
	{
		date[i].setDateByStr(mPayrollBussinessIO.getJsonPayroll()[i]["date"].get<string>());
		if ((d < date[i] || (d == date[i])) && (d1 > date[i] || (d1 == date[i])))
		{
			calculatePayroll.push_back(mPayrollBussinessIO.getJsonPayroll()[i]);
		}
	}
	map <string, float> salaryEmpList;
	for (int i = 0; i < calculatePayroll.size(); i++)
	{
		income += calculatePayroll[i]["income"].get<float>();
		for (int j = 0; j < calculatePayroll[i]["employee"].size(); j++)
		{
			salaryEmpList[calculatePayroll[i]["employee"][j]["id"]] = 0;

		}
	}
	map<string, float>::iterator it;
	for (it = salaryEmpList.begin(); it != salaryEmpList.end(); it++)
	{
		it->second = calSalaryEmp(it->first, calculatePayroll);
	}
	cout << "\t\t\t" << setw(5) << left << "SALARY AND PROFIT FROM OF NAIL SPA SALONS FROM " << d.toStr() << " to " << d1.toStr() << ": \n\n";
	cout << "\t\t\t\t\t" << setw(5) << left << "ID";
	cout << setw(30) << right << "Salary" << endl;
	cout << setfill('-');
	cout << "\t\t\t\t\t" << setw(35) << "-" << endl;
	cout << setfill(' ');
	for (it = salaryEmpList.begin(); it != salaryEmpList.end(); it++)
	{
		cout << "\t\t\t\t\t" << setw(5) << left << it->first;
		cout << setw(23) << right << it->second << endl;
		totalSalary += it->second;
	}
	cout << setfill('-');
	cout << "\t\t\t\t\t" << setw(35) << "-" << endl;
	cout << setfill(' ');
	cout << "\t\t\t\t\t" << setw(5) << left << "Income: " << income << endl;
	cout << "\t\t\t\t\t" << setw(5) << left << "Profit: " << income - totalSalary;
	cout << "\n\n";
	//cout << setw(4) << calculatePayroll;
	cout << endl;
	delete[] date;

}


float PayrollManagement::calSalaryEmp(string id, json salaryJson)
{
	BusinessIO mPayrollBussinessIO;
	float salary = 0;
	for (int i = 0; i < salaryJson.size(); i++)
	{
		for (int j = 0; j < salaryJson[i]["employee"].size(); j++)
		{
			if (salaryJson[i]["employee"][j]["id"] == id)
				salary += salaryJson[i]["employee"][j]["salary"];
		}
	}
	return salary;
}

