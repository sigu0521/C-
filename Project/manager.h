#pragma once
#include<iostream>
using namespace std;
#include "Identity.h"
#include<string>
#include "globalFILE.h"
#include <vector>
#include "student.h"
#include "teacher.h"
#include <algorithm>
#include "ComputerRoom.h"

class Manager : public Identity
{
public:
	//Ĭ�Ϲ���
	Manager();
	//�вι���
	Manager(string name, string pwd);
	//ѡ��˵�
	virtual void operMenu();
	//����˺�
	void AddPerson();
	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showcomputer();

	//���ԤԼ��¼
	void cleanFile();

	//����ظ�
	bool checkRepeat(int id, int type);

	//��ʼ������
	void initVector();

	//ѧ������
	vector<Student>vStu;

	//��ʦ����
	vector<Teacher>vTea;

	//��������
	vector<ComputerRoom>vCom;
};