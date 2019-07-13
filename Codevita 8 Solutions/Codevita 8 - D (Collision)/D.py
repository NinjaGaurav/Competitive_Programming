# -*- coding: utf-8 -*-
"""
Created on Fri Jul 12 18:29:10 2019

@author: gaurav
"""

def fact(n):
    f = 1
    for i in range(1,n+1):
        f = f*i
    return f

def ncr(n,r):
    return (fact(n)/(fact(n-r)*fact(r)))

#hash map
dic = {
}

c = int(input())

for zzz in range(c):
    inp = [ int(tmp) for tmp in input().split(' ') ]
    x = inp[0]
    y = inp[1]
    v = inp[2]
    dist= (x*x + y*y)/(v*v)
    if dist not in dic:
        dic[dist]=1
    else:
        dic[dist]+=1

ans = 0
for key in dic:
    if dic[key] >= 2:
        ans += ncr(dic[key],2)
print(int(ans))
        
