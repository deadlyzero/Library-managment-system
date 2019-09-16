#include<iostream.h>
#include<conio.h>
#include<fstream>
#include<string.h>
#include<stdlib.h>


using namespace std;

class LibraryManagement
{

private:

    int student_roll;
    int book_no;
    char student_name[50];
    char department_name[50];
    char book_name[100];
    char writer_name[100];

public:

    LibraryManagement( )
    {
            strcpy (student_name,"Null");
            strcpy (department_name,"Null");
            strcpy (book_name,"Null");
            strcpy (writer_name,"Null");
    }

    void get_student_info ()
    {
          cout<<"Creating Student Record"<<endl;
        cout<<"Enter your Roll NO: :";
        cin>>student_roll ;
        cin.ignore();

        cout<<"Enter your Department Name :";
        gets(department_name);

        cout<<"Enter your Name :";
        gets(student_name);
    }

    void student_info()
    {
        ofstream fout;
        fout.open("Student.txt", ios::app | ios::binary);
        fout.write((char*)this, sizeof(*this));
        fout.close();
    }

    void showStudentData()
    {
        cout<<"\nStudent Roll No: "<<student_roll <<"\nStudent Name : "<<student_name<< "\nDepartment : " << department_name << endl;

    }

    void view_all_student()
    {

        ifstream fin;
        fin.open("Student.txt", ios::app | ios::binary);

        fin.read((char*)this, sizeof(*this));

        while(!fin.eof())
        {
            showStudentData();
            fin.read((char*)this, sizeof(*this));
        }
        fin.close();

    }


    int search_student_info(int k)
    {

        ifstream file_in;

        file_in.open("Student.txt" , ios::in | ios::binary );

        int flag=0;

        while(!file_in.eof())
        {
            file_in.read((char*)this,sizeof(*this));

            if(student_roll==k)
            {
                showStudentData();
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            cout<<" Student Roll NO does not match the record ............"<<endl;
        }

        file_in.close();
    }


    int deleteStudent (int r)
    {
        ifstream fin;
        ofstream fout;

        fin.open("Student.txt", ios::in| ios::binary);

        if (!fin)
        {
            cout << "File Not Found\n";
        }
        else
        {
            fout.open("tempStudent.txt", ios::out| ios::binary);

            fin.read((char*)this, sizeof(*this));

            while(!fin.eof())
            {

                if( student_roll != r )
                    fout.write((char*)this, sizeof(*this));

                fin.read((char*)this, sizeof(*this));
            }

            fin.close();

            fout.close();

            remove("Student.txt");

            rename("tempStudent.txt","Student.txt");

        }

    }



    void createBook()
    {
        cout<<"Creating Book Record"<<endl;

        cout<<"\nEnter your Book NO: :";
        cin>>book_no;
        cin.ignore();

        cout<<"Enter Book Name :";
        gets(book_name);

        cout<<"Enter  Writer Name :";
        gets(writer_name);

    }

    void book_info()
    {
        ofstream fout;
        fout.open("Book.txt", ios::app | ios::binary);
        fout.write((char*)this, sizeof(*this));
        fout.close();
    }

    void showBookData()
    {
        cout<<"\nBook No : "<<book_no <<"\nBook Name : "<<book_name<< "\nWriter Name : " << writer_name << endl;

    }

    void view_all_book()
    {
        ifstream file_in;

        file_in.open("Book.txt", ios::app | ios::binary);

        file_in.read((char*)this,sizeof(*this));

        while(!file_in.eof())
        {
            showBookData();
            file_in.read((char*)this,sizeof(*this));
        }

        file_in.close();
    }


    int search_book_info(int l)
    {
        ifstream file_in;

        file_in.open("Book.txt", ios::in | ios::binary);

        int flag=0;

        while(!file_in.eof())
        {
            file_in.read((char*)this,sizeof(*this));
            if(book_no==l)
            {
                showBookData();
                flag=1;
                break;
            }
        }

        if(flag==0)
        {
            cout<<" Book NO does not match the record .........."<<endl;
        }
        file_in.close();
    }



    int delete_book (int bnum)
    {
        ifstream fin;
        ofstream fout;

        fin.open("Book.txt", ios::in| ios::binary);

        if (!fin)
        {
            cout << "File Not Found\n";
        }
        else
        {

            fout.open("tempBook.txt", ios::out| ios::binary);
            fin.read((char*)this, sizeof(*this));

            while(!fin.eof())
            {

                if(book_no != bnum)

                    fout.write((char*)this, sizeof(*this));

                fin.read((char*)this, sizeof(*this));
            }

            fin.close();
            fout.close();
            remove("Book.txt");
            rename("tempBook.txt","Book.txt");

        }

    }



    int inssuing_book()
    {

        int issue_student_roll;
        int issue_book_no;
        char issue_student_name[50];
        char issue_department_name[50];
        char issue_book_name[100];
        char issue_writer_name[100];

        int i, j, flag1=0, flag2=0;

        ifstream file_in, file_in1;

        ofstream file_out;

        file_in1.open("Book.txt",ios::in | ios::binary);

        file_in.open("Student.txt",ios::in | ios::binary);

        file_out.open("Record.txt",ios::app | ios::binary);


        cout<<"\n\tEnter the book No:";
        cin>>i;

        while(!file_in1.eof())
        {
            file_in1.read((char*)this, sizeof(*this));

            if(book_no==i)
            {
                showBookData();

                file_in1 >> book_no;
                file_in1 >> book_name;
                file_in1 >> writer_name;

                issue_book_no = book_no;

                strcpy(issue_book_name , book_name);

                strcpy(issue_writer_name , writer_name);

                flag1=1;

                cout<<"\nInformation accepted ....\n";
                break;
            }

        }
        if(flag1==0)
        {
            cout<<"Sorry ! Book does not exist\n";
            return 1;
        }

        cout<<"\n";
        cout<<"\n\tEnter the Roll No of the student: ";
        cin>>j;

        while(!file_in.eof())
        {
            file_in.read((char*)this, sizeof(*this));

            if(student_roll==j)
            {
                showStudentData();

                file_in >> student_roll;
                file_in >> student_name;
                file_in >> department_name;

                issue_student_roll = student_roll;
                strcpy(issue_student_name,student_name);
                strcpy(issue_department_name,department_name);


                flag2=1;


                //file_out <<issue_book_no<< " "  << issue_book_name << " " << issue_writer_name <<" "<<  issue_student_roll<< " " << issue_student_name << " " << issue_department_name<<"\n" ;
                file_out <<issue_student_name << " "  <<  issue_department_name << " " << issue_book_name<<" "<< issue_writer_name << "\n" ;

                cout<<"\nsuccessfully book issued\n";
                break;
            }
        }

        if(flag2==0)
        {
            cout<<"\nStudent record does not exist\n";
        }


        file_in1.close();

        file_in.close();

        file_out.close();

    }

    void issuing_book_list()
    {

        string line;

        ifstream myfile ("Record.txt" , ios::in | ios::binary);
        if (myfile.is_open())
        {
            while ( getline (myfile,line) )
            {
                cout << line <<"\n";
            }
            myfile.close();
        }



    }
     int return_book()
    {


        int i, j, flag=0;

        ifstream file_in, file_in1;

        ofstream file_out;

        file_in1.open("Book.txt",ios::in | ios::binary);

        file_in.open("Student.txt",ios::in | ios::binary);


        cout<<"\n\tEnter the Roll No of the student: ";
        cin>>j;

        while(!file_in.eof())
        {
            file_in.read((char*)this, sizeof(*this));

            if(student_roll==j)
            {
                flag=1;
                cout<<"\nInformation accepted ....\n";
                break;
            }
        }

        if(flag==0)
        {
            cout<<"\nStudent record does not exist\n";
        }


        cout<<"\n\tEnter the issue Book No:";
        cin>>i;

        while(!file_in1.eof())
        {
            file_in1.read((char*)this, sizeof(*this));

            if(book_no==i)
            {
                showBookData();

                cout<<"successfully book return\n";
                break;

            }

        }

        file_in1.close();

        file_in.close();

    }

};

int manu()
{
    int ch;


    cout << "\n\n\t\t\t=============||==============================||================\t\n";
    cout<<"\t\t\t             ||                              ||    \t\n";
    cout << "\t\t\t\t     || Library Management System    ||\t\n";
    cout<<"\t\t\t             ||                              ||    \t\n";
    cout << "\t\t\t=============||==============================||================\t\t\n\n\n";
    cout<<"\n\t\t  1. Student Information ";
    cout<<"\n\t\t  2. Book Information ";
    cout<<"\n\t\t  3. Issue Book";
    cout<<"\n\t\t  4. Return book";
    cout<<"\n\t\t  5. Exit ";

    cout<<"\n\n\t\t\t\t Enter your choice: ";

    cin>>ch;
    return ch;
}

int main()
{

    LibraryManagement s;

    int bnum,k,r,l,x;

    while (1)
    {
        system("cls");

        switch(manu())
        {
        case 1:
            cout<<"\n\t\t  1. Create Student Information ";
            cout<<"\n\t\t  2. View Student Information ";
            cout<<"\n\t\t  3. Search Student Information";
            cout<<"\n\t\t  4. Delete Student Information ";
            cout<<"\n\n\t\t\t\t Enter your choice: ";
            cin>>x;
            if(x==1){
                s.get_student_info();
                s.student_info();
                cout << "Information Inserted Successfully";
                getch();
                break;
            }
            else if(x==2){
                s.view_all_student();
                getch();
                break;
            }
            else if(x==3){
                cout<<"\n\n\t Now enter student roll you want to search .......... ";
                cin>>k;
                s.search_student_info(k);
                getch();
                break;
            }
            else if(x==4){
                 cout<<"\n\n\t Enter student Roll: ";
                cin>>r;
                s.deleteStudent (r);
                cout<<"\nDeleted..";
                getch();
                break;
            }
            else{
                getch();
                break;
            }


        case 2:
            cout<<"\n\t\t  1. Create Book Information ";
            cout<<"\n\t\t  2. View Book Information ";
            cout<<"\n\t\t  3. Search Book Information";
            cout<<"\n\t\t  4. Delete Book Information ";
            cout<<"\n\n\t\t\t\t Enter your choice: ";
            cin>>x;
            if(x==1){
                s.createBook();
                s.book_info();
                cout << "Successfully Inserted";
                getch();
                break;
            }
            else if(x==2){
                s.view_all_book();
                getch();
                break;
            }
            else if(x==3){
                cout<<"\n\n\t"<<"Now enter Book no you want to search .......... ";
                cin>>l;
                s.search_book_info(l);
                getch();
                break;
            }
            else if(x==4){
                cout<<"\n\n\t Enter Book no: ";
                cin>>bnum;
                s.delete_book(bnum);
                cout<<"\nDeleted..";
                getch();
                break;
            }
            else{
                getch();
                break;
            }
        case 3:
            cout<<"\n\t\t  1. Issue Book";
            cout<<"\n\t\t 2. View All Issued Book";
            cout<<"\n\n\t\t\t\t Enter your choice: ";
            cin>>x;
            if(x==1){
                s.inssuing_book();

                getch();
                break;
            }
            else if(x==2){
                s.issuing_book_list();
                getch();
                break;
            }
            else{
                getch();
                break;
            }

        case 4:
                s.return_book();
                getch();
                break;
        case 5:
            exit (0);

        default:
            cout<<"wrong Press...";
        }
    }

    return 0;
}

