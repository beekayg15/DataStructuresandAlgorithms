import math
import sys
import collections
import random
input=sys.stdin.readline
print=sys.stdout.write
sys.setrecursionlimit(1000000)
mod=1000000007

'''

Multistage Graph - Foreward Approach Algorithm

Time Complexity : O(N^2) , N -> Number of Nodes
Space Complexity : O(N^2) , N -> Number of Nodes

'''

def lin():
    return list(map(int,input().split()))

def solve():
    # Input
    n,e=lin()
    cost=[([0]*n) for _ in range(n)]
    for _ in range(e):
        a,b,w=lin()
        cost[a-1][b-1]=w
        
    # Initialising minimum cost bcost and best adjacent node array 
    bcost=[mod]*n
    d=[-1]*n
    d[n-1]=0
    bcost[n-1]=0
    
    # Backward Approach Algorithm
    for i in range(n-2,-1,-1):
        for r in range(n):
            if cost[i][r]:
                if cost[i][r]+bcost[r]<bcost[i]:
                    bcost[i]=cost[i][r]+bcost[r]
                    d[i]=r
                    
    # Calculating Number of Stages
    k=1
    x=0
    while(x!=n-1):
        k+=1
        x=d[x]
        
    # Computing Path 
    p=[0]*k
    p[k-1]=n-1
    for i in range(1,n-1):
        p[i]=d[p[i-1]]
        
    # Printing Output
    for i in range(k):
        print(str(p[i])+" ")
    print("\n")
    return

if __name__=='__main__':
    t=1
    while(t):
        t-=1
        solve()
