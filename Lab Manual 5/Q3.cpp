/*
	Name: Hamming Code
	Copyright: All Rights Reserved to Vinjit
	Author: Phantom
	Date: 15-10-19 00:42
*/

#include<iostream>

using namespace std;

int main()
{
	int arr[7],x;
	cout<<"Enter the 4-bit dataword one by one: ";
	cin>>arr[0];
	cin>>arr[1];
	cin>>arr[2];
	cin>>arr[4];
	
	x=arr[0]+arr[2]+arr[4];
	if(x%2==0)
		arr[6]=0;
	else
		arr[6]=1;
		
	x=arr[0]+arr[1]+arr[4];
	if(x%2==0)
		arr[5]=0;
	else
		arr[5]=1;
		
	x=arr[0]+arr[2]+arr[1];
	if(x%2==0)
		arr[3]=0;
	else
		arr[3]=1;
		
	cout<<"\nThe codeword send is: ";
	for(int i=0;i<7;i++)
		cout<<arr[i];
	
	return 0;
		
}
