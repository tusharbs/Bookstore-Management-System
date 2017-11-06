

class Person{

	char name[30];
	int age;
	int stock;

public:
    Person()
    {
        name[0]='\0';
        age=0;
        stock=1;

    }
    virtual void Cin(istream& input)
        {
            cout<<"Enter name: ";
		input.ignore();
		input.getline(name,30);
		//cin>>name;
		cout<<"Enter age: ";
		input>>age;
        }
    virtual void Cout(ostream& output)
    {
        cout<<"\nName: "<<name;
        cout<<"\nAge: "<<age;

    }


	friend istream &operator>>(istream &input,Person &P);
	friend ostream &operator<<(ostream &output,Person &P);


	void view_catalog()
	{
		cat.view_catalog();
	}

    void viewType();


	void search(int mode)
	{
		switch(mode)
		{
            case 1:
                {cout<<"Enter book name: ";
                char n[30];
                cin.ignore();
                cin.getline(n,30);
                //cin>>n;
                Book b;
                b = cat.search_by_name(n);
                if(b.ret_isbn()!=-1)
                    cout<<b;
                break;
                }
			case 2:
                {cout<<"Enter author name: ";
				char n[30];

				//cin>>n;
				cin.ignore();
				cin.getline(n,30);
				Book b;
				b = cat.search_by_author(n);
				if(b.ret_isbn()!=-1)
					cout<<b;
                break;
                }
        }
	}
    int chkname(char *str)
    {
        if(!strcmp(name,str))
        return 1;
        else
        return 0;
    }

 int check(Person &P)
    {
        if(strcmp(P.name,name))
            return 0;
        if(P.age!=age)
            return 0;
        return 1;
    }

 void update_stock(int st)
	{
		stock = st;
	}

char* getname()
{
    return name;
}

	int ret_stock() const{return stock;}

};




istream &operator>>(istream &input,Person &P)
{
    P.Cin(input);

}

ostream &operator<<(ostream &output,Person &P)
{
    P.Cout(output);
}


class Employee : public Person{

int id;
int type;
char pass[30];
public:
    Employee()
    {
        id=0;
        type=0;
    }
     Employee(int idx)
    {
        id=idx;
        type=0;
    }


    friend istream &operator>>(istream &input,Employee &E);
    friend ostream &operator<<(ostream &output,Employee &E);

    void addBook();
    void deleteBook();
    void updateStock();
    void updateStock(Book b,int stock);

	/*void add_book()
	{   if(type==1)
            cat.add_book();
		else
            cout<<"\nAccess Denied";

	}

	void delete_book()
	{
	    if(type==1)
            cat.delete_book();
        else
            cout<<"\nAccess Denied";
	}

	void update_stock_books()
	{
	    if(type==1)
        {
		cout<<"Enter the name of the book: ";
		char name[30];
		//cin>>name;
		cin.ignore();
		cin.getline(name,30);
		Book b;
		b = cat.search_by_name(name);
		if(b.ret_isbn()!=-1)
		{
			cout<<"Enter current number of copies of the book: ";
			int stock;
			cin>>stock;
			cat.update_stock(stock,name);
		}
        }
        else
            cout<<"\nAccess Denied";
	}
	*/



	void create_bill(Bill bill);

  /*  int chkpass(char *str)
    {
        if(!strcmp(pass,str))
            return 1;
        else
            return 0;
    }
*/


    int ret_type()
    {
        return type;
    }

     int check(char *str)
    {

        if(!strcmp(pass,str))
            return 1;
        else
            return 0;

    }

    int operator==(Employee &E)
    {
        //Person *P=&E;
        if(id!=E.id)
            return 0;

        return 1;

    }
};

istream &operator>>(istream &input,Employee &E)
{
    E.Person::Cin(input);
    cout<<"Enter ID: ";
    input>>E.id;
    cout<<"Choose Designation-\n1. Assistant Manager\n2. Cashier\n\nEnter: ";
    cin>>E.type;
    cout<<"Enter password: ";
    cin>>E.pass;
}
ostream &operator<<(ostream &output,Employee &E)
{
    E.Person::Cout(output);
    cout<<"\nID: "<<E.id;
}








