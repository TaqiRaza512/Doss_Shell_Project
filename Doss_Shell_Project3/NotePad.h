#pragma once
#include<iostream>
#include<fstream>
#include<list>
#include"CurrentFile.h"
using namespace std;
class NotePad
{
	friend class Doss;
private:
	list<CurrentFile*> NotePadFiles;
public:
	NotePad()
	{
		NotePadFiles = list<CurrentFile*>();
	}
	CurrentFile* FindFile(string _name)
	{
		list<CurrentFile*>::iterator it;
		for (it = NotePadFiles.begin(); it != NotePadFiles.end(); it++)
		{
			if ((*it)->name == _name)
			{
				return (*it);
			}
		}
			return nullptr;
	}
	void DeleteAllFiles()
	{
		list<CurrentFile*>::iterator it;
		for (it = NotePadFiles.begin(); it != NotePadFiles.end(); it++)
		{
			string Name = (*it)->name + ".txt";
			fstream File(Name);
			File.close();
			remove(((* it)->name + ".txt").c_str());
		}
	}
};