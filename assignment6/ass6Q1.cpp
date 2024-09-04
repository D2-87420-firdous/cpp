#include<iostream>
#include<typeinfo>
using namespace std;

class Employee
{
    int id;
    double salary;
public:
    Employee():id(0),salary(0.0){}
    Employee(int id, double salary): id(id), salary(salary){}
    void setID(int id)
    {
        this->id=id;
    }
    int getID()
    {
        return id;
    }
    void setSalary(double salary)
    {
        this->salary=salary;
    }
    double getSalary()
    {
        return salary;
    }
    virtual void accept()
    {
        cout<<"Enter ID : ";
        cin>>id;
        cout<<"Enter Salary : ";
        cin>>salary;
    }
    virtual void display()
    {
        cout<<"ID : "<<id<<endl;
        cout<<"Salary : "<<salary<<endl;
    }
    virtual ~Employee() {} 
};

class Manager: virtual public Employee
{
    double bonus;
protected:
    void acceptManager()
    {
        cout<<"Enter Bonus : ";
        cin>>bonus;
    }
    void displayManager()
    {
        cout<<"Bonus : "<<bonus<<endl;
    }
public:
    Manager():bonus(0.0){}
    Manager(double bonus):bonus(bonus){}
    void setBonus(double bonus)
    {
        this->bonus=bonus;
    }
    double getBonus()
    {
        return bonus;
    }
    virtual void accept()
    {
        Employee::accept();
        acceptManager();
    }
    virtual void display()
    {
        Employee::display();
        displayManager();
    }

};

class Salesman: virtual public Employee
{
    double commission;
protected:

    void acceptSalesman()
    {
        cout<<"Enter commission : ";
        cin>>commission;
    }
    void displaySalesman()
    {
        cout<<"Commission : "<<commission<<endl;
    }
public:
    Salesman():commission(0.0){}
    void setCommission(double commision)
    {
        this->commission=commision;
    }
    double getCommission()
    {
        return commission;
    }
    virtual void accept()
    {
        Employee::accept();
        acceptSalesman();
    }
    virtual void display()
    {
        Employee::display();
        displaySalesman();
    }    
};

class SalesManager: public Manager, public Salesman 
{
public:
    SalesManager(){}
    void accept()
    {
        Manager::accept();
        Salesman::acceptSalesman();
    }
    void display()
    {
        Manager::display();
        Salesman::displaySalesman();
    }
};

void menu()
{
    cout<<"1. Accept Manager "<<endl;
    cout<<"2. Accept Salesman "<<endl;
    cout<<"3. Accept SalesManager"<<endl;
    cout<<"4. Display All Managers "<<endl;
    cout<<"5. Display All Salesman "<<endl;
    cout<<"6. Display All SalesManagers "<<endl;
    cout<<"7. Display the count of all employees with respect to designation"<<endl;
    cout<<"0. Exit"<<endl;
}

int main()
{
    int countManager = 0;
    int countSalesman = 0;
    int countSalesManager = 0;
    int choice;
    Employee *arr[6];
    int index = 0;

    while (true)
    {
        menu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Thank you for using app....:)";
            for (int i = 0; i < index; i++)
            {
                delete arr[i];
            }
            return 0;
        case 1:
            if (index < 6)
            {
                arr[index] = new Manager();
                arr[index]->accept();
                index++;
                countManager++;
            }
            else{
                cout<<"Array is full"<<endl;
            }

            break;
        case 2:
            if (index < 6)
            {
                arr[index] = new Salesman();
                arr[index]->accept();
                index++;
                countSalesman++;
            }
            else{
                cout<<"Array is full"<<endl;
            }
            break;
        case 3:
            if (index < 6)
            {
                 arr[index] = new SalesManager();
                arr[index]->accept();
                index++;
                countSalesManager++;
            }else{
                cout<<"Array is full"<<endl;
            }
            break;
            
        case 4:
            for (int i = 0; i < index; i++)
            {

                if (typeid(*arr[i]).name() == typeid(Manager).name())
                {
                    cout << "----------**---------" << endl;
                    arr[i]->display();
                    cout << endl
                         << "---------**----------" << endl;
                }
            }
            break;
                case 5:
            for (int i = 0; i < index; i++)
            {

                if (typeid(*arr[i]).name() == typeid(Salesman).name())
                {
                    cout << "---------**----------" << endl;
                    arr[i]->display();
                    cout << endl
                         << "---------**----------" << endl;
                }
            }
            break;
        case 6:
            
            for (int i = 0; i < index; i++)
            {
                

                if (typeid(*arr[i]).name() == typeid(SalesManager).name())
                {
                    cout << "---------**----------" << endl;
                    arr[i]->display();
                    cout << "---------**----------" << endl;
                }
            }
            break;
        case 7: 
            cout << "Count of Managers: " << countManager << endl;
            cout << "Count of SalesManagers: " << countSalesManager << endl;
            cout << "Count of Salesman: " << countSalesman << endl;

        default:
            cout << "Invalid choice";
            break;
        }
    }
    return 0;
}