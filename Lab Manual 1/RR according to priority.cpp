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
	cout<<"\nEnter Time Quantum: ";
	cin>>tq;
	int pno[n],at[n],bt[n],tt[n],wt[n],ft[n],pr[n],status[n],rt[n];
	
	for(int i=0;i<n;i++)
	{
		pno[i]=i+1;
		status[i]=0;
	}
	
	cout<<"\nEnter details for following processes:";
	
	for(int i=0;i<n;i++)
	{
		//cout<<"\n\nEnter the arrival time for P"<<pno[i]<<" : ";
		at[i]=0;
		
		cout<<"\n\nEnter the burst time for P"<<pno[i]<<" : ";
		cin>>bt[i];
		
		cout<<"Enter Priority (lower number = Higher priority) for P"<<pno[i]<<" : ";
		cin>>pr[i];
		
		
		rt[i]=bt[i];
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(pr[j]>pr[j+1])
			{
				/*temp=at[j];
				at[j]=at[j+1];
				at[j+1]=temp;*/
				
				temp=rt[j];
				rt[j]=rt[j+1];
				rt[j+1]=temp;
				
				temp=bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=temp;
				
				temp=pno[j];
				pno[j]=pno[j+1];
				pno[j+1]=temp;
				
				temp=pr[j];
				pr[j]=pr[j+1];
				pr[j+1]=temp;
			}
		}
	}
	timer=at[0];
	
	while(flag!=1)
	{
		if(count>100)
		{
			count=0,
			timer++;
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
		
		for(int i=0;i<n;i++)
		{
			if(at[i]<=timer && status[i]==0)
			{
				cout<<"\n\nP"<<pno[i]<<"  start at time "<<timer;
				int min=tq;
				if(rt[i]<tq)
					min=rt[i];
					
				rt[i]-=min;		
				cout<<"\nRem time p"<<pno[i]<<"="<<rt[i];
				timer+=min;
				
				if(rt[i]==0)
				{
					cout<<"\nP"<<pno[i]<<" Completed at "<<timer;
					status[i]=1;
					wt[i]=timer-at[i]-bt[i];
					tt[i]=bt[i]+wt[i];
					ft[i]=timer;		
					totaltt+=tt[i];
					totalwt+=wt[i];
				}
				//cout<<"\nPr "<<i+1<<" : "<<rt[i];
			}
		}	
		count++;						
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
