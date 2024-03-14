// 15. 3SUM
// https://leetcode.com/problems/3sum/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>>num;
    set<vector<int>>set;
    /*  First Method  */
    /*  Brute Force  */
    
    for(int i=0; i<nums.size()-2; i++){
      for(int j=i+1; j<nums.size()-1; j++){
        for(int k=j+1; k<nums.size(); k++){
          if(i != j && i != k && j != k && nums[i] + nums[j] + nums[k] == 0){
            set.insert({nums[i],nums[j],nums[k]});
          }
        }
      }
    }

    for(auto it : set){
      num.push_back(it);
    }

    return num;
  }
};

int main(){
  vector<int> num = {-1,0,1,2,-1,-4};
  /*  Answer
    nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
    nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
    nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
  */
  // vector<int> num = {0,1,1};
  Solution s;
  vector<vector<int>> n = s.threeSum(num);

  if(n.size() == 0){
    cout<<endl<<endl<<"EMPTY!!!"<<endl<<endl;
  }else{
    cout<<endl<<endl<<"Indexes are :: ";
    for(int i=0; i<n.size(); i++){
      for(int j=0; j<n.size(); j++){
        cout<<n[i][j]<<" ";
      }cout<<endl;
    }
  }
  cout<<endl<<endl;

  return 0;
}