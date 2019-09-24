/*
	Name: Create network with cost
	Copyright: All rights reserved to Vinjit
	Author: Phantom
	Date: 25-09-19 00:41
*/
#include<iostream>

using namespace std;

int main()
{
	int graph[7][7],val;
	cout<<"If there is link, give weight of network link else 9999\n\n";
	for(int i=1;i<=6;i++)
	{
		for(int j=1;j<=i;j++)
		{
			cout<<"\nIs there a link between node "<<i<<" and node "<<j<<" : ";
			cin>>val;
			graph[i][j]=val;
			graph[j][i]=val;
		}
	}
	
	cout<<"Network graph is: \n";
	for(int i=1;i<=6;i++)
	{
		for(int j=1;j<=6;j++)
		{
			cout<<" "<<graph[i][j];
		}
		cout<<"\n";
	}
}
