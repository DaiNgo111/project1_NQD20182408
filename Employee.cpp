#include "Employee.h"
Employee::Employee() {
    this->mId = "";
    this->mAddress = "";
    this->mName = "";
    this->mPhoneNum = "";
    this->mDoB;
    this->mType = None;

}
Employee::Employee(string id, string name, string address, Date doB, string phoneNum) {
    this->mId = id;
    this->mName = name;
    this->mAddress = address;
    this->mPhoneNum = phoneNum;
    this->mDoB = doB;
    this->mType = None;

}
Employee::Employee(string id)
{
    this->mId = id;
    this->mAddress = "";
    this->mName = "";
    this->mPhoneNum = "";
    this->mDoB;
    this->mType = None;
}
void Employee::print()
{
    cout << "\t\t" << setw(15) << left << this->getId();
    cout << setw(20) << left << this->getName();
    cout << setw(20) << left << this->getAddress();
    cout << setw(20) << left << this->getDoB();
    cout << setw(20) << left << this->getPhone();
}
void Employee::inputInformation() {
    string dob;
    do
    {
        cout << "Enter Employee Name: ";
        getline(cin, mName);
        if (!(checkValidName(mName)))
        {
            cout << "DATA NOT VALID. PLEASE RETYPE!!!" << endl;
        }
    } while (!(checkValidName(mName)));
    cout << "Enter Employee Address: ";
    getline(cin, mAddress);
    do
    {
        cout << "Enter Employee Brithday (Format yyyy-mm-dd): ";
        cin >> dob;
        if (!(checkValidDateInput(dob)))
        {
            cout << "DATA NOT VALID. PLEASE RETYPE!!!" << endl;
        }
    } while (!(checkValidDateInput(dob)));
    mDoB.setDateByStr(dob);

    cin.ignore();
    do
    {
        cout << "Enter Employee Phone Number: ";
        getline(cin, mPhoneNum);
        if (!(checkValidPhoneNum(mPhoneNum)))
        {
            cout << "DATA NOT VALID. PLEASE RETYPE!!!" << endl;
        }
    } while (!(checkValidPhoneNum(mPhoneNum)));
}

string Employee::getId() {
    return mId;
}
void Employee::setId(string id) {
    this->mId = id;
}

string Employee::getName() {
    return mName;
}
void Employee::setName(string name) {
    this->mName = name;
}

string Employee::getAddress() {
    return mAddress;
}
void Employee::setAddress(string address) {
    this->mAddress = address;
}

string Employee::getPhone() {
    return mPhoneNum;
}
void Employee::setPhone(string phone) {
    this->mPhoneNum = phone;
}

string Employee::getDoB() {
    return mDoB.toStr();
}
void Employee::setDoB(Date doB) {
    this->mDoB = doB;
}

type Employee::getType_info() {
    return mType;
}
void Employee::setType_info(type type) {
    this->mType = type;
}

json Employee::toJsonObj()
{
    string emp = "{\"address\":\"\",\"coefficientsSalary\":\"\",\"doB\":\"\",\"id\":\"\",\"name\":\"\",\"phoneNum\":\"\",\"type\":\"\"}";
    json employee = json::parse(emp);
    employee["address"] = mAddress;
    employee["coefficientsSalary"] = 0;
    employee["doB"] = mDoB.toStr();
    employee["id"] = mId;
    employee["name"] = mName;
    employee["phoneNum"] = mPhoneNum;
    employee["type"] = None;
    return employee;
}
float getInputSalary(string input)
{
    float sum = 0;
    istringstream iss(input);
    string token;
    while (getline(iss, token, '+'))
    {
        float inputNum = stoi(token);
        sum += inputNum;
    }
    return sum;
}

//REGEX
bool checkValidId(string id)
{
    regex regexId("([a-zA-Z]+)([a-zA-Z]|\\d{1,9})$");
    return (regex_match(id, regexId));
}
bool checkValidPhoneNum(string phoneNum)
{
    regex regexPhoneNum("(\\+84|0)\\d{9,10}");
    return (regex_match(phoneNum, regexPhoneNum));
}
bool checkValidName(string name)
{
    regex regexName("([a-zA-Z\\s]+)");
    return (regex_match(name, regexName));
}
bool checkValidDateInput(string date)
{
    regex regexDate("\\b\\d{4}[-]\\d{1,2}[-]\\d{1,2}\\b");
    return ((regex_match(date, regexDate)) && (checkDateValid(date)));
}
bool checkInputPayroll(string payroll)
{
    regex regexPayroll("([0-9\+]*)([0-9])$");
    return (regex_match(payroll, regexPayroll));
}
bool checkDateValid(string date)
{
    istringstream iss(date);
    string token;
    getline(iss, token, '-');
    int year = stoi(token);
    getline(iss, token, '-');
    int month = stoi(token);
    getline(iss, token, '-');
    int day = stoi(token);
    int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (!year || !month || !day || month > 12)
        return 0;
    if ((((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) && month == 2)
        days[2]++;
    if (day > days[month])
        return 0;
    return 1;
}