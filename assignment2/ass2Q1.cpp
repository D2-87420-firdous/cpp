#include<iostream>
#include<string>

using namespace std;
class Box
{
    private:
        int length;
        int breadth;
        int height;

    public:

        Box()
        {
            length=1;
            breadth=1;
            height=1;
        }

        Box( int l,int b, int h)
        {
            length=l;
            breadth=b;
            height=h;
        }

        Box( int side)
        {
            length=side;
            breadth=side;
            height=side;
        }

        int calculate_volume_of_box()
        {
            return length*breadth*height;
        }

        void display()
        {
            cout<<"dimensions of the box: "<<length<<"x"<<breadth<<"x"<<height<<endl;
            cout<<"volume of box : "<<calculate_volume_of_box()<<endl;
        }

        void accept()
        {
        
         cout<<"enter length"<<endl;
         cin>>length;
            cout<<"enter breadth"<<endl;
         cin>>breadth;
            cout<<"enter height"<<endl;
        cin>>height;
        }
};

void menu()
{
    cout<<"Menu"<<endl;
    cout<<"1.calculate the volume with initialised parameters"<<endl;
    cout<<"2. calculate the volume with different paramenters"<<endl;
    cout<<"3. calculate the volume with same side"<<endl;
    cout<<"4. exit"<<endl;
    
    
}
int main()
{ 
    int choice;

    do{
        menu();
        cout<<"choose from menu"<<endl;
        cin>>choice;

    switch (choice)
    {
        case 1:{
        Box box;
        box .display();
        break;
        }

     case 2:{
        Box box;
        box.accept();
        
        box. display();
        break;
     }
    

        case 3:{
        int side;
        cout<<"enter side"<<endl;
        cin>>side;
        Box box(side);
        box.display();
        break;
        }

    case 4:
        cout<<"exit"<<endl;
        break;
    
        default:
        cout<<"invalid choice"<<endl;
    
    
    }
    }
    while(choice!=4);
return 0;
}

