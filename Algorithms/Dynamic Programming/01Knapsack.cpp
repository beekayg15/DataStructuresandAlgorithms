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

using namespace std;

/*

01Knapsack Algorithm

Time Complexity : O(N*C) , N -> Number of items , C -> Total Capacity
Space Complexity : O(N*C) , N -> Number of items , C -> Total Capacity

*/

void solve()
{
	// Input
	int n,c;
	cin>>n>>c;
	vint w(n+1);
	vint p(n+1);
	p[0]=0;
	w[0]=0;

	for(int i=1;i<=n;i++)
	{
		cin>>w[i]>>p[i];
	}

	// Building Cost Matrix
	vii cost;
	vint r;
	for(int i=0;i<c+1;i++)
	{
		r.push_back(0);
	}
	cost.push_back(r);
	for(int i=0;i<n;i++)
	{
		vint x;
		x.push_back(0);
		for(int j=0;j<c;j++)
		{
			x.push_back(-1);
		}
		cost.push_back(x);
	}

	// 01 Knapsack Algorithm
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=c;j++)
		{
			if(j<w[i])
			{
				cost[i][j]=cost[i-1][j];
			}
			else
			{
				int prev=cost[i-1][j];
				int now=cost[i-1][j-w[i]]+p[i];
				if(prev>now)
				{
					cost[i][j]=prev;
				}
				else
				{
					cost[i][j]=now;
				}
			}
		}
	}

	cout<<cost[n][c]<<endl;
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
