#include "orderFile.h"
#include <iostream>
using namespace std;

//构造函数
OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string data;//日期
	string interval;//时间段
	string stuId;//学生编号
	string stuName;//学生姓名
	string roomId;//机房编号
	string status;//预约状态

	this->m_Size = 0;//记录条数

	while (ifs >> data && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		/*cout << data << endl;
		cout << interval << endl;
		cout << stuId << endl;
		cout << stuName << endl;
		cout << roomId << endl;
		cout << status << endl;*/

		//data:11
		string key;
		string value;
		map<string, string>m;

		int pos = data.find(":");//4
		if (pos != -1)
		{
			key = data.substr(0, pos);
			value = data.substr(pos + 1, data.size() - pos - 1); //size = 9 ,pos =4 ,size - pos = 5 - 1 =4
			//cout << key << endl << value << endl;
			m.insert(pair<string, string>(key, value));
		}

		//interval:1
		pos = interval.find(":");
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);
			//cout << key << endl << value << endl;
			m.insert(pair<string, string>(key, value));
		}
		//stuId:1
		pos = stuId.find(":");
		if (pos != -1)
		{
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos - 1);
			//cout << key << endl << value << endl;
			m.insert(pair<string, string>(key, value));
		}
		//stuName:1
		pos = stuName.find(":");
		if (pos != -1)
		{
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos - 1);
			//cout << key << endl << value << endl;
			m.insert(pair<string, string>(key, value));
		}
		//roomId:1
		pos = roomId.find(":");
		if (pos != -1)
		{
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos - 1);
			//cout << key << endl << value << endl;
			m.insert(pair<string, string>(key, value));
		}
		//status:1
		pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);
			//cout << key << endl << value << endl;
			m.insert(pair<string, string>(key, value));
		}
		this->m_orderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;
		
	}
	ifs.close();

	//测试最大map容器
	//for (auto it = m_orderData.begin(); it != m_orderData.end(); it++)
	//{
	//	cout << "key:" << it->first << endl;
	//	for (auto  mit = it->second.begin(); mit != it->second.end(); mit++)
	//	{
	//		cout << "key = " << mit->first << "	value = " << mit->second << " ";
	//	}
	//	cout << endl;
	//}
}

//更新预约记录
void OrderFile::updateOrder()
{
	if (this->m_Size == 0)
	{
		return;//预约记录为0挑，直接return
	}

	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < this->m_Size; i++)
	{
		ofs << "data:" << this->m_orderData[i]["data"] << " ";
		ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
		ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
		ofs << "status:" << this->m_orderData[i]["status"] << " " << endl;

	}
	ofs.close();
}