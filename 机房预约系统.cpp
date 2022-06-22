#include <iostream>
#include <fstream>
#include "Identity.h"
#include "globalFile.h"
#include "student.h"
#include "manager.h"
#include "teacher.h"
using namespace std;

//�������Ա�Ӳ˵�����
void managerMenu(Identity*& manager)//����ָ��
{
	while (true)
	{
		//���ù���Ա�Ӳ˵����˴���managerָ��Ϊ����identity��ָ�룬ֻ�ܵ��ø���Ĵ��麯���ͳ�Ա���ԣ����ܵ���������ĳ�Ա���������Կ�������ʾ�����ж��ٸ�����
		manager->operMenu();

		//������ָ��ת��Ϊ����ָ�룬��������������ӿ�
		Manager* man = (Manager*)manager;

		int select = 0;

		//�����û�ѡ��
		cin >> select;
		if (select == 1)//����˺�
		{
			//cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (select == 2) //�鿴�˺�
		{
			//cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3) //�鿴����
		{
			//cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (select == 4) // ���ԤԼ
		{
			//cout << "���ԤԼ" << endl;
			man->clearFile();
		}
		else
		{
			delete manager; //���ٶ�������
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//����ѧ�����Ӳ˵�����
void studentMenu(Identity*& student)
{
	//ʹ�ø���ָ�������д���Ӳ˵�����̬����
	student->operMenu();

	//ת��ָ��Ϊ����
	Student* stu = (Student*)student;
	//stu->operMenu();
	int select = 0;

	cin >> select;
	if (select == 1)//����ԤԼ
	{
		stu->applyOrder();
	}
	else if (select == 2)//�鿴����ԤԼ
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
	else//ע����¼
	{
		delete student;
		cout << "ע���ɹ�" << endl;
		system("pause");
		system("cls");
	}
}

//�����ʦ���Ӳ˵�����
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		//�����Ӳ˵�����
		teacher->operMenu();

		//����ָ��ת��
		Teacher* tea = (Teacher*)teacher;

		int select = 0;
		cin >> select;

		if (select == 1)//�鿴���е�ԤԼ
		{
			tea->showAllOrder();
		}
		else if (select == 2)//���ԤԼ
		{
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//��¼����	����1	�����ļ���	����2	�����������
void loginIn(string filename, int type)
{
	//����ָ�룬����ָ���������
	Identity* person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(filename, ios::in);

	//�ж��ļ��Ƿ����
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	//�ļ����ڣ����ж�����,׼�������û���Ϣ
	int id = 0;
	string name;
	string pwd;

	//�ж����
	if (type==1)//ѧ�����
	{
		cout << "����������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if( type == 2)//ְ�����
	{
		cout << "����������ְ���ţ�" << endl;
		cin >> id;
	}

	cout << "�����������û�����" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;

	//���������֤
	if ( type == 1)
	{
		//ѧ�������֤
		int fId;//���ļ��ж�ȡ��Id��
		string fName;//���ļ��ж�ȡ������
		string fPwd;//���ļ��л�ȡ������
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "ѧ����֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//����ѧ����ݵ��Ӳ˵�
				studentMenu(person);
				return;

			}
		}
	}
	else if( type == 2)
	{
		//��ʦ�����֤
		int fId;
		string fName;
		string fPwd;
		while ( ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if ( id == fId && name == fName && pwd == fPwd)
			{
				cout << "��ʦ��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//�����ʦ��ݵ��Ӳ˵�
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//����Ա�����֤
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "����Ա��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//�������Ա��ݵ��Ӳ˵�
				managerMenu(person);
				return;
			}
		}
	}

	cout << "��֤��¼ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
	return;
}



int main()
{
	int select;
	while (true)
	{
		cout << "==============================  ��ӭ������һ�Ļ���ԤԼ����ϵͳ  ========================" << endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t ----------------------\n";
		cout << "\t\t|                      |\n";
		cout << "\t\t|                      |\n";
		cout << "\t\t|      1.ѧ������      |\n";
		cout << "\t\t|                      |\n";
		cout << "\t\t|      2.��    ʦ      |\n";
		cout << "\t\t|                      |\n";
		cout << "\t\t|      3.�� �� Ա      |\n";
		cout << "\t\t|                      |\n";
		cout << "\t\t|      0.��    ��      |\n";
		cout << "\t\t|                      |\n";
		cout << "\t\t|                      |\n";
		cout << "\t\t ----------------------\n";
		cout << "����������ѡ��" << endl;
		cin >> select;//�����û�ѡ��
		switch (select)
		{
		case 1://ѧ�����
			loginIn(STUDENT_FILE, 1);
			break;
		case 2://��ʦ���
			loginIn(TEACHER_FILE, 2);
			break;
		case 3://����Ա���
			loginIn(ADMIN_FILE, 3);
			break;
		case 0://�˳�ϵͳ
			cout << "��ӭ��һ��ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "������������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}