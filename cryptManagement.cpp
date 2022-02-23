#include "cryptManagement.h"
#include<string>
//void cryptManagement::enCrypt(string &data) {
//
//	for (int i = 0; i < data.length(); i++) 
//	{
//		if ((data[i] != '\\') && (data[i] != ',') && (data[i] != '{')&& (data[i] != '"') && (data[i] != ':') && (data[i] != '}') && (data[i] != '[') && (data[i] != ']'))

//			data[i] = data[i] - key;
//		
//	}
//}
//void cryptManagement::deCrypt(string &data) {
//
//	for (int i = 0; i < data.length(); i++) {
//		data[i] = data[i] + key;
//	}
//}

string cryptManagement::enCrypt(string data) {

	for (int i = 0; i < data.length(); i++) {

		data[i] = data[i] - key;

	}
	return data;
}
string cryptManagement::deCrypt(string data) {

	for (int i = 0; i < data.length(); i++) {
		data[i] = data[i] + key;
	}
	return data;
}