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
Node *starting_point_of_cycle(Node *head)
{
    unordered_map<Node *, int> st;
    Node *temp = head;
    int i = 1;
    while (temp != nullptr)
    {
        if (st.count(temp))
        {
            cout << "Yes" << endl;
            cout << st[temp] << endl;
            return temp;
        }
        st[temp] = i;
        i++;
        temp = temp->next;
    }
    cout << "No" << endl;
    return nullptr;
};
Node *starting_point_of_cycle_optimal(Node *head)
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
            fast = head;
            int i = 1;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
                i++;
            }
            cout << i << " ";
            return fast;
        }
    }
    cout << "No Cycle present" << endl; // No cycle
    return nullptr;
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
    Node *ans = starting_point_of_cycle_optimal(head);
    if (ans != nullptr)
    {
        cout << ans->data;
    }
    return 0;
}