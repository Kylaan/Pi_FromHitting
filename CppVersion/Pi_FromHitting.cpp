#include <iostream>
#include <cmath>

long long getHitCounts(double k) 
{
	long long cnt = 0;
	double v0 = 0;
	double u0 = -1;
 
	double u1 = (k-1)*u0 / (k+1);
	double v1 = k * (u0-u1);
	//first hit
	cnt++;
 
	double v2, u2;
	while (1)
	{
		if (v1 < 0)
			cnt++;
		if (u1 > 0 && -v1 <= u1)
		{
			break;
		}
		cnt++;
		u2 = (k-1)*u1 / (k+1) - 2*v1 / (k+1);
		v2 = 2*k*u1 / (k+1) + (k-1)*v1 / (k+1);

		v1 = v2;
		u1 = u2;
	}
 
	return cnt;
}

int main() {
    double x = 1;
    for (int i = 0; i < 9; i++)
    {
        x *= 1e2;
        printf("10^%d:\n%lld\n", 2*i, getHitCounts(x));
    }

    return 0;

}
