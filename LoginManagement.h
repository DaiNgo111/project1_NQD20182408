#pragma once
#ifndef LOGINMANAGEMENT_H
#define lOGINMANAGEMENT_H
#include "LoginManagement.h"
#include<iostream>
#include "BusinessIO.h"
#include<string>
class LoginManagement
{
private:
	string mUserName, mPassword;
	BusinessIO mLogin;
public:
	LoginManagement(string account);
	bool checklogin(string, string);

	void changePassword(string, string);


};
#endif

