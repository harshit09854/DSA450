// Two sum -Pairs with 0 Sum

#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
  public:
    vector<vector<int>> getPairs(vector<int>& arr) {
        // code here
     vector<vector<int>> result;
        set<pair<int, int>> uniquePairs;
        int n = arr.size();
        
    
        sort(arr.begin(), arr.end());

       
        int left = 0, right = n - 1;

        while (left < right) {
            int sum = arr[left] + arr[right];

            if (sum == 0) {
                uniquePairs.insert({arr[left], arr[right]});
                left++;
                right--;
            } else if (sum < 0) {
                left++; 
            } else {
                right--; 
            }
        }

      
        for (auto p : uniquePairs) {
            result.push_back({p.first, p.second});
        }
        
        return result;
    }
};