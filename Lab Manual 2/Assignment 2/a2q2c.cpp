/*
	Name: Dining Philosopher Problem
	Copyright: All rights reserved to Vinjit
	Author: Phantom
	Date: 25-09-19 00:41
*/
#include<iostream>

using namespace std;

Eating(int i, int status[])
{
	if(status[i] == 1 || status[(i+1)%5] == 1)
	{
		cout<<"\nNo this Philosopher cannot eat at the moment. Wait for neighbouring philosopher to finish.";
	}
	else
	{
		cout<<"Philosopher "<<i<<" is Eating now";
		status[i]=status[(i+1)%5]=1;
	}	
}

Thinking(int i, int status[])
{
	if(status[i] == 0 || status[(i+1)%5] == 0)
	{
		cout<<"\nThis Philosopher is already thinking.";
	}
	else
	{
		cout<<"Philosopher "<<i<<" is Thinking now";
		status[i]=status[(i+1)%5]=0;
	}	
}

CriticalSection(int semaphore, int status[], int i)
{
	if(semaphore==0)
		Eating(i,status);
		
	else if(semaphore==1)
		Thinking(i,status);
}

int main()
{
	int semaphore,i,status[5];
	char ch;
	
	//initially all philosophers are thinking
	for(int i=0;i<5;i++)
		status[i]=0;
		
	do{
		cout<<"\n\nPress 0 to make Philosopher eat";
		cout<<"\nPress 1 to make Philosopher think";
		cout<<"\n\nEnter Your Choice: ";
		cin>>semaphore;
		
		if(semaphore==0)
		{
			cout<<"\nEnter the Philosopher number (0-4) who wants to Eat: ";
			cin>>i;	
		}
		
		else if(semaphore==1)
		{
			cout<<"\nEnter the Philosopher number (0-4) who wants to stop Eating and Start Thinking: ";
			cin>>i;	
		}
		else
			cout<<"Invalid Input!";
			
		CriticalSection(semaphore,status,i);
		
		cout<<"\n\nDo You Wish To Continue(Y/N)? : ";
		cin>>ch;
	}while(ch=='Y'||ch=='y');
	
	return 0;
}
