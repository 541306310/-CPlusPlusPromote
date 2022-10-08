#pragma once
#include <iostream>
class CString
{
public:
	CString(const char *str);
	CString(const CString& obj);
	CString(CString&& obj) noexcept;
	CString sub(int start, int end);
	unsigned int len();
	char* Date;
	int Len;
};

