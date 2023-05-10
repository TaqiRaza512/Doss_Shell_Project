#pragma once
#include<vector>
#include<iostream>
#include"File.h"
#include<list>
#include"Tree.h"
#include"Folders.h"
#include<Windows.h>
#include"CurrentFile.h"
using namespace std;
class Doss
{
	friend class Tree;
	friend class Folder;
private:
	Tree T;
	NotePad ntpad;
	string command;
public:
	Doss()
	{
		command = "";
	}
	void color(int k)
	{
		if (k > 255)
		{
			k = 1;
		}
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, k);

	}
	void Profile()
	{
		gotoRowCol(0, 72);
		color(4);
		cout << "Muhammad Taqi Raza"<<" | "<<"BSCS20031\n";
	}
	void gotoRowCol(int rpos, int cpos)
	{
		COORD scrn;
		HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
		scrn.X = cpos;
		scrn.Y = rpos;
		SetConsoleCursorPosition(hOuput, scrn);
	}
	bool IsMakeDirectory()
	{
		string ChangedDirectory = command.substr(0, 5);
		if (ChangedDirectory == "mkdir")
		{
			string File_Name = command.substr(6,command.length());
			T.CurrentFolder->InsertSubFolder(File_Name);

			return true;
		}
		return false;
	}
	bool IsPrintDirectory()
	{
		if (command == "dir")
		{
			T.CurrentFolder->PrintSubFolders();
			T.CurrentFolder->PrintFiles();
			return true;
		}
		return false;
	}
	bool IsChangeDirectory()
	{
		string ChangeDirectory = command.substr(0,2);
		if (ChangeDirectory == "cd")
		{
			ChangeDirectory = command.substr(3, command.length());
			Folders*F=T.CurrentFolder->FindFolder(ChangeDirectory);
			T.CurrentFolder = F;
			cout << "\n Directory Changed Successfully\n";
			return true;
		}
		return false;
	}
	bool IsGoThrough()
	{
		if (command=="sheela")
		{
			T.GoThroughAllTree();
			return true;
		}
		return false;
	}
	bool IsClearScreen()
	{
		if (command=="cls")
		{
			system("cls");
			gotoRowCol(0, 72);
			color(4);
			cout << "Muhammad Taqi Raza" << " | " << "BSCS20031\n";
			return true;
		}
		return false;
	}
	bool IsGoToParent()
	{
		if (command=="cd..")
		{
			T.CurrentFolder = T.Root;
			return true;
		}
		return false;
	}
	bool IsCreateFile()
	{
		string CreateFile = command.substr(0, 6);
		if (CreateFile=="create")
		{
			CreateFile = command.substr(7,command.length());
			CreateFile = CreateFile.substr(0,CreateFile.size()-4);

			cout << CreateFile<<"\n";
			T.CurrentFolder->InsertSubFile(CreateFile);
			ntpad.NotePadFiles.push_back(T.CurrentFolder->Files.back()->CF);
			return true;
		}
		return false;
	}
	bool IsGotoRoot()
	{
		if (command=="cd\\")
		{
			while (T.CurrentFolder->Parent)
			{
				T.CurrentFolder = T.CurrentFolder->Parent;
			}
			return true;
		}
		return false;
	}
	bool IsEditFile()
	{
		string Edit=command.substr(0,12);

		if (Edit=="OpenEditFile")
		{
			Edit = command.substr(13, command.size() - 13-4);
			File* Temp = T.CurrentFolder->FindFile(Edit);
			if (Temp== nullptr)
			{
				cout << "File Not Exist";
				return true;
			}
			else
			{
				CurrentFile* F=ntpad.FindFile(Edit);
				F->Edit();
				F->Save();
			}
			return true;
		}
		return false;
	}
	bool IsExit()
	{
		if (command=="exit")
		{
			ntpad.DeleteAllFiles();
		}
		return false;
	}
	bool SaveTree()
	{
		if (command == "Save")
		{
			T.SaveTree();
			return true;
		}
		return false;
	}
	void ToLower()
	{
		for (int ri=0;ri<command.size();ri++)
		{
			if (65<=command[ri] and command[ri]<=90)
			{
				command[ri] = command[ri] + 32;
			}
		}
	}
	void InputCommand()
	{
		cout << T.CurrentFolder->Path<<">";
		getline(cin, command);
		if (IsExit())
		{
		}
		else if (SaveTree())
		{

		}
		else if (IsGoThrough())
		{
			//6
		}
		else if (IsCreateFile())
		{
		}
		else if (IsPrintDirectory())
		{
			//3
		}
		else if (IsMakeDirectory())
		{
			//>10
		}
		else if (IsGotoRoot())
		{
			//4
		}
		else if (IsGoToParent())
		{
			//3
		}
		else if (IsChangeDirectory())
		{
			//>5
		}
		else if (IsClearScreen())
		{
			//3
		}
		else if (IsEditFile())
		{


		}
		
		cout << endl;
	}
};
