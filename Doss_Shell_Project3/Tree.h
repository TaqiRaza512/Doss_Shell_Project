#pragma once
#include"Folders.h"
#include"File.h"
#include<string>
#include<ctime>
#include<time.h>
using namespace std;

class Tree
{
	friend class Doss;

	friend class Folders;
private:

	Folders* Root;
	Folders* CurrentFolder;

public:

	Tree();
	void SaveTree();
	void GoThroughAllTree();
	void GoThroughAllTree(Folders*CurrentFolder); //it is working fine

};

