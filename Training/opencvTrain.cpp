#include <iostream>

int main()
{
	int retCode = system("opencv_traincascade.exe -data data -vec pos.vec -bg Preprocess/bg.txt -numPos 1 -numNeg 1 -numStages 10 -minHitRate 0.999 -maxFalseAlarmRate 0.01 -w 40 -h 40 -mode ALL");
	
	return retCode;
}
