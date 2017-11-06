class Admin : public Person{



public:
void addEmp()
{
    Employee E;
    cin>>E;
    int flag=employee[E.ret_type()-1].add(E);
    if(flag==0)
        cout<<"\nEmployee with same ID is already present";

}

void dispEmp()
{
    cout<<"\n\nAssistant Managers\n------------------";
    cout<<employee[0];
    cout<<"\n\nCashiers\n--------";
    cout<<employee[1];
}


void remEmp()
{
    int id,pos,i;

    cout<<"Enter employee ID: ";
    cin>>id;
    Employee E(id);

    for(i=0;i<2;i++)
    {
        if(employee[i].rem(E))
        {
            cout<<"\nThe employee with ID:"<<id<<" has been removed";
            return;
        }


    }


        cout<<"\nEmployee not registered\n";

}


};
