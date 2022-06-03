#include<iostream>
#include"ContactsBook.h"
#include"Address.h"
#include"Contact.h"
#include<conio.h>
#include<iomanip>
#include<iostream>
#include<string>


void input_address(Address& address) {

    std::string temp;
    std::cout << "Enter Your house " << std::endl;
    std::cin >> temp;
    address.set_house(temp);

    std::cout << "Enter Your street " << std::endl;
    std::cin >> temp;
    address.set_street(temp);


    std::cout << "Enter Your city " << std::endl;
    std::cin >> temp;
    address.set_city(temp);


    std::cout << "Enter Your country " << std::endl;
    std::cin >> temp;
    address.set_country(temp);


}


int main() {
    Address address;

    ContactsBook ContactList;

    Contact contact;



    system("cls");
    system("color 03");
    std::cout << "\t\t\t\t*\t*";
    std::cout << "\t\t\t\t**\t**";
    std::cout << "\t\t\t\t***\t***";
    std::cout << "\t\t\t\t****\t****";
    std::cout << "\t\t\t\t*****\t*****";
    std::cout << "\t\t\t\t******\t******";
    std::cout << "\t\t\t\t*******\t*******";
    std::cout << "\t\t\t\t*******\t*******";
    std::cout << "\t\t\t\t******\t******";
    std::cout << "\t\t\t\t*****\t*****";
    std::cout << "\t\t\t\t****\t****";
    std::cout << "\t\t\t\t***\t***";
    std::cout << "\t\t\t\t**\t**";
    std::cout << "\t\t\t\t*\t*";

    for (;;)
    {
        int ch;
        std::cout << std::endl << std::endl << std::endl;
        std::cout << "\n\t\t\t **** Welcome to Contact Management System ****";
        std::cout << "\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n\t\t" <<
            "[1] Creat a Contact list \n\t\t" <<
            "[2] Add a Contact \n\t\t" <<
            "[3] Merge Duplicates \n\t\t" <<
            "[4] store to file \n\t\t" <<
            "[5] load to file t\n\t\t" <<
            "[6] Print Sorted contacts t\n\t\t" <<
            "[7] print contacts t\n\t\t" <<
            "[8] search Contacts t\n\t\t" <<
            "[9] Number of Contacts t\n\t\t" <<
            "[0] Exit\n\t\t================ = \n\t\t";
        std::cout << "Enter the choice:";

        std::cin >> ch;

        if (ch == 1) {

            int size;
            system("cls");
            system("color 0A");

            std::cout << " Enter the size of contacts " << std::endl;
            std::cin >> size;
            ContactList.set_size_of_list(size);
            system("cls");


        }


        else if (ch == 2) {

            system("cls");
            system("color 0A");

            std::string temp;

            std::cout << "Enter Your First Name " << std::endl;
            std::cin >> temp;
            contact.set_first_name(temp);


            std::cout << "Enter Your Last Name " << std::endl;
            std::cin >> temp;
            contact.set_last_name(temp);

            std::cout << "Enter Your Mobile Number it should be 11 digit " << std::endl;
            while (1) {

                std::cin >> temp;
                if (!(temp.length() > 11 || temp.length() < 11))
                    break;
                else std::cout << "you have entered incorrect Mobile number please re enter the number   " << std::endl;

            }
            contact.set_mobile_number(temp);

            std::cout << "Enter Your email address " << std::endl;
            std::cin >> temp;
            contact.set_email_address(temp);

            input_address(address);
            contact.set_address(&address);

            ContactList.add_contact(contact);

            system("cls");

        }

        else if (ch == 3) {

            system("cls");
            system("color 0A");
            ContactList.merge_duplicates();

            std::cout << "sucessfully merged";
            system("cls");

        }


        else if (ch == 4) {

            system("cls");
            system("color 0A");
            std::cout << " work in progress ";

            system("cls");

        }

        else if (ch == 5) {

            system("cls");
            system("color 0A");
            std::cout << " work in progress ";


            system("cls");

        }


        else if (ch == 6) {




            system("cls");
            system("color 0A");
            std::string choice;

            std::cout << "For First Name Sorting enter the \" F \" and for Last Name sorting enter the \" L \"  " << std::endl;
            std::cin >> choice;
            ContactList.print_contacts_sorted(choice);
            //  system("cls");

        }
        else if (ch == 7) {
            system("cls");
            system("color 0A");

            ContactList.print_contacts();
            //  system("cls");
        }


        else if (ch == 8) {
            system("cls");
            system("color 0A");

            int choice;

            std::cout << "[1] Search By First name Last name " << std::endl;
            std::cout << "[2] Search Mobile number  " << std::endl;
            std::cout << "[3] Search By Address " << std::endl;
            std::cin >> choice;

            if (choice == 1) {

                system("cls");
                system("color 0A");
                std::string first, last;

                std::cout << "Enter Your First Name " << std::endl;
                std::cin >> first;

                std::cout << "Enter Your Last Name " << std::endl;
                std::cin >> last;

               Contact *tempcontact= ContactList.search_contact(first, last);

              

               std::cout << std::endl << "Name : " << tempcontact->get_first_name() << "  " << tempcontact->get_last_name() << "  phone :  " << tempcontact->get_mobile_number() << "  Email : " << tempcontact->get_email_address() << std::endl << std::endl;
               tempcontact->get_address()->print_address();



            }

            else  if (choice == 2) {

                system("cls");
                system("color 0A");
                std::string phone;


                std::cout << "Enter Your Mobile Number it should be 11 digit " << std::endl;
                while (1) {

                    std::cin >> phone;
                    if (!(phone.length() > 11 || phone.length() < 11))
                        break;
                    else std::cout << "you have entered incorrect Mobile number please re enter the number   " << std::endl;

                }


                Contact* tempcontact = ContactList.search_contact(phone);



                std::cout << std::endl << "Name : " << tempcontact->get_first_name() << "  " << tempcontact->get_last_name() << "  phone :  " << tempcontact->get_mobile_number() << "  Email : " << tempcontact->get_email_address() << std::endl << std::endl;
                tempcontact->get_address()->print_address();


            }
            else  if (choice == 3) {

                Address temp;
                input_address(temp);

               Contact *tempcontact =ContactList.search_contact(temp);

               std::cout << std::endl << "Name : " << tempcontact->get_first_name() << "  " << tempcontact->get_last_name() << "  phone :  " << tempcontact->get_mobile_number()<< "  Email : " << tempcontact->get_email_address() << std::endl << std::endl;
               tempcontact->get_address()->print_address();
            }


        }


        else if (ch == 9) {
            system("cls");
            system("color 0A");
            std::cout << " there are : " << ContactList.total_contacts() << " Total contacts Available ";

        }

        else if (ch == 0) {

            exit(0);
        }





    }




    return 0;
}

