
#include<iostream>
#include <stack>
using namespace std;
#include<vector>
int largestRectangle(vector<int> &hei)
{
    int n = hei.size();
    if (n == 0)
    {
        return 0;
    }

    stack<int> s;
    int area_max = 0;
    int tp, width, area_with_top;
    int i = 0;

    while (i < n)
    {
        if (s.empty() || hei[s.top()] <= hei[i])
        {
            s.push(i++);
        }
        else
        {
            tp = s.top();
            s.pop();
            // width = s.empty() ? i : i - s.top() - 1;
            if (s.empty())
            {
                width = i;
            }
            else
            {
                width = i - s.top() - 1;
            }
            area_with_top = hei[tp] * width;
            area_max = max(area_max, area_with_top);
        }
    }

    while (!s.empty())
    {
        tp = s.top();
        s.pop();
        if (s.empty())
        {
            width = i;
        }
        else
        {
            width = i - s.top() - 1;
        }
        area_with_top = hei[tp] * width;
        area_max = max(area_max, area_with_top);
    }

    return area_max;
}
int main(){
    
}