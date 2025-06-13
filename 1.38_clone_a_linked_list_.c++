#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *random;

    Node(int data1)
    {
        data = data1;
        next = nullptr;
        random = nullptr;
    }
};

// Clone function using hash map
Node *clone_the_LL(Node *head)
{
    if (!head)
        return nullptr;

    unordered_map<Node *, Node *> hashmap;

    Node *temp = head;
    while (temp)
    {
        hashmap[temp] = new Node(temp->data);
        temp = temp->next;
    }

    temp = head;
    while (temp)
    {
        hashmap[temp]->next = hashmap[temp->next];
        hashmap[temp]->random = hashmap[temp->random];
        temp = temp->next;
    }

    return hashmap[head];
}
// optimal approach
Node *clone_a_LL_optimal(Node *head)
{
    if (!head)
        return nullptr;
    Node *temp = head;
    Node *front = head;
    while (front)
    {
        front = temp->next;
        Node *Copy = new Node(temp->data);
        temp->next = Copy;
        Copy->next = front;
        temp = front;
    }
    temp = head;
    while (temp)
    {
        if (temp->random)
        {
            temp->next->random = temp->random->next;
        }
        temp = temp->next->next;
    }
    temp = head;
    Node *newhead = head->next;
    Node *dummy = newhead;
    while (dummy->next)
    {
        temp->next = dummy->next;
        temp = temp->next;
        dummy->next = temp->next;
        dummy = dummy->next;
    }
    return newhead;
}
// Function to print list with random pointers
void printList(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << "Node: " << temp->data;
        if (temp->random)
            cout << ", Random: " << temp->random->data;
        else
            cout << ", Random: NULL";
        cout << endl;
        temp = temp->next;
    }
}

int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<Node *> nodeList(n);
    cout << "Enter node values: ";
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        nodeList[i] = new Node(val);
        if (i > 0)
            nodeList[i - 1]->next = nodeList[i];
    }

    Node *head = nodeList[0];

    cout << "Enter random pointer indices (-1 for NULL):\n";
    for (int i = 0; i < n; i++)
    {
        int idx;
        cin >> idx;
        if (idx >= 0)
            nodeList[i]->random = nodeList[idx];
        else
            nodeList[i]->random = nullptr;
    }

    cout << "\nOriginal Linked List:\n";
    printList(head);

    Node *clonedHead = clone_a_LL_optimal(head);

    cout << "\nCloned Linked List:\n";
    printList(clonedHead);

    return 0;
}
