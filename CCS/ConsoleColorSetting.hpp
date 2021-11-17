#ifndef CONSOLECOLORSETTING_HPP_INCLUDED
#define CONSOLECOLORSETTING_HPP_INCLUDED
#include <tuple>
#include <string>
#include <iostream>
#include <cstdint>
#ifdef WIN32
#include <Windows.h>
#endif






enum colorCode : unsigned
{
    Black=0, Red, Green, Yellow, Blue, Magenta, Cyan, White,
    Gray, BrightRed, BrightGreen, BrightYellow, BrightBlue, BrightMagenta, BrightCyan, BrightWhite
};


class ConsoleColorSetting
{
public:
    void setForegroundColor(colorCode cc);
    void setBackgroundColor(colorCode cc);
    void Reset();

private:
    ConsoleColorSetting();
    static bool ANSI_Escape_Codes_Supported;//true if unix/win10 1607+
    static bool IsWin10OrAbove;//true if win10 1607+ (1511 is end of service)
    static std::uint16_t DefaultWin32consoleAttributes;//"Default" wAttributes, will not be used if unix

public:
    ConsoleColorSetting(const ConsoleColorSetting&)=delete;
    ConsoleColorSetting& operator=(const ConsoleColorSetting&)=delete;
    ~ConsoleColorSetting();
    static ConsoleColorSetting& getInstance()
    {
        static ConsoleColorSetting inst;
        return inst;
    }
};

ConsoleColorSetting::ConsoleColorSetting()
{
    //gether sys info
    #ifdef WIN32
    CONSOLE_SCREEN_BUFFER_INFO win32_console_screen_buffer_info;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &win32_console_screen_buffer_info);
    this->DefaultWin32consoleAttributes ^= static_cast<uint16_t>(win32_console_screen_buffer_info.wAttributes);


    int Major = 0;
    int Minor = 0;
	NTSTATUS(WINAPI *RtlGetVersion)(LPOSVERSIONINFOEXW);
	OSVERSIONINFOEXW osInfo;

	*reinterpret_cast<FARPROC*>(&RtlGetVersion) = GetProcAddress(GetModuleHandleA("ntdll"), "RtlGetVersion");

	if (nullptr != RtlGetVersion)
	{
		osInfo.dwOSVersionInfoSize = sizeof osInfo;
		RtlGetVersion(&osInfo);
		Major = osInfo.dwMajorVersion;
		Minor = osInfo.dwMinorVersion;
	}

	if(Major>10) this->ANSI_Escape_Codes_Supported=true;
	else if(Major=10 and Minor>=1607) this->ANSI_Escape_Codes_Supported=true;
	else this->ANSI_Escape_Codes_Supported=false;

    #endif

}

ConsoleColorSetting::~ConsoleColorSetting()
{

}
void ConsoleColorSetting::setForegroundColor(colorCode cc)
{
    std::string colorCodeAnsi[]={"\x1b[30m","\x1b[31m","\x1b[32m","\x1b[33m","\x1b[34m","\x1b[35m","\x1b[36m","\x1b[37m",
    "\x1b[1;30m","\x1b[1;31m","\x1b[1;32m","\x1b[1;33m","\x1b[1;34m","\x1b[1;35m","\x1b[1;36m","\x1b[1;37m"};
    std::cout<<colorCodeAnsi[cc];
}

void ConsoleColorSetting::setBackgroundColor(colorCode cc)
{
    std::string colorCodeAnsi[]={"\x1b[40m","\x1b[41m","\x1b[42m","\x1b[43m","\x1b[44m","\x1b[45m","\x1b[46m","\x1b[47m",
    "\x1b[1;40m","\x1b[1;41m","\x1b[1;42m","\x1b[1;43m","\x1b[1;44m","\x1b[1;45m","\x1b[1;46m","\x1b[1;47m"};
    std::cout<<colorCodeAnsi[cc];
}
void ConsoleColorSetting::Reset(){std::cout<<"\x1b[0m";}
ConsoleColorSetting& ccs=ConsoleColorSetting::getInstance();




#endif // CONSOLECOLORSETTING_HPP_INCLUDED
