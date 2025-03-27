#include <vector>
#include <algorithm>

class Solution {
  public:
  std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
 
          if(intervals.empty()){
              return {};
          }
      sort(intervals.begin(),intervals.end());
      
  
      std::vector<std::vector<int>> newIntervals;
      for(auto a:intervals)
  {
      if (newIntervals.empty() || newIntervals.back()[1] < a[0]) {
              newIntervals.push_back(a);
          } else {
              newIntervals.back()[1] = std::max(newIntervals.back()[1], a[1]);
          }
      }
      
      return newIntervals;
  }
  }; 



  // Example
  // Step-by-Step Execution:
  // First Interval {1, 3}
  
  // newIntervals = [{1, 3}]
  
  // No merging needed.
  
  // Second Interval {2, 6}
  
  // Overlap Check: 3 >= 2 (overlapping ✅)
  
  // Update Last Interval's End:
  
  // cpp
  // Copy code
  // newIntervals.back()[1] = max(3, 6) = 6;
  // Updated newIntervals → [{1, 6}]
  
  // Third Interval {8, 10}
  
  // 6 < 8 (No overlap ❌)
  
  // Add {8, 10} as a new interval.
  
  // newIntervals = [{1, 6}, {8, 10}]
  
  // Fourth Interval {15, 18}
  
  // 10 < 15 (No overlap ❌)
  
  // Add {15, 18} as a new interval.
  
  // newIntervals = [{1, 6}, {8, 10}, {15, 18}]