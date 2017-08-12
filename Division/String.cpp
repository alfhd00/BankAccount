#include "String.h"

String& String::String::operator=(const String& str)
{
	std::cout << "String::operator=(const String& str)" << std::endl;

	if(this->str != NULL) delete []this->str;

	this->str = new char[strlen(str.str) + 1];
	strcpy(this->str, str.str);

	this->length = str.length;
	
	return *this;
}

String& String::operator=(const char * str)
{
	std::cout << "String::operator=(const char * str)" << std::endl;

	if(this->str != NULL) delete []this->str;

	this->str = new char[strlen(str)+1];
	strcpy(this->str, str);
	
	this->length = strlen(str);

	return *this;
}

String String::operator+(const String& str)
{
	std::cout << "String::operator+(const String& str)" << std::endl;

	char * newStr = new char[(this->length + str.length) + 1];
	strcpy(newStr, this->str);
	strcat(newStr, str.str);

	return String(newStr);
}

String& String::operator+=(const String& str)
{
	std::cout << "String::operator+(const String& str)" << std::endl;
	char * newstr = new  char[(length+str.length)+1];
	strcpy(newstr, this->str);
	strcat(newstr, str.str);

	if(this->str != NULL) delete []this->str;
	this->str = newstr;
	this->length = strlen(this->str);

	return *this;
}
	
bool String::operator==(const String& str)
{
	if(strcmp(this->str, str.str)==0) return true;
	else return false;
}

std::ostream& operator<<(std::ostream& os, String& str)
{
	os << str.str; 
	return os;
}

std::istream& operator>>(std::istream& is, String& str)
{
	char tmp[100];

	is >> tmp;
	str.String::operator=(tmp);
	
	return is;
}
