#pragma once
#include <string>
#include <stdarg.h>

namespace StringUtils
{
	std::string GetCommandLineArg(int inIndex);

	inline std::string Sprintf(const char* inFormat, ...)
	{
		//not thread safe...
		static char temp[4096];

		va_list args;
		va_start(args, inFormat);

#if _WIN32
		_vsnprintf_s(temp, 4096, 4096, inFormat, args);
#else
		vsnprintf(temp, 4096, inFormat, args);
#endif
		return std::string(temp);
	}

	void	Log(const char* inFormat);
	//void	Log(const char* inFormat, ...);
}

#define LOG( ... ) StringUtils::Log( __VA_ARGS__ );