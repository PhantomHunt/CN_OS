/*
	Name: C-LOOK
	Copyright: All Rights Reserved to Vinjit
	Author: Phantom
	Date: 15-10-19 00:42
*/
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,ul,x,prev,flag=0;
	
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
				req[i]=-1;
				//cout<<"\nHead movements till now = "<<x;			
			}
		}
		
		flag=0;
		for(int m=0;m<n;m++)
		{
			if(req[m]!=-1)
			{
				flag=1;
				break;
			}
		}
		
		if(flag==1)
		{
			x+=prev-req[0];
			cout<<"\n"<<prev<<" -----> "<<req[0];			
			prev=req[0];	
			
			for(int i=1;i<n;i++)
			{
				if(req[i]>prev && req[i]!=-1)
				{
					cout<<"\n"<<prev<<" -----> "<<req[i];
					x+=req[i]-prev;
					prev=req[i];
					req[i]=-1;
					//cout<<"\nHead movements till now = "<<x;			
				}
			}
		}	
	
	cout<<"\n\nTotal Head movements = "<<x;
}
