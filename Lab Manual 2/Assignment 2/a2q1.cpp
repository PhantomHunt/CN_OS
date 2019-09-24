#include<iostream>

using namespace std;

void prims(int G[20][20],int n,int e)
{
	int visited[n],src,dest,min,ecount=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{	
			if(G[i][j]==0)
				G[i][j]=99999;
		}
	}
	
	for(int i=0;i<n;i++)
		visited[i]=0;
		
	visited[0]=1;
	
	cout<<"\nEfficient Network is: \n";
	cout<<"Source  Destination  Cost\n\n"; 
	
	while(ecount<n-1)
	{
		min=99999;
		for(int i=0;i<n;i++)
		{
			if(visited[i]==1)
			{
				for(int j=0;j<n;j++)
				{
					if(visited[j]==0 && G[i][j]<min)
					{
						min=G[i][j];
						src=i;
						dest=j;
					}
				}
			}
		}
		visited[dest]=1;
		ecount++;
		cout<<src+1<<"\t"<<dest+1<<"\t  "<<min<<"\n";
	}
}

int main()
{	
	int n,e,src,dest,cost;
	cout<<"Enter number of Device: ";
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
	
	prims(G,n,e);
	
	return 0;
}
