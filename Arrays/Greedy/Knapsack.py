import math
import sys
import collections
import random
input=sys.stdin.readline
print=sys.stdout.write
sys.setrecursionlimit(1000000)

'''

Fractional Knapsack

Time Complexity : O(NlogN), N -> Number of elements
Space Complexity : O(N), N -> Number of elements

'''

def lin():
    return list(map(int,input().split()))

def knapsack(v,w,n,k): #Fractional Knapsack algorithm
    sol=[0 for _ in range(n)]
    triplets=[]
    for i in range(n):
        t=[]
        t.append(v[i]/w[i]) #Finding price to weight ratio
        t.append(v[i])
        t.append(w[i])
        t.append(i)
        triplets.append(t)
    triplets=sorted(triplets,reverse=True)
    
    tw=0.0
    tv=0.0
    i=0
    
    while tw<k and i<n:
        if triplets[i][2]<=k-tw: #Can grab entire element
            sol[triplets[i][3]]=1.0
            tv+=triplets[i][1]
            tw+=triplets[i][2]
            i+=1
        else: #Can grab only a part
            sol[triplets[i][3]]=(k-tw)/triplets[i][2]
            tw=k
            tv+=sol[triplets[i][3]]*triplets[i][2]*triplets[i][0]
            break
        
    return tv,sol

def solve():
    #input
    n=int(input())
    val=lin()
    weight=lin()
    kw=int(input())
    
    #Calculation
    total,solution=knapsack(val,weight,n,kw)
    
    #Printing Solution
    for i in solution:
        print(str(i)+" ")
    print('\n'+str(total)+'\n')
    return

if __name__=='__main__':
    t=1
    while(t):
        t-=1
        solve()
