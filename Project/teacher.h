#pragma once
#include<iostream>
using namespace std;
#include "Identity.h"
#include<string>
#include "orderFile.h"
#include "globalFILE.h"
#include <vector>

class Teacher : public Identity
{
public:
	//Ĭ�Ϲ���
	Teacher();
	//�вι���
	Teacher(int empId, string name, string pwd);
	//�˵�����
	virtual void operMenu();
	//�鿴ԤԼ
	void showAllOrder();
	//���ԤԼ
	void validOrder();


	//ְ����
	int m_EmpId;
};