/*
	Name: FIFO page replacement
	Copyright: All rights reserved to Vinjit
	Author: Phantom
	Date: 08-10-19 00:32
*/
#include<iostream>

using namespace std;

int main()
{
	int l,n,flag=0,hit=0,pf=0;
	float hitr=0.0,missr=0.0;
	
	cout<<"Enter Frame Size: ";
	cin>>n;
	
	cout<<"\nEnter length of page sequence: ";
	cin>>l;
	
	int que[n],seq[l];
	
	for(int i=0;i<n;i++)
		que[i]=-1;
	
	cout<<"\nEnter the page sequence: ";
	for(int i=0;i<l;i++)
		cin>>seq[i];
	
	cout<<"\n\nFrame status--->[-1 indicates empty slot]";
	for(int i=0;i<l;i++)
	{
		cout<<"\nFrame: ";
		for(int m=0;m<n;m++)
			cout<<que[m]<<" ";
			
		flag=0;
		for(int j=0;j<n;j++)
		{
			if(seq[i]==que[j])
			{
				flag=1;
				hit++;
				break;
			}
		}
		
		if(flag==0)
		{
			for(int k=n;k>0;k--)
			{
				que[k]=que[k-1];
			}				
			que[0]=seq[i];				
			pf++;
		}
	}
	cout<<"\nFrame: ";
	for(int m=0;m<n;m++)
		cout<<que[m]<<" ";
	
	hitr=(float)hit/l;
	missr=(float)pf/l;
		
	cout<<"\n\n\n->Number of page faults are: "<<pf;
	cout<<"\n->Number of hits are: "<<hit;
	cout<<"\n->Hit Ratio: "<<hitr;
	cout<<"\n->Miss Ratio: "<<missr;
	
	return 0;
}
