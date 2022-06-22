#include <iostream>
#include <fstream>
#include "Identity.h"
#include "globalFile.h"
#include "student.h"
#include "manager.h"
#include "teacher.h"
using namespace std;

//进入管理员子菜单界面
void managerMenu(Identity*& manager)//引用指针
{
	while (true)
	{
		//调用管理员子菜单，此处的manager指针为父类identity的指针，只能调用父类的纯虚函数和成员属性，不能调用派生类的成员函数，可以看智能提示里面有多少个东西
		manager->operMenu();

		//将父类指针转换为子类指针，调用子类的其他接口
		Manager* man = (Manager*)manager;

		int select = 0;

		//接受用户选项
		cin >> select;
		if (select == 1)//添加账号
		{
			//cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2) //查看账号
		{
			//cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3) //查看机房
		{
			//cout << "查看机房" << endl;
			man->showComputer();
		}
		else if (select == 4) // 清空预约
		{
			//cout << "清空预约" << endl;
			man->clearFile();
		}
		else
		{
			delete manager; //销毁堆区对象
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入学生的子菜单界面
void studentMenu(Identity*& student)
{
	//使用父类指针调用重写的子菜单，多态概念
	student->operMenu();

	//转换指针为子类
	Student* stu = (Student*)student;
	//stu->operMenu();
	int select = 0;

	cin >> select;
	if (select == 1)//申请预约
	{
		stu->applyOrder();
	}
	else if (select == 2)//查看自身预约
	{
		stu->showMyOrder();
	}
	else if (select == 3)//查看所有人预约
	{
		stu->showAllOrder();
	}
	else if (select == 4)//取消预约
	{
		stu->cancelOrder();
	}
	else//注销登录
	{
		delete student;
		cout << "注销成功" << endl;
		system("pause");
		system("cls");
	}
}

//进入教师的子菜单界面
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		//调用子菜单界面
		teacher->operMenu();

		//进行指针转换
		Teacher* tea = (Teacher*)teacher;

		int select = 0;
		cin >> select;

		if (select == 1)//查看所有的预约
		{
			tea->showAllOrder();
		}
		else if (select == 2)//审核预约
		{
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//登录功能	参数1	操作文件名	参数2	操作身份类型
void loginIn(string filename, int type)
{
	//父类指针，用于指向子类对象
	Identity* person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(filename, ios::in);

	//判断文件是否存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	//文件存在，则判断类型,准备接受用户信息
	int id = 0;
	string name;
	string pwd;

	//判断身份
	if (type==1)//学生身份
	{
		cout << "请输入您的学号：" << endl;
		cin >> id;
	}
	else if( type == 2)//职工身份
	{
		cout << "请输入您的职工号：" << endl;
		cin >> id;
	}

	cout << "请输入您的用户名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;

	//进行身份验证
	if ( type == 1)
	{
		//学生身份验证
		int fId;//从文件中读取的Id号
		string fName;//从文件中读取的姓名
		string fPwd;//从文件中获取的密码
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "学生验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//进入学生身份的子菜单
				studentMenu(person);
				return;

			}
		}
	}
	else if( type == 2)
	{
		//教师身份验证
		int fId;
		string fName;
		string fPwd;
		while ( ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if ( id == fId && name == fName && pwd == fPwd)
			{
				cout << "教师验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//进入教师身份的子菜单
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//管理员身份验证
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "管理员验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//进入管理员身份的子菜单
				managerMenu(person);
				return;
			}
		}
	}

	cout << "验证登录失败！" << endl;
	system("pause");
	system("cls");
	return;
}



int main()
{
	int select;
	while (true)
	{
		cout << "==============================  欢迎来到初一的机房预约管理系统  ========================" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t ----------------------\n";
		cout << "\t\t|                      |\n";
		cout << "\t\t|                      |\n";
		cout << "\t\t|      1.学生代表      |\n";
		cout << "\t\t|                      |\n";
		cout << "\t\t|      2.老    师      |\n";
		cout << "\t\t|                      |\n";
		cout << "\t\t|      3.管 理 员      |\n";
		cout << "\t\t|                      |\n";
		cout << "\t\t|      0.退    出      |\n";
		cout << "\t\t|                      |\n";
		cout << "\t\t|                      |\n";
		cout << "\t\t ----------------------\n";
		cout << "请输入您的选择：" << endl;
		cin >> select;//接受用户选择
		switch (select)
		{
		case 1://学生身份
			loginIn(STUDENT_FILE, 1);
			break;
		case 2://老师身份
			loginIn(TEACHER_FILE, 2);
			break;
		case 3://管理员身份
			loginIn(ADMIN_FILE, 3);
			break;
		case 0://退出系统
			cout << "欢迎下一次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "您的输入有误！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}