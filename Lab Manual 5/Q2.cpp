#include<iostream>

using namespace std;

int main()
{
	int d,s,t;
	
	cout<<"Enter Dmin: ";
	cin>>d;
	s=d-1;
	t=(d-1)/2;
	
	cout<<"\nNumber of error bits that can be detected: "<<s;
	cout<<"\nNumber of error bits that can be corrected: "<<t;
}
