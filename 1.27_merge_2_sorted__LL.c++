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
Node *merge_2_LL_brute(Node *h1, Node *h2)
{
    Node *dummy = new Node(-1);
    Node *tail = dummy;
    while (h1 != nullptr && h2 != nullptr)
    {
        if (h1->data <= h2->data)
        {
            tail->next = new Node(h1->data);
            h1 = h1->next;
            tail = tail->next;
        }
        else
        {
            tail->next = new Node(h2->data);
            h2 = h2->next;
            tail = tail->next;
        }
    }
    while (h1 != nullptr)
    {
        tail->next = new Node(h1->data);
        h1 = h1->next;
        tail = tail->next;
    }
    while (h2 != nullptr)
    {
        tail->next = new Node(h2->data);
        h2 = h2->next;
        tail = tail->next;
    }
    tail->next = nullptr;
    return dummy->next;
};
Node *merge_2__optimal_way_ll(Node *head1, Node *head2)
{
    if (head1 == nullptr)
    {
        return head2;
    }
    if (head2 == nullptr)
    {
        return head1;
    }
    Node *newhead;
    Node *l1, *l2;
    if (head1->data <= head2->data)
    {
        newhead = head1;
        l1 = head1;
        l2 = head2;
    }
    else
    {
        newhead = head2;
        l1 = head2;
        l2 = head1;
    }
    while (l1 != nullptr && l2 != nullptr)
    {
        Node *temp;
        while (l1 != nullptr && l1->data <= l2->data)
        {
            temp = l1;
            l1 = l1->next;
        }
        temp->next = l2;
        swap(l1, l2);
    }
    return newhead;
}
int main()
{
    while (true)
    {
        int n1;
        cin >> n1;
        vector<int> ve1c(n1);
        for (auto &it : ve1c)
        {
            cin >> it;
        }
        int n2;
        cin >> n2;
        vector<int> vec2(n2);
        for (auto &it : vec2)
        {
            cin >> it;
        }
        Node *head1 = ConvertarraytoLL(ve1c);
        Node *head2 = ConvertarraytoLL(vec2);
        Node *head = merge_2__optimal_way_ll(head1, head2);
        trasverseLl(head);
    }
    return 0;
}