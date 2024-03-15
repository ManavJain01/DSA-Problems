// 18 4Sum
//https://leetcode.com/problems/4sum/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    /*  Optimized Solution */
    sort(nums.begin(), nums.end());
    set<vector<int>>st;

    for(int a=0; a<nums.size()-1; a++){
      if(a>0 && nums[a] == nums[a-1]) a++;

      for(int b = a+1; b<nums.size(); b++){
        if(b>a+1 && nums[b] == nums[b-1]) b++;

        int c = b+1;
        int d = nums.size()-1;
        while(c<d){
          long long sum = nums[a] + nums[b];
          sum += nums[c] + nums[d];
          if(sum < target) c++;
          else if(sum > target) d--;
          else{
            st.insert({nums[a], nums[b], nums[c], nums[d]});
            c++;
            d--;
            while(c<d && nums[c] == nums[c-1]) c++;
            while(c<d && nums[d] == nums[d+1]) d--;
          }
        }
      }
    }
    vector<vector<int>> num(st.begin(), st.end());
    return num;
  }
};

int main(){
  vector<int> num = {1,0,-1,0,-2,2};
  int target = 0;
  Solution s;
  vector<vector<int>> n = s.fourSum(num,target);

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