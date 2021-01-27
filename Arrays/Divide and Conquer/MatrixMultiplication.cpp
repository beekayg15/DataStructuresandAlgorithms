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

Strassen's matrix multiplication
Applicable for matrices of order N x N , N -> Order of 2

Time Complexity : O(N^2.882)
Space Complexity : O(N^2)

Reduces Time complexity by reducing the number of multiplicative terms

*/

using namespace std;

vii matAdd(vii A,vii B,int n) //Matrix Addition
{
    vii C;
    for(int i=0;i<n;i++)
    {
        vint r;
        for(int j=0;j<n;j++)
        {
            int s=A[i][j]+B[i][j];
            r.push_back(s);
        }
        C.push_back(r);
    }
    return C;
}

vii matSub(vii A,vii B,int n) //Matrix Subtraction
{
    vii C;
    for(int i=0;i<n;i++)
    {
        vint r;
        for(int j=0;j<n;j++)
        {
            int s=A[i][j]-B[i][j];
            r.push_back(s);
        }
        C.push_back(r);
    }
    return C;
}

void matSplit(vii &a,vii &b,vii &c,vii &d,vii A,int n) //Matrix Splitting into four Quaters
{
    int x=n/2;
    for(int i=0;i<x;i++)
    {
        vint r;
        for(int j=0;j<x;j++)
        {
            r.push_back(A[i][j]);
        }
        a.push_back(r);
    }
    for(int i=0;i<x;i++)
    {
        vint r;
        for(int j=x;j<n;j++)
        {
            r.push_back(A[i][j]);
        }
        b.push_back(r);
    }
    for(int i=x;i<n;i++)
    {
        vint r;
        for(int j=0;j<x;j++)
        {
            r.push_back(A[i][j]);
        }
        c.push_back(r);
    }
    for(int i=x;i<n;i++)
    {
        vint r;
        for(int j=x;j<n;j++)
        {
            r.push_back(A[i][j]);
        }
        d.push_back(r);
    }
}

vii matMerge(vii a,vii b,vii c,vii d,int x) //Merging four Quaters into a Matrix
{
    vii uh,lh;
    uh=a;
    lh=c;
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<x;j++)
        {
            uh[i].push_back(b[i][j]);
            lh[i].push_back(d[i][j]);
        }
    }
    for(int i=0;i<x;i++)
    {
        uh.push_back(lh[i]);
    }
    return uh;
}

vii matMul(vii A,vii B,int n) //Strassen's Matrix Multiplication Algorithm
{
    if(n==1)
    {
        vii result;
        vint r;
        r.push_back(A[0][0]*B[0][0]);
        result.push_back(r);
        return result;
    }

    vii C,a,b,c,d,e,f,g,h;
    matSplit(a,b,c,d,A,n);
    matSplit(e,f,g,h,B,n);
    int x=n/2;
    
    vii p=matMul(matAdd(a,d,x),matAdd(e,h,x),x);
    vii q=matMul(matAdd(c,d,x),e,x);
    vii r=matMul(a,matSub(f,h,x),x);
    vii s=matMul(d,matSub(g,e,x),x);
    vii t=matMul(matAdd(a,b,x),h,x);
    vii u=matMul(matSub(c,a,x),matAdd(e,f,x),x);
    vii v=matMul(matSub(b,d,x),matAdd(g,h,x),x);

    vii C1=matSub(matAdd(matAdd(p,s,x),v,x),t,x);
    vii C2=matAdd(r,t,x);
    vii C3=matAdd(q,s,x);
    vii C4=matSub(matAdd(matAdd(p,r,x),u,x),q,x);

    C=matMerge(C1,C2,C3,C4,x);

    return C;
}

void solve()
{
    //Input
    int n;
    cin>>n;
    vii A,B;
    for(int i=0;i<n;i++)
    {
        vint r;
        for(int j=0;j<n;j++)
        {
            int z;
            cin>>z;
            r.push_back(z);
        }
        A.push_back(r);
    }
    for(int i=0;i<n;i++)
    {
        vint r;
        for(int j=0;j<n;j++)
        {
            int z;
            cin>>z;
            r.push_back(z);
        }
        B.push_back(r);
    }

    //Calculations
    vii C=matMul(A,B,n);

    //Priting Output
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<C[i][j]<<" ";
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
