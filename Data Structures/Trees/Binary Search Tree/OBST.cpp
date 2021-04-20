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

Optimal Binary Search Tree Algorithm

Time Complexity : O(N^3) , N -> Number of Nodes
Space Complexity : O(N^2) , N -> Number of Nodes

*/

using namespace std;

void solve()
{
	// Input
	int n;
	cin>>n;
	vint p(n+1);
	vint q(n+1);
	for(int i=0;i<n;i++)
	{
		cin>>p[i+1];
	}
	for(int i=0;i<=n;i++)
	{
		cin>>q[i];
	}

	// Initialising Total Probablity w, Root r and Cost c
	vii w;
	vii c;
	vii r;
	for(int i=0;i<=n;i++)
	{
		vint x;
		for(int j=0;j<=n;j++)
		{
			x.push_back(0);
		}
		w.push_back(x);
		c.push_back(x);
		r.push_back(x);
	}
	for(int i=0;i<=n;i++)
	{
		w[i][i]=q[i];
	}

	// Optimal Binary Search Tree Algorithm
	for(int j=1;j<=n;j++)
	{
		for(int i=0;j+i<=n;i++)
		{
			int min=mod;
			int minind=-1;
			w[i][j+i]=w[i][j+i-1]+p[i+j]+q[i+j];
			for(int k=i+1;k<=j+i;k++)
			{
				if(c[i][k-1]+c[k][j+i]<min)
				{
					min=c[i][k-1]+c[k][j+i];
					minind=k;
				}
			}
			c[i][i+j]=min+w[i][j+i];
			r[i][i+j]=minind;
		}
	}

	// Printing Output
	for(int j=0;j<=n;j++)
	{
		for(int i=0;j+i<=n;i++)
		{
			cout<<w[i][j+i]<<" "<<c[i][j+i]<<" "<<r[i][j+i]<<" | ";
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
