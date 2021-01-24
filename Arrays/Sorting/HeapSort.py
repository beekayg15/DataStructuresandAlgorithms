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

def heapify(arr,i,l):
    left=2*i+1
    right=2*i+2
    max=i
    if left<l and arr[left]>arr[max]:
        max=left
    if right<l and arr[right]>arr[max]:
        max=right
    if max!=i:
        arr[i],arr[max]=arr[max],arr[i]
        arr=heapify(arr,max,l)
    return arr

def heapSort(arr):
    l=len(arr)
    p=l//2-1
    for i in range(p,-1,-1):
        arr=heapify(arr,i,l)
    for i in range(l-1,0,-1):
        arr[i],arr[0]=arr[0],arr[i]
        heapify(arr,0,i)
    return arr

if __name__ == '__main__':
    n=int(input())
    arr=lin()
    arr=heapSort(arr)
    for i in arr:
        print(str(i)+" ")
    print('\n')