/*
	Name: SSTF
	Copyright: All Rights Reserved to Vinjit
	Author: Phantom
	Date: 15-10-19 00:42
*/
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,ul,x,prev,val=0,pos,flag=1,min,inf;
	
	cout<<"How many tracks does disk have? : ";
	cin>>ul;
	
	inf=ul+1000;
	ul=ul-1;
	
	cout<<"\nEnter number of requests: ";
	cin>>n;
	
	cout<<"\nEnter The disk requests: ";
	int req[n];
	for(int i=0;i<n;i++)
		cin>>req[i];
		
	cout<<"\nEnter current arm position: ";
	cin>>prev;
		
	while(flag==1)
	{
		min=inf;
		for(int k=0;k<n;k++)
		{
			val=inf+1;
			if(req[k]>prev && req[k]!=inf)
				val=req[k]-prev;
			else if(req[k]<prev && req[k]!=inf)
				val=prev-req[k];
				
			if(val<min && val!=inf+1)
			{
				min=val;
					pos=k;
			}
					
		}	
		cout<<"\n"<<prev<<" -----> "<<req[pos];
		x+=min;
		prev=req[pos];	
		req[pos]=inf;	
		
		flag=0;
		for(int m=0;m<n;m++)
		{
			if(req[m]!=inf)
			{
				flag=1;
				break;
			}
		}	
	}		
	cout<<"\n\nTotal Head movements = "<<x;
	return 0;
}

