#include <iostream>
#include <vector>
using namespace std;

struct Node{
  int val;
  Node *next;
  Node *prev;
  Node() : val(0), next(nullptr) , prev(nullptr) {}
  Node(int x) : val(x), next(nullptr) , prev(nullptr) {}
  Node(int x, Node *next, Node *prev) : val(x), next(next), prev(prev) {}
};

Node *convert2DLL(vector<int>&arr)
{
  Node *head = new Node(arr[0]);
  Node *temp = head;
  for(int i = 1 ; i < arr.size() ; i++)
    {
      Node *newNode = new Node(arr[i]);
      temp->next = newNode;
      newNode->prev = temp;
      temp = temp->next;
    }
  return head;
}

Node *deleteHead(Node *head , int value)
{
  Node *temp = head;

  while(temp != NULL)
    {
        if(temp->val == value)
        {
          if(temp->prev == NULL) // temp is the head
          {
            head = head->next;
            if(head != NULL) // if list has more than one node
                head->prev = NULL;
            delete(temp);
            break;
          }
          else if(temp->next == NULL) // temp is the tail
          {
            temp->prev->next = NULL;
            delete(temp);
            break;
          }
          else // temp is in the middle
          {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete(temp);
            break;
          }
        }
      temp = temp->next;
    }
  return head;
}

Node *insertHead(Node *head, int val ,int k)
{  
  int count = 0;
  if(head == NULL)
    return new Node(val); 
  Node *temp = head;
  while(temp->next != NULL)
  {  
    if(count == k)
    {
      Node *newNode = new Node(val);
      newNode->next = temp;
      newNode->prev = temp->prev;
      if(temp->prev != NULL) 
          temp->prev->next = newNode;
      temp->prev = newNode;
      return head;
    }
    count++;
    temp = temp->next;
  }
  Node *newNode = new Node(val);
  newNode->prev = temp;
  temp->next = newNode;
  newNode->next = NULL;

  return head;
}
void print(Node *head)
{
  Node *temp = head;
  while(temp)
    {
      cout<<temp->val<<" ";
      temp = temp->next;
    }
}
int main() {
  vector<int>arr = {11,23,4,56,7};
  Node *head = convert2DLL(arr);
 // Node *inserthead = insertHead(head , 9 , 6);
  Node *deletehead = deleteHead(head , 4);
  print(deletehead);
}