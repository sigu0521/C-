#pragma once
#include<iostream>
using namespace std;
#include "Identity.h"
#include<string>
#include <vector>
#include "ComputerRoom.h"
#include "globalFILE.h"
#include <fstream>
#include "orderFile.h"

class Student : public Identity
{
public:
	//Ĭ�Ϲ���
	Student();
	//�вι���  ѧ�� ���� ����
	Student(int Id, string name, string pwd);

	//�˵�����
	virtual void operMenu();

	//����ԤԼ
	void applyOrder();
	//�鿴����ԤԼ
	void showMyOrder();
	//�鿴�����˵�ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void cancelOrder();

	//ѧ��ѧ��
	int m_Id;

	//��������
	vector<ComputerRoom>vCom;
};
