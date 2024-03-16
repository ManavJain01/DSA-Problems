// 3. Longest Substring without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    vector<int> vc(256, -1);
    int maxLen = 0;
    int start = -1;
    for(int i=0; i<s.length(); i++){
      if(vc[s[i]] > start){
        start = vc[s[i]];
      }
      vc[s[i]] = i;
      maxLen = max(maxLen, i-start);
    }
    return maxLen;
  }
};

int main(){
  string str = "abcabcbb";
  Solution s;
  cout<<endl<<endl;
  int n = s.lengthOfLongestSubstring(str);
  cout<<endl<<endl<<n<<endl;
  

  return 0;
}