// 43. Palindrome Partitioning
// https://leetcode.com/problems/palindrome-partitioning/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string>path;
    func(0, s, path, res);
    return res;
  }

  void func(int index, string s, vector<string>& path, vector<vector<string>>& res){
    if(index == s.size()){
      res.push_back(path);
      return;
    }
    for(int i=index; i<s.size(); ++i){
      if(isPalindrome(s, index, i)){
        path.push_back(s.substr(index, i-index+1));
        func(i+1, s, path, res);
        path.pop_back();
      }
    }
  }

  bool isPalindrome(string s, int start, int end){
    while(start <= end){
      if(s[start++] != s[end--])  return false;
    }
    return true;
  }
};

int main(){
  // string str = "aab";
  // string str = "a";
  string str = "aabb";
  Solution s;
  cout<<endl<<endl;
  vector<vector<string>> str1 = s.partition(str);
  
  for(int i=0; i<str1.size(); i++){
    for(int j=0; j<str1[i].size(); j++){
      cout<<str1[i][j]<<" ";
    }
    cout<<endl;
  }
  

  return 0;
}