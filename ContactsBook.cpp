#include "ContactsBook.h"



ContactsBook::ContactsBook(int size_of_list)
{
	/*
	*	Initialize the contacts_list array, also initialize the size and count members accordingly
	*/

	contacts_count = 0;

	size_of_contacts = size_of_list;
	contacts_list = new Contact[size_of_list];



}

void ContactsBook::set_size_of_list(int size) { 
	
	size_of_contacts = size; 
	contacts_list = new Contact[size];


};

void ContactsBook::add_contact(Contact& contact)
{
	/*
	* 
	* 
		- Check if the list is full, if it is full call the resize function
		- If list is not full add the contact to the end of the array 
		- (end means the place where last contact was inserted)
		- At start it will be 0th index as no contact has been inserted before so 
		- count is zero (contacts_count member)
		- Increment the count
		- As inserted successfully, return 1
	*/
	if (full())
		resize_list();

	contacts_list[contacts_count++] = contact;


}

int ContactsBook::total_contacts()
{
	/*
	*	Return the total contacts currently stored
	*/

	/*
	*	Remove this return -1; before writing your code
	*/
	return contacts_count;
}

bool ContactsBook::full()
{
	/*
	* Return true if list is full, false otherwise
	*/

	if (contacts_count >= size_of_contacts)
		return true;

	/*
	*	Remove this return false; before writing your code
	*/
	return false;
}

void ContactsBook::resize_list()
{
	/*
	*	Here you will resize the contact list, see example code given in lab manual to see how to resize arrays
	*	You will allocate a temporary new array of double the current size and copy the contacts from 
	*   previous array to this array one by one, get the copy of each contact using copy_contact 
	*   function of Contact class
	*	Delete the previous array
	*	Assign the new temporary array to the contacts_list pointer
	*	Updated the this->size_of_contacts with new size
	*/
	             

	size_of_contacts *= 2;

	Contact* temp = new Contact[size_of_contacts];

	for (int i = 0; i < size_of_contacts; i++) {

		temp[i] = *contacts_list[i].copy_contact();
	}

	delete[]contacts_list;
	contacts_list = NULL;
	contacts_list = temp;

}

Contact* ContactsBook::search_contact(std::string first_name, std::string last_name)
{
	/*
	*	In all search functions perform the searching according the given parameter and return a copy of the contact using copy func
	*	Remove this return nullptr; before writing your code
	*/

	Contact* temp = new Contact;

	for (int i = 0; i < contacts_count; i++) {

		if (contacts_list[i].get_first_name() == first_name && contacts_list->get_last_name() == last_name)

			*temp = contacts_list[i];
		else std::cout << "erroe";
	}

	


	return temp; 
	
}

Contact* ContactsBook::search_contact(std::string phone)
{
	/*
	*	Remove this return nullptr; before writing your code
	*/
	Contact* temp = new Contact;


	for (int i = 0; i < contacts_count; i++) {

		if (contacts_list[i].get_mobile_number()==phone)

			*temp = contacts_list[i];

	}

	return temp;
}
                                                     
Contact* ContactsBook::search_contact(Address address)
{

	Contact* temp = new Contact;
	/*
	*	Remove this return nullptr; before writing your code
	*/


	for (int i = 0; i < contacts_count; i++) {

		if (contacts_list[i].get_address()->equals(address))

			*temp = contacts_list[i];

	}
	return temp;

}


void ContactsBook::print_contacts_sorted(std::string choice)
{
	/*
	*	Create a copy of this->contacts_list array here (do it by creating a new function that returns copy)
	*	Call the sort function sort_contacts_list to sort the newly created copy
	*	This copy is created to avoid changing the original insertion order of contact list
	*	Then print the contacts in following format:
	*	[First Name] [Last Name] [Mobile] [Email]
	*	Call the address print function to print address on next line
	*/
	Contact* list;

	list = new Contact[contacts_count];

	for (int i = 0; i < contacts_count; i++) {

		list[i] = contacts_list[i];
	}

	sort_contacts_list(list, choice);

	for (int i = 0; i < contacts_count; i++) {

		std::cout << std::endl<< "Name : "<<list[i].get_first_name() << "  " << list[i].get_last_name() << "  phone :  "<<list[i].get_mobile_number()<<"  Email : "<<list[i].get_email_address()<<std::endl<<std::endl;
		std::cout << " Address : ";
		list[i].get_address()->print_address();
	}

}
void ContactsBook::print_contacts() {

	for (int i = 0; i < contacts_count; i++) {

		std::cout << std::endl << "Name : " << contacts_list[i].get_first_name() << "  " << contacts_list[i].get_last_name() << "  phone :  " << contacts_list[i].get_mobile_number() << "  Email : " << contacts_list[i].get_email_address() << std::endl << std::endl;
		std::cout << " Address : ";
		contacts_list[i].get_address()->print_address();
	}

}

//void ContactsBook::sort_contacts_list(Contact* contact_list, std::string choice)
//{
//	/*
//		You should not duplicate the code to sort based on choices
//		Follow the strategy provided in manual/tutorial to avoid duplicating the code (Section B & E only)
//		Sort by the fist letter of first name or last name as given in choice
//	*/
//
//	Contact temp;
//
//	if (choice == "F") {
//		for (int i = 0; i < contacts_count; i++) {
//
//			for (int j = i + 1; j < contacts_count; j++) {
//
//				if (contacts_list[i].get_first_name() > contacts_list[j].get_first_name())
//
//					std::swap(contacts_list[i], contacts_list[j]);
//
//			}
//		}
//	}
//	else if (choice == "L") {
//
//
//		for (int i = 0; i < contacts_count; i++) {
//
//			for (int j = i + 1; j < contacts_count; j++) {
//
//
//				if (contacts_list[i].get_last_name() > contacts_list[j].get_last_name())
//
//					std::swap(contacts_list[i], contacts_list[j]);
//
//			}
//		}
//
//
//	}
//}
void ContactsBook::sort_contacts_list(Contact* cont_list, std::string choice) {
	for (int i = 0; i < contacts_count; i++) {
		for (int j = i + 1; j < contacts_count; j++) {
			if (choice == "First Name" && cont_list[i].get_first_name() > cont_list[j].get_first_name()) {
				std::swap(cont_list[i], cont_list[j]);
			}
			else if (choice == "Last Name" && cont_list[i].get_last_name() > cont_list[j].get_last_name()) {
				std::swap(cont_list[i], cont_list[j]);
			}
		}
	}
}




void ContactsBook::merge_duplicates() 
{
	// Implement this function that finds and merges all the duplicates
	// Duplicate means exact equal
	// If there are three copies of a Contact, then only one should remain
	// For example: If total contact are 10, and 2 contacts are same, after removing duplicates
	// 9 contacts will be left; and the this->contacts_count of list will 9
	// At the end display contacts merged, and count of merged contacts

	for (int i = 0; i < contacts_count; i++) {
		for (int j = i+1; j < contacts_count; j++)
		{

			if (contacts_list[i].equals(contacts_list[j])) {
				contacts_list[i].set_first_name("0");
				contacts_count--;
			}

		}

	}


	Contact* temp = new Contact[contacts_count];


	for (int i = 0; i < contacts_count; i++) {

		if (!(contacts_list[i].get_first_name()=="0"))
		temp[i] = *(contacts_list[i].copy_contact());
	}

	delete[]contacts_list;

	contacts_list = NULL;

	contacts_list = temp;

}

//
// ContactsBook* ContactsBook::load_from_file(std::string file_name) 
//{
//	/*
//	*	Read contacts back from file in the same format
//	* 	Read size_of_contacts
//	*	Using this size_of_contacts read from file, create a new ContactsBook object
//	*	Read the contacts_count, and run a loop for this contacts_count and read the 
//	*	contacts in the same format as you stored, create new object for each contact
//	*	that you read from file and add it to contact book object you created above.
//	* 	Return contacts book.
//	*	Finally, close the file
//	*/
//	 
//}


void ContactsBook::save_to_file(std::string file_name) 
{
	/*
	*	In this function you will store all the contacts to a file
	*	On first line store size_of_contacts
	*	On second line store contacts_count
	*	On next lines store contacts in the following format:
	*   2 lines for each contact
	*   On oneline write contact attributes(except address) in comma separated format. On second line
	*	store address atributes in the same format
	*	first_name,last_name,mobile_number,email_address
	*	house,street,city,country
	*	Close the file
	*/
}
