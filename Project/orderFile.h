#pragma once
#include <iostream>
using namespace std;
#include<fstream>
#include<string>
#include<map>
#include "globalFILE.h"

class OrderFile
{
public:
	//���캯��
	OrderFile();
	//����ԤԼ��¼
	void updateOrder();
	//��¼ԤԼ����
	int m_Size;
	//��¼ԤԼ��Ϣ������
	map<int, map<string, string>> m_orderData;

};