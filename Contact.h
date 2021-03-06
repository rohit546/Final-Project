#pragma once

#ifndef BASIC_LIB
#define BASIC_LIB
	#include <iostream>
	#include <string>
#endif // !BASIC_LIB

#include "Address.h"


class Contact {
private:
	std::string first_name;
	std::string last_name;
	std::string mobile_number;
	std::string email_address;
	Address* address;

public:
	bool equals(Contact contact);
	Contact* copy_contact();

	Contact() {
	
		address = new Address;
	
	}
	void operator = (const Contact& obj);
	Contact(std::string first_name, std::string last_name, std::string mobile_number, std::string email_address, Address *address);
	

	//setters :
	void set_first_name(std::string first_name);
	void set_last_name(std::string last_name);
	void set_mobile_number(std::string mobile_number);
	void set_email_address(std::string email_address);
	void set_address(Address* address);

	//getters:


	std::string get_first_name();
	std::string get_last_name();
	std::string get_mobile_number();
	std::string get_email_address();
	Address* get_address();

		
	

};
