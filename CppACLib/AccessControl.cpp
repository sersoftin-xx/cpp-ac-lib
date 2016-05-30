#include "AccessControl.h"

namespace AccessControlLibrary
{

	AccessControl::~AccessControl()
	{
	}

	AccessControl::AccessControl(Configuration* configuration)
	{
		_config = configuration;
	}
}
