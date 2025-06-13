#include <bits/stdc++.h>
using namespace std;
struct Node
{
public:
    int data;   // data of this node
    Node *next; // pointer to next
public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};
Node *ConvertarraytoLL(vector<int> vec)
{
    int n = vec.size();
    Node *y = new Node(vec[0]);
    Node *head = y;
    Node *mover = y;
    int i = 1;
    while (i < n)
    {
        Node *temp = new Node(vec[i]); // making node with a pointer on it
        mover->next = temp;            // creating link
        mover = temp;                  // or mover =mover->next             // mover ko next par bhej diya jaha temp tha
        i++;
    }
    return head;
}
// traversing Linked list
void trasverseLl(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
}
Node *intersection_of_2_LL_brute(Node *h1, Node *h2)
{
    Node *temp = h1;
    while (h2 != nullptr)
    {
        h1 = temp;
        while (h1 != nullptr)
        {
            if (h1 == h2)
            {
                return h1;
            }
            h1 = h1->next;
        }
        h2 = h2->next;
    }
    return NULL;
}
Node *intersection_of_2_LL_better(Node *head1, Node *head2) // using hashtable
{
    unordered_set<Node *> visited;
    Node *temp1 = head1;

    // Store all nodes of first list in set
    while (temp1 != nullptr)
    {
        visited.insert(temp1);
        temp1 = temp1->next;
    }

    // Traverse second list and check for common node
    Node *temp2 = head2;
    while (temp2 != nullptr)
    {
        if (visited.count(temp2))
        {
            return temp2; // Intersection point
        }
        temp2 = temp2->next;
    }

    return nullptr; // No intersection
}
Node *intersection_of_2_LL_optimal_1(Node *head1, Node *head2)
{
    Node *temp = head1;
    int cnt1 = 1;
    while (temp->next != nullptr)
    {
        temp = temp->next;
        cnt1++;
    }
    temp = head2;
    int cnt2 = 1;
    while (temp->next != nullptr)
    {
        /* code */
        temp = temp->next;
        cnt2++;
    }
    Node *ptr1 = head1;
    Node *ptr2 = head2;
    // Advance the pointer of the longer list
    if (cnt1 > cnt2)
    {
        int diff = cnt1 - cnt2;
        while (diff--)
            ptr1 = ptr1->next;
    }
    else
    {
        int diff = cnt2 - cnt1;
        while (diff--)
            ptr2 = ptr2->next;
    }
    while (ptr1 != nullptr && ptr2 != nullptr)
    {
        /* code */
        if (ptr1 == ptr2) // Intersection found
        {
            return ptr1;
        }
        else
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }
    return nullptr; // No intersection
}
Node *intersection_of_2_LL_optimnal_2(Node *h1, Node *h2)
{
    Node *d1 = h1;
    Node *d2 = h2;
    while (d1 != nullptr && d2 != nullptr)
    {
        d1 = d1->next;
        d2 = d2->next;
    }
    if (d1 == nullptr)
    {
        d1 = h2;
        while (d2)
        {
            d2 = d2->next;
            d1 = d1->next;
        }
        d2 = h1;
    }
    else
    {
        d2 = h1;
        while (d1)
        {
            d2 = d2->next;
            d1 = d1->next;
        }
        d1 = h2;
    }
    while (d1 && d2)
    {
        if (d1 == d2)
        {
            return d1;
        }
        d1 = d1->next;
        d2 = d2->next;
    }
    return nullptr;
}
int main()
{

    {
        // Shared part
        Node *common = new Node(8);
        common->next = new Node(10);

        // First list: 3 -> 7 -> 8 -> 10
        Node *head1 = new Node(3);
        head1->next = new Node(7);
        head1->next->next = common;

        // Second list: 99 -> 1 -> 8 -> 10
        Node *head2 = new Node(99);
        head2->next = new Node(1);
        head2->next->next = common;
        Node *inter = intersection_of_2_LL_optimnal_2(head1, head2);
        if (inter)
        {
            cout << inter->data;
        }
        else
            cout << "NULl";
    }
    return 0;
}