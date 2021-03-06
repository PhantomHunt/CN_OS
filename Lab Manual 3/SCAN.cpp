/*
	Name: SCAN
	Copyright: All Rights Reserved to Vinjit
	Author: Phantom
	Date: 15-10-19 00:42
*/
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,ul,x,prev,flag=1;
	
	cout<<"How many tracks does disk have? : ";
	cin>>ul;
	
	ul=ul-1;
	
	cout<<"\nEnter number of requests: ";
	cin>>n;
	
	cout<<"\nEnter The disk requests: ";
	int req[n];
	for(int i=0;i<n;i++)
		cin>>req[i];
	
	sort(req,req+n);
	
	cout<<"\nEnter current arm position: ";
	cin>>prev;
			
	for(int i=0;i<n;i++)
	{
		if(req[i]>prev && req[i]!=-1)
		{
			cout<<"\n"<<prev<<" -----> "<<req[i];
			x+=req[i]-prev;
			prev=req[i];
			if(i==n-1)					
				x+=ul-req[i];
			req[i]=-1;
			//cout<<"\nHead movements till now = "<<x;			
		}
	}	
	
	cout<<"\n"<<prev<<" -----> "<<ul;
	prev=ul;
	
	for(int i=n-1;i>=0;i--)
	{
		if(req[i]<prev && req[i]!=-1)
		{
			cout<<"\n"<<prev<<" -----> "<<req[i];
			x+=prev-req[i];
			prev=req[i];
			req[i]=-1;
			//cout<<"\nHead movements till now = "<<x;			
		}
	}
	cout<<"\n\nTotal Head movements = "<<x;
}
