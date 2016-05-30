#pragma once
#include <array>

namespace AccessControlLibrary
{
	class Api
	{
	public:
		Api(std::string base_url, std::array<unsigned char, 20> cert_hash);
		~Api();
	private:
		std::array<unsigned char, 20> _certHash;
		std::string _base_url;

		std::string executeGetApiMethod(std::string method_name);
		std::string executePostApiMethod(std::string method_name, std::string request_body);
	};
}
