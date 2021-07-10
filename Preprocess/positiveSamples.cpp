#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <sstream>

using namespace std;

int numOccurence(string STRING, string temp)
{
	int ind, r, start, l, num_occ = 0;
	ind = STRING.find(temp);
	string TEMP_STRING = STRING;
	string RESULT = "";
	start = TEMP_STRING.find(":") + 1;
	while (true)
	{
		r = TEMP_STRING.find(temp);
		RESULT = RESULT + TEMP_STRING.substr(start, r-19);
		l = TEMP_STRING.length();
		if (TEMP_STRING.substr(r+1, l-1).find(temp) != string::npos)
		{
			TEMP_STRING = TEMP_STRING.substr(r+1, l-1);
			start = 19;
			num_occ = num_occ + 1;
		}
		else
		{
			break;
		}
	}
	return num_occ + 1;
}

void posList(string text)
{
	int x = 0;
	int ind = 0;
	int num_occ = 0;
	int start, r, l;
	int i, j, k;
	int x1= 0, y1 = 0, x2 = 0, y2 = 0;
	bool copy;
	string STRING;
    string IMAGE_NAME;
    string RESULT;
    string TEMP_STRING;
    string LOCATIONS;
    string SRC_PATH;
    string DST_PATH;
    string temp = "70_SIGN";
    ifstream myFile;
    ofstream posFile;
    posFile.open("pos.txt");
	myFile.open(text.c_str());
	i = 0;
	while (!myFile.eof())
	{
		stringstream ss;
		getline(myFile, STRING); 
		if (STRING.find(temp) != string::npos)
		{
			x = x + 1;
		}
		else
		{
			continue;
		}
    	RESULT = "";
    	num_occ = numOccurence(STRING, temp);
    	IMAGE_NAME = STRING.substr(0, STRING.find(":"));
    	TEMP_STRING = STRING.substr(STRING.find(":") + 1, STRING.find(";")-25);
    	k = 0;
    	if (TEMP_STRING.find(temp) != string::npos)
    	{
    		cout << "pos/" << IMAGE_NAME << " " << num_occ << " ";
    		posFile << "pos/" << IMAGE_NAME << " " << num_occ << " ";
    		ss << TEMP_STRING;
    		while (!ss.eof())
			{
				ss >> LOCATIONS;
				if (stringstream(LOCATIONS) >> j)
				{
					if (k >= 4)
					{
						k = k + 1;
						continue;
					}
					if (k == 0)
					{
						x1 = j;
					}
					else if(k == 1)
					{
						y1 = j;
					}
					else if(k == 2)
					{
						x2 = j;
					}
					else if(k == 3)
					{
						y2 = j;
					}
					k = k + 1;
					cout << j << " ";
				}
			}
			posFile << x2 << " " << y2 << " " << x1 - x2 << " " << y1 - y2;
    		//cout << IMAGE_NAME << " " << TEMP_STRING << " ";
		}
		else
		{
			cout << "pos/" << IMAGE_NAME << " " << num_occ << " ";
			posFile << "pos/" << IMAGE_NAME << " " << num_occ << " ";
		}
    	
    	while (true)
    	{
    		stringstream ss;
    		LOCATIONS = "";
			STRING = STRING.substr(STRING.find(";")+1, STRING.length()-1);
    		SRC_PATH = STRING.substr(0, STRING.find(";")+1);
    		if (SRC_PATH.find(temp) == string::npos)
    		{
    			if (SRC_PATH.length() <= 0)
	    		{
	    			break;
				}
    			continue;
			}
			ss << SRC_PATH;
			k = 0;
    		while (!ss.eof())
			{
				ss >> LOCATIONS;
				if (stringstream(LOCATIONS) >> j)
				{
					if (k >= 4)
					{
						k = k + 1;
						continue;
					}
					if (k == 0)
					{
						x1 = j;
					}
					else if(k == 1)
					{
						y1 = j;
					}
					else if(k == 2)
					{
						x2 = j;
					}
					else if(k == 3)
					{
						y2 = j;
					}
					k = k + 1;
					cout << j << " ";
				}
			}
			posFile << x2 << " " << y2 << " " << x1 - x2 << " " << y1 - y2;
    		//cout << SRC_PATH << " ";
    		//posFile << SRC_PATH << " ";
    		if (SRC_PATH.length() <= 0)
    		{
    			break;
			}
			
		}
		cout << endl;
    	posFile << endl;
    	DST_PATH = "pos/" + IMAGE_NAME;
    	SRC_PATH = "Set1Part0/" + IMAGE_NAME;
    	CopyFile(SRC_PATH.c_str(), DST_PATH.c_str(),true);
    	
	}
	
    myFile.close();
    posFile.close();
    cout << endl;
    cout << "Done. Total positive images: " << x << endl;
    cout << "Positive images were saved in pos/ folder!"<< endl;
    cout << "The list of directories of positive images was saved in pos.txt file!"<< endl;
}

int main()
{
    int sum = 0;
    string STRING;
    string RESULT;
    int x;
    
    posList("annotations_train.txt");

    
    return 0;
}
