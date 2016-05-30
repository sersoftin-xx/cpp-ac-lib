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

			std::string getUniqueKey() const;
			std::string getPcName() const;

			~Tower();
		private:
			TowerWmiInfo * _towerInfo;
			std::string _hash_salt;
		};
	}
}

