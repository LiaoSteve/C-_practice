#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main(){
    fstream myFile;
    myFile.open("write.txt", ios::out);//write
    if (myFile.is_open())
    {
        myFile << "/tmp/test/1.jpg,cat\n";
        myFile.close();
    }

    myFile.open("write.txt", ios::app);//append
    if (myFile.is_open())
    {
        myFile << "/tmp/test/2.jpg,dog\n";
        myFile.close();
    }

    vector<string> paths;
    vector<string> labels;
    cout << "open file" << endl;
    myFile.open("write.txt", ios::in); //read
    if (myFile.is_open())
    {
        cout << "open file" << endl;
        string s;

        while (getline(myFile, s, ','))
        {
            paths.push_back(s);
            cout << s << endl;
            getline(myFile, s, '\n');
            cout << s << endl;
            labels.push_back(s);
        }
        myFile.close();
    }
    for (int i=0; i<paths.size(); i++){
        cout<<"path: "<<paths[i] <<",label: "<<labels[i]<< endl;
    }
    
    
    for (int i=0; i<paths.size(); i++){
        stringstream ss(paths[i]);
        string s;
        while (getline(ss, s, '/'))
            continue;
        cout<<"image name: "<<s<< endl;
    }
    system("pause 0");
    return 0;
}
