#pragma once
#pragma warning(disable:4996)
#include<string>
#include<iomanip>
#include<list>
#include"File.h"
#include<time.h>
#include<ctime>
#include<iostream>
#include"Tree.h"
#include<filesystem>
#include"NotePad.h"

using namespace std;
class Folders
{
	friend class File;
	friend class Tree;
	friend class Doss;
private:
	string Name;
	string Extension;
	Folders* Parent;
	time_t Creation_Time;
	string Time;
	list<Folders*>SubFolders;
	list<File*>Files;
	string Path;
	bool Hidden;
public:
	Folders(string _Name = "null", Folders* _Parent = nullptr, string _Path = " ", list<Folders*>_Folders = list<Folders*>(), list<File*>_Files = list<File*>(), bool _Hidden = false, time_t _Creation_Time = time(0))
	{
		Name = _Name;
		Parent = _Parent;
		Path = _Path;
		Files = _Files;
		Hidden = _Hidden;

		SubFolders = _Folders;
		Creation_Time = _Creation_Time;

		Time= ctime(&Creation_Time);
		ConvertTime(Time);
	}
	void ConvertTime(string &Time)
	{
		string AM_PM;
		string Date = Time.substr(8, 2);
		string Month= Time.substr(4, 3);
		string Day = Time.substr(0,3);
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
		Time = Month +" "+ Date + "," + Year + "  " + Hour + ":" + Minute + ":" + Seconds + " " + AM_PM;
	}
	void InsertSubFolder(string _Name)
	{
		string Slash;
		if (Name!="C:")
		{
			Slash = "\\";
		}
		Folders* To_Be_Inserted = new Folders(_Name,this,Path+Slash+_Name);
		SubFolders.push_back(To_Be_Inserted);
	}
	void RemoveSubFolder(string _Name)
	{
		list<Folders*>::iterator it;
		for (it=SubFolders.begin();it!=SubFolders.end(); it++)
		{
			if ((*it)->Name==_Name)
			{
				SubFolders.erase(it);
				break;
			}
		}
	}
	void PrintSubFolders()
	{
		list<Folders*>::iterator it;
		cout << "Directory of " << Name << "  is :\n\n";
		for (it = SubFolders.begin(); it != SubFolders.end(); it++)
		{
			cout<< left<<setw(30) << (* it)->Time << " <DIR>  " << (*it)->Name;
			cout << endl;
		}
	}
	void PrintFiles()
	{
		list<File*>::iterator it;
		for (it = Files.begin(); it != Files.end(); it++)
		{
			cout << left << setw(38) << (*it)->Time  << (*it)->Name<< (*it)->Extension;
			cout << endl;
		}
	}
	void InsertSubFile(string _Name)
	{
		File* To_Be_Inserted = new File(_Name);
		Files.push_back(To_Be_Inserted);
	}
	Folders* FindFolder(string _Name)
	{
		list<Folders*>::iterator it;
		for (it=SubFolders.begin();it!=SubFolders.end(); it++)
		{
			if ((*it)->Name == _Name)
			{
				return (*it);
			}
		}
		return nullptr;
	}
	File* FindFile(string _Name)
	{

		list<File*>::iterator it;
		for (it = Files.begin(); it != Files.end(); it++)
		{
			if ((*it)->Name == _Name)
			{
				return (*it);
			}
		}
		return nullptr;
	}
	void RemoveFile(string _Name)
	{
		list<File*>::iterator it;
		for (it = Files.begin(); it != Files.end(); it++)
		{
			if ((*it)->Name == _Name)
			{
				Files.erase(it);
				break;
			}
		}
	}
	void DeleteFolder(Folders* Root)
	{
		if (Root==nullptr)
		{
			return;
		}
		list<Folders*>::iterator it;
		for (it = Root->SubFolders.begin(); it != Root->SubFolders.end(); it++)
		{
			DeleteFolder(*it);
		}
	}
	void DeleteFolder()
	{
		DeleteFolder(this);
	}

};