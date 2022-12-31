def TimeCounter (k):
    cnt = 0
    v0 = 0
    u0 = -1
    #start
    u1 = (k-1)*u0 / (k+1)
    v1 = k * (u0-u1)
    #First hit
    cnt+=1
    v2 = 0
    u2 = 0
    while 1:
        if (v1 < 0):
            cnt+=1
        if u1 > 0 and -v1 <= u1:
            break
        cnt+=1
        u2=(k-1)*u1/(k+1)-2*v1/(k+1)
        v2=2*k*u1/(k+1)+(k-1)*v1/(k+1)
 
        v1 = v2
        u1 = u2
	
    return cnt

for i in range(1,10):
    x = 10**(2*i)
    print(f"\x1b[90m[M:m=10^{2*i}]\x1b[0m: {TimeCounter(x)}")
