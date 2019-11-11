/*
	Name: Bankers Algo
	Copyright: All rights reserved to Vinjit
	Author: Phantom
	Date: 08-10-19 00:14
*/

#include<iostream>

using namespace std;

int main() 
{ 
	int n,m,ind=0; 
	
	cout<<"Enter number of processes: ";
	cin>>n;
	
	cout<<"\nEnter number of resources: ";
	cin>>m;
	
	int alloc[n][m],max[n][m],need[n][m],avail[m],status[n],seq[n];
	
	cout<<"\nEnter the Adjacency matrix for allocation: ";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>alloc[i][j];
		}
	}
	
	cout<<"\nEnter the maximum need matrix: ";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>max[i][j];
		}
	}
	
	cout<<"\nEnter amount of available resources: ";
	for(int i=0;i<m;i++)
		cin>>avail[i]; 

	for (int k = 0; k < n; k++) 
		status[k] = 0; 
		 
	for (int i = 0; i < n; i++)
	{ 
		for (int j=0; j<m; j++) 
			need[i][j] = max[i][j] - alloc[i][j]; 
	} 
	
	for (int k=0; k<n; k++)
	{ 
		for (int i=0; i<n; i++)
		{ 
			if (status[i] == 0)
			{ 
				int flag = 0; 
				for (int j=0; j<m; j++)
				{ 
					if(need[i][j] > avail[j])
					{ 
						flag = 1; 
						break; 
					} 
				} 

				if (flag == 0)
				{ 
					seq[ind]=i; 
					for (int y=0;y<m;y++) 
						avail[y] += alloc[i][y]; 
					status[i] = 1; 
					ind++;
				} 
			} 
		} 
	} 

	int flag=0;
	for(int i=0;i<n;i++)
	{
		if(status[i]==0)
			flag=1;
	}
	
	if(flag==1)
		cout<<"\nERROR: No Safe sequence possible!";
	else
	{	
		int i;
		cout<<"\n\nFollowing is the SAFE Sequence:-\n"; 
		for (i=0;i<n-1;i++) 
			cout<<" P"<<seq[i]<<" ->"; 
		cout<<" P"<<seq[i]; 
	}

	return 0; 
} 
