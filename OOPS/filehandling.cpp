void empFileRead()
{

    fstream file;
    file.exceptions ( ifstream::failbit | ifstream::badbit );

    try
    {
    file.open("EMP.dat", ios::in|ios::binary);
    }
    catch(const ifstream::failure &e)
    {
        return;
    }

    file>>employee[0];
    file>>employee[1];

    file.close();
}
void empFileWrite()
{

    fstream file;
    file.open("EMP.dat", ios::out|ios::binary);
    file<<employee[0];
    file<<employee[1];
    file.close();
}

void bookFileRead()
{

    fstream file;
    file.exceptions ( ifstream::failbit | ifstream::badbit );

    try
    {
    file.open("BOOK.dat", ios::in|ios::binary);
    }
    catch(const ifstream::failure &e)
    {
        return;
    }

    file>>books[0];
    file>>books[1];
    file>>books[2];
    file>>books[3];


    file.close();
}
void bookFileWrite()
{

    fstream file;
    file.open("BOOK.dat", ios::out|ios::binary);
    file<<books[0];
    file<<books[1];
    file<<books[2];
    file<<books[3];
    file.close();
}
