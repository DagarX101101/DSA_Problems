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
Node *remove_nth_node_from_back(Node *head, int n)
{
    Node *temp = head;
    int cnt = 1;
    while (temp->next != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    int k = cnt - n + 1;
    cnt = 1;
    Node *prev = NULL;
    temp = head;
    while (cnt != k)
    {
        cnt++;
        prev = temp;
        temp = temp->next;
    }
    if (cnt != 1)
    {
        prev->next = temp->next;
        temp->next = nullptr;
        delete temp;
        return head;
    }
    else
    {
        head = head->next;
        temp->next = nullptr;
        delete temp;
        return head;
    }
};
Node *remove_nth_node_from_back_optimal(Node *head, int n)
{
    Node *dummy = new Node(-1);
    dummy->next = head;
    Node *f = dummy;
    for (int i = 0; i < n; i++)
    {
        f = f->next;
    }
    Node *s = dummy;
    while (f->next != nullptr)
    {
        s = s->next;
        f = f->next;
    }
    if (s == dummy)
    {
        head = head->next;
        s->next->next = nullptr;
        delete s->next;
        return head;
    }
    Node *temp = s->next;
    s->next = s->next->next;
    temp->next = nullptr;
    delete temp;
    return head;
}
int main()
{
    while (true)
    {
        int n1;
        cin >> n1;
        vector<int> vec(n1);
        for (auto &it : vec)
        {
            cin >> it;
        }
        int n;
        cin >> n;
        Node *head = ConvertarraytoLL(vec);
        head = remove_nth_node_from_back_optimal(head, n);
        trasverseLl(head);
    }
    return 0;
}