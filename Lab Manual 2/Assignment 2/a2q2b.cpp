/*
	Name: Reader-Writer Problem
	Copyright: All rights reserved to Vinjit
	Author: Phantom
	Date: 25-09-19 00:41
*/
#include<iostream>
using namespace std;

void criticalsection(int semaphore,int readercount)
{
	if(semaphore==0)
	{
		cout<<readercount<<" Readers in critical section! ";
	}
	
	else if(semaphore==1)
	{
		cout<<"\nWriter in Critical section! ";
	}

}

int main()
{
	int semaphore,option,readercount=0,writercount=0;
	char ch;
	
	do{
		cout<<"\nMENU\n";
		cout<<"\nPress 0 to allow reader to critical section";
		cout<<"\nPress 1 to allow writer to critical section";
		cout<<"\nPress 2 to remove writer from critical section";
		cout<<"\nPress 3 to remove one reader from critical section";
		cout<<"\n\nEnter your choice: ";
		cin>>option;
		if(option==0)
		{
			if(writercount!=0)
			{
				cout<<"\nWait! Writer is performing operation in critical section.";
			}
			else
			{
			    readercount++;
				semaphore=0;
				criticalsection(semaphore,readercount);
			}
		}
		
		else if(option==1)
		{
			if(readercount!=0)
			{
				cout<<"\nWait! Reader is performing operation in critical section.";
			}
			else
			{
				writercount++;
				semaphore=1;
				criticalsection(semaphore,readercount);
			}
		}
		
		else if(option==2)
		{
			if(writercount==0)
				cout<<"\nNo writer in critical section!";
			else
			{
				writercount--;
				cout<<"\nWriter removed from critical section successfully!";
			}
		}
			
		else if(option==3)
		{
			if(readercount==0)
				cout<<"\nNo reader in critical section!";
			else
			{
				readercount--;
				cout<<"\nReader removed from critical section successfully. Number of readers in critical section: "<<readercount;
			}
		}
			
		else
			cout<<"INVALID OPERATION!";
			
		cout<<"\n\nDo you wish to continue(Y/N)?";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
}
