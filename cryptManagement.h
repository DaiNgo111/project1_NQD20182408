#pragma once
#ifndef CRYPTMANAGEMENT_H
#define CRYPTMANAGEMENT_H
#include<iostream>
#include<string>
using namespace std;
class cryptManagement
{
private:
	int key = 9;
public:
	/*void enCrypt(string &);
	void deCrypt(string &);*/
	string enCrypt(string);
	string deCrypt(string);
};
#endif

