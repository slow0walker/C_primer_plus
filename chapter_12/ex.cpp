#include <iostream>
using namespace std;

int main()
{
    long long x, y;
    cin >> x >> y;

    long long sum = x + y;

    long long digit_sum = 0;

    while (sum > 0)
    {
        digit_sum += sum % 10;
        sum /= 10;
    }

    cout << digit_sum << endl;

    return 0;
}
