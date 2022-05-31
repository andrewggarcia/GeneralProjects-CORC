#include "calchead.h"

//I'm not sure how to port this to a proper desktop app so for now I'm going to make this a cl
//program and go from there

//I'm going to need to redo this, the overall design is wrong because I had to alter the 
//struct the program is based on. I'll go through and alter the program tonight and go
//though how to do app design with VS code

int WINAPI winpain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR     lpCmdLine,
    _In_ int       nCmdShow)
{
    
}

LRESULT CALLBACK WndProc(
    _In_ HWND   hWnd,
    _In_ UINT   message,
    _In_ WPARAM wParam,
    _In_ LPARAM lParam
)
{
     
}

int main(int argc, char** argv)
{
    ifstream fin;
    ofstream fout;
    vector <item> things;
    vector <item> output;
    vector <int> items;
    int size, item;
    double price;
    string searchitem;

    if (argc < 2)
    {
        cout << "Error: too few files\n";
        return 0;
    }
    fin.open(argv[1]);

    if (!fin.is_open())
    {
        cout << "unable to open file\n";
        return 0;
    }
    
    size = fill(fin, things);

    while (getline(cin, searchitem))
    {
        search(size, things, searchitem);
        cout << endl;
    }

    price = calculate(items, things, size);

    return 0;
}

int fill(ifstream& fin, vector<item>& things)
{
    int i = 0, quantity, unit;
    string temp, price;
    double priceD;
    
    getline(fin, temp, ',');
    getline(fin, price,'\n'); //this is only nessicarry if there's a header in the
    //inital csv file, which I doubt but Ill keep this in here just in case
    while ( getline(fin, temp, ',') && &things[i] != NULL)
    {
        
        things.push_back(item());
        things[i].itmNum = temp;
        getline(fin, temp, ',');   //this should sucesfully read in the csv file
        things[i].name = temp;
        getline(fin, temp, ',');
        quantity = stoi(temp);
        things[i].quantity = quantity;
        getline(fin, temp, ',');
        things[i].unit = temp;
        getline(fin, price, '\n');
        priceD = stod(price);
        things[i].price = priceD;

        things[i].estimate = things[i].price * double(things[i].quantity);
       
        i++;
    }

    return i;

}

