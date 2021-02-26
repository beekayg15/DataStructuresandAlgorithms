import math
import sys
import collections
import random
import functools
input=sys.stdin.readline
print=sys.stdout.write
sys.setrecursionlimit(1000000)

'''

Time Complexity : O(NlogN), N -> Number of Vertices
Space Complexity : O(N), N -> Number of Vertices

'''

start=[]

def lin():
    return list(map(int,input().split()))

# Determining clockwise or counter clockwise rotation
def sideof(a,b,c):
    val=(c[0]-a[0])*(c[1]-b[1])-(c[0]-b[0])*(c[1]-a[1])
    if val>0:
        return 1
    elif val<0:
        return -1
    return 0

# For sorting based on orientation
def compare(a,b):
    val=(b[0]-start[0])*(b[1]-a[1])-(b[0]-a[0])*(b[1]-start[1])
    if val==0:
        return 0
    if val>0:
        return 1
    return -1

# Graham Scan Algorithm
def findHull(p,n):
    ans=[]
    m=p[0][1]
    ind=0
    
    # Choosing start point
    for i in range(1,n):
        if p[i][1]<m or (p[i][1]==m and p[i][0]<p[ind][0]):
            m=p[i][1]
            ind=i
    
    global start
    start=p[ind]
    p.remove(start)
    
    # Sorting based on orientation
    p.sort(key=functools.cmp_to_key(compare),reverse=True)
    
    ans.append(start)
    ans.append(p[0])
    ans.append(p[1])
    count=3
    i=2
    
    # Selecting counter clockwise and neglecting clockwise rotating points
    while(i<n-1):
        val=sideof(ans[count-2],ans[count-1],p[i])
        if val<0:
            ans=ans[:-1]
            count-=1
        else:
            count+=1
            ans.append(p[i])
            i+=1
    return ans

def solve():
    # Input
    n=int(input())
    p=[]
    for i in range(n):
        p.append(lin())
    
    result=findHull(p,n)
    
    # Printing Result
    for i in result:
        print(str(i[0])+" "+str(i[1])+"\n");
    return

if __name__=='__main__':
    t=1
    while(t):
        t-=1
        solve()
