#pragma once
#include <iostream>
#include "Identity.h"
#include "orderFile.h"
#include <vector>
using namespace std;

class Teacher : public Identity
{
public:
	//Ĭ�Ϲ���
	Teacher();
	//�вι���
	Teacher(int empId, string name, string pwd);
	//�˵�����
	virtual void operMenu();
	//�鿴����ԤԼ
	void showAllOrder();
	//���ԤԼ
	void validOrder();
	//ְ����
	int m_EmpId;
};