#pragma once
#include<iostream>
using namespace std;
#include<string>
#include<fstream>


//�������
class Identity
{
public:

	//menu ���麯��
	virtual void operMenu() = 0;
	//user
	string m_name;
	//passward
	string m_Pwd;
};

