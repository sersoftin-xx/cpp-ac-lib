#include "AccessRequest.h"


AccessRequest::AccessRequest(const std::string& pc_name, const std::string& pc_unique_key, int product_id)
	: _pc_name(pc_name),
	_pc_unique_key(pc_unique_key),
	_product_id(product_id)
{

}

std::string AccessRequest::getPcName() const
{
	return _pc_name;
}

std::string AccessRequest::getPcUniqueKey() const
{
	return _pc_unique_key;
}

int AccessRequest::getProductId() const
{
	return _product_id;
}

void AccessRequest::setPcName(std::string pc_name)
{
	_pc_name = pc_name;
}

void AccessRequest::setPcUniqueKey(std::string pc_unique_key)
{
	_pc_unique_key = pc_unique_key;
}

void AccessRequest::setProductId(int product_id)
{
	_product_id = product_id;
}