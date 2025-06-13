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
Node *reversell(Node *head)
{
    Node *temp = head;
    Node *Dummy = NULL;
    while (temp != nullptr)
    {
        Node *front = temp->next;
        temp->next = Dummy;
        Dummy = temp;
        temp = front;
    }
    return Dummy;
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
        Node *head = ConvertarraytoLL(vec);
        head = reversell(head);
        trasverseLl(head);
    }
    return 0;
}