#include <bits/stdc++.h>
using namespace std;
struct Node
{
public:
    int data; // data of this node
    Node *next;
    Node *bottom; // pointer to next
public:
    Node(int data1, Node *next1, Node *bottom1)
    {
        data = data1;
        next = next1;
        bottom = bottom1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        bottom = nullptr;
    }
};
// Create bottom list from a vector
Node *createBottomList(vector<int> &vals)
{
    if (vals.empty())
        return nullptr;
    Node *head = new Node(vals[0]);
    Node *temp = head;
    int y = vals.size();
    for (int i = 1; i < y; i++)
    {
        temp->bottom = new Node(vals[i]);
        temp = temp->bottom;
    }
    return head;
}
// Take input
Node *takeInput2DLinkedList()
{
    int n;
    cout << "Enter number of horizontal nodes: ";
    cin >> n;

    Node *head = nullptr;
    Node *last = nullptr;

    for (int i = 0; i < n; i++)
    {
        int val;
        cout << "\nEnter main node value: ";
        cin >> val;

        Node *row = new Node(val);

        int k;
        cout << "Enter number of bottom nodes: ";
        cin >> k;

        vector<int> bottomVals(k);
        cout << "Enter bottom values: ";
        for (int j = 0; j < k; j++)
        {
            cin >> bottomVals[j];
        }

        row->bottom = createBottomList(bottomVals);

        if (!head)
            head = row;
        else
            last->next = row;

        last = row;
    }

    return head;
}
// print the 2d LL
void trasversal(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        Node *down = temp;
        while (down != nullptr)
        {
            cout << down->data << " ";
            down = down->bottom;
        }
        cout << endl;
        temp = temp->next;
    }
}
// Merge two sorted bottom lists
Node *mergeTwoLists(Node *a, Node *b)
{
    Node *temp = new Node(0); // Dummy node
    Node *res = temp;

    while (a != NULL && b != NULL)
    {
        if (a->data < b->data)
        {
            temp->bottom = a;
            a = a->bottom;
        }
        else
        {
            temp->bottom = b;
            b = b->bottom;
        }
        temp = temp->bottom;
    }

    if (a)
        temp->bottom = a;
    else
        temp->bottom = b;

    return res->bottom;
}

Node *flatten_2d_LL(Node *root)
{
    if (!root || !root->next)
        return root;

    // Flatten the rest of the list
    root->next = flatten_2d_LL(root->next);

    // Merge current column with flattened next column
    root = mergeTwoLists(root, root->next);

    return root;
}
// 1d trasversal in bottom
void trasverseLl1d(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << "->";
        temp = temp->bottom;
    }
    cout << "NULL";
}
int main()
{
    while (true)
    {
        Node *head = takeInput2DLinkedList();
        head = flatten_2d_LL(head);
        trasverseLl1d(head);
    }
    return 0;
}