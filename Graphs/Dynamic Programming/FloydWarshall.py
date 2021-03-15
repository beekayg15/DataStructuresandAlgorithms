import math
import sys
import collections
import random
input=sys.stdin.readline
print=sys.stdout.write
sys.setrecursionlimit(1000000)
mod=1000000007

'''

Floyd Warshall's Algorithm

Time Complexity : O(N^3) ,  N -> Number of vertices
Space Complexity : O(N^2) ,  N -> Number of vertices

'''

def lin():
    return list(map(int,input().split()))

def solve():
    # Input
    n,e=lin()
    distance=[]
    
    # Initialising Distance Matrix
    for _ in range(n):
        r=[mod]*n
        distance.append(r)
    
    for _ in range(e):
        a,b,w=lin()
        distance[a-1][b-1]=w
    
    # Floyd's Algorithm
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if distance[i][k]+distance[k][j]<distance[i][j]:
                    distance[i][j]=distance[i][k]+distance[k][j]
    
    # Printing Result
    for i in range(n):
        for j in range(n):
            if distance[i][j]==mod:
                distance[i][j]=-1
            print(str(distance[i][j])+"\t")
        print("\n")
    return

if __name__=='__main__':
    t=1
    while(t):
        t-=1
        solve()
