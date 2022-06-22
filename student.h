#pragma once
#include <iostream>
#include "computerRoom.h"
#include "Identity.h"
#include <vector>
#include <fstream>
#include "globalFile.h"
#include "orderFile.h"
using namespace std;

//ѧ����,�̳���Identity����
class Student : public Identity
{
public:
	//Ĭ�Ϲ���
	Student();

	//�вι��� ������ѧ�š�����������
	Student(int id, string name, string pwd);

	//�˵�����
	virtual void operMenu();
	
	//����ԤԼ
	void applyOrder();

	//�鿴����ԤԼ
	void showMyOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void cancelOrder();

	//ѧ��ѧ��
	int m_Id;
	
	//��������
	vector<ComputerRoom> vCom;

};