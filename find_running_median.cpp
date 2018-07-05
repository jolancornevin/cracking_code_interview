// https://www.hackerrank.com/challenges/ctci-find-the-running-median/problem
#include <bits/stdc++.h>

using namespace std;

#include <stdlib.h>
 
typedef struct element element;
struct element
{
    int val;
    struct element *nxt;
};
 
typedef element* llist;

llist newElement(const int val) {
    llist ele = (element*)malloc(sizeof(element));
    ele->val = val;
    ele->nxt = NULL;
    return ele;
}


int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> a(n);
    
    int a_item;
    cin >> a_item;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    // Get the first element to fill the linked list head.
    llist head = newElement(a_item);
    cout << (float)a_item << ".0\n";

    for (int i = 1; i < n; ++i) {
        cin >> a_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        // Create a new element with the new number
        llist nouvelElement = newElement(a_item);
        
        // Create an iterator a the beginning of our linked list.
        llist iter = head;
        
        // Loop in our list until we find a higher value than our current one.
        // When we do, we can insert the new element in our list.
        if (iter->val < a_item) {
            while (iter->nxt != NULL && iter->nxt->val < a_item) {
                iter = iter->nxt;
            }
        }
        
        // Insert the new element in the list.
        llist temp = iter->nxt;
        iter->nxt = nouvelElement;
        nouvelElement->nxt = temp;
        
        iter = head;
        while (iter->nxt != NULL) {
            // cout << iter->val << " - ";
            iter = iter->nxt;
        }
        // cout << iter->val;
        
        // Go back to the head, to loop to the middle of the list to print the median value.
        iter = head;
        if ((i + 1) % 2 == 0) {
            for (int j = 0; j < i/2; ++j) {
                iter = iter->nxt;
            }
            cout << ( ((float) (iter->val + iter->nxt->val)) / 2.0 ) << '\n';
        } else {
            for (int j = 0; j < i/2; ++j) {
                iter = iter->nxt;
            }
            cout << (float)iter->val << ".0\n";
        }
    }
    
    // Delete the linked list.
    llist iter = head;
    while (iter->nxt != NULL && iter->nxt->val > a_item) {
        llist temp = iter;
        iter = iter->nxt;
        free(temp);
    }

    return 0;
}
