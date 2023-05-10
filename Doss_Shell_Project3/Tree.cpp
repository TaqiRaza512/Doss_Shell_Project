#include "Tree.h"
#include<string.h>
#include"File.h"
#include"Folders.h"
#include<iostream>
#include<fstream>
using namespace std;
Tree::Tree()
{

	Root = CurrentFolder=new Folders("C:",nullptr,"C:\\");
	CurrentFolder->InsertSubFolder("Pakistan");
	Folders*Pakistan=CurrentFolder->SubFolders.front();
	Pakistan->InsertSubFolder("Punjab");
	Pakistan->InsertSubFolder("Sindh");
	Pakistan->InsertSubFolder("Balochistan");
	Pakistan->InsertSubFolder("KPK");
}
void Tree::SaveTree()
{
	ofstream F("Tree.txt");
	list<Folders*>SaveList;
	Folders* Temp;
	/// /////////
	SaveList.push_back(Root);
	SaveList.push_back(nullptr);

	/////////////////////////////
	list<Folders*>::iterator SaveIT;
	////////////////////////////

	for (SaveIT = SaveList.begin(); SaveIT != SaveList.end(); SaveIT++)
	{
		if (*SaveIT==nullptr)
		{
			continue;
		}
		Temp = *SaveIT;
		F << Temp->Name;
		list<Folders*>::iterator it;
		for (it = Temp->SubFolders.begin(); it != Temp->SubFolders.end(); it++)
		{
			SaveList.push_back(*it);
			F << "Dir" << (*it)->Name << ",";
		}
	}
	cout << endl;
}
void Tree::GoThroughAllTree(Folders *CurrentFolder)
{
	if (CurrentFolder->SubFolders.size()==0)
	{
		return;
	}
	for (auto t=CurrentFolder->SubFolders.begin(); t != CurrentFolder->SubFolders.end();t++)
	{
		GoThroughAllTree(*t);
		cout << (*t)->Name << " ";
	}
	cout << endl;
}
void Tree::GoThroughAllTree()
{
	GoThroughAllTree(Root);
}
