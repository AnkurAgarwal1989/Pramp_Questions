/*Bracket Match

A string of brackets is considered correctly matched if every opening bracket in the string can be paired up with a later closing bracket, and vice versa.For instance, (())() is correctly matched, whereas )( and (( arent.For instance, (( could become correctly matched by adding two closing brackets at the end, so youd return 2.

Given a string that consists of brackets, write a function bracketMatch that takes a bracket string as an input and returns the minimum number of brackets youd need to add to the input in order to make it correctly matched.

Explain the correctness of your code, and analyze its time and space complexities.

Examples:

input:  text = (()
  output : 1

  input : text = (())
  output : 0

  input : text = ())(
    output : 2*/

#include<vector>
#include<stack>
#include<iostream>
#include<string>

using namespace std;

int bracketMatch(string text) {
  stack<char> bracketStack;
  cout << "text: " << text << endl;
  for (int i = 0; i < text.size(); ++i) {
    if (text[i] == '(') {
      bracketStack.push(text[i]);
    }
    else if (text[i] == ')'){
      if (bracketStack.size() > 0 && bracketStack.top() == '(') {
        bracketStack.pop();
      }
      else
        bracketStack.push(text[i]);
      }
    }

  return bracketStack.size();
}

int main() {
  cout << "Required Match:" << bracketMatch(")");
  cin.get();
  return 1;
}