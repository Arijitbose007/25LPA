#include <iostream>
#include <vector>
using namespace std;
struct Node{
    int value;
    Node *next;
    Node(int x)
    {
        value = x;
        next = nullptr;
    }
    Node(int x , Node *next)
    {
        value = x;
        this->next = next;
    }
};

Node* Arr2LL(vector<int>& arr)
{
  Node* head = new Node(arr[0]);
  Node* temp = head;
  for(int i = 1 ; i < arr.size() ; i++)
    { temp->next = new Node(arr[i]); temp = temp->next;}
  return head;
}

Node* deleteLL(Node* head, int val)
  {
    if(head == NULL) return head;
    if(head->value == val)
    {
       Node* temp = head;
      head = head->next;
      delete(temp);
      return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL)
      {
        
        if(temp->value == val)
        {
          prev->next = prev->next->next;
          delete(temp);
          break;
        }
        prev = temp;
        temp = temp->next;
      }
    return head;
  }
Node* insertLL(Node* head,int k , int el)
{
  if(head == NULL) {
    if(k == 1) return new Node(el);
  }
  if(k==1) return new Node(el,head);
  int counter = 0;
  Node* temp = head;
  while(temp != NULL)
    {
      counter++;
      if(counter == k-1)
      {
        Node *Insert = new Node(el,temp->next);
        temp->next = Insert;
        break;
      }
      temp = temp->next;
    }
  return head;
}

int main()
{
    vector<int>arr = {2,5,9,7};
    Node* head = Arr2LL(arr);
   // Node* head1 = deleteLL(head , 2);
    Node* head2 = insertLL(head , 1 , 3);
    Node *current = head2; 
    while (current) {
    cout << current->value << " ";
    Node* nextNode = current->next;
    delete(current);
    current = nextNode; 
  }
  
  head2 = nullptr;
  return 0;

}

