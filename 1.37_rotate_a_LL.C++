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
Node *rotate(Node *head, int k)
{
    if(head==nullptr||head->next==nullptr)
    {
        return head;
    }
    Node *temp = head;
    int cnt = 1;
    while (temp->next != nullptr)
    {
        temp = temp->next;
        cnt++;
    }
    temp->next = head;
    k = k % cnt;
    k = cnt - k;
    cnt = 1;
    Node *_Dummy = new Node(0);
    _Dummy->next = head;
    while (cnt <= k)
    {
        _Dummy = head;
        head = head->next;
        cnt++;
    }
    _Dummy->next = nullptr;
    return head;
};
int main()
{
    while (true)
    {
        int n;
        cin >> n;
        vector<int> vec(n);
        for (auto &it : vec)
        {
            cin >> it;
        }
        int k;
        cin >> k;
        Node *head = ConvertarraytoLL(vec);
        head = rotate(head, k);
        trasverseLl(head);
    }
    return 0;
}