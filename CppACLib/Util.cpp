#include "Util.h"

namespace AccessControlLibrary
{
	std::string Util::sha256(std::string input_string)
	{
		unsigned char hash[SHA256_DIGEST_LENGTH];
		SHA256_CTX sha256;
		SHA256_Init(&sha256);
		SHA256_Update(&sha256, input_string.c_str(), input_string.size());
		SHA256_Final(hash, &sha256);
		return toHex(hash);
	}

	std::string Util::toHex(unsigned char* hash)
	{
		char result[SHA256_DIGEST_LENGTH * 2 + 1];
		for (auto i = 0; i < SHA256_DIGEST_LENGTH; ++i)
		{
			sprintf(result + i * 2, "%02X", hash[i]);
		}
		result[SHA256_DIGEST_LENGTH * 2] = 0x00;
		return std::string(result);
	}
}