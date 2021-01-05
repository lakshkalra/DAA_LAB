def activityselector(s, f):
    n = len(f)
    print("The activities are: ")
    k = 1
    print(k,end=" ")
    for j in range(n):
        if s[j] >= f[k]:
            print(j,end=" ")
            k=j

s = [1,3,0,5,8,5]
f = [2,4,6,7,9,9]
print(activityselector(s, f))
