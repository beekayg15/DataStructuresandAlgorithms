import math
import sys
import collections
import random
input=sys.stdin.readline
print=sys.stdout.write
sys.setrecursionlimit(1000000)

'''
 
Time Complexity: O(N^2)
Space Complexity: O(N) -> Input Array
 
Check the link below for Visualization:
https://barathkumarbk-15.github.io/SortingAlgorithms/

'''

def lin():
    return list(map(int,input().split()))

def selectionSort(arr):
    l=len(arr)
    for i in range(l-1):
        min=i
        for j in range(i+1,l):
            if arr[j]<arr[min]:
                min=j
        arr[i],arr[min]=arr[min],arr[i]
    return arr

if __name__ == '__main__':
    n=int(input())
    arr=lin()
    arr=selectionSort(arr)
    for i in arr:
        print(str(i)+" ")
    print('\n')