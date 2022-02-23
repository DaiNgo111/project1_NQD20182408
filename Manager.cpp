#include "Manager.h"
Manager::Manager(string id, string name, string address, Date doB, string phoneNum, float csSalary) : Employee(id, name, address, doB, phoneNum) {
	this->mCsSalary = csSalary;
	this->setType_info(mManager);
}
Manager::Manager() : Employee()
{
	this->mCsSalary = 0;
	this->setType_info(mManager);
}
Manager::Manager(string id) : Employee(id)
{

	this->setType_info(mManager);
}
float Manager::getCsSalary()
{
	return mCsSalary;
}
void Manager::setCsSalary(float csSalary)
{
	this->mCsSalary = csSalary;
}
void Manager::inputInformation() {
	Employee::inputInformation();
	cout << "Enter Employee Salary per hour (unit $): ";
	cin >> mCsSalary;
}

void Manager::print()
{
	Employee::print();
	cout << setw(20) << left << "  Manager";
	cout << setw(20) << left << this->getCsSalary() << endl;;
}
void Manager::inputPayroll(Date d)
{
	float workHour;
	BusinessIO payroll;
	cout << "Enter hours/day (unit hour): ";
	cin >> workHour;
	payroll.addEmployeeSalarytoFile(getId(), (workHour * mCsSalary), d, 0);
}
json Manager::toJsonObj()
{
	string emp = "{\"address\":\"\",\"coefficientsSalary\":\"\",\"doB\":\"\",\"id\":\"\",\"name\":\"\",\"phoneNum\":\"\",\"type\":\"\"}";
	json employee = json::parse(emp);
	employee["address"] = getAddress();
	employee["coefficientsSalary"] = mCsSalary;
	employee["doB"] = getDoB();
	employee["id"] = getId();
	employee["name"] = getName();
	employee["phoneNum"] = getPhone();
	employee["type"] = mManager;
	return employee;
}