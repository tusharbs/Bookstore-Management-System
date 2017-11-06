class Employee;

class Bill
{
	int billno;
	float amount;
	int number;
	Book book_sold[100];

public:
	Bill()
	{
	    billno=0;
		number = 0;
		amount = 0.0;
	}


    friend ostream &operator<<(ostream &output,const Bill &B);


	void createBill(int id,Employee E);


};

ostream &operator<<(ostream &output, const Bill &B)
{
       // output<<"Employee ID: "<<id<<endl;
		output<<"Bill Number: "<<B.billno<<endl;
		output<<"Price: "<<B.amount<<endl;
		output<<"Books:\n\n";
		for (int i = 0; i < B.number; ++i)
		{
			cout<<B.book_sold[i].name<<endl;
			cout<<"\t-"<<B.book_sold[i].author<<endl;
		}
		output<<'\n';

}








