#include <iostream>
#include "md5.cpp"
#include <string>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <Windows.h>
#include <winuser.h>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <complex>
#include <string>
using namespace std;

void toClipboard(HWND hwnd, const std::string &s);
int main(int argc, char *argv[])
{
	string userString;
	string md5String;
    	cout << "Write your string here: "<< endl;
    	cin>>userString;
	md5String=md5(userString);
	cout<<md5String;
	HWND hwnd = GetDesktopWindow();
	toClipboard(hwnd, md5String);
	cout << endl<<"String saved to clipboard";
	cout << endl<<"Press enter to exit";
	getch();
   	return 0;
}
void toClipboard(HWND hwnd, const std::string &s){
	OpenClipboard(hwnd);
	EmptyClipboard();	
	HGLOBAL hg=GlobalAlloc(GMEM_MOVEABLE,s.size()+1);
	if (!hg){
		CloseClipboard();
		return;
	}
	memcpy(GlobalLock(hg),s.c_str(),s.size()+1);
	GlobalUnlock(hg);
	SetClipboardData(CF_TEXT,hg);
	CloseClipboard();
	GlobalFree(hg);
}
