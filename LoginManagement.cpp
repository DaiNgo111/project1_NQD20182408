#include "LoginManagement.h"
#include "Menu.h"


LoginManagement::LoginManagement(string account) {
	mLogin.setAccountPassword(account);
	this->mUserName = account;
	this->mPassword = "";
}
bool LoginManagement::checklogin(string userName, string password) {

	mLogin.getAccoutPassword(mUserName, mPassword);
	if (this->mUserName == userName && this->mPassword == password) {
		return true;

	}
	else {
		return false;


	}
}
void LoginManagement::changePassword(string oldPassword, string newPassword) {
	if (oldPassword == mPassword) {
		mLogin.upDatePassWordToFile(newPassword);
		cout << "Change password successfully !" << endl;
		Sleep(1000);
	}
	else {
		cout << "Incorrect old password, exited, haha !" << endl;
		Sleep(1000);
	}
}