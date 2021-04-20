import math
import sys
import collections
import random
input=sys.stdin.readline
print=sys.stdout.write
sys.setrecursionlimit(1000000)

'''

01Knapsack Algorithm

Time Complexity : O(N*C) , N -> Number of items , C -> Total Capacity
Space Complexity : O(N*C) , N -> Number of items , C -> Total Capacity

'''

def lin():
    return list(map(int,input().split()))

def solve():
    # Input
    n,c=lin()
    w=[0]*(n+1)
    p=[0]*(n+1)
    for i in range(n):
        w[i+1],p[i+1]=lin()
        
    #  Building Cost Matrix
    cost=[]
    for i in range(n+1):
        r=[0]*(c+1)
        cost.append(r)
        
    #  01 Knapsack Algorithm
    for i in range(1,n+1):
        for j in range(1,c+1):
            if j<w[i]:
                cost[i][j]=cost[i-1][j]
            else:
                prev=cost[i-1][j]
                now=cost[i-1][j-w[i]]+p[i]
                if prev>now:
                    cost[i][j]=prev
                else:
                    cost[i][j]=now
    
    print(str(cost[n][c])+"\n")
    return

if __name__=='__main__':
    t=1
    while(t):
        t-=1
        solve()
