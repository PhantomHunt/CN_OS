/*
	Name: CRC
	Copyright: All Rights Reserved to Vinjit
	Author: Phantom
	Date: 15-10-19 00:42
*/
#include<iostream>

using namespace std;

int main()
{
	string codeword,rem,temp,quot,data,div,div2;
	int c=0,n,k,x;
	cout<<"Enter dataword: ";
	cin>>data;
	
	cout<<"Enter divisor: ";
	cin>>div;
	div2=div;
	
	k=data.length();
	x=div.length();	
	n=k+(x-1);
	for(int i=k;i<n;i++)
		data[i]='0';
	
	for(int i=0;i<x;i++)
		temp[i]=data[i];	
		
	for(int i=0;i<k;i++)
	{
		quot[i]=temp[0];
		
		if(quot[i]=='0')
		{	
			for(int j=0;j<x;j++)		
				div[j]='0';
		}
		
		else
		{
			div=div2;
		}
		
		for(int j=x-1;j>0;j--)
		{
			if(temp[j]==div[j])
				rem[j-1]='0';
			else
				rem[j-1]='1';
		}
		rem[x-1]=data[x+i];
		temp=rem;
	}
	
	codeword=data;
	
	for(int i=k;i<n;i++)
	{		
		codeword[i]=rem[c];
		c++;
	}
	cout<<"\nQuotient: ";
	for(int i=0;i<k;i++)
		cout<<quot[i];
		
	cout<<"\nRemainder: ";
	for(int i=0;i<x-1;i++)
		cout<<rem[i];
		
	cout<<"\nCodeword: ";
	for(int i=0;i<n;i++)
		cout<<codeword[i];
	
	return 0;
}
