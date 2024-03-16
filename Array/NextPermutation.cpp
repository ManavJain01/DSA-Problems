// 31 Next Permutation
// https://leetcode.com/problems/next-permutation/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  void nextPermutation(vector<int>& nums) {
    /* My Method Only For 3 Elements in an array*/
    /* Brute Force */
    /*
    vector<int>num = nums;

    sort(nums.begin(), nums.end());
    set<vector<int>>st;

    for(int i=0; i<nums.size(); i++){
      vector<int>temp;

      temp.push_back(nums[i]);
      for(int j=0; j<nums.size(); j++){
        if(j != i) temp.push_back(nums[j]);
      }
      st.insert(temp);

      vector<int>temp2;
      int j = 0;
      if(j < nums.size()) temp2.push_back(temp[j]);
      if(j+2 < nums.size()) temp2.push_back(temp[j+2]);
      if(j+1 < nums.size()) temp2.push_back(temp[j+1]);
      st.insert(temp2);
    }

    vector<vector<int>>vc(st.begin(), st.end());
    cout<<"VC->";
    for(int i=0; i<vc.size(); i++){
      for(int j=0; j<vc[i].size(); j++){
        cout<<vc[i][j]<<" ";
      }cout<<endl;
    }

    for(int i=0; i<vc.size(); i++){
      if(vc[i] == num){
        for(int j=0; j<vc[i+1].size(); j++){
          nums[j] = vc[i+1][j];
        }
        break;
      }
    }

    cout<<endl<<"Result->";
    for(int i=0; i<nums.size(); i++){
      cout<<nums[i]<<" ";
    }
    */

    /* Second Method / Better Solution */
    /* Use STL Library */
    /*
    next_permutation(nums.begin(), nums.end());
    */

    /* Third Method / Optimized Solution */
    int index = -1;
    int n = nums.size();
    for(int i=n-2; i>=0; i--){
      if(nums[i] < nums[i+1]){
        index = i;
        break;
      }
    }
    if(index == -1){
      reverse(nums.begin(), nums.end());
      return;
    }
    for(int i= n-1; i>index; i--){
      if(nums[i] > nums[index]){
        swap(nums[i],nums[index]);
        break;
      }
    }

    reverse(nums.begin()+(index+1), nums.end());
  }
};

int main(){
  // vector<int> num = {1,2,3};
  // vector<int> num = {1,3,2};
  // vector<int> num = {3,2,1};
  // vector<int> num = {1,1,5};
  // vector<int> num = {1};
  vector<int> num = {1,3,2};
  Solution s;
  cout<<endl<<endl;
  s.nextPermutation(num);
  cout<<endl<<endl;
  for(int i=0; i<num.size(); i++){
    cout<<num[i]<<" ";
  }

  return 0;
}