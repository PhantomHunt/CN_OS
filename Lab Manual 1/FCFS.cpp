/*
	Copyright: All rights reserved to Vinjit
	Author: Phantom
	Date: 25-09-19 00:41
*/
#include<iostream>

using namespace std;

int main()
{
	int n,temp,totaltt=0,totalwt=0;
	float avtt=0,avwt=0;
	cout<<"Enter number of processes: ";
	cin>>n;
	int pno[n],at[n],bt[n],tt[n],wt[n],ft[n];
	
	for(int i=0;i<n;i++)
	{
		pno[i]=i+1;
	}
	
	cout<<"\nEnter details for following processes:";
	
	for(int i=0;i<n;i++)
	{
		cout<<"\n\nEnter the arrival time for P"<<pno[i]<<" : ";
		cin>>at[i];
		
		cout<<"Enter the burst time for P"<<pno[i]<<" : ";
		cin>>bt[i];
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(at[j]>at[j+1])
			{
				temp=at[j];
				at[j]=at[j+1];
				at[j+1]=temp;
				
				temp=bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=temp;
				
				temp=pno[j];
				pno[j]=pno[j+1];
				pno[j+1]=temp;
			}
		}
	}
		
	ft[0] = at[0] + bt[0];
    for (int k=1; k<n; k++)
	{
        ft[k] = ft[k - 1] + bt[k];
    }
    
    wt[0] = 0;
    for (int i=1; i<n; i++)
	{
        wt[i] = ft[i] - at[i] - bt[i];
    }
	
	for(int i=0;i<n;i++)
	{
		tt[i]=bt[i]+wt[i];
	}
	
	cout<<"\nProcess\t"<<"\tArrival Time\t"<<"\tBurst Time\t"<<"Completion Time\t\t"<<"Turnaround Time\t\t"<<"Waiting Time\t\t";
	for(int i=0;i<n;i++)
	{
		cout<<"\n"<<pno[i]<<"  \t\t "<<at[i]<<"  \t\t\t"<<bt[i]<<"  \t\t"<<ft[i]<<" \t\t\t"<<tt[i]<<"  \t\t\t"<<wt[i];
	}
	
	for(int i=0;i<n;i++)
	{
		totaltt+=tt[i];
		totalwt+=wt[i];
	}
	
	avtt=(float)totaltt/n;
	avwt=(float)totalwt/n;
	
	cout<<"\n\nTotal Turnaround Time: "<<totaltt;
	cout<<"\nAverage Turnaround Time: "<<avtt;

	cout<<"\n\nTotal Waiting Time: "<<totalwt;
	cout<<"\nAverage Waiting Time: "<<avwt;	
	
	return 0;
}
