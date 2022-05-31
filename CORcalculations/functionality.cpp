#include "calchead.h"

item search(int size, vector<item>& things, string SearchItem)
{
    int i = 0;
    if (things[i].name == SearchItem)
        return things[i];

    //I'm not sure what the best search algorithem would be for this
    //I'll go by by big o for worse case, but I should also go by computational complexity
    //Try brute force for a start

    while (i < size || (things[i].name != SearchItem))
    {
        if (things[i].name == SearchItem)
            return things[i];
        i++;
    }

    return;

}

double calculate(vector<int> items, vector<item> things, int size)
{
    double FinalCalc = 0.0;//maybe use a 2x2 vector or just add another catagory
    int i = 0;

    while ( ( size > 0 ) && i < size)
    {
        FinalCalc = things[items[i]].estimate + FinalCalc;
    }

    return FinalCalc;


}
void menue()//Todo:look up how to add icons and interacitable grapics to this program
{

}

void output(ofstream fout, vector<item> things, double finalprice) //go over csv output or check to outputing to a .txt and then outputting that to an excell
{
    string filename;
    cout << "Pleses assign a file name:  ";
    cin >> filename;
    cout << endl;
    filename = filename + ".csv";


    fout.open(filename);
    if (!fout.is_open())
    {
        fout.close();
        cout << "error failed to open file\n";
        return;  //this return is nonviable, main will just contiue dispite the error
    }


}


