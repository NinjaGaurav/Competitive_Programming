#include <bits/stdc++.h>
using namespace std;

int main() {

	cout<<"The Speed of Sound!\n";
	int choice;
	double dist;
	double speed[4]={1,1100,4900,16400};    // store all data , speed[0] helps accessing speed[choice] correctly
                                            // as choice starts from 1
	while(1)
    {
        cout<<"\nSelect the Medium: \n";
        cout<<"1. Air \n2. Water \n3. Steel \nPress 4 to Exit\n";
        cout<<"Enter your choice (1-4): ";
        cin>>choice;
        while(choice>4 && choice<0)     //while illegal input
        {
             cout<<"Please enter a number between 1 and 4: ";
             cin>>choice;
        }
        if(choice==4)
            return 0;
        cout<<"\nEnter the distance: ";
        cin>>dist;
        while(dist<0)       //while illegal input
        {
            cout<<"\nDistance cannot be negative!";
            cout<<"\nEnter a non negative value: ";
            cin>>dist;
        }
        double ans=dist/speed[choice];  // time = dist/speed
        ans= round(ans*10000)/10000;   // Round off by shifting left 4 places, rounding off then shifting right 4 places
        cout<<"\nIt will take sound wave "<<fixed<<setprecision(4)<<ans<<" seconds to travel in the selected medium\n";
        cout<<"\nDo you want to continue? Press 1 for Yes & 0 for No: ";
        cin>>choice;
        if(choice==0)
            return 0;
    }
	return 0;
}
