#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>
#include<algorithm>
#include<string>
#include<map>
#include<bitset>
#include<cmath>
#include<set>
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
#define pii pair<int,int>
#define vpii vector<pair<int,int>>

/*

Time Complexity : O(NlogN), N -> Number of Points
Space Complexity : O(N), N -> Number of Points

*/

using namespace std;

set<pii> result;

// Find the side with respect to line AB
int sideof(pii a,pii b,pii c)
{
	int x=((c.second-a.second)*(b.first-a.first)-(b.second-a.second)*(c.first-a.first));
	if(x>0)
		return 1;
	if(x<0)
		return -1;
	return 0;
}

// Find distance from the line AB
int distance(pii a,pii b,pii c)
{
	return abs((c.second-a.second)*(b.first-a.first)-(b.second-a.second)*(c.first-a.first));
}

// Recursive function to find the vertices of convex hull
void quickHull(vpii p,int n,pii a,pii b,int side)
{
	int ind=-1;
	int max=0;

	for(int i=0;i<n;i++)
	{
		int d=distance(a,b,p[i]);
		int s=sideof(a,b,p[i]);
		if(d>max && s==side)
		{
			ind=i;
			max=d;
		}
	}
	if(ind==-1)
	{
		result.insert(a);
		result.insert(b);
		return;
	}

	quickHull(p,n,a,p[ind],side);
	quickHull(p,n,p[ind],b,side);
}

void findHull(vpii p,int n)
{
	int max=0,min=0;
	for(int i=0;i<n;i++)
	{
		if(p[i].first>p[max].first)
		{
			max=i;
		}
		else if(p[i].first<p[min].first)
		{
			min=i;
		}
	}

	quickHull(p,n,p[min],p[max],1);
	quickHull(p,n,p[min],p[max],-1);

	return;
}

void solve()
{
	// Input
	int n;
	cin>>n;
	vpii p(n);
	for(int i=0;i<n;i++)
	{
		cin>>p[i].first;
		cin>>p[i].second;
	}

	findHull(p,n);

	// Printing Output
	set<pii> t(result.begin(),result.end());
	while(!t.empty())
	{
		pii x=*t.begin();
		cout<<x.first<<" "<<x.second<<endl;
		t.erase(t.begin());
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
