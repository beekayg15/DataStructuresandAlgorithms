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
#define pii pair<int,int>
#define vpii vector<pair<int,int>>

/*

Time Complexity : O(NlogN), N -> Number of Vertices
Space Complexity : O(N), N -> Number of Vertices

*/

using namespace std;

pii start;

// Determining clockwise or counter clockwise rotation
int sideof(pii a,pii b,pii c)
{
	int x=((c.second-a.second)*(b.first-a.first)-(b.second-a.second)*(c.first-a.first));
	if(x>0)
		return 1;
	if(x<0)
		return -1;
	return 0;
}

// For sorting based on orientation
bool comp(const pii &a,const pii &b)
{
	int val=(b.first-start.first)*(b.second-a.second)-(b.first-a.first)*(b.second-start.second);
	if(val==0)
	{
		if(a.second==b.second)
		{
			return a.first<b.first;
		}
		return a.second<b.second;
	}
	return val>0;
}

// Graham Scan Algorithm
vpii findHull(vpii p,int n)
{
	vpii ans;
	int min=p[0].second;
	int ind=0;

	// Choosing start point
	for(int i=0;i<n;i++)
	{
		if(p[i].second<min || (p[i].second==min && p[i].first<p[ind].first))
		{
			min=p[i].second;
			ind=i;
		}
	}

	start=p[ind];
	p.erase(p.begin()+ind);

	// Sorting based on orientation
	sort(p.begin(),p.end(),comp);

	ans.push_back(start);
	ans.push_back(p[0]);
	ans.push_back(p[1]);
	int count=3;

	// Selecting counter clockwise and neglecting clockwise rotating points
	for(int i=2;i<n-1;i++)
	{
		int x=sideof(ans[count-2],ans[count-1],p[i]);
		if(x<0)
		{
			ans.erase(ans.end());
			count--;
			i--;
		}
		else
		{
			ans.push_back(p[i]);
			count++;
		}
	}

	return ans;
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

	vpii result=findHull(p,n);

	// Printing result
	for(int i=0;i<result.size();i++)
	{
		cout<<result[i].first<<" "<<result[i].second<<endl;
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
