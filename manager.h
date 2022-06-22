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
	//默认构造
	Manager();
	//有参构造
	Manager(string name, string pwd);
	//显示菜单
	virtual void operMenu();
	//添加账号
	void addPerson();
	//查看账号
	void showPerson();
	//查看机房信息
	void showComputer();
	//清空预约记录
	void clearFile();

	//初始化容器
	void initVector();

	//学生容器
	vector<Student> vStu;

	//教师容器
	vector<Teacher> vTea;

	//检测重复	参数1 检测学号/职工号	参数2 检测类型
	bool checkRepeat(int id, int type);

	//存放机房信息
	vector<ComputerRoom> vCom;
private:
	string m_Name;
	string m_Pwd;
};