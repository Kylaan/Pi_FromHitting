#include <iostream>
#include <cmath>
using namespace std;

int getHitCounts(long long k) 
{
	int cnt = 0;
	float v0 = 0;
	float u0 = -1000;
 
	float u1 = (k-1)*u0 / (k+1);
	float v1 = k * (u0-u1);
	//first hit
	cnt++;
 
	float v2, u2;
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
    for (int i = 0; i < 30; i++)
    {
        long long x = pow(10, i);
        cout << x << ":\n"
             << getHitCounts(x) << endl;
    }
    
    return 0;

}
