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

Fractional Knapsack

Time Complexity : O(NlogN), N -> Number of elements
Space Complexity : O(N), N -> Number of elements

*/

using namespace std;

bool compare(const vd &a,const vd &b)
{
    return a[0]<b[0];
}

void knapsack(double &total,vd &sol,vd v,vd w,int n,double k)
{
    vector<vd> t;
    for(int i=0;i<n;i++)
    {
        vd r;
        r.push_back(v[i]/w[i]);
        r.push_back(v[i]);
        r.push_back(w[i]);
        r.push_back(i);
        t.push_back(r);
    }

    int i=0;
    double tw=0;
    total=0;

    sort(t.begin(),t.end(),compare);

    while(tw<k && i<n)
    {
        if(t[i][2]<=k-tw) //Can grab entire element
        {
            sol[t[i][3]]=1.0;
            total+=t[i][1];
            tw+=t[i][2];
            i+=1;
        }
        else //Can grab only a part
        {
            sol[t[i][3]]=(k-tw)/t[i][2];
            tw=k;
            total+=sol[t[i][3]]*t[i][2]*t[i][0];
            break;
        }
    }
}

void solve()
{
    int n;
    cin>>n;
    vd val(n);
    vd w(n);
    double k;
    for(int i=0;i<n;i++)
    {
        cin>>val[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>w[i];
    }
    cin>>k;

    double total;
    vd sol(n,0);
    knapsack(total,sol,val,w,n,k);

    for(int i=0;i<n;i++)
    {
        cout<<sol[i]<<" ";
    }
    cout<<endl<<total<<endl;
    
	return;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
/*
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
*/
	int t=1;
	while(t--)
	{
		solve();
	}
	return 0;
}
