#include "BusinessIO.h"
bool isEmpty(std::ifstream& pFile)
{
	return pFile.peek() == ifstream::traits_type::eof();
}
void BusinessIO::init(ifstream& file, string filePath)
{
	if (isEmpty(file))
	{
		if (filePath == payRollInfoPath)
		{
			ofstream file1;
			file1.open(payRollInfoPath);
			string b = "[]";
			file1 << encrypt(b);
			file1.close();
		}
		else if (filePath == employeeInfoPath)
		{
			ofstream file1;
			file1.open(employeeInfoPath);
			string b = "{\"Employee\":[]}";
			file1 << encrypt(b);
			file1.close();
		}
		else if (filePath == loginPath)
		{
			ofstream file1;
			file1.open(loginPath);
			string b = "{\"account\":\"\",\"password\":\"\"}";
			file1 << encrypt(b);
			file1.close();
		}
	}
}

//
BusinessIO::BusinessIO()
{
	ifstream file;
	file.open(employeeInfoPath);
	init(file, employeeInfoPath);
	decryptFile(employeeInfoPath, jsonEmployeeInfo);
	file.close();
	//
	file.open(loginPath);
	init(file, loginPath);
	decryptFile(loginPath, jsonLogin);
	file.close();
	//
	file.open(payRollInfoPath);
	init(file, payRollInfoPath);
	decryptFile(payRollInfoPath, jsonPayrollInfo);
	file.close();
}
// PAYROLL
int BusinessIO::getPositionPayrollInfoByDateFromFile(Date date)
{
	decryptFile(payRollInfoPath, jsonPayrollInfo);
	int pos = -1;
	for (int i = 0; i < jsonPayrollInfo.size(); i++)
	{
		if (jsonPayrollInfo[i].at("date") == date.toStr())
		{
			pos = i;
			break;
		}
	}
	return pos;
}
int BusinessIO::getPositionEmployeePayrollInfoFromFile(string id, Date date)
{
	decryptFile(payRollInfoPath, jsonPayrollInfo);
	int posDate = getPositionPayrollInfoByDateFromFile(date);
	if (posDate == -1) return (-1);
	else
	{
		int posEmp = -2;
		for (int i = 0; i < jsonPayrollInfo[posDate].at("employee").size(); i++)
		{
			if (jsonPayrollInfo[posDate].at("employee").at(i).at("id") == id)
			{
				posEmp = i;
				break;
			}
		}
		return posEmp;
	}

}
void BusinessIO::addEmployeeSalarytoFile(string id, float salary, Date date, float income)
{
	decryptFile(payRollInfoPath, jsonPayrollInfo);
	int posDate = getPositionPayrollInfoByDateFromFile(date);
	int posEmp = getPositionEmployeePayrollInfoFromFile(id, date);
	string newPayrollInfo = "{\"date\":\"\",\"income\":\"\",\"employee\":[]}";
	json payrollInfo = json::parse(newPayrollInfo);
	string newEmpPayroll = "{\"id\":\"\",\"salary\":\"\"}";
	json empPayroll = json::parse(newEmpPayroll);
	if (posDate == -1)
	{
		payrollInfo["date"] = date.toStr();
		payrollInfo["income"] = income;
		empPayroll["id"] = id;
		empPayroll["salary"] = salary;
		payrollInfo["employee"].push_back(empPayroll);
		jsonPayrollInfo.push_back(payrollInfo);
	}
	else
	{
		if (posEmp == -2)
		{
			empPayroll["id"] = id;
			empPayroll["salary"] = salary;
			jsonPayrollInfo[posDate]["income"] = income + jsonPayrollInfo[posDate]["income"];
			jsonPayrollInfo[posDate].at("employee").push_back(empPayroll);
		}
		else
		{
			empPayroll["id"] = id;
			empPayroll["salary"] = salary + jsonPayrollInfo[posDate].at("employee")[posEmp].at("salary");
			jsonPayrollInfo[posDate]["income"] = income + jsonPayrollInfo[posDate]["income"];
			jsonPayrollInfo[posDate].at("employee")[posEmp].update(empPayroll);
		}
	}
	encryptFile(jsonPayrollInfo, payRollInfoPath);
	cout << "Add Complete";
}

json BusinessIO::getPayrollInfoFromFile(Date date)
{
	decryptFile(payRollInfoPath, jsonPayrollInfo);
	int posDate = getPositionPayrollInfoByDateFromFile(date);
	if (posDate == -1) return NULL;
	else
	{
		return jsonPayrollInfo[posDate].at("employee");
	}
}
json BusinessIO::getJsonPayroll()
{
	decryptFile(payRollInfoPath, jsonPayrollInfo);
	return jsonPayrollInfo;
}
// EMPLOYEE INFO
int BusinessIO::getPositionEmployeeInFoFromFile(string id)
{
	decryptFile(employeeInfoPath, jsonEmployeeInfo);
	int pos = -1;
	for (int i = 0; i < jsonEmployeeInfo["Employee"].size(); i++)
	{
		if (jsonEmployeeInfo.at("Employee").at(i).at("id") == id)
		{
			pos = i;
			break;
		}


	}
	return pos;

}
void BusinessIO::addEmployeeToFile(json employee)
{
	decryptFile(employeeInfoPath, jsonEmployeeInfo);
	jsonEmployeeInfo["Employee"].push_back(employee);
	encryptFile(jsonEmployeeInfo, employeeInfoPath);
}
void BusinessIO::deleteEmployeeByIdToFile(string id)
{
	decryptFile(employeeInfoPath, jsonEmployeeInfo);
	int pos = getPositionEmployeeInFoFromFile(id);
	if (pos == -1) cout << "Khong ton tai id";
	else
	{
		jsonEmployeeInfo.at("Employee").erase(jsonEmployeeInfo.at("Employee").begin() + pos);
	}
	encryptFile(jsonEmployeeInfo, employeeInfoPath);

}

void BusinessIO::upDateEmployeeToFile(string id, json newEmployee)
{
	decryptFile(employeeInfoPath, jsonEmployeeInfo);
	int pos = getPositionEmployeeInFoFromFile(id);
	if (pos == -1) cout << "Khong ton tai id";
	else
	{
		jsonEmployeeInfo.at("Employee").at(pos).update(newEmployee);
	}
	encryptFile(jsonEmployeeInfo, employeeInfoPath);

}
json BusinessIO::getEmpInfo()
{
	decryptFile(employeeInfoPath, jsonEmployeeInfo);
	return jsonEmployeeInfo["Employee"];
}

void BusinessIO::upDatePassWordToFile(string pass) {
	decryptFile(loginPath, jsonLogin);
	jsonLogin["password"] = pass;
	encryptFile(jsonLogin, loginPath);
}
void BusinessIO::getAccoutPassword(string& accout, string& password) {
	decryptFile(loginPath, jsonLogin);
	accout = jsonLogin["account"].get<string>();
	password = jsonLogin["password"].get<string>();
}
void BusinessIO::setAccountPassword(string account)
{
	decryptFile(loginPath, jsonLogin);
	jsonLogin["account"] = account;
	encryptFile(jsonLogin, loginPath);
}

// CRYPT
void BusinessIO::decryptFile(string filePath, json& info)
{
	char c;
	string fileData;
	ifstream file(filePath);
	file >> noskipws;
	while (file >> c) fileData += c;
	file.close();
	info = json::parse(decrypt(fileData));
}

void BusinessIO::encryptFile(json info, string filePath)
{
	ofstream file;
	file.open(filePath, ios::trunc);
	file << encrypt(info.dump().c_str());
	file.close();
}
string  BusinessIO::encrypt(string data) {

	for (int i = 0; i < data.length(); i++) {

		data[i] = data[i] - 9;

	}
	return data;
}
string BusinessIO::decrypt(string data) {

	for (int i = 0; i < data.length(); i++) {
		data[i] = data[i] + 9;
	}
	return data;
}

