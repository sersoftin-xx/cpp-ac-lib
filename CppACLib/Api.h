#pragma once
#include <array>

namespace AccessControlLibrary
{
	class Api
	{
	public:
		Api(std::string baseUrl, std::array<unsigned char, 20> certHash);
		~Api();
	private:
		std::array<unsigned char, 20> _certHash;
	};
}
