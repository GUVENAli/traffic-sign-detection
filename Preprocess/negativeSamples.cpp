#include <iostream>
#include <fstream>
#include <string>
#include <tchar.h>
#include <Windows.h>

using namespace std;

void negList(string text)
{
	int x = 0;
	bool copy;
	string STRING;
    string RESULT;
    string SRC_PATH;
    string DST_PATH;
    ifstream myFile;
    ofstream bgFile;
    bgFile.open("bg.txt");
	myFile.open(text);
	while(!myFile.eof())
    {
    	getline(myFile, STRING);
    	if (STRING.length() < 28)
		{
			RESULT = STRING.substr(0, STRING.find(":"));
			SRC_PATH = "C:/Users/aligu/Downloads/Set1Part0/" + RESULT;
			DST_PATH = "neg/" + RESULT;
	    	cout << SRC_PATH << endl;
	    	CopyFile(SRC_PATH.c_str(), DST_PATH.c_str(),true);
	    	bgFile << DST_PATH << endl;
	    	x = x + 1;
		} 
    	
	}
    myFile.close();
    bgFile.close();
    cout << "Done. Total negative images: " << x << endl;
    cout << "Negative images were saved in neg/ folder!"<< endl;
}

int main()
{
    int sum = 0;
    string STRING;
    string RESULT;
    int x;
    
    negList("C:/Users/aligu/Desktop/annotations_train.txt");

    
    return 0;
}

