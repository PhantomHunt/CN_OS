#include<iostream>
#include<stdlib.h>
#include<ctime>

using namespace std;

void dectobin(int num)
{
	int arr[10],i;
	for(int i=0;i<10;i++)
		arr[i]=0;
	for(i=0;num>0;i++)
	{
		arr[i]=num%2;
		num=num/2;
	}
	
	for(i=i-1;i>=0;i--)
		cout<<arr[i];
}

int main()
{
	int arrsent[10], arrnoise[10], arrreceive[10];
	int sent,receive,noise;
	
	cout<<"Enter the data to send: ";
	cin>>sent;
	
	srand(time(NULL));
	noise=rand()%10;
	
	receive=sent+noise;
	
	cout<<"\nMessage Sent --->"<<sent<<"\nNoise in channel --->"<<noise;
	cout<<endl<<endl;
	dectobin(sent);
	cout<<" ---> ";	
	
	dectobin(noise);
	cout<<" ---> ";
	
	dectobin(receive);
	
	cout<<"\n\nReceived Data --->"<<receive;
	return 0;
	
	
}
