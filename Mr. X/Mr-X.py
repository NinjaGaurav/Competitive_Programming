# -*- coding: utf-8 -*-
"""
Created on Sun Jun 16 13:40:46 2019

@author: gaurav

import sys
sys.stdin = open('input.txt', 'r')
sys.stdout = open('output.txt', 'w')
"""


def solve(expr):
    x = 0
    X = not x
    a = eval(expr)
    x = 1
    X = not x
    b = eval(expr)
    if a == b:
        return 0
    else:
        return 1


t = int(input())
for tc in range(1, t+1):
    string = input()
    ans = solve(string)
    print('Case #%s: %s' % (tc, ans))
