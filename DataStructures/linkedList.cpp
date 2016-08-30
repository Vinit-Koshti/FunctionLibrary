#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

int listSize(Node* head)
{
    int counter=0;
    while(head)
    {
        counter++;
        head = head->next;
    }
    return counter;
}

//just use for the first node
void initNode(struct Node* head, int n )
{
    head->data = n;
    head->next = NULL;
}

//insert node in the front of linkedList and return the new head
Node* insertFront(Node* head, int n)
{
    Node* newnode = new Node;
    newnode->data = n;
    newnode->next = head;
    head = newnode;
    return head;
}

//insert node at nth loction including last,
// node will not be added if location is greater than size of list.
void insert(Node* head, int location, int data)
{
    int size = listSize(head);
    if (location > size+1)
    {
        return;
    }
    else
    {
        Node* newnode = new Node;
        newnode->data = data;
        Node* prev = head;
        for (int i=1; i < location-1; i++ )
        {
            prev=prev->next;
        }

        if(prev->next == NULL)
        {
            prev->next = newnode;
            newnode->next = NULL;
        }
        else
        {
            newnode->next = prev->next;
            prev->next = newnode; 
        }
    }
}

//delete node at nth location including last
// node will not be deleted if location is greater than size of list.
void deleteNode(Node* head, int location)
{
    int size = listSize(head);
    if (location > size+1)
    {
        return;
    }
    else
    {
        Node* curr = head;
        Node* prev = head;

        for (int i=1; i < location-1; i++ )
            {
                prev=prev->next;
            }

        curr = prev->next;
        prev->next = curr->next;
    }

}
//search location of node on basis of data
int searchNode(Node* head, int data)
{
    int counter = 1;
    while(head)
    {
        if(head->data == data)
        {
            return counter;
        }
        head = head->next;
        counter++;
    }
    cout << endl << "Data not present in linkedList. "<<endl;
    return 0;
}

//reverse the linkedList and return the new head, that would be the last node
Node* reverse(Node* head)
{
    Node* prev = NULL;
    Node* curr = head;
    Node* Next = head;

    while(curr)
    {
        Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
    }
    head = prev;
    return head;
}

//reverse linkedlist using recurrsion
Node* storeHead;
void reverseRecurrse(Node* p)
{
    if (p->next == NULL) 
        {
            storeHead = p;
            return ;
        }
    
    reverseRecurrse(p->next);
    Node* q = p->next;
    q->next = p;
    p->next = NULL;
}

//used to print the entire linkedList
//head is local variable to this function, it won't change the head in main function
void displayList(struct Node* head)
{
    while(head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;

}

int main()
{
    Node* head = new Node;
    initNode(head,6);
    head = insertFront(head, 4);
    head = insertFront(head, 3);
    insert(head, 3, 5);
    insert(head, 5, 7);
    insert(head, 6, 9);
    insert(head, 6, 8);

    deleteNode(head, 4);
    deleteNode(head, 6);
    //cout<<searchNode(head, 5)<<endl;
    
    displayList(head); 
    cout << endl;
    reverseRecurrse(head);
    displayList(storeHead);
}