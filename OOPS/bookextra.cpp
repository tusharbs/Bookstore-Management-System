void Employee::addBook()
{

    if(type==2)
    {
        cout<<"\nAccess denied";
        return;
    }

    Book b;
    cin>>b;

    int pos,type;
    type=b.ret_type();
    pos=books[type-1].find(b);
    if(pos==books[type-1].ret_num())
    {
        books[type-1].add(b);
        cat.add_book(b);
    }
    else
        cout<<"\nBook already present";

}


void Employee::deleteBook()
{
     if(type==2)
    {
        cout<<"\nAccess denied";
        return;
    }
    char name[30],author[30];
    int isbn;
    cout<<"Enter book name: ";
    cin.ignore();
	cin.getline(name,30);
	cout<<"Enter author name: ";
	cin.getline(author,30);
	cout<<"Enter ISBN: ";
	cin>>isbn;

	Book b(name,author,isbn);

	int flag,i;

	for(i=0;i<4;i++)
    {
      flag=books[i].rem(b);
      if(flag==1)
      {
      cat.delete_book(b);
      return;
      }
    }
	cout<<"\nBook not found";

}

void Employee::updateStock()
{
     if(type==2)
    {
        cout<<"\nAccess denied";
        return;
    }

    char name[30],author[30];
    int isbn,stock;
    cout<<"Enter book name: ";
    cin.ignore();
	cin.getline(name,30);
	cout<<"Enter author name: ";
	cin.getline(author,30);
	cout<<"Enter ISBN: ";
    cin>>isbn;
    cout<<"Enter the updated stock: ";
    cin>>stock;
    int flag,i;
   	Book b(name,author,isbn);

    if(stock<0)
    {
        cout<<"\nInvalid input";
        return;
    }
    else if(stock==0)
    {
    for(i=0;i<4;i++)
    {
      flag=books[i].rem(b);
      if(flag==1)
      {
      cat.delete_book(b);
      return;
      }
    }
	cout<<"\nBook not found";
        return;
    }


	for(i=0;i<4;i++)
    {
      flag=books[i].update_stock(b,stock);
      if(flag==1)
      {
      cat.update_stock(b,stock);
      return;
      }
    }
	cout<<"\nBook not found";
}


void Employee::updateStock(Book b,int stock)
{
     if(type==2)
    {
        cout<<"\nAccess denied";
        return;
    }
    int flag,i;

    if(stock<0)
    {
        cout<<"\nInvalid input";
        return;
    }
    else if(stock==0)
    {
    for(i=0;i<4;i++)
    {
      flag=books[i].rem(b);
      if(flag==1)
      {
      cat.delete_book(b);
      return;
      }
    }
	cout<<"\nBook not found";
        return;
    }


	for(i=0;i<4;i++)
    {
      flag=books[i].update_stock(b,stock);
      if(flag==1)
      {
      cat.update_stock(b,stock);
      return;
      }
    }
	cout<<"\nBook not found";


}



void Person::viewType()
{
    int type;
    cout<<"\nChoose category:\n1. Action and Adventure\n2. Sci-fi\n3. Educational\n4. Horror\n\nEnter: ";
    cin>>type;

    cout<<books[type-1];
}


void Bill::createBill(int id,Employee E)
{

	//Search in catalog and add book_sold to Bill
		billno=1000+(rand()%9000);
		while(1)
		{
			cout<<"Enter book name: ";
			char name[30];
			cin.ignore();
			cin.getline(name,30);
			//cin>>name;
			Book b = cat.search_by_name(name);
			if(b.isbn!=-1)
			{
				cout<<b;
				cout<<"Do you want to add this book to cart? (y/n): ";
				char ch;
				cin>>ch;
				if(ch == 'y')
				{
					book_sold[number] = b;
					amount += b.price;
					number++;
					E.updateStock(b,b.stock - 1);
				}
			}
			cout<<"Do you want to add another book? (y/n): ";
			char ch;
			cin>>ch;
			if(ch !='y')
			{
				break;
			}
		}
		cout<<"Employee ID: "<<id<<endl;
		cout<<*this;
}

void Employee::create_bill(Bill bill)
{
	    if(type==2)
            bill.createBill(id,*this);
        else
            cout<<"\nAccess Denied";
}


void Catalog::construct()
{
    int i,j;
    for(i=0;i<4;i++)
        for(j=0;j<books[i].number;j++)
            add_book(books[i].object[j]);

}
