import math
import sys
import collections
import random
input=sys.stdin.readline
print=sys.stdout.write
sys.setrecursionlimit(1000000)

'''

Time Complexity: O(V+E), V->Number of Nodes, E->Number of Edges 
Space Complexity: O(V^2), Each node may have a maximum of V neighbouring nodes

'''

def lin():
    return list(map(int,input().split()))

if __name__=='__main__':
    N=10001
    e=int(input())
    ch=[[] for _ in range(N)]
    for i in range(e):
        x,y=lin()
        ch[x].append(y)
        ch[y].append(x)
    
    a,b=lin()
    if a==b:
        print(str(a)+'\n')
    else:
        flag=0
        path=[[] for _ in range(N)]
        l=1
        visit=[1 for _ in range(N)]
        queue=[a]
        visit[a]=0
        path[a].append(a)
        while l:
            x=queue[0]
            queue=queue[1:]
            l-=1
            for i in ch[x]:
                queue.append(i)
                l+=1
                visit[i]=0
                path[i]=path[x]+[i]
                if b==i:
                    flag=1
                    break
            if(flag):
                break
        if(flag):
            print(' '.join(map(str,path[b])))
            print('\n')
        else:
            print("NO PATH POSSIBLE\n")