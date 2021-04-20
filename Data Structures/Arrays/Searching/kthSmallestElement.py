import math
import sys
import collections
import random
input=sys.stdin.readline
print=sys.stdout.write
sys.setrecursionlimit(1000000)

'''

Median of Medians Algorithms for kth smallest element

Time Complexity : O(N), N -> Number of elements
Space Complexity : O(N), N -> Number of elements

'''

def lin():
    return list(map(int,input().split()))

def swap(arr, a, b):  # Swap elements of array
    temp = arr[a]  
    arr[a] = arr[b]  
    arr[b] = temp 

def partition(arr,start,end,pivot): # Partitioning 
    for i in range(start,end):
        if arr[i]==pivot:
            swap(arr,i,end)
            break;
    insert=start
    for i in range(start,end):      # Smaller elements to left
        if arr[i]<=pivot:
            swap(arr,insert,i)
            insert+=1
    swap(arr,insert,end)
    return insert+1

def kthSmallestElement(arr,start,end,k):
    l=end-start+1
    medians=[]
    
    for i in range(l//5): # Finding median of sub-groups
        a=start+(i*5)
        b=start+(i*5)+5
        x=arr[a:b]
        x=sorted(x)
        medians.append(x[2])
    if l%5:
        x=arr[start+((l//5)*5):end+1]
        x=sorted(x)
        xl=len(x)
        medians.append(x[xl//2])
    ml=len(medians)
    
    medianofmedians=None
    if ml==1:
        medianofmedians=medians[0]
    else: # Finding median of medians
        medianofmedians=kthSmallestElement(medians,0,ml-1,ml//2)
    
    position=partition(arr,start,end,medianofmedians)
    
    if position==k+start: 
        return arr[position-1]
    elif position>k+start: # Search in left sub-array
        return kthSmallestElement(arr,start,position-2,k)
    else: # Search in right sub-array
        return kthSmallestElement(arr,position,end,k+start-position)
    return -1

if __name__=='__main__':
    n=int(input())
    arr=lin()
    k=int(input())
    result=kthSmallestElement(arr,0,n-1,k)
    print(str(result)+'\n')
