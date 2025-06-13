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
Node *reverse(Node *head2)
{
    Node *temp = head2;
    Node *_Dummy = nullptr;
    while (temp != nullptr)
    {
        Node *front = temp->next;
        temp->next = _Dummy;
        _Dummy = temp;
        temp = front;
    }
    return _Dummy;
}
void palindrome_LL(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = reverse(slow->next);
    slow = slow->next;
    Node *_Dummy = head;
    while (slow != nullptr)
    {
        if (slow->data != _Dummy->data)
        {
            cout << "No\n";
            return;
        }
        slow = slow->next;
        _Dummy = _Dummy->next;
    }
    cout << "Yes" << endl;
    return;
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
        Node *head = ConvertarraytoLL(vec);
        palindrome_LL(head);
    }
    return 0;
}