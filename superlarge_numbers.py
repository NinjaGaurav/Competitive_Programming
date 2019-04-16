a = int(input("ENTER FIRST NUMBER: "))
b = int(input("ENTER SECOND NUMBER: "))
c = int(input("ENTER THIRD NUMBER: "))
result = a
if b > result and b > c:
    result = b
elif c > result:
    result = c
print("THE LARGEST NUMBER IS: " + str(result))
