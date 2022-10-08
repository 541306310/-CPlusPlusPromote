#include <iostream>
#include "CString.h"

int main()
{
	CString str ("nihao");
	CString str1 = CString(str);
	CString str2 = str.sub(1, 2);
	std::cout << str.Date<<std::endl;
	std::cout << str2.Date << std::endl;

	std::cout << "Hello World!\n";
;
}
