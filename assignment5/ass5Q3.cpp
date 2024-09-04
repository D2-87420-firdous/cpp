#include<iostream>
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
class SalesManagaer: public Manager, public Salesman 
{
public:
    SalesManagaer(){}
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
int main()
{
    Employee emp;
    Manager mgr;
    Salesman sales;
    SalesManagaer sm;

    cout << "Testing Employee class:" << endl;
    emp.accept();
    emp.display();

    cout << "\nTesting Manager class:" << endl;
    mgr.accept();
    mgr.display();

    cout << "\nTesting Salesman class:" << endl;
    sales.accept();
    sales.display();

    cout << "\nTesting SalesManager class:" << endl;
    sm.accept();
    sm.display();

    emp.setID(10);
    emp.setSalary(50000.0);
    cout << "\nEmployee ID: " << emp.getID() << endl;
    cout << "Employee Salary: " << emp.getSalary() << endl;

    mgr.setBonus(10000.0);
    cout << "\nManager Bonus: " << mgr.getBonus() << endl;

    sales.setCommission(5000.0);
    cout << "\nSalesman Commission: " << sales.getCommission() << endl;

    return 0; 
}