#include "student.h"

//Ĭ�Ϲ���
Student::Student()
{

}

//�вι��� ������ѧ�š�����������
Student::Student(int id, string name, string pwd)
{
	//��ʼ������
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		//����ȡ������Ϣ�ŵ�����֮��
		vCom.push_back(com);
	}
	ifs.close();

}

//�˵�����
void Student::operMenu()
{
	//�Ը����麯��������д
	cout << "��ӭѧ��������" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ----------------------\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|      1.����ԤԼ      |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|      2.�鿴�ҵ�ԤԼ  |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|      3.�鿴����ԤԼ  |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|      4.ȡ��ԤԼ      |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|      0.ע����¼      |\n";
	cout << "\t\t ----------------------\n";
}

//����ԤԼ
void Student::applyOrder()
{
	cout << "��������ʱ��Ϊ��һ�����壡" << endl;
	cout << "����������ԤԼ��ʱ�䣺" << endl;
	cout << "1.��һ" << endl;
	cout << "2.�ܶ�" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;
	cout << "5.����" << endl;

	int data = 0;//����
	int interval = 0;//ʱ���
	int room = 0; //�������

	while (true)
	{
		cin >> data;
		if (data >= 1 && data <= 5)
		{
			break;
		}
		cout << "������������������" << endl;
	}
	cout << "����������ԤԼ��ʱ��Σ�" << endl;
	cout << "1.����" << endl;
	cout << "2.����" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <=2)
		{
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "��ѡ�������" << endl;
	for (int i = 0; i < vCom.size(); i++)
	{
		cout << vCom[i].m_ComId << "�Ż�������Ϊ" << vCom[i].m_MaxNum << endl;
	}
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <=3)
		{
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "ԤԼ�ɹ��������" << endl;

	//�����ļ�
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::app);

	ofs << "data:" << data << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
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
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++)
	{
		//string תint
		//1.c++ string ����.c_str() ת const char*
		//2.����atoi ��const char*�� תint
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str()))//�ҵ�����ԤԼ
		{
			cout << "ԤԼ���ڣ���" << of.m_orderData[i]["data"];
			cout << " ʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
			cout << " ������" << of.m_orderData[i]["roomId"];
			string status = "״̬��";
			//1.����� 2.��ԤԼ -1.ԤԼʧ�� 0.ȡ��ԤԼ
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "�����";
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
	}
	system("pause");
	system("cls");
}

//�鿴����ԤԼ
void Student::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("puase");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << "��";
		cout << "ԤԼ���ڣ���" << of.m_orderData[i]["data"];
		cout << " ʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
		cout << " ѧ�ţ�" << of.m_orderData[i]["stuId"];
		cout << " ������" << of.m_orderData[i]["stuName"];
		cout << " ������ţ�" << of.m_orderData[i]["roomId"];
		string status = " ״̬��";

		//1 ����� 2 ��ԤԼ -1 ԤԼʧ�� 0 ȡ��ԤԼ
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "�����";
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
			status += "ԤԼ�Ѿ�ȡ��";
		}
		cout << status << endl;

	}
	system("pause");
	system("cls");
	return;

}

//ȡ��ԤԼ
void Student::cancelOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;
	vector<int>v;//�������������е��±���
	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		//���ж���������ѧ��
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str()))
		{
			//��ɸѡ״̬������л�ԤԼ�ɹ��Ĳſ���ȡ��
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "��";
				cout << "ԤԼ���ڣ���" << of.m_orderData[i]["data"];
				cout << " ʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
				cout << "������ţ�" << of.m_orderData[i]["roomId"];
				string status = " ״̬��";
				if (of.m_orderData[i]["status"] == "1")
				{
					status += "�����";
				}
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "ԤԼ�ɹ�";
				}
				cout << status << endl;
 			}
		}
	}

	cout << "������ȡ���ļ�¼��0��������" << endl;
	int select = 0;
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
				of.m_orderData[v[select - 1]]["status"] = "0";//�ĵ�״ֵ̬
				//�������ļ�
				of.updateOrder();
				cout << "��ȡ��ԤԼ" << endl;
				break;
			}
		}
		cout << "������������������" << endl;
	}
	system("pause");
	system("cls");
}