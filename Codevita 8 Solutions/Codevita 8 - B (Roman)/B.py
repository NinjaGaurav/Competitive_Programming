number = [1,4,5,9,10,40,50,90,100,400,500,900,1000]
symbol = ["I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"]
DICT = {
    'C':12,
    'D':13,
    'I':18,
    'L':21,
    'M':22,
    'V':31,
    'X':33
}
def roman(n):
    i = 12
    string = ''
    while n>0:
        div = n // number[i]
        n = n % number[i]
        
        string = string + symbol[i]*div
        i = i-1
    return string


def base(m):
    lim = 0
    for x in m:
        lim = max(lim, DICT[x])
    lim = lim + 1
    ans = 0
    for x in m:
        ans = ans*lim + DICT[x]
    return ans    
    
n = int(input())
while n>=1 and n<=3999:
    m = roman(n)
    n = base(m)
    
print(n)