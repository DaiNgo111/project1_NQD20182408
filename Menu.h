#pragma once
#ifndef MENU_H
#define MENU_H
#include<Windows.h>
#include"EmployeeManagement.h"
#include"PayrollManagement.h"
#include"LoginManagement.h"
using namespace std;
// WELCOME, LOGIN, MAIN
void displayMainMenu();
void dislayWelcomeMenu();
// EMPLOYEE MANAGEMENT
void displayEmployeeManagementMenu();
void addEmployeeMenu();
void removeEmployeeMenu();
void searchInfoMenu();
void updateEmployeeMenu();
// PAYROLL MANAGEMENT
void displayPayrollManagementMenu();
void calculateSalaryAndProfitMenu();
void inputPayrollMenu();
// LOGIN MANAGEMENT
void displayChangePasswordMenu();
void displayLoginMenu();
#endif