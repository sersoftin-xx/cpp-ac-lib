#include "Tower.h"
namespace AccessControlLibrary
{
	namespace Hardware
	{
		Tower::Tower(std::string hash_salt)
			:_hash_salt(hash_salt)
		{
			_towerInfo = new TowerWmiInfo();
		}

		std::string Tower::getUniqueKey() const
		{
			auto baseboardHash = _towerInfo->getBaseboard().getHash();
			auto systemEnclosureHash = _towerInfo->getSystemEnclosure().getHash();
			auto uuidHash = Util::sha256(_towerInfo->getPcUuid());
			return Util::sha256(baseboardHash + ":" + systemEnclosureHash + ":" + uuidHash + ":" + _hash_salt);
		}

		std::string Tower::getPcName() const
		{
			return getenv("COMPUTERNAME");
		}

		Tower::~Tower()
		{
			delete _towerInfo;
		}
	}
}