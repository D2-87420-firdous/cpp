#include<iostream>
using namespace std;

class Time{
    private:

        int hour;
        int minutes;
        int seconds;

    public:
        Time():hour(0),minutes(0),seconds(0){}

        Time(int h,int m, int s):hour(h),minutes(m),seconds(s){}

        int getHour()const
        {
            return hour;
        }
        void setHour (int h)
        {
            hour=h;
        
        }

        int getMinutes()
        {
            return minutes;
        }
        void setMinutes(int m)
        {
            minutes =m;
        }

        int getseconds()
        {
            return seconds;
        }

        void setSeconds(int s)
        {
            seconds = s;
        }

         void printTime() const
          {
          cout << (hour < 10 ? "0" : "") << hour << ":"
             << (minutes < 10 ? "0" : "") << minutes << ":"
             << (seconds < 10 ? "0" : "") << seconds << endl;
    }
    

};

int main()
{  
     int n;
    cout<<"enter the number of time object to create";
    cin>>n;
    Time*timeArray = new Time[n];

    for (int i=0;i<n;i++)
    {
        int h,m,s;
        cout<<"enter time in hrs,min and sec"<<(i+1)<<":";
        cin>>h>>m>>s;
        timeArray[i].setHour(h);
        timeArray[i].setMinutes(m);
        timeArray[i].setSeconds(s);
    }

    cout<<"displaying time for each object"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"time object"<<(i+1)<<":";
        timeArray[i].printTime();

    }


    delete[]timeArray;
    return 0;

};