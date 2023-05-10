#include<iostream>
#include"NotePad.h"
#include"CurrentFile.h"
#include"Doss.h"
#include"Tree.h"
#include"File.h"
#include"Folders.h"

using namespace std;
int main()
{
	Doss D;
	D.Profile();
	while (true)
	{
		D.InputCommand();
	}
}