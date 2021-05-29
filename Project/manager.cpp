#include "manager.h"


//Ĭ�Ϲ���
Manager::Manager()
{

}
//�вι���
Manager::Manager(string name, string pwd)
{
	//��ʼ������Ա��Ϣ
	this->m_name = name;
	this->m_Pwd = pwd;
	//��ʼ������ ����ȡ��ʦ��ѧ����Ϣ
	this->initVector();
	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
	cout << "computer size  " << vCom.size() << endl;
}
//ѡ��˵�
void Manager::operMenu()
{
	cout << "Welcome Adminstrator: " << this->m_name << " Login!" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.Add User             |\n ";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.Check User           |\n ";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.Check Computer       |\n ";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.Clear                |\n ";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.Exit                 |\n ";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "Please Input your choose: ";
}
//����˺�
void Manager::AddPerson()
{
	cout << "Please Enter The AddType:" << endl;
	cout << " 1.Add Student" << endl;
	cout << " 2.Add Teacher" << endl;

	string fileName; //�����ļ���
	string tip;		//��ʾid
	string errortip;
	ofstream ofs; //�ļ���������

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//add student
		fileName = STUDENT_FILE;
		tip = "Please Enter Student ID:";
		errortip = "ѧ��id�ظ�������������";
	}
	else
	{
		//add teacher
		fileName = TEACHER_FILE;
		tip = "Please Enter Employee ID:";
		errortip = "��ʦid�ظ�������������";

	}

	ofs.open(fileName, ios::out | ios::app);

	int id;
	string name;
	string pwd;
	//�����Ϣ
	cout << tip << endl;
	while (true)
	{
		cin >> id;
		bool ret = checkRepeat(id, select);
		if (ret)
		{
			cout << errortip << endl;
		}
		else
		{
			break;
		}
	}

	cout << "Please Enter Your Name: " << endl;
	cin >> name;

	cout << "Please Enter Your Passward: " << endl;
	cin >> pwd;
	
	//д����Ϣ
	ofs << id << " " << name << " " << pwd << endl;
	cout << "Add success!" << endl;
	//���ó�ʼ�������ӿڣ����»�ȡ�ļ���Ϣ
	this->initVector();

	system("pause");
	system("cls");
	return;

}
void PrintStudent(Student& s)
{
	cout << "Id:" << s.m_Id << "  Name:" << s.m_name << "  Passward:" << s.m_Pwd << endl;
}
void PrintTeacher(Teacher& t)
{
	cout << "EmpId :" << t.m_EmpId << "Name :" << t.m_name << "Passward :" << t.m_Pwd << endl;
}

//�鿴�˺�
void Manager::showPerson()
{
	cout << "Please select what you want to view : " << endl;
	cout << "1.View all student information" << endl;
	cout << "2.View all teacher information" << endl;
	int select;
	cin >> select;
	if (select == 1)
	{
		//��ѧ��
		cout << "All student information :" << endl;
		for_each(vStu.begin(), vStu.end(), PrintStudent);
	}
	else
	{
		//����ʦ
		cout << "All teacher information :" << endl;
		for_each(vTea.begin(), vTea.end(), PrintTeacher);
	}
	system("pause");
	system("cls");
}

void PrintComputer(ComputerRoom& c)
{
	cout << "ComId:" << c.m_ComId << "  MaxNum:" << c.m_MaxNum << endl;
}
//�鿴������Ϣ
void Manager::showcomputer()
{
	cout << "������Ϣ����:" << endl;
	for_each(vCom.begin(), vCom.end(), PrintComputer);
	system("pause");
	system("cls");
}

//���ԤԼ��¼
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "��ճɹ�!" << endl;
	system("pause");
	system("cls");
}

void Manager::initVector()
{
	//���
	vStu.clear();
	vTea.clear();
	//��ȡѧ����Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "no file!" << endl;
		ifs.close();
		return;
	}

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "��ǰѧ������Ϊ :" << vStu.size() << endl;
	ifs.close();

	// ��ȡ��ʦ��Ϣ
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "no file!" << endl;
		ifs.close();
		return;
	}

	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ����Ϊ :" << vTea.size() << endl;
	ifs.close();
}

//����ظ�
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		//���ѧ��
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}
	else
	{
		//�����ʦ
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
	}

	return false;
}