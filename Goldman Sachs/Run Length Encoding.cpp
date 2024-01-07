// https://www.geeksforgeeks.org/problems/run-length-encoding/1
// TC: O(N)
// SC: O(1)

string encode(string src)
{     
  //Your code here 
  int n=src.size();
  string str;
  int i=0;
  while(i<n){
      char c=src[i];
      int cnt=1;
      i++;
      while(src[i]==c){
          cnt++;
          i++;
      }
      str+=c;
      str+=to_string(cnt);
  }
  
  return str;
  
}   