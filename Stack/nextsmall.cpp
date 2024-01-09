
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    // Function to find smaller number
    vector<int> nextsmaller(vector<int> &arr, int n)
    {
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; --i)
        {
            int curr = arr[i];
            while (!st.empty() && st.top() >= curr)
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(curr);
        }
    }
    // Function to find smaller number
    vector<int> pevsmaller(vector<int> &arr, int n)
    {
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);
        for (int i = 0; i = n - 1 ; i++)
        {
            int curr = arr[i];
            while (!st.empty() && st.top() >= curr)
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(curr);
        }
    }

    // Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {

        // Your code here
    }
};

//{ Driver Code Starts.

int main()
{
    long long t;

    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        long long *arr;
        arr = new long long[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.getMaxArea(arr, n) << endl;
    }
    return 0;
}

// } Driver Code Ends