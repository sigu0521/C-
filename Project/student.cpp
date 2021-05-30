#include "student.h"

//Ĭ�Ϲ���
Student::Student()
{

}
//�вι���  ѧ�� ���� ����
Student::Student(int Id, string name, string pwd)
{
	this->m_Id = Id;
	this->m_name = name;
	this->m_Pwd = pwd;

	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
}

//�˵�����
void Student::operMenu()
{
	cout << "Welcome Student: " << this->m_name << " Login!" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|         1.Apply Order           |\n ";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|         2.Check My Order        |\n ";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|         3.Check All Order       |\n ";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|         4.Cancel Order          |\n ";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|         0.Exit                  |\n ";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "Please Input your choose: ";
}

//����ԤԼ
void Student::applyOrder()
{
	cout << "�������ŵ�ʱ��Ϊ��һ������" << endl;
	cout << "������ԤԼ��ʱ��:" << endl;
	cout << "1.Monday" << endl;
	cout << "2.Tuesday" << endl;
	cout << "3.Wednesday" << endl;
	cout << "4.Thursday" << endl;
	cout << "5.Friday" << endl;
	
	int date = 0; //ʱ��
	int interval = 0; //ʱ���
	int room = 0; //����

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "Input error! Please Input again!" << endl;
	}

	cout << "������ԤԼ��ʱ���:" << endl;
	cout << "1.In the morning" << endl;
	cout << "2.In the afternoon" << endl;

	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "Input error! Please Input again!" << endl;
	}

	cout << "��ѡ�����:" << endl;
	for (int i = 0; i < 3; i++) 
	{
		cout << vCom[i].m_ComId << "�Ż���������Ϊ :" << vCom[i].m_MaxNum << endl;
	}
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "Input error! Please Input again!" << endl;
	}
	cout << "ԤԼ�ɹ�! �����!" << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;

	ofs.close();

	system("pause");
	system("cls");

}
//�鿴����ԤԼ
void Student::showMyOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼!" << endl;
		system("pause");
		system("cls");
		return; 
	}
	for (int i = 0; i < of.m_Size; i++)
	{
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str()))//�ҵ�����ԤԼ
		{
			cout << "ԤԼ����: ��" << of.m_orderData[i]["date"] << " ";
			cout << " ʱ���:" << (of.m_orderData[i]["interval"] == "1" ? "Morning" : "Afternoon") << " ";
			cout << " �������:" << of.m_orderData[i]["roomId"] << " ";
			string status = "״̬: ";
			//1.����� 2.��ԤԼ -1.ԤԼʧ�� 4.ȡ��ԤԼ
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "�����...";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			else if (of.m_orderData[i]["status"] == "-1")
			{
				status += "ԤԼʧ�ܣ����δͨ��";
			}
			else
			{
				status += "ԤԼ��ȡ��";
			}
			cout << status << endl;
		}
		/*else
		{
			cout << "����ԤԼ��¼!" << endl;
			break;
		}*/
	}
	system("pause");
	system("cls");
}
//�鿴�����˵�ԤԼ
void Student::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼!" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << ". ";
		cout << "ԤԼ����: ��" << of.m_orderData[i]["date"] << " ";
		cout << " ʱ���:" << (of.m_orderData[i]["interval"] == "1" ? "Morning" : "Afternoon") << " ";
		cout << " ѧ��:" << of.m_orderData[i]["stuId"] << " ";
		cout << " ����:" << of.m_orderData[i]["stuName"] << "";
		cout << " �������:" << of.m_orderData[i]["roomId"] << " ";
		string status = "״̬: ";
		//1.����� 2.��ԤԼ -1.ԤԼʧ�� 4.ȡ��ԤԼ
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "�����...";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "ԤԼʧ�ܣ����δͨ��";
		}
		else
		{
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

//ȡ��ԤԼ
void Student::cancelOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼!" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "��ȡ����ԤԼ��¼��:" << endl;
	vector<int>v;
	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		//�ж��Ƿ�������ѧ��
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str()))
		{
			//ɸѡ״̬
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << ". ";
				cout << "ԤԼ����: ��" << of.m_orderData[i]["date"] << " ";
				cout << " ʱ���:" << (of.m_orderData[i]["interval"] == "1" ? "Morning" : "Afternoon") << " ";
				cout << " �������:" << of.m_orderData[i]["roomId"] << " ";
				string status = "״̬: ";
				//1.����� 2.��ԤԼ -1.ԤԼʧ�� 4.ȡ��ԤԼ
				if (of.m_orderData[i]["status"] == "1")
				{
					status += "�����...";
				}
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "ԤԼ�ɹ�";
				}
				cout << status << endl;
			}
		}
	}
	cout << "������ȡ���ļ�¼��0������" << endl;
	int select;

	while (true)
	{
		cin >> select;

		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				of.m_orderData[v[select - 1]]["status"] = "0";

				of.updateOrder();

				cout << "��ȡ��ԤԼ" << endl;
				break;
			}
		}
		else
		{
			cout << "������������������" << endl;
		}
	}
	system("pause");
	system("cls");
}