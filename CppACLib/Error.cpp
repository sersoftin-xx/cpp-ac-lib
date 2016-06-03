#include "Error.h"
#include <iostream>


namespace AccessControlLibrary
{
	namespace Entities
	{
		Error::Error(): _error_code(0)
		{
		}

		std::string Error::getMessage() const
		{
			return _message;
		}

		std::string Error::getUrl() const
		{
			return _url;
		}

		int Error::getCode() const
		{
			return _error_code;
		}

		void Error::setCode(int error_code)
		{
			_error_code = error_code;
		}

		Error::~Error()
		{
		}

		std::string Error::Serialize() const
		{
			Json::Value root;
			root["message"] = _message;
			root["url"] = _url;
			root["code"] = _error_code;
			Json::StyledWriter writer;
			return writer.write(root);
		}

		bool Error::Deserialize(std::string json_content)
		{
			Json::Value root;
			Json::Reader reader;
			if (!reader.parse(json_content, root))
				return false;
			_message = root.get("message", "").asString();
			_url = root.get("url", "").asString();
			_error_code = root.get("code", 0).asInt();
			return true;
		}
	}
}
