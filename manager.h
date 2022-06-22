#pragma once
#include <iostream>
#include <fstream>
#include "globalFile.h"
#include <vector>
#include <string>
#include "Identity.h"
#include "teacher.h"
#include "student.h"
#include <algorithm>
#include "computerRoom.h"

using namespace std;

class Manager : public Identity
{
public:
	//Ĭ�Ϲ���
	Manager();
	//�вι���
	Manager(string name, string pwd);
	//��ʾ�˵�
	virtual void operMenu();
	//����˺�
	void addPerson();
	//�鿴�˺�
	void showPerson();
	//�鿴������Ϣ
	void showComputer();
	//���ԤԼ��¼
	void clearFile();

	//��ʼ������
	void initVector();

	//ѧ������
	vector<Student> vStu;

	//��ʦ����
	vector<Teacher> vTea;

	//����ظ�	����1 ���ѧ��/ְ����	����2 �������
	bool checkRepeat(int id, int type);

	//��Ż�����Ϣ
	vector<ComputerRoom> vCom;
private:
	string m_Name;
	string m_Pwd;
};