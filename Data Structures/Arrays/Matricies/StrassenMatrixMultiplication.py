import math
import sys
import collections
import random
input=sys.stdin.readline
print=sys.stdout.write
sys.setrecursionlimit(1000000)

'''

Strassen's matrix multiplication
Applicable for matrices of order N x N , N -> Order of 2

Time Complexity : O(N^2.882)
Space Complexity : O(N^2)

Reduces Time complexity by reducing the number of multiplicative terms

'''

def lin():
    return list(map(int,input().split()))

def MatAdd(A,B,n): # Matrix Addition
    C=[]
    for i in range(n):
        r=[]
        for j in range(n):
            s=A[i][j]+B[i][j]
            r.append(s)
        C.append(r)
    return C

def MatSub(A,B,n): # Matrix Subtraction
    C=[]
    for i in range(n):
        r=[]
        for j in range(n):
            s=A[i][j]-B[i][j]
            r.append(s)
        C.append(r)
    return C

def Matsplit(A,n): # Splitting Matrix into Four Quaters
    x=n//2
    uhalf=A[:x]
    lhalf=A[x:]  
    q1=[]
    q2=[]
    q3=[]
    q4=[]
    for i in range(x):
        q1.append(uhalf[i][:x])
        q2.append(uhalf[i][x:])
        q3.append(lhalf[i][:x])
        q4.append(lhalf[i][x:])
    return q1,q2,q3,q4  

def MatMerge(q1,q2,q3,q4,x): # Merging four Quaters into a Matrix
    C=[]
    uhalf=q1
    lhalf=q3
    for i in range(x):
        uhalf[i]+=q2[i]
        lhalf[i]+=q4[i]
    C=uhalf+lhalf
    return C

def MatMul(A,B,n): # Strassens Matrix Multiplication Algorithm
    C=[]
    if n==1:
        return [[A[0][0]*B[0][0]]]
    
    x=n//2
    a,b,c,d=Matsplit(A,n)
    e,f,g,h=Matsplit(B,n)
    p=MatMul(MatAdd(a,d,x),MatAdd(e,h,x),x)
    q=MatMul(MatAdd(c,d,x),e,x)
    r=MatMul(a,MatSub(f,h,x),x)
    s=MatMul(d,MatSub(g,e,x),x)
    t=MatMul(MatAdd(a,b,x),h,x)
    u=MatMul(MatSub(c,a,x),MatAdd(e,f,x),x)
    v=MatMul(MatSub(b,d,x),MatAdd(g,h,x),x)
    
    C1=MatSub(MatAdd(MatAdd(p,s,x),v,x),t,x)
    C2=MatAdd(r,t,x)
    C3=MatAdd(q,s,x)
    C4=MatSub(MatAdd(MatAdd(p,r,x),u,x),q,x)
    
    C=MatMerge(C1,C2,C3,C4,x)
    
    return C

def solve():
    #input
    n=int(input())
    A=[]
    B=[]
    for i in range(n):
        r=lin()
        A.append(r)
    for i in range(n):
        r=lin()
        B.append(r)
        
    C=MatMul(A,B,n)

    #printing output matrix
    print('\n')
    for i in range(n):
        for j in range(n):
            print(str(C[i][j])+' ')
        print('\n')

if __name__=='__main__':
    t=1
    while(t):
        t-=1
        solve()
