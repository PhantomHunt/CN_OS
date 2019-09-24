/*
	Copyright: All rights reserved to Vinjit
	Author: Phantom
	Date: 25-09-19 00:41
*/
#include<iostream>

using namespace std;

int main()
{
	int n,tq,temp,flag=0,count=0,timer=0,totaltt=0,totalwt=0;
	float avtt=0,avwt=0;
	cout<<"Enter number of processes: ";
	cin>>n;
	int pno[n],at[n],bt[n],tt[n],wt[n],ft[n],status[n],rt[n];
	
	for(int i=0;i<n;i++)
	{
		pno[i]=i+1;
		status[i]=0;
	}
	
	cout<<"\nEnter details for following processes:";
	
	for(int i=0;i<n;i++)
	{
		at[i]=0;
		
		cout<<"Enter the burst time for P"<<pno[i]<<" : ";
		cin>>bt[i];
		
		rt[i]=bt[i];
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
				
				temp=rt[j];
				rt[j]=rt[j+1];
				rt[j+1]=temp;
				
				temp=pno[j];
				pno[j]=pno[j+1];
				pno[j+1]=temp;
			}
		}
	}
	timer=at[0];
	tq=8;
	
	for(int i=0;i<n;i++)
	{
		
		int min=tq;
		if(rt[i]<tq)
			min=rt[i];
			
		rt[i]-=min;		
				
		timer+=min;
			
		if(rt[i]==0)
		{
			status[i]=1;
			wt[i]=timer-at[i]-bt[i];
			tt[i]=bt[i]+wt[i];
			ft[i]=timer;		
			totaltt+=tt[i];
			totalwt+=wt[i];
		}
	}	
	
	tq=4;
	for(int i=0;i<n;i++)
	{
		if(status[i]==0)
		{	
			flag=0;
			break;
		}
		else 
			flag=1;
	}
	
	if(flag==0)
	{
		for(int i=0;i<n;i++)
		{		
			int min=tq;
			if(status[i]==0)
			{
				if(rt[i]<tq)
					min=rt[i];
					
				rt[i]-=min;		
						
				timer+=min;
					
				if(rt[i]==0)
				{
					status[i]=1;
					wt[i]=timer-at[i]-bt[i];
					tt[i]=bt[i]+wt[i];
					ft[i]=timer;		
					totaltt+=tt[i];
					totalwt+=wt[i];
				}
			}
		}					
	}
	
	for(int i=0;i<n;i++)
	{
		if(status[i]==0)
		{	
			flag=0;
			break;
		}
		else 
			flag=1;
	}
	
	if(flag==0)
	{
		for(int i=0;i<n;i++)
		{
			if(status[i]!=1)
			{	
				timer+=rt[i];
				{
					status[i]=1;
					rt[i]=0;
					wt[i]=timer-at[i]-bt[i];
					tt[i]=bt[i]+wt[i];
					ft[i]=timer;		
					totaltt+=tt[i];
					totalwt+=wt[i];
				}
			}
		}
	}
	cout<<"\nProcess\t"<<"\tArrival Time\t"<<"\tBurst Time\t"<<"Completion Time\t\t"<<"Turnaround Time\t\t"<<"Waiting Time\t\t";
	for(int i=0;i<n;i++)
	{
		cout<<"\n"<<pno[i]<<"  \t\t "<<at[i]<<"  \t\t\t"<<bt[i]<<"  \t\t"<<ft[i]<<" \t\t\t"<<tt[i]<<"  \t\t\t"<<wt[i];
	}
	
	avtt=(float)totaltt/n;
	avwt=(float)totalwt/n;
	
	cout<<"\n\nTotal Turnaround Time: "<<totaltt;
	cout<<"\nAverage Turnaround Time: "<<avtt;

	cout<<"\n\nTotal Waiting Time: "<<totalwt;
	cout<<"\nAverage Waiting Time: "<<avwt;	
	
	return 0;
}
