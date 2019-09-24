/*
	Name: Produce-Consumer Problem
	Copyright: All rights reserved to Vinjit
	Author: Phantom
	Date: 25-09-19 00:41
*/
#include<iostream>
using namespace std;

int producer(int buffer,int len_buffer)
{
	if(buffer+1>len_buffer)
	{
		cout<<"Can't produce more as buffer is Full!";
	}
	
	else
	{
		buffer++;
	}
	
	return buffer;
}

int consumer(int buffer)
{
	if(buffer-1<0)
	{
		cout<<"Can't consume more as buffer is Empty!";
	}
	
	else
	{
		buffer--;
	}
	
	return buffer;
}

int main()
{
	int semaphore,len_buffer=0,buffer=0;
	char ch;
	cout<<"Enter total length of buffer: ";
	cin>>len_buffer;
	
	do{
		cout<<"\nMENU\n";
		cout<<"\nPress 0 to consume";
		cout<<"\nPress 1 to produce";
		cout<<"\n\nEnter your choice: ";
		cin>>semaphore;
		if(semaphore==0)
		{
		    buffer=consumer(buffer);
			cout<<"\n"<<buffer<<" units out of "<<len_buffer<<" is currently in buffer";
		}
		
		else if(semaphore==1)
		{
			buffer=producer(buffer,len_buffer);
			cout<<"\n"<<buffer<<" units out of "<<len_buffer<<" is currently in buffer";
		}
		else
			cout<<"INVALID OPERATION!";
			
		cout<<"\n\nDo you wish to continue(Y/N)?";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
}
