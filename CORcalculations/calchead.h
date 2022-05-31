#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <Windows.h>
#include <tchar.h>

static TCHAR szWindowClass[] = _T("DesktopApp");

static TCHAR szTitle[] = _T("Bid Calculation Desktop Application");

HINSTANCE hInst;

using namespace std;
#ifndef _CALCHEAD_H
#define _CALCHEAD_

struct item  //I might need to add another catigory to this to accound for the number of times an item is used
{
    string itmNum;
    string name;
    int quantity;
    string unit;
    double price;
    double estimate;
};

int WINAPI winpain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR     lpCmdLine,
    _In_ int       nCmdShow);

LRESULT CALLBACK WndProc(
    _In_ HWND   hWnd,
    _In_ UINT   message,
    _In_ WPARAM wParam,
    _In_ LPARAM lParam
);

int main(int argc, char** argv);
int fill(ifstream& fin, vector<item>& things);
item search(int size, vector<item>& things, string SearchItem);
double calculate(vector<int> items, vector<item> things, int size);

#endif