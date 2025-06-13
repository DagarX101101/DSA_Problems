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
void remove_nth_node_(Node *node) // head is not given
{
    Node *temp = node->next;
    int x = temp->data;
    temp->data = node->data;
    node->data = x;
    swap(node, temp); // swaps only pointer names not the data
    temp->next = node->next;
    node->next = nullptr;
    delete node;
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
        remove_nth_node_(head);
        trasverseLl(head);
    }
    return 0;
}