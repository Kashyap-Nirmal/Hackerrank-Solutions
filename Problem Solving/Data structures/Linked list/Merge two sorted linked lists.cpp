/*	
	250721
	https://www.hackerrank.com/challenges/merge-two-sorted-linked-lists/problem
	Solution.
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

// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    if((head1==NULL) && (head2==NULL))
        return NULL;
    if((head1!=NULL) && (head2==NULL))
        return head1;
    if((head1 == NULL) && (head2!=NULL))
        return head2;
    if(head1->data < head2->data)
        head1->next = mergeLists(head1->next, head2);
    else if(head1->data >= head2->data)
    {
        SinglyLinkedListNode* temp = head2;
        head2 = head2->next;
        temp->next = head1;
        head1 = temp;
        head1->next = mergeLists(head1->next, head2);
    }
    return head1;
/*
    SinglyLinkedListNode* ans,*temp1=head1,*temp2=head2,*ans2;
    int cnt1=0,cnt2=0,i;
    while(temp1)
    {
        cnt1++;
        temp1=temp1->next;
    }
    while(temp2)
    {
        cnt2++;
        temp2=temp2->next;
    }
    temp1=head1;
    temp2=head2;
    ans=new SinglyLinkedListNode(-1);
    ans2=ans;
    for(i=0;i<cnt1+cnt2 && (temp1->next || temp2->next);i++)
    {
        cout<<temp1->data<<" "<<temp2->data<<" "<<ans->data<<" ";
        ans->next=new SinglyLinkedListNode(min(temp1->data, temp2->data));
        if(temp1->data == temp2->data)
        {
            cout<<"I ";
            cout<<"\nA: "<<ans->data<<" "<<ans->next->data<<"\n";
            cout<<min(temp1->data, temp2->data)<<"\n";
            if(temp1->next)
                temp1=temp1->next;
            if(temp2->next)
                temp2=temp2->next;
        }
        else if(temp1->data < temp2->data && temp1->next)
        {
            cout<<"EI\n";
            temp1=temp1->next;
        }
        else if(temp1->data > temp2->data && temp2->next)
        {
            cout<<"EI2\n";
            temp2=temp2->next;
        }
        cout<<"A: "<<ans->data<<" "<<ans->next->data<<"\n";
        ans=ans->next;
    }
    cout<<"\n\n";
    cout<<temp1->data<<" "<<temp2->data<<" "<<ans->data<<"\n";
    ans->next = new SinglyLinkedListNode(min(temp1->data, temp2->data));
    ans=ans->next;
    cout<<temp1->data<<" "<<temp2->data<<" "<<ans->data<<"\n";
    ans->next = new SinglyLinkedListNode(max(temp1->data, temp2->data));
    ans=ans->next;
    cout<<temp1->data<<" "<<temp2->data<<" "<<ans->data<<"\n";
    ans->next=NULL;
    ans2=ans2->next;
    cout<<"B: "<<ans2->data<<"\n";
    free(head1);
    free(head2);
    return ans2;
    */
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int tests;
    cin >> tests;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
        SinglyLinkedList* llist1 = new SinglyLinkedList();

        int llist1_count;
        cin >> llist1_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist1_count; i++) {
            int llist1_item;
            cin >> llist1_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist1->insert_node(llist1_item);
        }
      
      	SinglyLinkedList* llist2 = new SinglyLinkedList();

        int llist2_count;
        cin >> llist2_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist2_count; i++) {
            int llist2_item;
            cin >> llist2_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist2->insert_node(llist2_item);
        }

        SinglyLinkedListNode* llist3 = mergeLists(llist1->head, llist2->head);

        print_singly_linked_list(llist3, " ", fout);
        fout << "\n";

        free_singly_linked_list(llist3);
    }

    fout.close();

    return 0;
}