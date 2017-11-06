#include <iostream>
#include <fstream>
#include<typeinfo>
#include <stdlib.h>
#include<string.h>


using namespace std;


#include "book.cpp"
Catalog cat;
#include "misc.cpp"
#include "person.cpp"
#include "collection.cpp"
Collection<Employee> employee[2];
Collection<Book> books[4];
#include "admin.cpp"
#include "filehandling.cpp"
#include "bookextra.cpp"

//Reading occurs at beginning of main() and writing ONLY occurs just before program termination.


int main()
{
	int ch1,ch2,ch3,mode;

    empFileRead();
    bookFileRead();
    cat.construct();

	while(1)
	{
		cout<<"\n\nBOOKSTORE MANAGEMENT SYSTEM\n---------------------------\n\nMENU\n\n1. Customer\n2. Employee\n3. Admin\n4. Exit\n\nEnter your choice: ";
		cin>>ch1;

		if(ch1 == 1)
		{
			Person P;
			cin>>P;
			do
			{
				cout<<"\n\nCUSTOMER\n\n1. View Catalog\n2. View Books by Category\n3. Search\n4. Back\n\nEnter your choice: ";
				cin>>ch2;

				switch(ch2)
				{
					case 1:
						P.view_catalog();
						break;
                    case 2:
                        P.viewType();
                        break;
					case 3:
					    cout<<"\n\nSEARCH\n1. Search by name\n2. Search by author\nEnter: ";
						cin>>mode;
                        P.search(mode);
						break;
					case 4:
					    break;

				}
			}while(ch2!=4);
		}

			else if(ch1 == 2)
			{

				Bill bill;
				char name[30],pass[30];
				strcpy(pass,"\0");

                Employee *E;
                cout<<"\nEnter your name: ";
                cin.ignore();
                cin.getline(name,30);
                E=login(name,pass,employee[0]);
                if(E==NULL)
                    E=login(name,pass,employee[1]);
                if(E==NULL)
                {
                 if(!strcmp(pass,"\0"))
                        cout<<"\nNot found";
                 else
                    cout<<"\nInvalid credentials";
                    continue;
                }

				do
				{
					cout<<"\n\nEMPLOYEE\n\n1. View Catalog\n2. View Books by Category\n3. Search\n4. Add Book\n5. Update Stock\n6. Delete Book\n7. Create Bill\n8. Back\n\nEnter your choice: ";
					cin>>ch2;
					switch(ch2)
					{
						case 1:
							E->view_catalog();
							break;
                        case 2:
                            E->viewType();
                            break;
						case 3:
                            cout<<"\n\nSEARCH\n1. Search by name\n2. Search by author\nEnter: ";
                            cin>>mode;
                            E->search(mode);
						    break;
						case 4:
							E->addBook();
							break;
						case 6:
							E->deleteBook();
							break;
						case 5:
							E->updateStock();
							break;
						case 7:
							E->create_bill(bill);
							break;
						case 8:
						    break;
					}

				}while(ch2!=8);
			}

                else if(ch1==3)
                {
                    char pass[30];
                    Admin A;
                    cout<<"Enter password: ";
                    cin>>pass;
                    if(strcmp(pass,"iamtheboss"))
                    {
                    cout<<"Invalid";
                    continue;
                    }
                    do
                    {


                    cout<<"\n\nADMIN\n\n1. Add Employee\n2. Remove Employee\n3. Display Employees\n4. Back\n\nEnter your choice: ";
					cin>>ch3;

                    switch(ch3)
                    {
                        case 1:A.addEmp();
                               break;
                        case 2:A.remEmp();
                            break;
                        case 3:A.dispEmp();
                                break;
                        case 4:break;
                    }
                    }while(ch3!=4);
                }
				else if(ch1 == 4)
				{

				    empFileWrite();
				    bookFileWrite();
					exit(0);


				}
	}



}

