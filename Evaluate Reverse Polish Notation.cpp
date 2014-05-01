//============================================================================
// Evaluate Reverse Polish Notation
//
// Evaluate the value of an arithmetic expression in Reverse Polish Notation.
//
// Valid operators are +, -, *, /. Each operand may be an integer or another 
// expression.
//
// Some examples:
//  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
//
// Complexity:
// O(n) time, O(n) space
//============================================================================

#include "iostream"
#include "string"
#include "algorithm"
#include "stack"
#include "sstream"
#include "iterator"
using namespace std;

class Solution {
public:
	int evalRPN(vector<string> &tokens) {
		return evalRPN1(tokens);
	}

	int evalRPN1(vector<string> &tokens) {
		stack<int> stk;
		int pos = 0;
		while (pos != tokens.size()) {
			if (tokens[pos].length() > 1){
				stk.push(stoi(tokens[pos]));
			} else switch (tokens[pos][0]) {
				case '+': {
					int b = stk.top();
					stk.pop();
					int a = stk.top();
					stk.pop();
					int c = a + b;
					stk.push(c);
					break;
				}
				case '-': {
					int b = stk.top();
					stk.pop();
					int a = stk.top();
					stk.pop();
					int c = a - b;
					stk.push(c);
					break;
				}
				case '*': {
					int b = stk.top();
					stk.pop();
					int a = stk.top();
					stk.pop();
					int c = a * b;
					stk.push(c);
					break;
				}
				case '/': {
					int b = stk.top();
					stk.pop();
					int a = stk.top();
					stk.pop();
					int c = a / b;
					stk.push(c);
					break;
				}
				default: {
					stk.push(stoi(tokens[pos]));
					break;
				}
			}
			++pos;
		}
		return stk.top();
	}

	int evalRPN2(vector<string> &tokens) {
		int op1, op2;
		stack<int> stk;
		for (auto str : tokens) {
			if (str == "+" || str == "-" || str == "*" || str == "/") {
				op2 = stk.top(), stk.pop();
				op1 = stk.top(), stk.pop();
				if (str == "+") stk.push(op1 + op2);
				else if (str == "-") stk.push(op1 - op2);
				else if (str == "*") stk.push(op1*op2);
				else stk.push(op1 / op2);
			}
			else {
				stk.push(stoi(str));
			}
		}
		return stk.top();
	}
};

int main(int argc, char const *argv[])
{
	Solution s;
	vector<string> tokens({"2", "1", "+", "3", "*"});
	cout << s.evalRPN(tokens) << endl;
	return 0;
}