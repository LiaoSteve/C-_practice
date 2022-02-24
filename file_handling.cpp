#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    fstream myFile;
    myFile.open("write.txt", ios::out);//write
    if (myFile.is_open())
    {
        myFile << "Hello,F123456\n";
        myFile.close();
    }
    
    myFile.open("write.txt", ios::app);//append
    if (myFile.is_open())
    {
        myFile << "Hello2,F2123456\n";
        myFile.close();
    }

    myFile.open("write.txt", ios::in); //read
    if (myFile.is_open())
    {
        string s;
       
        while (getline(myFile, s, ','))
        {
            cout << s << endl;
        }
        myFile.close();
    }

    return 0;
}