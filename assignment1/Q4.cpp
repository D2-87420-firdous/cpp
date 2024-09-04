#include<iostream>
#include<string>
using namespace std;

namespace NStudent{
class Student
{
    private:

    int rollno;
    string name;
    int marks;
public:
    void initStudent()
    {
        rollno=1;
        name="fizzy";
        marks=90;
        cout<<"students initialize with default values"<<endl;
    }

    void printStudentOnConsole()
    {
        cout<<"\n roll no:"<<rollno;
        cout<<"\n name:"<<name;
        cout<<"\n marks:"<<marks;
       
    }

    void acceptstudentFromConsole()
    {
        cout<<"enter rollno";
        cin>>rollno;
        cout<<"name:";
        cin>>name;
        cout<<"marks:";
        cin>>marks;
    }

  

};
}

  void menu()
    {
        cout<<"menu:"<<endl;
        cout<<"1.initialize student"<<endl;
        cout<<"2. print student"<<endl;
        cout<<"3. accept student"<<endl;
        cout<<"4. exit.."<<endl;
    }

int main()
{
   NStudent :: Student student;

    int choice;
   
    
    do{
         cout<<"enter your choice"<<endl;
         menu();
   

        cin>>choice;

        switch (choice)
        {
            case 1:
             student.initStudent();
             break;

             case 2:
            student.printStudentOnConsole();
            break;

             case 3:
             student.acceptstudentFromConsole();
            break;

            case 4:
            cout<<"exit";
            break;

        }
    }while(choice!=4);
    
    return 0;
}