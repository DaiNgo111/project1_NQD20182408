#pragma once
#ifndef BUSINESSIO_H
#define BUSINESSIO_H
#include "Third_Party/json.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include"Date.h"
using namespace std;
using json = nlohmann::json;
bool isEmpty(std::ifstream& pFile);
class BusinessIO
{
private:
	json jsonEmployeeInfo;
	const string employeeInfoPath = "Files/EmployeeInfo.json";
	json jsonLogin;
	const string loginPath = "Files/login.json";
	json jsonPayrollInfo;
	const string payRollInfoPath = "Files/Payroll.json";
	void init(ifstream&, string);

public:
	int getPositionPayrollInfoByDateFromFile(Date date);
	int getPositionEmployeeInFoFromFile(string id);
	BusinessIO();
	int getPositionEmployeePayrollInfoFromFile(string id, Date date);

	//emInfo
	void addEmployeeToFile(json emp);
	void deleteEmployeeByIdToFile(string id);
	void upDateEmployeeToFile(string id, json emp);
	json getEmpInfo();

	// loginInfo
	void upDatePassWordToFile(string);
	void getAccoutPassword(string& accout, string& password);
	void setAccountPassword(string account);

	//payrollInfo
	void addEmployeeSalarytoFile(string id, float salary, Date date, float income);
	json getPayrollInfoFromFile(Date date);
	json getJsonPayroll();
	
	// Crypt
	void decryptFile(string filePath, json& info);
	void encryptFile(json info, string filePath);
	string decrypt(string);
	string encrypt(string);

};
#endif
