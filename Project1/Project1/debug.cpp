#include<DxLib.h>
#include<sstream>
#include "debug.h"

void debug::Out(const char* str)
{
	OutputDebugStringA(str);
}

void debug::Out(const wchar_t* str)
{
	OutputDebugStringW(str);
}

void debug::Out(const std::string& str)
{
	Out(str.c_str());
	Out("\n");
}

void debug::Out(const std::wstring& str)
{
	Out(str.c_str());
	Out("\n");
}

void debug::OutLine(const char* str)
{
	Out(str);
	Out("\n");
}

void debug::OutLine(const wchar_t* str)
{
	Out(str);
	Out("\n");
}

void debug::OutLine(const std::string& str)
{
	Out(str);
	Out("\n");
}

void debug::OutLine(const std::wstring& str)
{
	Out(str);
	Out("\n");
}

void debug::Out(const int val)
{
	std::ostringstream oss;
	oss << val;
	Out(oss.str());
	Out(L"\n");
}

void debug::Out(const float val)
{
	std::ostringstream oss;
	oss << val;
	Out(oss.str());
	Out(L"\n");
}
