#include "Menu.h"
const Date currentDate = currentDate.presentDate();
PayrollManagement& payrollManager = PayrollManagement::instance();
EmployeeManagement& empManager = EmployeeManagement::instance();
LoginManagement loginManage("project1");// current pass 1234
// WELCOME, MAIN
void displayMainMenu()
{
	string option;
	while (true)
	{
		system("cls");
		cout << "\t\t\t\t\t******************MAIN MENU****************\n\n";
		cout << "\t\t\t\t\t[1]   :Go to Employee Management.\n";
		cout << "\t\t\t\t\t[2]   :Go to Payroll Management.\n";
		cout << "\t\t\t\t\t[3]   :Change password.\n";
		cout << "\t\t\t\t\t[0]   :Exit.\n";
		cout << "\t\t\t\t\tEnter your choice(interger): ";
		cin >> option;
		if (option == "1")
		{
			displayEmployeeManagementMenu();

		}
		else if (option == "2")
		{
			// displayPayrollManagementMenu();
			displayPayrollManagementMenu();
		}
		else if (option == "3")
		{
			// displayChangePasswordMenu();
			displayChangePasswordMenu();
		}
		else if (option == "0")
		{
			break;
		}
	}
}
void dislayWelcomeMenu()
{
	string option;
	while (true)
	{
		system("cls");
		cout << "\t\t\t\t\tWELCOME SPA MANAGEMENT SYSTEM MENU !\t\t\t\t\t\t\n" << endl;
		cout << "\tMENU:" << endl;
		cout << "\t\t[1]. Login." << endl;
		cout << "\t\t[2]. Exit." << endl;
		cout << "\tEnter your choice(interger): ";
		cin >> option;
		system("cls");
		if (option == "1")
		{
			displayLoginMenu();
		}
		else if (option == "2") break;
		else
		{
			cout << "Moi nhap lai";
			Sleep(1000);
		}
	}
}

// EMPLOYEE MANAGEMENT
void addEmployeeMenu()
{
	string empType;
	string id;
	bool flag = false;
	string option;
	cout << "\t\t\t\t\t******************ADD NEW EMPLOYEE MENU****************\n\n";
	cout << "Enter Employee Type (0: Nail Technician, 1: Manager): ";
	cin >> empType;
	if (empType == "0" || empType == "1")
	{
		do
		{
			cin.ignore();
			do
			{
				cout << "Enter Employee ID: ";
				getline(cin, id);
				if (!(checkValidId(id)))
				{
					cout << "DATA NOT VALID. PLEASE RETYPE!!!" << endl;
				}
			} while (!(checkValidId(id)));
			if (empManager.empExist(id) != NULL) {
				cout << "Duplicate ID, choice 0 to exit, 1 to continue: ";
				cin >> option;
				if (option == "0") flag = true;
				else if (option == "1") flag = false;
			}
		} while ((empManager.empExist(id) != NULL) && (flag == false));
		if (flag == false)
		{
			Employee* emp;
			if (empType == "1")
			{
				emp = new Manager(id);
				emp->inputInformation();
				empManager.addEmp(emp);
			}
			else if (empType == "0")
			{
				emp = new NailTechnician(id);
				emp->inputInformation();
				empManager.addEmp(emp);
			}
		}
	}
	else
	{
		cout << "EMPLOYEE TYPE DOESN'T EXIST";
		Sleep(1000);
	}
}
void removeEmployeeMenu()
{
	string id;
	cout << "\t\t\t\t******************REMOVE EMPLOYEE MENU****************\n\n";
	cout << "\t\t\t\tEnter Employee ID: ";
	cin.ignore();
	getline(cin, id);
	empManager.deleteEmp(id);
	Sleep(1000);

}
void updateEmployeeMenu() {
	string employeeID;
	cout << "\t\t\t\t\t******************UPDATE EMPLOYEE MENU****************" << endl;
	cout << "Enter Employee ID: ";
	cin.ignore();
	getline(cin, employeeID);
	empManager.updateEmp(employeeID);
}
void searchInfoMenu() {
	int choice;
	string employeeID;
	cout << "\t\t\t\t\t******************SEARCH EMPLOYEE MENU****************" << endl;
	cout << "Enter Employee ID: ";
	cin >> employeeID;
	empManager.searchEmp(employeeID);
}
void displayEmployeeManagementMenu()
{
	string option;
	while (true)
	{
		system("cls");
		cout << "\t\t\t\t\t******************EMPLOYEE MANAGEMENT MENU****************\n\n";
		cout << "\t\t\t\t[1]   :Print all employees information.\n";
		cout << "\t\t\t\t[2]   :Add new employee.\n";
		cout << "\t\t\t\t[3]   :Remove an employee by id.\n";
		cout << "\t\t\t\t[4]   :Update information an employee by id.\n";
		cout << "\t\t\t\t[5]   :Search information an employee by id.\n";
		cout << "\t\t\t\t[0]   :Exit.\n";
		cout << "\t\t\t\tEnter your choice(interger): ";
		cin >> option;
		if (option == "1")
		{
			do
			{
				// Print all employees information.
				system("cls");
				empManager.printEmployeeList();
				cout << endl;
				cout << "\t\t" << "Enter 0 to exit: ";
				cin >> option;
			} while (option != "0");

		}
		else if (option == "2")
		{
			// Add new employee.
			system("cls");
			addEmployeeMenu();

			Sleep(500);

		}
		else if (option == "3")
		{
			// Remove an employee by id.
			system("cls");
			removeEmployeeMenu();
		}
		else if (option == "4")
		{
			// Update information an employee by id.
			system("cls");
			updateEmployeeMenu();
		}
		else if (option == "5")
		{
			// Search information an employee by id.
			system("cls");
			searchInfoMenu();
		}
		else if (option == "0")
		{
			// exit
			break;
		}
	}
}
// PAYROLL MANAGEMENT
void displayPayrollManagementMenu()
{
	string option;
	while (true)
	{
		system("cls");
		cout << "\t\t\t\t\t******************PAYROLL MANAGEMENT MENU****************\n";
		cout << "\t\t\t\t[1]   :Input payroll for employee.\n";
		cout << "\t\t\t\t[2]   :Calculate salary and profit.\n";
		cout << "\t\t\t\t[0]   :Exit.\n";
		cout << "\t\t\t\tEnter your choice(interger): ";
		cin >> option;
		if (option == "1")
		{
			// InputPayrollforEmployee.
			system("cls");
			inputPayrollMenu();
		}
		else if (option == "2")
		{
			// calculateSalaryAndProfit();
			system("cls");
			calculateSalaryAndProfitMenu();
		}
		else if (option == "0")
		{
			break;
		}
	}
}

void calculateSalaryAndProfitMenu()
{
	Date startDate, endDate;
	string start, end;
	string option;
	bool flag = FALSE;
	do
	{
		system("cls");
		cout << "\t\t\t\t\t******************CALCULATE SALARY AND PROFIT MENU ****************" << endl;
		do
		{
			cout << "Enter Start Date (Format yyyy - mm - dd): ";
			cin >> start;
			if (!(checkValidDateInput(start)))
			{
				cout << "DATA NOT VALID. PLEASE RETYPE!!!" << endl;
			}
		} while (!(checkValidDateInput(start)));
		startDate.setDateByStr(start);

		do
		{
			cout << "Enter End Date (Format yyyy - mm - dd): ";
			cin >> end;
			if (!(checkValidDateInput(end)))
			{
				cout << "DATA NOT VALID. PLEASE RETYPE!!!" << endl;
			}
		} while (!(checkValidDateInput(end)));
		endDate.setDateByStr(end);

		if ((startDate > endDate) || (endDate > currentDate) || (startDate == endDate))
		{
			cout << "Start Date Must Be Less Than End Date And They Cannot Exceed The Current Date. Please Retype";
			Sleep(1500);
		}
		else
		{
			flag = true;
			do
			{
				system("cls");
				payrollManager.calculateSalaryAndProfit(startDate, endDate);
				cout << "\n\n";
				cout << "\t\t\t\t\t" << setw(5) << left << "Enter 0 to exit: ";
				cin >> option;
			} while (option != "0");
		}
	} while (((startDate < endDate) || (endDate < currentDate) || (startDate == endDate)) && /*(choice != 0)*/(flag == false));
}
void inputPayrollMenu()
{
	Date payrollDate;
	string date;
	string id;
	cout << "\t\t\t\t\t******************PAYROLL INPUT MENU****************\n";
	do
	{
		cout << "Enter Date (Format yyyy-mm-dd): ";
		cin >> date;
		if (!(checkValidDateInput(date)))
		{
			cout << "DATA NOT VALID. PLEASE RETYPE!!!" << endl;
		}
	} while (!(checkValidDateInput(date)));
	payrollDate.setDateByStr(date);

	if (payrollDate > currentDate)
	{
		cout << "Invalid date !";
		Sleep(1000);
	}
	else
	{
		cin.ignore();
		cout << "Enter Employee id: ";
		getline(cin, id);
		if (empManager.empExist(id) == NULL)
		{
			cout << "Invalid employee ! ";
			Sleep(1000);
		}
		else
		{
			empManager.empExist(id)->inputPayroll(payrollDate);
			Sleep(1000);
		}

	}
}
// LOGIN MANAGEMENT
void displayLoginMenu()
{
	string userName, password;
	cout << "\t\t\t\t\t******************MAIN MENU****************\n\n";
	cin.ignore();
	cout << "\t\t\t\t\tUserName: ";
	getline(cin, userName);
	cout << "\t\t\t\t\tPassword: ";
	getline(cin, password);
	if (loginManage.checklogin(userName, password))
	{
		cout << "Login success.";
		Sleep(1000);
		displayMainMenu();
	}
	else
	{
		cout << "Incorrect username or password.";
		Sleep(1000);
	}
}
void displayChangePasswordMenu()
{

	string oldPassword, newPassword;
	system("cls");
	cout << "\t\t\t\t\t******************CHANGE PASSWORD MENU ****************\n\n";
	cin.ignore();
	cout << "Enter old password.\n";
	getline(cin, oldPassword);
	cout << "\nEnter new password.\n";
	getline(cin, newPassword);
	loginManage.changePassword(oldPassword, newPassword);
}
