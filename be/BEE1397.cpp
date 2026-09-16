#include <iostream>
using namespace std;
int main()
{
    int a, b, n;

    while (cin >> n && n != 0)
    {
        int i = 1;
        int counta = 0, countb = 0;
        while (i <= n)
        {
            cin >> a >> b;

            if (a > b)
            {
                counta++;
            }
            else if (b > a)
            {
                countb++;
            }
            i++;
        }

        cout << counta << " " << countb << endl;
    }
    return 0;
}