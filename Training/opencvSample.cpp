#include <iostream>

int main()
{
	int retCode = system("opencv_createsamples.exe -info Preprocess/pos.info -w 40 -h 40 -vec pos.vec");
	
	return retCode;
}
