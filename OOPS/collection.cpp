template <class Type>
class Collection;

template <class Type>
ostream &operator<<(ostream &output,Collection<Type> &C);
template <class Type>
fstream &operator<<(fstream &output,Collection<Type> &C);
template <class Type>
fstream &operator>>(fstream &input,Collection<Type> &C);




template <class Type> class Collection
{

  Type object[100];
  int number;

  public:
      Collection()
      {
          number=0;
      }
      int add(Type obj)
      {
          int pos=find(obj);
        if(pos!=number)
            return 0;
          object[number++]=obj;
        return 1;
      }

      int update_stock(Type obj,int st)
      {
          int pos=find(obj);
          if(pos==number)
            return 0;


          object[pos].update_stock(st);
          return 1;
      }

      int find(char *name)
      {
          int i;
       for(i=0;i<number;i++)
       {
           if(object[i].chkname(name))
            return i;
       }
       return i;
      }

      int find(Type obj)
      {
          int i;
       for(i=0;i<number;i++)
       {
           if(object[i]==obj)
            return i;
       }

       return i;
      }

    int rem(Type obj)
    {
        int pos=find(obj);
        if(pos==number)
            return 0;
        object[pos]=object[number-1];
        number--;
return 1;
    }

int ret_num()
{
    return number;
}

friend ostream &operator<<<Type>(ostream &output,Collection &C);


friend fstream &operator<<<Type>(fstream &output,Collection &C);
friend fstream &operator>><Type>(fstream &input,Collection &C);


friend Employee* login(char *empname,char *pass,Collection<Employee> &C);
friend void Catalog::construct();

};

template<class Type>
ostream &operator<<(ostream &output,Collection<Type> &C)
{
    int i;
    if(C.number>0)
    {


for(i=0;i<C.number;i++)
{
    string s(typeid(C.object[0]).name());
    if(s.find("Employee")!=string::npos)
    {
        cout<<"\n\nEmployee "<<i+1;
    }
    else if(s.find("Book")!=string::npos)
    {
        cout<<"\n\nBook "<<i+1;
    }
    cout<<C.object[i];
}
    }
}

template<class Type>
fstream &operator<<(fstream &output,Collection<Type> &C)
{
    output.write((char *)&C,sizeof(C));
}


template<class Type>
fstream &operator>>(fstream &input,Collection<Type> &C)
{
    input.read((char *)&C,sizeof(C));
}




Employee* login(char *empname,char *pass,Collection<Employee> &C)
    {
        int pos;
        pos=C.find(empname);
        if(pos==C.number)
        {
            return NULL;
        }
        if(!strcmp(pass,"\0"))
        {
        cout<<"Enter the password: ";
        cin.getline(pass,30);

        }
        if(C.object[pos].check(pass))
            return &C.object[pos];
        return NULL;


    }




