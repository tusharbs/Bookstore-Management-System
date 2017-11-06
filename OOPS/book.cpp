class Catalog;
class Bill;

class Book{

friend class Catalog;
friend class Bill;
	char author[30],name[30];
	long isbn;
	int type;
	int stock;
	float price;


public:
	Book()
	{
	    name[0]='\0';
	    author[0]='\0';
	    price=0.0;
	    type=0;
		stock = 0;
		isbn = -1;
	}
	Book(char *bname,char *bauth,int bisbn)
	{
	    strcpy(name,bname);
	    strcpy(author,bauth);
	    isbn=bisbn;
	    price=0.0;
	    type=0;
		stock = 0;

	}


Book(const Book &b)
{
  strcpy(name,b.name);
   strcpy(author,b.author);
   isbn=b.isbn;
   type=b.type;
   stock=b.stock;
   price=b.price;

}


	void update_stock(int st)
	{
		stock = st;
	}



	int operator==(const Book &B)
	{

	if(strcmp(author,B.author))
        return 0;
    if(strcmp(name,B.name))
        return 0;
    if(isbn!=B.isbn)
        return 0;

	return 1;
	}


	friend istream &operator>>(istream &input,Book &B);

	friend ostream &operator<<(ostream &output,const Book &B);

	friend ostream &operator<<(ostream &output,const Bill &B);


//	const char* ret_name() const{return name;}
//	const char* ret_author() const{return author;}
	long ret_isbn() const{return isbn;}
//	float ret_price() const{return price;}
	int ret_stock() const{return stock;}
	int ret_type(){return type;}

};


istream &operator>>(istream &input, Book &B)
{
    cout<<"Enter book name: ";
		input.ignore();
		input.getline(B.name,30);
		//cin>>name;
		cout<<"Enter author name: ";
		input.getline(B.author,30);
		//cin>>author;
		cout<<"Enter ISBN: ";
		input>>B.isbn;
		cout<<"Choose type:\n1. Action and Adventure\n2. Sci-fi\n3. Educational\n4. Horror\n\nEnter: ";
		cin>>B.type;
		cout<<"Enter price: ";
		input>>B.price;
		do
        {


		cout<<"Enter current stock: ";
		input>>B.stock;
		if(B.stock<=0)
            cout<<"Invalid Input\n";
        }while(B.stock<=0);

}



ostream &operator<<( ostream &output, const Book &B )
{
        output<<"Name: "<<B.name<<endl;
		output<<"Author: "<<B.author<<endl;
		output<<"ISBN: "<<B.isbn<<endl;
		output<<"Category: ";
		if(B.type==1)
            output<<"Action and Adventure";
        else if(B.type==2)
            output<<"Sci-fi";
        else if(B.type==3)
            output<<"Educational";
        else
            output<<"Horror";
		output<<endl;
		output<<"Price: "<<B.price<<endl;
		output<<"Quantity: "<<B.stock<<"\n\n";
}


class Catalog{

	Book book[100];
	int number;

public:
	Catalog()
	{
		number = 0;
	}



	void add_book(Book b);
	void delete_book(Book b);
	void update_stock(Book B,int stock);
	Book search_by_name(char* name);
	Book search_by_author(char* author);
	void view_catalog();
	void construct();


};





void Catalog::add_book(Book b)
	{



		book[number] = b;
		number++;

		//string name = b.ret_name();
		//cout<<name<<endl;
	}

void Catalog::delete_book(Book b)
{

		int index;
		for (int i = 0; i < number; ++i)
		{
			if(b==book[i])
			{
				index = i;
				break;
			}
		}

         cout<<"The following book will be removed:\n";
                cout<<book[index];
                for (int i = index; i < number; ++i)
                {
                    book[i] = book[i+1];
                }
                number--;

}


void Catalog::update_stock(Book B,int stock)
	{

		int pos = -1;
		for (int i = 0; i < number; ++i)
		{
			if(B==book[i])
			{
				pos = i;
				break;
			}
		}

		book[pos].update_stock(stock);
	}

Book Catalog::search_by_name(char* name)
	{
		Book b;
		for (int i = 0; i < number; ++i)
		{
			if(!strcmp(name,book[i].name))
			{
				return book[i];
			}
		}

		cout<<"This book doesn't exist\n";
		return b;
	}

Book Catalog::search_by_author(char* author)
	{
		Book b;
		for (int i = 0; i < number; ++i)
		{
			if(!strcmp(author,book[i].author))
			{
				return book[i];
			}
		}

		cout<<"This book doesn't exist\n";
		return b;
	}


void Catalog::view_catalog()
	{
		cout<<"Catalog: "<<"\n\n";
		for (int i = 0; i < number; ++i)
		{

		    cout<<"\n";
		    cout<<"Book "<<i+1<<"\n";
			cout<<book[i];

		}
	}
