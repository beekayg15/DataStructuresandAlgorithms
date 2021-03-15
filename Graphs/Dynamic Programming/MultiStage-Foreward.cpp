#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>
#include<algorithm>
#include<string>
#include<map>
#include<bitset>
#include<cmath>
#include<iomanip>
#define vint vector<int>
#define ll long long
#define mod 1000000007
#define vll vector<long long>
#define ld long double
#define mii map<int,int>
#define miv map<int,vector<int>>
#define vf vector<float>
#define vd vector<double>
#define vii vector<vector<int>>

/*

Multistage Graph - Foreward Approach Algorithm

Time Complexity : O(N^2) , N -> Number of Nodes
Space Complexity : O(N^2) , N -> Number of Nodes

*/

using namespace std;

void solve()
{
	// Input
	int n,e;
	cin>>n>>e;
	vii cost;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cost[i][j]=0;
		}
	}
	for(int i=0;i<e;i++)
	{
		int a,b,w;
		cin>>a>>b>>w;
		cost[a-1][b-1]=w;
	}

	// Initialising minimum cost bcost and best adjacent node array 
	vint d(n,-1);
	vint bcost(n,mod);
	d[n-1]=0;
	bcost[n-1]=0;

	// Foreward Approach Algorithm
	for(int j=n-2;j>=0;j--)
	{
		for(int r=0;r<n;r++)
		{
			if(cost[j][r])
			{
				if(bcost[r]+cost[j][r]<bcost[j])
				{
					bcost[j]=bcost[r]+cost[j][r];
					d[j]=r;
				}
			}
		}
	}

	// Calculating Number of Stages
	int k=1;
	int x=0;
	while(x!=n-1)
	{
		x=d[x];
		k++;
	}

	// Computing Path 
	vint p(k);
	p[0]=0;
	p[k-1]=n-1;
	for(int i=1;i<n-1;i++)
	{
		p[i]=d[p[i-1]];
	}

	// Printing Output
	for(int i=0;i<k;i++)
	{
		cout<<p[i]<<" ";
	}
	cout<<endl;
	return;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int t=1;
	while(t--)
	{
		solve();
	}
	return 0;
}
