#include "SystemFuncs.h"

#include <filesystem>
#include <iostream>
#include <fstream>

#include <string>
#include <vector>

#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cstddef>
#include <cstdint>


#include <minizip/unzip.h>
#include <json/json.h>

namespace stdfs = std::filesystem;


typedef char* charptr;
typedef void* voidptr;
typedef wchar_t* wcharTptr;


Json::Value LangZHCNConf;



std::filesystem::path GetWPSIntVerPath()
{
	stdfs::path RTPath;
#ifdef WIN32
	std::byte* U16StrBufferPtr;
	std::uint32_t BufferCap = 100, StrSize;
	std::wstring NPathStr;
	for (StrSize = BufferCap; true; BufferCap = BufferCap + 20)
	{
		U16StrBufferPtr = new std::byte[StrSize]();

		LSTATUS REGFuncStatus=RegGetValueW(
			HKEY_CURRENT_USER,
			L"Software\\kingsoft\\Office\\6.0\\Common",
			L"InstallRoot",
			RRF_RT_REG_SZ,
			nullptr,
			voidptr(U16StrBufferPtr),
			LPDWORD(&StrSize)
		);
		switch (REGFuncStatus)
		{
		case ERROR_SUCCESS:
			NPathStr = wcharTptr(U16StrBufferPtr);
			RTPath = NPathStr;
			delete[] U16StrBufferPtr;
			return RTPath;
		case ERROR_FILE_NOT_FOUND:
			std::fprintf(stderr, u8"无法在注册表找到WPS国际版的安装位置，\n可能您尚未安装WPS国际版。\n请安装后重试！\n");
			delete[] U16StrBufferPtr;
			U16StrBufferPtr = nullptr;
			std::exit(1);
		case ERROR_MORE_DATA:
			delete[] U16StrBufferPtr;
			U16StrBufferPtr = nullptr;
			break;
		default:
			delete[] U16StrBufferPtr;
			U16StrBufferPtr = nullptr;
			std::abort();
		}
	}
	
	
#endif // WIN32
	return RTPath;
 
}

std::filesystem::path GetWPSIntVerLocalizePkgPath()
{
	std::string PkgPath;
	do
	{
		std::cout << u8"输入汉化包的目录（包括带后辍名的包文件名）:\n";
		std::getline(std::cin, PkgPath);
		std::cout << '\n';
		if (!PkgPath.empty()) break;
	} while (true);
    return std::filesystem::path(PkgPath);
}

bool LocalizeWPSI(std::filesystem::path WpsPath, std::filesystem::path PkgPath)//unfinished
{
	//std::vector<std::byte> CompressedPkgBuffer, UncompressedPkgBuffer;
	std::ifstream FileReader;
	std::ofstream FileWriter;
	Json::Value WPSLangFile;

/*	unzFile unzipedpkg = unzOpen64((PkgPath.string()).c_str());
	unz_global_info64 zipPkgInfo;
	if (unzGetGlobalInfo64(unzipedpkg, &zipPkgInfo) != UNZ_OK)
	{
		unzClose(unzipedpkg);
		std::exit(-1);
	}





	
	FileReader.open(PkgPath.string(), std::ios_base::in | std::ios_base::binary | std::ios_base::ate);
	if (!FileReader.is_open()) { throw; }
	std::size_t buffersize = FileReader.tellg();
	FileReader.seekg(std::ios_base::beg);
	if (CompressedPkgBuffer.capacity() < buffersize) { CompressedPkgBuffer.resize(buffersize); }
	FileReader.read((char*)CompressedPkgBuffer.data(),CompressedPkgBuffer.capacity());
*/

	return false;
}
bool extractPkg(stdfs::path extractDir,stdfs::path PkgPath)
{

}







