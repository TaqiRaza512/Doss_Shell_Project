#pragma once
#pragma warning(disable:4996)
#include<time.h>
#include<fstream>
#include<iostream>
#include<ctime>
#include"CurrentFile.h"
#include<string>
using namespace std;

class File
{
	friend class Folders;
	friend class Doss;
	friend class Tree;

private:
	string Name;
	time_t Creation_Time;
	string Path;
	string Time;
	CurrentFile* CF;
	string Extension;

	bool Hidden;
	void CreationOfFile()
	{
		ofstream FileCreator(Name + Extension);
		if (FileCreator.is_open())
		{
			cout << "File Created";
			FileCreator.close();
		}
		else
		{
			cout << "File Not created";
		}
	}
	void ConvertTime(string& Time)
	{
		string AM_PM;
		string Date = Time.substr(8, 2);
		string Month = Time.substr(4, 3);
		string Day = Time.substr(0, 3);
		string Hour = Time.substr(11, 2);
		int Hr = stoi(Hour);
		if (Hr > 12)
		{
			Hr = Hr - 12;
			AM_PM = "PM";
		}
		else
		{
			AM_PM = "AM";
		}
		Hour = to_string(Hr);
		string Minute = Time.substr(14, 2);
		string Seconds = Time.substr(17, 2);
		string Year = Time.substr(20, 4);
		Time = "";
		Time = Month + " " + Date + "," + Year + "  " + Hour + ":" + Minute + ":" + Seconds + " " + AM_PM;
	}

public:
	File(string _Name = "Null", string _Path = "", time_t _Creation_Time = time(0), bool _Hiddden = false,string _Extension=".txt",CurrentFile *_CF=nullptr)
	{
		Name = _Name;
		Extension = _Extension;
		Path = _Path;
		Creation_Time = _Creation_Time;
		Time = ctime(&Creation_Time);
		ConvertTime(Time);
		Hidden = _Hiddden;
		if (!_CF)
		{
			CF = new CurrentFile(Name);
		}
		else
		{
			CF = _CF;
		}
		CreationOfFile();
	}
};