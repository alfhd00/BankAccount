#ifndef __STR_CLASS__
#define __STR_CLASS__

#include <cstring>
#include <iostream>

class String
{
	private:
		char * str;
		int length;
	public:
		String()
		{
			std::cout << "String()" << std::endl;
			this->str = NULL;
			this->length = 0;
		}

		String(const char * str)
		{
			std::cout << "String(const chsr * str)" << std::endl;
			this->str = new char[strlen(str)+1];
			strcpy(this->str, str);

			length = strlen(str);
		}

		String(const String& str)
		{
			std::cout << "String(const String& str)" << std::endl;
			this->str = new char[str.length + 1];
			strcpy(this->str, str.str);
			
			this->length = str.length;
		}
/*
		static String operator=(const char * str)
		{
			
			return new String(str);
		}
*/
		String& operator=(const String& str);

		String& operator=(const char * str);

		String operator+(const String& str);

		String& operator+=(const String& str);
			
		bool operator==(const String& str);

		~String()
		{
			delete []str;
		}

		friend std::ostream& operator<<(std::ostream& os, String& str);
		friend std::istream& operator>>(std::istream& is, String& str);
};
#endif
