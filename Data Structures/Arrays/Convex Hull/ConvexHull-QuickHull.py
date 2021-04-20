import math
import sys
import collections
import random
input=sys.stdin.readline
print=sys.stdout.write
sys.setrecursionlimit(1000000)

'''

Time Complexity : O(NlogN), N -> Number of Points
Space Complexity : O(N), N -> Number of Points

'''

result=set()

# Find distance from line AB
def distance(a,b,c):
    return abs((c[0]-a[0])*(c[1]-b[1])-(c[0]-b[0])*(c[1]-a[1]))

# Find the side with respect to line AB
def sideof(a,b,c):
    val=(c[0]-a[0])*(c[1]-b[1])-(c[0]-b[0])*(c[1]-a[1])
    if val>0:
        return 1
    elif val<0:
        return -1
    return 0

def lin():
    return list(map(int,input().strip().split()))

# Recursive Function to find the vertices to the convex hull
def quickHull(p,n,a,b,side):
    ind=-1
    max=0
    
    for i in range(n):
        d=distance(a,b,p[i])
        s=sideof(a,b,p[i])
        if d>max and side==s:
            max=d
            ind=i
            
    if ind==-1:
        result.add(tuple(a))
        result.add(tuple(b))
        return
    
    quickHull(p,n,a,p[ind],side)
    quickHull(p,n,p[ind],b,side)
    return

def findHull(p,n):
    max=0
    min=0
    
    # Find extreme X-axis points
    for i in range(n):
        if p[i][0]<p[min][0]:
            max=i
        elif p[i][0]>p[max][0]:
            min=i
    
    quickHull(p,n,p[min],p[max],1)
    quickHull(p,n,p[min],p[max],-1)
    
    return

def solve():
    # Input
    n=int(input())
    p=[]
    for i in range(n):
        r=lin()
        p.append(r)
    
    # Finding Points of the Hull
    findHull(p,n)
    
    # Printing Output
    for i in result:
        print(str(i[0])+" "+str(i[1])+"\n")
    return

if __name__=='__main__':
    t=1
    while(t):
        t-=1
        solve()
