#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>
#include<algorithm>
#include<string>
#include<map>
#include<set>
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
#define uint64 unsigned long long int
#define pb push_back
#define vs vector<string>
#define sint set<int>

using namespace std;

int maxarr(vint arr)
{
	int n=arr.size();
	int max=-1*mod;
	for(int i=0;i<n;i++)
	{
		if(arr[i]>max)
		{
			max=arr[i];
		}
	}
	return max;
}

int minarr(vint arr)
{
	int n=arr.size();
	int min=mod;
	for(int i=0;i<n;i++)
	{
		if(arr[i]<min)
		{
			min=arr[i];
		}
	}
	return min;
}

int maxi(int a,int b)
{
	if(a>b)
	{
		return a;
	}
	return b;
}

int mini(int a,int b)
{
	if(a<b)
	{
		return a;
	}
	return b;
}

double maxd(double a,double b)
{
	if(a>b)
	{
		return a;
	}
	return b;
}

double mind(double a,double b)
{
	if(a<b)
	{
		return a;
	}
	return b;
}

vint inarr(int n)
{
	vint arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	return arr;
}

void printarr(vint arr)
{
	int n=arr.size();
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int gcd(int a,int b)
{
	int x=maxi(a,b);
	int y=mini(a,b);
	if(x%y==0)
	{
		return y;
	}
	return gcd(y,x%y);
}

int sumarr(vint arr)
{
	int s=0;
	int n=arr.size();
	for(int i=0;i<n;i++)
	{
		s+=arr[i];
	}
	return s;
}

string bin(int x)
{
	string s="";
	while(x)
	{
		if(x%2)
		{
			s="1"+s;
		}
		else
		{
			s="0"+s;
		}
		x/=2;
	}
	return s;
}

int binint(string s)
{
	int sum=0;
	int term=1;
	int l=s.length()-1;
	for(int i=l;i>=0;i--)
	{
		if(s[i]=='1')
		{
			sum+=term;
		}
		term*=2;
	}
	return sum;
}

void sorta(vint &a)
{
	sort(a.begin(),a.end());
}

void sortd(vint &a)
{
	sort(a.begin(),a.end(),greater<int>());
}

bool vintcomp(const vint &a,const vint &b)
{
	return a[0]<b[0];
}

void sortv(vector<vint> &a)
{
	sort(a.begin(),a.end(),vintcomp);
}

bool vdcomp(const vd &a,const vd &b)
{
	return a[0]<b[0];
}

void sortvd(vector<vd> &a)
{
	sort(a.begin(),a.end(),vdcomp);
}

void solve()
{
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

	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
