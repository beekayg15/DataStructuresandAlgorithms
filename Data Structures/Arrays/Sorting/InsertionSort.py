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

def insertionSort(arr):
    l=len(arr)
    for i in range(1,l):
        for j in range(i,0,-1):
            if arr[j]<arr[j-1]:
                arr[j],arr[j-1]=arr[j-1],arr[j]
            else:
                break
    return arr

if __name__ == '__main__':
    n=int(input())
    arr=lin()
    arr=insertionSort(arr)
    for i in arr:
        print(str(i)+" ")
    print('\n')