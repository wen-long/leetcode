/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


#include "iostream"
#include "string"
#include "algorithm"
#include "vector"
#include "sstream"
#include "iterator"
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode *result, *templ1 = l1, *templ2 = l2;
		int len1 = 0, len2 = 0;
		while (templ1 -> next) {
			templ1 = templ1 -> next;
			++len1;
		}
		while (templ2 -> next) {
			templ2 = templ2 -> next;
			++len2;
		}
		templ1 = l1;
		templ2 = l2;
		while (len1 > len2) {
			templ1 = templ1 -> next;
			--len1;
		}
		while (len1 < len2) {
			templ2 = templ2 -> next;
			--len2;
		}
		ListNode *endofl1 = templ1;
		ListNode *endofl2 = templ2;

		
		
		ListNode head(0);
		ListNode *h = &head;
		while (len2) {
			int sum = templ1 -> val + templ2 -> val;
			templ1 = templ1 -> next;
			templ2 = templ2 -> next;
			h -> next = new ListNode(sum);
			h = h -> next;
			--len2;
		}

	}
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}