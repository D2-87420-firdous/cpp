#include<iostream>
using namespace std;

class tollbooth
{
    private:
        unsigned int totalcars;
        unsigned int payingcars;
        unsigned int nonpayingcars;
        double totalAmt;

    public:
        tollbooth(): totalcars(0),payingcars(0),nonpayingcars(0), totalAmt(0) {} //member initialiser list
        
           void payingcar()
           {
               totalcars++;
                payingcars++;
                totalAmt +=0.50;
           }

           void nonpayingcar()
           {
               totalcars++;
               nonpayingcars++;
           }

           void printOnConsole()
           {
               cout<<"total cars"<<totalcars<<endl;
               cout<<"payingcars"<<payingcars<<endl;
               cout<<"nonpayingcars"<<nonpayingcars<<endl;
               cout<<"totalamt"<<totalAmt<<endl;
           } 

        
};

int main()
{
    tollbooth booth;
    int choice;
    do{

         cout<<"\nEnter 1: for paying cars \n 2: for non-payingcars  \n 3: total cars ,\n4:to quit: ";
         cin>>choice;

         switch (choice)
         {
             case 1:
                booth.payingcar();
                break;

            case 2:
                booth.nonpayingcar();
                break;

            case 3:
                booth.printOnConsole();
                break;

            case 4:
                cout<<"exit \n";
                break;
            default:
                 cout<<"invalid input ";
         }
    }while(choice!=4);
   

    
    return 0;
}