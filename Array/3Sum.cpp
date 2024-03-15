// 15. 3SUM
// https://leetcode.com/problems/3sum/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    /*  First Method  */
    /*  Brute Force  */
    /*
    vector<vector<int>>num;
    set<vector<int>>set;

    for(int i=0; i<nums.size()-2; i++){
      for(int j=i+1; j<nums.size()-1; j++){
        for(int k=j+1; k<nums.size(); k++){
          if(i != j && i != k && j != k && nums[i] + nums[j] + nums[k] == 0){
            // num.push_back({i,j,k});
            set.insert({nums[i],nums[j],nums[k]});
          }
        }
      }
    }

    for(auto it : set){
      num.push_back(it);
    }
    return num;
    */

    /*  Second Method / Better Solution  */
    /*  Using Hashset */
    /*
    set<vector<int>>st;

    for(int i=0; i<nums.size()-1; i++){
      set<int> hashset;
      for(int j=i+1; j<nums.size(); j++){
        int third = -(nums[i] + nums[j]);
        if(hashset.find(third) != hashset.end()){
          vector<int>temp = {nums[i], nums[j], third};
          sort(temp.begin(), temp.end());
          st.insert(temp);
        }
        hashset.insert(nums[j]);
      }
    }
    vector<vector<int>>num(st.begin(), st.end());
    return num;
  }
  */

  /*  Third Method / Optimal Solution  */
    /*  Using 2Pointers */
    vector<vector<int>>num;
    sort(nums.begin(), nums.end());

    for(int i=0; i<nums.size(); i++){
      if(i>0 && nums[i] == nums[i-1]) continue;
      int j=i+1;
      int k=nums.size()-1;
      while(j<k){
        int sum = nums[i] + nums[j] + nums[k];
        if(sum < 0){
          j++;
    
        }else if(sum > 0){
          k--;

        }else{
          num.push_back({nums[i], nums[j], nums[k]});
          j++;
          k--;
          while(j<k && nums[j] == nums[j-1]) j++;
          while(j<k && nums[k] == nums[k+1]) k--;
        }
      }
    }

    return num;
  }
};

int main(){
  // vector<int> num = {-1,0,1,2,-1,-4};
  vector<int> num = {-4,-1,-1,0,1,2};
  /*
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