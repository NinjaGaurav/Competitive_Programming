memo = [1 , 1]
for dp in range(2,150):
    memo.append( dp*memo[dp-1]+ (dp-1)*memo[dp-2])
def factors(n):
    ans = 0
    i = 1
    while(i*i<=n):
        if(n%i==0):
            ans = ans + 1
            if(n/i!=i):
                ans = ans + 1
        i += 1
    return ans  


t = int(input())
for i in range(t):
    n = int(input())
    print( memo[ (factors(n)-1) ], end='' )
    if(i!=t-1):
        print()