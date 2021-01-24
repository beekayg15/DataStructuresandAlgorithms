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
    if start>=end:
        return arr
    insert=start
    pivot=arr[end]
    for i in range(start,end):
        if arr[i]<pivot:
            arr[i],arr[insert]=arr[insert],arr[i]
            insert+=1
    arr[end],arr[insert]=arr[insert],arr[end]
    sorter(arr,start,insert-1)
    sorter(arr,insert+1,end)
    return arr

def quickSort(arr):
    l=len(arr)
    arr=sorter(arr,0,l-1)
    return arr

if __name__ == '__main__':
    n=int(input())
    arr=lin()
    arr=quickSort(arr)
    for i in arr:
        print(str(i)+" ")
    print('\n')