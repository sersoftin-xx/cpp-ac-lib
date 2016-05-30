#pragma once
#include "Configuration.h"
namespace AccessControlLibrary
{
	class AccessControl
	{
	public:
		AccessControl(Configuration * configuration);



		~AccessControl();
	private:
		Configuration * _config;
	};
}