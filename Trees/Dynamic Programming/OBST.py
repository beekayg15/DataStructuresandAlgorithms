import math
import sys
import collections
import random
input=sys.stdin.readline
print=sys.stdout.write
sys.setrecursionlimit(1000000)
mod=1000000007

'''

Optimal Binary Search Tree Algorithm

Time Complexity : O(N^3) , N -> Number of Nodes
Space Complexity : O(N^2) , N -> Number of Nodes

'''
def lin():
    return list(map(int,input().split()))

def solve():
    # Input
    n=int(input())
    p=[0]+lin()
    q=lin()
    
    # Initialising Total Probablity w, Root r and Cost c
    c=[([0]*(n+1)) for _ in range(n+1)]
    w=[([0]*(n+1)) for _ in range(n+1)]
    r=[([0]*(n+1)) for _ in range(n+1)]
    for i in range(n+1):
        w[i][i]=q[i]
        
    # Optimal Binary Search Tree Algorithm
    for u in range(1,n+1):
        for i in range(n+1-u):
            j=i+u
            w[i][j]=w[i][j-1]+p[j]+q[j]
            min=mod
            minind=-1
            for k in range(i+1,j+1):
                if c[i][k-1]+c[k][j]<min:
                    min=c[i][k-1]+c[k][j]
                    minind=k
            r[i][j]=minind
            c[i][j]=min+w[i][j]
            
    # Printing Output
    for u in range(n+1):
        for i in range(n+1-u):
            j=i+u
            print(str(w[i][j])+" "+str(c[i][j])+" "+str(r[i][j])+" | ")
        print("\n")
    return

if __name__=='__main__':
    t=1
    while(t):
        t-=1
        solve()
