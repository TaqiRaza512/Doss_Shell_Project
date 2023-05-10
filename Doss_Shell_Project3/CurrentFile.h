#pragma once
#include<list>
#include<iostream>
#include<queue>
#include<stack>
#include<fstream>
#include<conio.h>
using namespace std;

struct state
{
	int CurrentRow, CurrentCol;
	list<list<char>> text;
	list<char>::iterator citr;
	list<list<char>>::iterator ritr;
};
class CurrentFile
{
	friend class Doss;
	friend class NotePad;
	friend class Folders;
	friend class File;
private:

	int CurrentRow, CurrentCol;
	string name;
	int size=0;
	list<list<char>> text;
	list<char>::iterator citr;
	list<list<char>>::iterator ritr;
	//undo 
	//Redo
public:
	CurrentFile(string _name)
	{
		CurrentRow = 0;
		CurrentCol = 0;
		name = _name;
		text.push_back(list<char>());
		ritr = text.begin();
		(*ritr).push_back(' ');
		citr = (* ritr).begin();
	}
	void OpenSaveFile()
	{
		list<list<char>>::iterator Temp = text.begin();

		for (Temp = text.begin(); Temp != text.end(); ++Temp)
		{
			list<char>::iterator Col;
			for (Col = (*Temp).begin(); Col != (*Temp).end(); Col++)
			{
				cout << *Col;
			}
			cout << endl;
		}
	}
	void SaveDataFromFileTo2dListBeforeEditing()
	{
		ifstream FileData(name + ".txt");
		char ch;
		while (!FileData.eof())
		{
			FileData >> ch;
			InsertText(ch);
		}
	}
	void Edit()
	{
		if (size>=1)
		{
			OpenSaveFile();
		}
		else if (size==0)
		{
			SaveDataFromFileTo2dListBeforeEditing();
		}
		while(1)
		{
			char ch = _getch();
			size++;
			cout << ch;
			InsertText(ch);
			if (ch == '1')
				return;
		}
	}
	void Save()
	{
		ofstream Save(name+".txt");
		char ch;
		list<list<char>>::iterator Temp = text.begin();
		for (Temp = text.begin(); Temp != text.end(); ++Temp)
		{
			list<char>::iterator Col;

			for (Col = (*Temp).begin(); Col != (*Temp).end(); Col++)
			{
				ch= *Col;
				Save << ch;
			}
			cout << endl;
		}
		Save.close();
	}
	void InsertText(char ch)
	{
		if (ch=='\n')
		{
			text.push_back(list<char>());
			ritr++;
			CurrentRow++;
		}
		else
		{
			(*ritr).push_back(ch);
			CurrentCol++;
		}
	}
	void PrintFile()
	{
		list<list<char>>::iterator Temp=text.begin();
		for (Temp = text.begin();Temp!= text.end(); ++Temp)
		{
			list<char>::iterator Col;
			for (Col = (* Temp).begin(); Col != (*Temp).end(); Col++)
			{
				cout << *Col;
			}
			cout << endl;
		}
	}
};