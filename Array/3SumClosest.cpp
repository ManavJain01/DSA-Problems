// 16. 3SUM Closest
// https://leetcode.com/problems/3sum-closest/

/*
  this solution is very similar to previous solution.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
    /*  Optimised Solution */
    int resultSum = nums[0] + nums[1] + nums[2];
    int minDiff = INT_MAX;
    sort(nums.begin(), nums.end());

    for(int i=0; i<nums.size(); i++){
      int j=i+1;
      int k=nums.size()-1;
      while(j<k){
        int sum = nums[i] + nums[j] + nums[k];
        if(sum < target)    j++;
        else if(sum > target)   k--;
        else if(sum == target)  return target;
        
        int diffToTarget = abs(sum - target);
        if(diffToTarget < minDiff){
          minDiff = diffToTarget;
          resultSum = sum;
        }
      }
    }
    return resultSum;
    
  }
};

int main(){
  vector<int> num = {-1,2,1,-4};
  int target = 1;
  Solution s;
  int n = s.threeSumClosest(num,target);

  cout<<endl<<endl<<n<<endl<<endl;

  return 0;
}