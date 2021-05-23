#pragma once

class debug
{
	static void Out(const char* str);
	static void Out(const wchar_t* str);
public:
	static void Out(const std::string& str);
	static void Out(const std::wstring& str);
	static void OutLine(const char* str);
	static void OutLine(const wchar_t* str);
	static void OutLine(const std::string& str);
	static void OutLine(const std::wstring& str);
	static void Out(const int val);
	static void Out(const float val);
};

