/*
	Name: Checksum
	Copyright: All Rights Reserved to Vinjit
	Author: Phantom
	Date: 15-10-19 00:42
*/
#include<iostream>

using namespace std;

int main()
{
	int n,sum=0;
	cout<<"Enter number of data to be sent: ";
	cin>>n;
	
	int sdata[n],rdata[n];
	
	cout<<"Enter data sent: ";
	for(int i=0;i<n;i++)
	{
		cin>>sdata[i];
		sum+=sdata[i];
	}
	int checksum=sum-(2*sum);
	cout<<"\nChecksum = "<<checksum;
	cout<<"\nEnter received data: ";
	
	sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>rdata[i];
		sum+=rdata[i];
	}
	sum+=checksum;
	
	if(sum==0)
		cout<<"No Error. Data Transmitted Successfully!";
	else
		cout<<"Error in received data! Please Retransmit your data";   
	
}
