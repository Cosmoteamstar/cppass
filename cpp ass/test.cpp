#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
int DisplayMenu();
void Checkstock(string FN);
void Insertstock(string FN);
void Sellproduct(string FN);

int main(){
    const string Filename = "stock.txt";
    ifstream InFile;
    ofstream OutFile;
    int m;
    do {
        m = DisplayMenu();
        switch(m){
            case 1 :Checkstock(Filename); break;
            case 2 :Insertstock(Filename); break;
            case 3 :Sellproduct(Filename); break;
        }
    }while (m !=0);
        cout << "Exit Program." << endl;
        return(0);
}
    

int DisplayMenu(){
    int Choose;
    cout << endl;
    cout << "Program sales alcohol  " << endl;
    cout << "0.Exit" << endl;
    cout << "1.Check stock" << endl;
    cout << "2.Insert product" << endl;
    cout << "3.Sell product" << endl;
    cout << "Enter your choose number : ";
    cin >> Choose;
    return(Choose);
}

void Checkstock(string FN,string st[]){
    ifstream InFile(FN.c_str(), ios_base::in);
    if(InFile.is_open()){
        const  string st[Idp, Namep, Price, Amount];
        int n = 0;
        cout << "\nLiist Product\n";
        cout << "No. ID Name Amount\n";
        InFile >> st[Idp] >> st[Namep] >> st[Price] >> st[Amount];
        while(!InFile.eof()){
            n = n + 1;
            cout << right << setw(3) << n << " : ";
            cout << left << setw(3) << st[Idp];
            cout << right << setw(3) << st[Namep];
            cout << left << setw(3) << "  " << st[Price];
            cout << left << setw(3) << "  " << st[Amount] << endl;
            InFile >> st[Idp] >> st[Namep] >> st[Price] >> st[Amount];
        }
        InFile.close();
        char Wait;
        cin.get(Wait);
        cout << "\nPress Enter to continue";
        cin.get(Wait);
    }
    else cout <<"File could not opened." << endl;
}

void Insertstock(string FN){
    ofstream OutFile(FN.c_str(), ios_base::out | ios_base::app);
    if(OutFile.is_open()){
        string Idp,Namep;
        int Amount;
        cout << "Insert Product \n";
        cout << "Enter ID Product : ";
        cin >> Idp;
        cout << "Enter Name Product : ";
        cin >> Namep;
        cout << "Enter Amount Product : ";
        cin >> Amount;
        OutFile << Idp << " " << Namep << " " << Amount << endl;
        OutFile.close();
         char Wait;
        cin.get(Wait);
        cout << "\nSaved already ,Press Enter to continue";
        cin.get(Wait);
    }
    else cout << "File could not opened." <<endl;
}
void Sellproduct(string FN){
    ifstream InFile(FN.c_str(), ios_base::in | ios_base::out);
        if(InFile.is_open()){
        string Idp,Namep;
        int Amount;
        int n = 0;
        cout << "\nLiist Product\n";
        cout << "No. ID Name Amount\n";
        InFile >> Idp >> Namep >> Amount;
        while(!InFile.eof()){
            n = n + 1;
            cout << right << setw(3) << n << " : ";
            cout << left << setw(3) << Idp;
            cout << right << setw(3) << Namep;
            cout << left << setw(3) << "  " << Amount << endl;
            InFile >> Idp >> Namep >> Amount;
        }
        InFile.close();
        char Wait;
        cin.get(Wait);
        cout << "\nPress Enter to continue";
        cin.get(Wait);
    }
    else cout <<"File could not opened." << endl;
}