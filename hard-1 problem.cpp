#include<bits/stdc++.h>
using namespace std;
class Answer{
public:
    vector<int> maxSliding(vector<int>& num, int l) 
      {
        deque<int>dq;
        vector<int>ans;
        for(int i=0;i<l;i++)
	{
            while(!dq.empty()&&num[i]>=num[dq.back()])
            dq.pop_back();
            dq.push_back(i);
        }
	ans.push_back(num[dq.front()]);

        for(int i=l;i<num.size();i++)
	{
            if(!dq.empty()&&i-l>=dq.front())
	     {
                dq.pop_front();
            }

  while(!dq.empty()&&num[i]>=num[dq.back()])
            dq.pop_back();
            dq.push_back(i);
            ans.push_back(num[dq.front()]);
        }
         return ans;
    }
  
};

int main() {
    Answer solution;

    int n, m;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter the window size (m): ";
    cin >> m;
    vector<int> result = solution.maxSliding(nums, m);
    cout << "Sliding Window Maximums:\n";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}