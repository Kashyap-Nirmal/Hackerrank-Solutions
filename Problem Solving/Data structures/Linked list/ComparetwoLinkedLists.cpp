/*
	200721
	https://www.hackerrank.com/challenges/compare-two-linked-lists/problem
	Done
*/

#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the compare_lists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
 
bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    bool ans=true;
    SinglyLinkedListNode* temp1 = head1,*temp2 = head2;
    while(ans && temp1 && temp2)
    {
        if(temp1->data!=temp2->data)
            ans=false;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    if(temp1!=temp2 && (temp1!=NULL | temp2!=NULL) && ans==true)        
        ans=false;
    return ans;
}

int main()