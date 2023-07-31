#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int a;
    while (cin >> a)
    {
        vector<string> arr(a);
        for (int i = 0; i < a; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        for (int i = 0; i < a; i++)
        {
            cout << arr[i] << endl;
        }
    }
    return 0;
}