/*
	Copyright: All rights reserved to Vinjit
	Author: Phantom
	Date: 25-09-19 00:41
*/
#include<iostream>

using namespace std;

int main()
{
	int n,temp,min=0,flag=0,timer=0,totaltt=0,totalwt=0;
	float avtt=0,avwt=0;
	cout<<"Enter number of processes: ";
	cin>>n;
	int pno[n],at[n],bt[n],tt[n],wt[n],pr[n],ft[n],status[n],rt[n];
	
	for(int i=0;i<n;i++)
	{
		pno[i]=i+1;
		status[i]=0;
	}
	
	cout<<"\nEnter details for following processes:";
	
	for(int i=0;i<n;i++)
	{
		cout<<"\n\nEnter the arrival time for P"<<pno[i]<<" : ";
		cin>>at[i];
		
		cout<<"Enter the burst time for P"<<pno[i]<<" : ";
		cin>>bt[i];
		
		cout<<"Enter Priority (lower number = Higher priority) for P"<<pno[i]<<" : ";
		cin>>pr[i];
		
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
	int pointer=0;
	
	while(flag!=1)
	{	
		min=pointer;	
		for(int i=0;i<n-1;i++)
		{
			if(at[i+1]<=timer && status[i+1]==0)
			{
				if(pr[i+1]<pr[min])
				{
					min=i+1;
				}
			}
		}
		
		for(int i=0;i<n;i++)
		{
			if(i==min)
				continue;
			else
				pr[i]--;
		}
		
		timer++;
		if(status[min]==0)
			rt[min]--;							
		if(rt[min]==0)
		{
			status[min]=1;
			wt[min]=timer-at[min]-bt[min];
			tt[min]=bt[min]+wt[min];
			ft[min]=timer;		
			totaltt+=tt[min];
			totalwt+=wt[min];
			
			temp=at[min];
			at[min]=at[pointer];
			at[pointer]=temp;
			
			temp=pr[min];
			pr[min]=pr[pointer];
			pr[pointer]=temp;
			
			temp=bt[min];
			bt[min]=bt[pointer];
			bt[pointer]=temp;
			
			temp=rt[min];
			rt[min]=rt[pointer];
			rt[pointer]=temp;
			
			temp=status[min];
			status[min]=status[pointer];
			status[pointer]=temp;
			
			temp=wt[min];
			wt[min]=wt[pointer];
			wt[pointer]=temp;
			
			temp=tt[min];
			tt[min]=tt[pointer];
			tt[pointer]=temp;
			
			temp=ft[min];
			ft[min]=ft[pointer];
			ft[pointer]=temp;
			
			temp=pno[min];
			pno[min]=pno[pointer];
			pno[pointer]=temp;
			
			pointer++;
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
		
	}
	
	cout<<"\nProcess\t"<<"\tArrival Time\t"<<"\tBurst Time\t"<<"Completion Time\t\t"<<"Turnaround Time\t\t"<<"Waiting Time\t\t";
	for(int i=0;i<n;i++)
	{
		cout<<"\n"<<pno[i]<<" -> Pr("<<pr[i]<<")"<<"  \t "<<at[i]<<"  \t\t\t"<<bt[i]<<"  \t\t"<<ft[i]<<" \t\t\t"<<tt[i]<<"  \t\t\t"<<wt[i];
	}
	
	avtt=(float)totaltt/n;
	avwt=(float)totalwt/n;
	
	cout<<"\n\nTotal Turnaround Time: "<<totaltt;
	cout<<"\nAverage Turnaround Time: "<<avtt;

	cout<<"\n\nTotal Waiting Time: "<<totalwt;
	cout<<"\nAverage Waiting Time: "<<avwt;	
	
	return 0;
}
