#include "EmployeeManagement.h"
EmployeeManagement::EmployeeManagement()
{
	int size = mBusinessIO.getEmpInfo().size();
	for (int i = 0; i < size; i++)
	{
		if (mBusinessIO.getEmpInfo()[i].is_null() == false)
		{
			mEmployeeList[mBusinessIO.getEmpInfo()[i]["id"]] = jsonToEmp(mBusinessIO.getEmpInfo()[i]["id"]);
			delete jsonToEmp(mBusinessIO.getEmpInfo()[i]["id"]);
		}
	}
}
Employee* EmployeeManagement::empExist(string id) {
	map<string, Employee*>::iterator iter;
	int pos = -1;
	for (map<string, Employee*>::iterator it = mEmployeeList.begin(); it != mEmployeeList.end(); it++)
	{
		if (it->first == id)
		{
			pos = distance(mEmployeeList.begin(), it);
			break;
		}
	}
	if (pos == -1) return NULL;
	return mEmployeeList[id];
}

void EmployeeManagement::addEmp(Employee* emp)
{
	mEmployeeList[emp->getId()] = emp;
	mBusinessIO.addEmployeeToFile(mEmployeeList[emp->getId()]->toJsonObj());
	cout << "ADD COMPLETED" << endl;

}
void EmployeeManagement::deleteEmp(string id)
{
	if (empExist(id) == NULL) cout << "System doesn't include this id, remove failed.";
	else
	{
		map<string, Employee*>::iterator iter;
		iter = mEmployeeList.find(id);
		mEmployeeList.erase(iter);
		mBusinessIO.deleteEmployeeByIdToFile(id);
		cout << "Remove Successfully.";
	}
}
void EmployeeManagement::updateEmp(string id)
{

	if (empExist(id) == NULL) {
		cout << "System doesn't include this id, update failed. ";
		Sleep(1000);
	}
	else
	{
		updateEmpDetail(id);
	}
}
void EmployeeManagement::printEmployeeList()
{
	map<string, Employee*>::iterator it;
	cout << "\t\t" << setw(15) << left << "ID";
	cout << setw(20) << left << "Full Name";
	cout << setw(20) << left << "Address";
	cout << setw(20) << left << "Birthday";
	cout << setw(20) << left << "Phone Number";
	cout << setw(20) << left << "  Type";
	cout << setw(20) << left << "Salary/hour(unit $)" << endl;
	cout << setfill('-');
	cout << "\t\t" << setw(135) << "-" << endl;
	cout << setfill(' ');
	cout << endl;
	for (it = mEmployeeList.begin(); it != mEmployeeList.end(); it++)
	{
		it->second->print();
		if (it->second->getType_info() == mNailTechnician)
		{
			cout << setw(20) << left << "None" << endl;
		}
		cout << endl;
	}
	cout << setfill('-');
	cout << "\t\t" << setw(135) << "-" << endl;
	cout << setfill(' ');
	cout << endl;
	cout << "\t\t" << "Number of employee: " << mEmployeeList.size();
}

Employee* EmployeeManagement::jsonToEmp(string id)
{
	Employee* emp = NULL;
	int pos = mBusinessIO.getPositionEmployeeInFoFromFile(id);
	if (pos == -1) return NULL;
	else
	{
		string id = mBusinessIO.getEmpInfo().at(pos).at("id");
		string name = mBusinessIO.getEmpInfo().at(pos).at("name");
		string address = mBusinessIO.getEmpInfo().at(pos).at("address");
		float csSalary = mBusinessIO.getEmpInfo().at(pos).at("coefficientsSalary");
		Date doB(mBusinessIO.getEmpInfo().at(pos).at("doB").get<string>());
		string phoneNum = mBusinessIO.getEmpInfo().at(pos).at("phoneNum");
		if (mBusinessIO.getEmpInfo()[pos]["type"] == 1)
		{
			emp = new Manager(id, name, address, doB, phoneNum, csSalary); //Manager(string id, string name, string address, string doB, string phoneNum, float csSalary) :
		}
		else if (mBusinessIO.getEmpInfo()[pos]["type"] == 0)
		{
			emp = new NailTechnician(id, name, address, doB, phoneNum); //NailTechnician(string id, string name, string address, string date_em, string phone)
		}

		return emp;
	}
}
void EmployeeManagement::updateEmpDetail(string id)
{
	string choice;
	string newName, newAddress, newPhoneNum, dob;
	Date newDoB;
	float newCsSalary;
	Employee* emp = empExist(id);
	while (true)
	{
		system("cls");
		cout << "\t\t\t\t\t******************UPDATE EMPLOYEE MENU****************" << endl;
		cout << "[1]   :Update Name" << endl;
		cout << "[2]   :Update Address." << endl;
		cout << "[3]   :Update Day of Birth." << endl;
		cout << "[4]   :Update Phone Number." << endl;
		if ((emp->getType_info() == mManager)) cout << "[5]   :Update Coefficients Salary." << endl;
		cout << "[0]   :Exit." << endl;
		cout << "Enter your choice (integer): ";
		cin >> choice;

		if (choice == "1")
		{
			system("cls");
			cout << "\t\t\t\t\t******************UPDATE EMPLOYEE MENU****************" << endl;
			cin.ignore();
			do
			{
				cout << "Enter new employee's name: ";
				getline(cin, newName);
				if (!(checkValidName(newName)))
				{
					cout << "DATA NOT VALID. PLEASE RETYPE!!!" << endl;
				}
			} while (!(checkValidName(newName)));
			emp->setName(newName);
		}
		else if (choice == "2")
		{
			system("cls");
			cout << "\t\t\t\t\t******************UPDATE EMPLOYEE MENU****************" << endl;
			cin.ignore();
			cout << "Enter new employee's address: ";
			getline(cin, newAddress);
			emp->setAddress(newAddress);
		}
		else if (choice == "3")
		{
			system("cls");
			cout << "\t\t\t\t\t******************UPDATE EMPLOYEE MENU****************" << endl;
			cin.ignore();
			do
			{
				cout << "Enter new employee's birthday (Format yyyy-mm-dd): ";
				cin >> dob;
				if (!(checkValidDateInput(dob)))
				{
					cout << "DATA NOT VALID. PLEASE RETYPE!!!" << endl;
				}
			} while (!(checkValidDateInput(dob)));
			newDoB.setDateByStr(dob);
			emp->setDoB(newDoB);
		}
		else if (choice == "4")
		{
			system("cls");
			cout << "\t\t\t\t\t******************UPDATE EMPLOYEE MENU****************" << endl;
			cin.ignore();
			do
			{
				cout << "Enter new employee's phone number: ";
				getline(cin, newPhoneNum);
				if (!(checkValidPhoneNum(newPhoneNum)))
				{
					cout << "DATA NOT VALID. PLEASE RETYPE!!!" << endl;
				}
			} while (!(checkValidPhoneNum(newPhoneNum)));
			emp->setPhone(newPhoneNum);
		}
		else if ((choice == "5") && (emp->getType_info() == mManager))
		{
			system("cls");
			cout << "\t\t\t\t\t******************UPDATE EMPLOYEE MENU****************" << endl;
			cout << "Enter new employee's coefficients salary: ";
			cin >> newCsSalary;
			emp->setCsSalary(newCsSalary);
		}
		else if (choice == "0")
		{
			map<string, Employee*>::iterator iter;
			iter = mEmployeeList.find(id);
			if (iter != mEmployeeList.end())
				iter->second = emp;
			mBusinessIO.upDateEmployeeToFile(iter->first, iter->second->toJsonObj());
			cout << "Update Completed";
			Sleep(1000);
			break;
		}
	}
}
void EmployeeManagement::searchEmp(string id)
{
	int choice;
	if (empExist(id) == NULL)
	{
		cout << "System doesn't include this ID.";
		Sleep(1000);
	}
	else
	{
		do
		{
			system("cls");
			cout << "\t\t" << setw(15) << left << "ID";
			cout << setw(20) << left << "Full Name";
			cout << setw(20) << left << "Address";
			cout << setw(20) << left << "Birthday";
			cout << setw(20) << left << "Phone Number";
			cout << setw(20) << left << "  Type";
			if (empExist(id)->getType_info() == mNailTechnician)
			{
				cout << endl;
				cout << setfill('-');
				cout << "\t\t" << setw(115) << "-" << endl;
				cout << setfill(' ');
				empExist(id)->print();
			}
			else if (empExist(id)->getType_info() == mManager)
			{
				cout << setw(20) << left << "Salary/hour(unit $)" << endl;
				cout << setfill('-');
				cout << "\t\t" << setw(135) << "-" << endl;
				cout << setfill(' ');
				empExist(id)->print();
			}
			cout << "\n\t\t" << "Enter 0 to exit: ";
			cin >> choice;
		} while (choice != 0);
	}
}
