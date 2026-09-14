#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int min = 0;
    for (int i = 0; i < n; i++)
    {
        if ((arr[min]) > arr[i])
        {
            min = i;
        }
    }
    cout << min + 1 << endl;
    return 0;
}