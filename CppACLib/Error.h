#pragma once
#include <json/json.h>

namespace AccessControlLibrary
{
	namespace Entities
	{
		class Error
		{
		public:
			Error();

			std::string getMessage() const;
			std::string getUrl() const;
			int getCode() const;

			void setCode(int error_code);

			std::string Serialize() const;
			bool Deserialize(std::string json_content);

			~Error();
		private:
			std::string _message;
			std::string _url;
			int _error_code;
		};		
	}
}
