

#include<iostream>
#include <stack>
using namespace std;
#include<vector>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> st;
    vector<int> ans(n);
    st.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (st.top() >= curr)
        {
            st.pop();
        }

        ans[i] = st.top();
        st.push(curr);
    }

    return ans;
}