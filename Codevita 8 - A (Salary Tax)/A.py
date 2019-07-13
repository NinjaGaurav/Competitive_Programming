# -*- coding: utf-8 -*-
"""
Created on Fri Jul 12 16:36:39 2019

@author: gaurav
"""
taxslab = [ int(x) for x in input().split()]
taxper = [ int(x)/100 for x in input().split()]

rebate = int(input())
emptax = [ int(x) for x in input().split()]
ans = 0
helper = []
for i in range(1,len(taxslab)):
    helper.append((taxslab[i]-taxslab[i-1])*taxper[i-1])
for x in emptax:
    if x == 0:
        ans+=0 #1 check (no tax, 0<sal<first slab+rebate?)
    else:
        i = 0
        esal = 0
        while x>0 and i<len(taxslab)-1:
            if x>=helper[i]:
                x-=helper[i]
                esal = taxslab[i+1]             
                i+=1
            elif x<helper[i]:
                esal = x/taxper[i]+taxslab[i]
                x = 0
        if x>0:
            esal = x/taxper[i]+taxslab[i]
            x = 0
        esal += rebate
        ans += esal
print(int(ans),end='') #2 check

        
            