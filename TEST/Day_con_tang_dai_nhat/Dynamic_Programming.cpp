#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestIncreasingSubsequence(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return 0;

    vector<int> dp(n, 1); 

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main()
{
    int n;
    cin >> n; 
    vector<int> arr(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << longestIncreasingSubsequence(arr) << endl;
    return 0;
}