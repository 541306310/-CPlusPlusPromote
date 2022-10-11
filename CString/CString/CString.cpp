#include "CString.h"
#include <cstring>

CString::CString(const char* str)
{
	Len = strlen(str) + 1;
	Date = new char[Len];
	memcpy(Date, str, Len);
}

CString::CString(const CString& obj)
{
	if (this == &obj)
	{
		return;
	}
	this->Len= obj.Len;
	this->Date = new char[this->Len];
	memcpy(this->Date, obj.Date, Len);
}

CString::CString(CString&& obj) noexcept
{
	if (this == &obj)
		return;
	this->Date = std::exchange(obj.Date,nullptr);
	this->Len = obj.Len;
}

CString CString::sub(int start, int end)
{
	if (start < 0 || end > this->Len-1)
		return nullptr;
	int len = end - start +1 ;
	char *tep = new char[len + 1];
	int tep_flag = 0;
	for (int i=start;i <= end; i++,tep_flag++)
	{
		tep[tep_flag] = this->Date[i];
	}
	tep[tep_flag+1] = '\0';
	CString ret (tep);
//	delete []tep;
	return ret;
}

unsigned int CString::len()
{
	return Len;
}

