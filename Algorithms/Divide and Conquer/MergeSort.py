import math
import sys
import collections
import random
input=sys.stdin.readline
print=sys.stdout.write
sys.setrecursionlimit(1000000)

'''
 
Time Complexity: O(NlogN)
Space Complexity: O(N) -> Input Array
 
Check the link below for Visualization:
https://barathkumarbk-15.github.io/SortingAlgorithms/

'''

def lin():
    return list(map(int,input().split()))

def sorter(arr,start,end):
    if start>=end-1:
        return arr
    mid=(start+end)//2
    arr=sorter(arr,start,mid)
    arr=sorter(arr,mid,end)
    new_arr=[]
    i=start
    j=mid
    k=0
    while i<mid and j<end:
        if arr[i]<arr[j]:
            new_arr.append(arr[i])
            i+=1
        else:
            new_arr.append(arr[j])
            j+=1
    
    if j!=end:
        new_arr+=arr[j:end]
    if i!=mid:
        new_arr+=arr[i:mid]
    for z in range(start,end):
        arr[z]=new_arr[k]
        k+=1
    return arr

def mergeSort(arr):
    l=len(arr)
    arr=sorter(arr,0,l)
    return arr

if __name__ == '__main__':
    n=int(input())
    arr=lin()
    arr=mergeSort(arr)
    for i in arr:
        print(str(i)+" ")
    print('\n')