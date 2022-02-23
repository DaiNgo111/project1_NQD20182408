#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Date.h"
#include"BusinessIO.h"
#include <sstream>
#include<regex>
float getInputSalary(string);
//REGEX
bool checkInputPayroll(string payroll);
bool checkValidId(string id);
bool checkValidPhoneNum(string phoneNum);
bool checkValidName(string name);
bool checkValidDateInput(string date);
bool checkDateValid(string date);
enum type
{
    mNailTechnician,
    mManager,
    None
};
class Employee
{
private:
    string mId;
    string mName;
    string mAddress;
    Date mDoB;
    string mPhoneNum;
    type mType;
public:
    Employee();
    Employee(string id);
    Employee(string id, string name, string address, Date doB, string phoneNum);
    string getId();
    void setId(string);
    string getName();
    void setName(string);
    string getAddress();
    void setAddress(string);
    string getPhone();
    void setPhone(string);
    string getDoB();
    void setDoB(Date);
    type getType_info();
    void setType_info(type);
    virtual json toJsonObj();
    virtual float getCsSalary() { return 0; };
    virtual void setCsSalary(float) {};
    virtual void inputInformation();
    virtual void print();
    virtual void inputPayroll(Date) {};
};
#endif