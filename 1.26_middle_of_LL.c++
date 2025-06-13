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
void middle(Node *head) // brute O(n)+O(n/2);
{                       // sc : O(1);
    Node *temp = head;

    int cnt = 1;
    if (head == nullptr)
    {
        cout << "Null";
        return;
    }
    if (head->next == nullptr)
    {
        cout << head->data;
        return;
    }
    while (temp->next != nullptr)
    {
        temp = temp->next;
        cnt++;
    }
    int n = cnt / 2 + 1;
    cnt = 1;
    temp = head;
    while (cnt != n)
    {
        temp = temp->next;
        cnt++;
    }
    cout << temp->data;
    return;
}

void optimal(Node *head) // Tortoise Method
{
    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << slow->data;
    return;
}
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
        optimal(head);
    }
    return 0;
}