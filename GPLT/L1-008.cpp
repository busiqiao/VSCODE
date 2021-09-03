//L1-008 求整数段和 (10 分)
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, sum = 0;
    cin >> a >> b;
    for (int i = a, count = 0; i <= b; i++)
    {
        sum += i;
        if (count >= 5)
        {
            cout << endl;
            count = 0;
        }

        printf("%5d", i);
        count++;
    }
    cout << endl << "Sum = " << sum;

    return 0;
}
