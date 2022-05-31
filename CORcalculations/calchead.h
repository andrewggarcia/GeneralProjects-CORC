#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <Windows.h>
#include <tchar.h>


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

int main(int argc, char** argv);
int fill(ifstream& fin, vector<item>& things);
item search(int size, vector<item>& things, string SearchItem);
double calculate(vector<int> items, vector<item> things, int size);

#endif