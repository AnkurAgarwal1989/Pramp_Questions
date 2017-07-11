/*Deletion Distance

The deletion distance of two strings is the minimum number of characters you need to delete in the two strings in order to get the same string.For instance, the deletion distance between "heat" and "hit" is 3:

By deleting 'e' and 'a' in "heat", and 'i' in "hit", we get the string "ht" in both cases.
We cannot get the same string from both strings by deleting 2 letters or fewer.
Given the strings str1 and str2, write an efficient function deletionDistance that returns the deletion distance between them.Explain how your function works, and analyze its time and space complexities.

Examples :

  input : str1 = "dog", str2 = "frog"
  output : 3

  input : str1 = "some", str2 = "some"
  output : 0

  input : str1 = "some", str2 = "thing"
  output : 9

  input : str1 = "", str2 = ""
  output : 0*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void printVec(vector<unsigned int> v) {
  for_each(v.begin(), v.end(), [](auto& e) {cout << e << " "; });
  cout << endl;
}

int deletionDistance(string s1, string s2) {
  cout << s1 <<", " <<s2 << endl;

  vector<unsigned int> prev(s1.size()+1);
  vector<unsigned int> curr(s1.size()+1, 0);

  //Fill initial vector
  for (int i = 0; i < prev.size(); ++i) {
    prev[i] = i;
  }

  printVec(prev);
  printVec(curr);

  //Iterate over second string
  for (int j = 0; j < s2.size()+1; ++j) {
    curr[0] = j;
    for (int i = 1; i < prev.size(); ++i) {
      if (s2[j] == s1[i - 1]) {
        curr[i] = prev[i-1];
      }
      else
        curr[i] = min(prev[i], curr[i - 1]) + 1;
    }
    printVec(prev);
    printVec(curr);
    prev = curr;
    curr.empty();
  }

  return curr[curr.size() - 1];
}

int main() {
  cout << deletionDistance("dog", "frog") << endl;
  cin.get();
  return 1;
}