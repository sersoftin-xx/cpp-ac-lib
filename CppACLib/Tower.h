#pragma once
#include <string>
#include "TowerWmiInfo.h"

namespace AccessControlLibrary
{
	namespace Hardware
	{
		class Tower
		{
		public:
			explicit Tower(std::string hash_salt);
			~Tower();
		private:
			TowerWmiInfo
		};
	}
}

