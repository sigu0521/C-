#include <iostream>
using namespace std;
#include "Identity.h"
#include <fstream>
#include <string>
#include "globalFILE.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"

//����ѧ���Ӳ˵�
void studentMenu(Identity*& student)
{
	while (true)
	{
		//�����Ӳ˵�
		student->operMenu();
		//������ָ��תΪ����ָ��
		Student* stu = (Student*)student;

		int select = 0;
		cin >> select;

		if (select == 1) //����ԤԼ
		{
			stu->applyOrder();
		}
		else if (select == 2) //�鿴����ԤԼ
		{
			stu->showMyOrder();
		}
		else if (select == 3)//�鿴������ԤԼ
		{
			stu->showAllOrder();
		}
		else if (select == 4)//ȡ��ԤԼ
		{
			stu->cancelOrder();
		}
		else //ע��
		{
			delete student;
			cout << "Log out!" << endl;
			system("pause");
			system("cls");
			return;
		}
	}

}

//�����ʦ�Ӳ˵�
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		//���ý�ʦ�˵�
		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;

		int select = 0;
		cin >> select;

		if (select == 1)//�鿴����ԤԼ
		{
			tea->showAllOrder();
		}
		else if (select == 2)//���ԤԼ
		{
			tea->validOrder();
		}
		else
		{
			//ע��
			delete teacher; //���ٶ�������
			cout << "Log out!" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


//�������Ա�Ӳ˵�����
void managerMenu(Identity*& manager)
{
	while (true)
	{
		//���ù�·Ա�Ӳ˵�
		manager->operMenu();

		//������ָ��תΪ����ָ��
		Manager* man = (Manager*)manager;

		int select = 0;
		//�����û�ѡ��
		cin >> select;

		if (select == 1)//����˺�
		{
			//cout << "���" << endl;
			man->AddPerson();
		}
		else if (select == 2)//�鿴�˺�
		{
			//cout << "�鿴 " << endl;
			man->showPerson();
		}
		else if (select == 3)//�鿴����
		{
			//cout << "���� " << endl;
			man->showcomputer();
		}
		else if (select == 4)//���ԤԼ
		{
			//cout << "���" << endl;
			man->cleanFile();
		}
		else
		{
			//ע��
			delete manager; //���ٶ�������
			cout << "Log out!" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


//��¼
void LoginIt(string filename, int type)
{
	//����ָ�룬ָ������
	Identity* person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(filename, ios::in);

	//�ж��ļ��Ƿ����
	if (!ifs.is_open())
	{
		cout << "no file!" << endl;
		ifs.close();
		return;
	}

	//׼�������û���Ϣ
	int id = 0;
	string name;
	string pwd;

	//student
	if (type == 1)
	{
		cout << "Please Enter The Student ID:" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "Please Enter The Employee ID:" << endl;
		cin >> id;
	}
	cout << "Please Enter Username:" << endl;
	cin >> name;

	cout << "Please Enter Passward:" << endl;
	cin >> pwd;
	if (type == 1)
	{
		//student��֤
		int fId;	//�ļ��е�ѧ��id
		string fName;	//�ļ��е�ѧ������
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//�Ƚ�
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "Login successful!" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//����ѧ�����Ӳ˵�
				studentMenu(person);
				return;
			}
			/*else
			{
				cout << "��������" << endl;
				system("pause");
				system("cls");
				return;
			}*/
		}

	}
	//teacher��֤
	else if (type == 2)
	{
		//teacher��֤
		int fId;	//�ļ��е���ʦid
		string fName;	//�ļ��е���ʦ����
		string fPwd;	//����
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//�Ƚ�
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "Login successful!" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//�����ʦ���Ӳ˵�
				teacherMenu(person);
				return;
			}
		}
	}
	//admin��֤
	else if (type == 3)
	{
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && fPwd == pwd)
			{
				cout << "Login successful!" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//�������Ա�˵�
				managerMenu(person);
				return;
			}
		}
	}
	
	cout << "Login Failed!" << endl;
	system("pause");
	system("cls");
	return;
}


int main()
{
	int select = 0;

	while (true)
	{
		cout << "=====================================welcome to the system of servation=====================================" << endl;
		cout << "Please enter your identity" << endl;
		cout << "\t\t ---------------------------------\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|           1.Student             |\n ";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|           2.Teacher             |\n ";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|           3.Adminstrator        |\n ";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|           0.Exit                |\n ";
		cout << "\t\t|                                 |\n";
		cout << "\t\t ---------------------------------\n";
		cout << "Please Input your choose: ";

		cin >> select;   //user Input

		switch (select) 
		{
		case 1:		//student
			LoginIt(STUDENT_FILE, 1);
			break;
		case 2:		//teacher
			LoginIt(TEACHER_FILE, 2);
			break;
		case 3:		//adminstrator
			LoginIt(ADMIN_FILE, 3);
			break;
		case 0:		//exit
			cout << "Welcome to use next time!" << endl;
			system("pause");
			return 0;
			break;
		default:	//error
			cout << "Input error! Please choose again!" << endl;
			system("pause");
			system("cls");
			break;
		}
	}


	system("pause");
	return 0;
}