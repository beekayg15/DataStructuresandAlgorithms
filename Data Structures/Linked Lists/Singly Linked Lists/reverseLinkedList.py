import math
import sys
import collections
import random
input=sys.stdin.readline
print=sys.stdout.write
sys.setrecursionlimit(1000000)

'''

Time Complexity : O(N), N -> Number of Nodes
Space Complexity : O(N), N -> Number of Nodes

'''

def lin():
    return list(map(int,input().split()))

class Node: 
    def __init__(self, data): 
        self.data = data 
        self.next = None
  
class LinkedList: 
    def __init__(self): 
        self.head = None
        
    def printList(self): 
        temp = self.head 
        while (temp): 
            print (str(temp.data)+" ") 
            temp = temp.next
        print('\n')
        
    def push_back(self,data):
        node=Node(data)
        last=self.head
        if(last==None):
            self.head=node;
        else:
            while(last.next):
                last=last.next
            last.next=node

def reverseLinkedList(ll):
    first=ll.head
    second=first.next
    first.next=None
    while second:
        temp=second.next
        second.next=first
        first=second
        second=temp
    ll.head=first
    return ll

if __name__=='__main__':
    n=int(input())
    arr=lin()
    ll=LinkedList()
    for i in arr:
        ll.push_back(i)
    ll=reverseLinkedList(ll)
    ll.printList()