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
Node *add_2_numbers_optimal(Node *h1, Node *h2)
{
    Node *dummy = new Node(0);
    Node *temp = dummy;
    int carry = 0;
    while (h1 != nullptr || h2 != nullptr || carry != 0)
    {
        int n;
        if (h1 == nullptr && h2 != nullptr)
        {
            n = h2->data + carry;
            h2 = h2->next;
        }
        else if (h1 != nullptr && h2 == nullptr)
        {
            n = h1->data + carry;
            h2 = h2->next;
        }
        else if (h1 == nullptr && h2 == nullptr)
        {
            n = carry;
        }
        else
        {
            n = h1->data + h2->data + carry;
            h1 = h1->next;
            h2 = h2->next;
        }
        int x = n % 10;
        Node *nn = new Node(x);
        carry = n / 10;
        temp->next = nn;
        temp = nn;
    }
    return dummy->next;
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
        Node *head = add_2_numbers_optimal(head1, head2);
        trasverseLl(head);
    }
    return 0;
}