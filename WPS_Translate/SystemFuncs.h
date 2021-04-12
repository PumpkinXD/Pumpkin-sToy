#ifndef __SYSTEM_FUNCS__INCLUDED__
#define __SYSTEM_FUNCS__INCLUDED__
#include <string>
#include <filesystem>
#ifdef WIN32
#include <Windows.h>
#endif // WIN32



std::filesystem::path GetWPSIntVerPath();
std::filesystem::path GetWPSIntVerLocalizePkgPath();
enum TermColorCode
{

};
bool ChangeTermColor(TermColorCode);

bool LocalizeWPSI(std::filesystem::path WpsPath,std::filesystem::path PkgPath);//soon






#endif