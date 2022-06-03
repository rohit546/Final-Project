#include "Contact.h"

/*
*	Implement a constructor that initializes all the Contact parts, including address. Call the setter to set values
*	as they have the logic to check correct input
*	Declaration is given in Contact.h
*/

void Contact::operator = (const Contact& obj) {


	this->first_name = obj.first_name;

	this->last_name = obj.last_name;

	this->email_address = obj.email_address;
	 
	this->mobile_number = obj.mobile_number;

	this->address = new Address;


	this->address = obj.address;


}

Contact::Contact(std::string first_name, std::string last_name, std::string mobile_number, std::string email_address, Address* address) {

	
	set_first_name(first_name);
	set_last_name(last_name);
	set_mobile_number(mobile_number);
	set_email_address(email_address);
	set_address(address);

}

/*
*	Implement getter/setters for all the member variables of Contact. Also declare them in the Contact.h header file
*	In each setter, do not set value if string is empty ("" 0 size). 
*   Check in phone number setter, Phone number must be 11 digits
*/


//setters :
void Contact:: set_first_name(std::string first_name){

	this->first_name = first_name;
}

void Contact::set_last_name(std::string last_name){

	this->last_name = last_name;
}

void Contact::set_mobile_number(std::string mobile_number){

	//if (mobile_number.length() < 11 || mobile_number.length() > 11)
		this->mobile_number = mobile_number;
	//else std::cout << "mobile number is invalid enter valid number";

}

void Contact::set_email_address(std::string email_address){

	if (email_address.find('@') != std::string::npos)
		this->email_address = email_address;
	else
		std::cout << "enter the valid email";

}


void Contact::set_address( Address* address){

	
	this->address = new Address;

	this->address->set_house(address->get_house());

	this->address->set_street(address->get_street());

	this->address->set_city(address->get_city());

	this->address->set_country(address->get_country());

 

}

//getters:


std::string Contact::get_first_name(){
	return first_name;
}

std::string  Contact::get_last_name(){
	return last_name;
}

std::string  Contact::get_mobile_number(){
	return mobile_number;
}

std::string  Contact::get_email_address(){
	return email_address;
}

Address* Contact::get_address() {
	return this->address;
}
/*
*	Implement the equals function(as declared in header file) that takes a 
*   Contact object and checks if it is equal to current object refered by (this pointer). 
*   Compare all the attributes.
*   For comparing address of contact you can call the equals function of the Address object;
*   For example: this.address.equals
*/

bool Contact::equals(Contact contact) {


	if (this->first_name == contact.first_name && this->last_name == contact.last_name && this->mobile_number == contact.mobile_number && 
		this->email_address == contact.email_address && address->get_city()==contact.address->get_city() && contact.address->get_house()==address->get_house()
		&& contact.address->get_street()==address->get_street() && contact.address->get_country()==address->get_country())
  return true;

	else return false;



}

Contact* Contact::copy_contact()
{
	/*
		Return a new object(deep copy of "this"[due to Address pointer, which should also be copied])
	*/

	Contact* temp = new Contact;

	*temp->address = *address;
	temp->email_address = email_address;
	temp->first_name = first_name;
	temp->last_name = last_name;
	temp->mobile_number = mobile_number;

	return temp;
}
