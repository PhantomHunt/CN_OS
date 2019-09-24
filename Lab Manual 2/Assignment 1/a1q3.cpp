/*
	Name: Create network and compute minimum cost to all device from source device
	Copyright: All rights reserved to Vinjit
	Author: Phantom
	Date: 25-09-19 00:41
*/
#include<iostream>

using namespace std;

int find_min_node(int distance[],bool visited[],int n)
{
	int minnode,min=99999;
	
	for(int i=0;i<n;i++)
	{
		if(visited[i]==false && distance[i]<min)
		{
			min=distance[i];
			minnode=i;
		}
	}
	return minnode;
}

void dijkstra(int G[20][20],int n,int e,int s)
{
	int distance[n],minnode;
	bool visited[n];
	
	for(int i=0;i<n;i++)
	{
		distance[i]=99999;	
		visited[i]=false;
		
		for(int j=0;j<n;j++)
		{	
			if(G[i][j]==0)
				G[i][j]=99999;
		}
	}
			
	distance[s]=0;
	
	for(int i=0;i<n-1;i++)
	{
		minnode=find_min_node(distance,visited,n);
		visited[minnode]=true;
		
		for(int j=0;j<n;j++)
		{
			if(visited[j]==false && distance[minnode]+G[minnode][j]<distance[j])
			{
				distance[j]=distance[minnode]+G[minnode][j];
			}
		}
	}
	
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		if(i!=s)
			cout<<"\nMinimum distance of device "<<i+1<<" from "<<s+1<<" is: "<<distance[i];
	}
}

int main()
{	
	int n,e,s,src,dest,cost;
	cout<<"Enter number of Devices in network: ";
	cin>>n;
	int G[20][20];
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			G[i][j]=0;
			
	cout<<"\nEnter number of Links: ";
	cin>>e;
	
	cout<<"\nEnter the cost of Links:-\n(Input format- src dest cost)\n";
	for(int i=0;i<e;i++)
	{
		cin>>src>>dest>>cost;
		G[src-1][dest-1]=cost;
		G[dest-1][src-1]=cost;
	}
	
	cout<<"\nAdjacency matrix for this connection is: \n\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<G[i][j]<<" ";
		cout<<"\n";
	}
	
	cout<<"\nEnter the source node: ";
	cin>>s;
	
	dijkstra(G,n,e,s-1);
	
	return 0;
}
