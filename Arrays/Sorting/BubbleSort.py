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

def bubbleSort(arr):
    l=len(arr)
    for i in range(l-1):
        count=0
        for j in range(l-1):
            if arr[j]>arr[j+1]:
                arr[j+1],arr[j]=arr[j],arr[j+1]
            else:
                count+=1
        if count==l-i-1:
            break
    return arr

if __name__ == '__main__':
    n=int(input())
    arr=lin()
    arr=bubbleSort(arr)
    for i in arr:
        print(str(i)+" ")
    print('\n')