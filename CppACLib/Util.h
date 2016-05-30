#pragma once
#include <string>
#include <openssl/sha.h>

class Util
{
public:
	static std::string sha256(std::string input_string);
private:
	static std::string toHex(unsigned char* hash);
};

