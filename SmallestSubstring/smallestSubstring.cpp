/*Given an array with unique characters arr and a string str, find the smallest substring of str containing all characters of arr.

Example:
arr: [x, y, z], str : xyyzyzyx
result : zyx*/

/*
Logic:
We iterate through str and count elemnts at the head.
At the tail end, we move forward and disregard elements till we get the smallest substring.

We maintain:
a count of unique elements seen
a count of each element seen
head
tail

*/

#include<string>
#include<vector>
#include<iostream>
#include<map>

using namespace std;

string getSubString(string str, int begin, int end) {
  return str.substr(begin, end - begin + 1);
}

//Every time we see a new char, see if all required characters have been found
//Return True if all char have been found
//Return Flase if not
int numCharactersFound(map<char, bool> &cmap, char c) {
  cmap.find(c)->second=true;

  int chars_found = 0;
  for (auto &p : cmap) {
    chars_found += p.second;
  }
  return chars_found;
}

void initMap(map<char, int> &cmap, vector<char> arr) {
  for (const char &c : arr) {
    cmap[c] = 0;
  }
}

void printMap(const map<char, int> &cmap) {
  for (auto p : cmap) {
    std::cout << p.first << ": " << p.second << std::endl;
  }
}

int main() {
  vector<char> arr = { 'x', 'y', 'z' };
  string str = "xyyzxzyx";
  int unique_elements_seen = 0;
  map<char, int> countMap;
  initMap(countMap, arr);
  printMap(countMap);
  string bestString = str;
  bool bestFound = false;
  map<char, int>::iterator p;
  int begin = 0;
  int steps = arr.size();

  int tail = 0;

  for (int head = 0; head < str.size(); ++head) {
    p = countMap.find(str[head]);
    if (p == countMap.end()) {  //Char is not a required elem in arr
      continue;
    }
    //for each character in string, add it's count to countMap. If this is the first time it is being added, add to unique elements
    if (p->second == 0) {
      //Element seen first time
      ++unique_elements_seen;
    }
    ++(p->second);
    printMap(countMap);
    cout << endl;

    while (unique_elements_seen == arr.size()) {
      //Start reducing length to see if we can get a smaller substring
     
      string temp = getSubString(str, tail, head);
     
      if (!bestFound || temp.size() < bestString.size()) {
        cout << "Found a valid substring" << endl;
        cout << temp << endl;
        bestString = temp;
        bestFound = true;
      }

      if (temp.size() == arr.size()) {
        cout << "Found smallest substring" << endl;
        cout << temp << endl;
        return 1;
      }
      cout << "Reducing " << endl;

      countMap.find(str[tail])->second -= 1;
      if (countMap.find(str[tail])->second == 0) {
        --unique_elements_seen;
      }
      ++tail;
      
    }
  }
  /*while (1) {
    for (int i = begin; i < str.size(); ++i) {
      steps = arr.size() - numCharactersFound(countMap, str[i]);
      cout << str[i] << endl;
      printMap(countMap);
      cout << "Steps " << steps << endl;
      if (steps == 0) {
        cout << "Found a valid substring" << endl;
        bestString = getSubString(str, begin, i);
        cout << bestString << endl;
        resetMap(countMap, arr);
        i = begin;
        ++begin;
      }
    }
  }
  
  
 

  string substr = getSubString(str, 0, 3);
  std::cout << substr << endl;*/
  std::cin.get();
  return 1;
}