#include <iostream>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        float a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        float min = a[0];
        for (int i = 1; i < n; i++)
        {
            if (min > a[i])
            {
                min = a[i];
            }
        }
        cout << min << endl;
    }
    return 0;
}
