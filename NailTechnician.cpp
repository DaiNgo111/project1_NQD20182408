#include "NailTechnician.h"
NailTechnician::NailTechnician(string id, string name, string address, Date doB, string phone) : Employee(id, name, address, doB, phone) {
	this->setType_info(mNailTechnician);
}


NailTechnician::NailTechnician() : Employee()
{
	this->setType_info(mNailTechnician);
}

NailTechnician::NailTechnician(string id) : Employee(id)
{
	this->setType_info(mNailTechnician);
}

json NailTechnician::toJsonObj()
{
	string emp = "{\"address\":\"\",\"coefficientsSalary\":\"\",\"doB\":\"\",\"id\":\"\",\"name\":\"\",\"phoneNum\":\"\",\"type\":\"\"}";
	json employee = json::parse(emp);
	employee["address"] = getAddress();
	employee["coefficientsSalary"] = 0;
	employee["doB"] = getDoB();
	employee["id"] = getId();
	employee["name"] = getName();
	employee["phoneNum"] = getPhone();
	employee["type"] = mNailTechnician;
	return employee;
}
void NailTechnician::inputPayroll(Date d)
{
	string inputMoney, inputTips;
	BusinessIO payroll;
	do
	{
		cout << "Enter money(split + by each receipt, unit $), no space between words: ";
		getline(cin, inputMoney);
		if (!(checkInputPayroll(inputMoney)))
		{
			cout << "DATA NOT VALID. PLEASE RETYPE!!!" << endl;
		}
	} while (!(checkInputPayroll(inputMoney)));
	do
	{
		cout << "Enter money(split + by each receipt, unit $), no space between words: ";
		getline(cin, inputTips);
		if (!(checkInputPayroll(inputTips)))
		{
			cout << "DATA NOT VALID. PLEASE RETYPE!!!" << endl;
		}
	} while (!(checkInputPayroll(inputTips)));
	float salary = 0.6 * getInputSalary(inputMoney) + getInputSalary(inputTips);
	payroll.addEmployeeSalarytoFile(getId(), salary, d, getInputSalary(inputMoney) + getInputSalary(inputTips));
}
void NailTechnician::print()
{
	Employee::print();
	cout << setw(20) << left << "  Nail Technician";
}