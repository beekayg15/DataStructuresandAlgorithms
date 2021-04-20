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

Floyd Warshall's Algorithm

Time Complexity : O(N^3) ,  N -> Number of vertices
Space Complexity : O(N^2) ,  N -> Number of vertices

*/

using namespace std;

void solve()
{
	// Input
	int n,e;
	cin>>n>>e;
	vii distance;
	for(int i=0;i<n;i++)
	{
		vint r;
		for(int j=0;j<n;j++)
		{
			r.push_back(mod);
		}
		distance.push_back(r);
	}

	// Initialising Distance Matrix
	for(int i=0;i<e;i++)
	{
		int a,b,w;
		cin>>a>>b>>w;
		a--;
		b--;
		distance[a][b]=w;
	}

	// Floyd's Algorithm
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(distance[i][k]+distance[k][j]<distance[i][j])
				{
					distance[i][j]=distance[i][k]+distance[k][j];
				}
			}
		}
	}

	// Printing Result
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(distance[i][j]==mod)
			{
				distance[i][j]=-1;
			}
			cout<<distance[i][j]<<"\t";
		}
		cout<<endl;
	}
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
