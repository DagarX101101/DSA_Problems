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
void detect_a_cycle(Node *head)
{
    unordered_set<Node *> st;
    Node *temp = head;
    while (temp != nullptr)
    {
        if (st.count(temp))
        {
            cout << "Yes" << endl;
            return;
        }
        st.insert(temp);
        temp = temp->next;
    }
    cout << "No" << endl;
    return;
};
void detect_a_cycle_optimal(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            cout << "Yes"; // Cycle detected
            return;
        }
    }

    cout << "No"; // No cycle
    return;
};

int main()
{
    int n1;
    cin >> n1;
    vector<int> vec(n1);
    for (auto &it : vec)
    {
        cin >> it;
    }
    Node *head = ConvertarraytoLL(vec);
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    // temp->next = head->next->next;
    detect_a_cycle_optimal(head);

    return 0;
}