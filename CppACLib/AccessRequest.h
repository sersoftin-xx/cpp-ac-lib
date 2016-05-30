#pragma once
#include <string>

class AccessRequest
{
public:
	AccessRequest(const std::string& pc_name, const std::string& pc_unique_key, int product_id);

	std::string getPcName() const;
	std::string getPcUniqueKey() const;
	int getProductId() const;

	void setPcName(std::string pc_name);
	void setPcUniqueKey(std::string pc_unique_key);
	void setProductId(int product_id);
private:
	std::string _pc_name;
	std::string _pc_unique_key;
	int _product_id;
};

