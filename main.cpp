/**
 * Definition for singly-linked list. */
#include <vector>
#include <iostream>

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* modifiedList(std::vector<int>& nums, ListNode* head) {
        
        for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
            head = deleteNode(*it,head);
        }
        return head;
    }
    ListNode* deleteNode (int n, ListNode* head)
{
    ListNode* current;
    ListNode* temp;
    current = head;
    while (current !=nullptr)
    {
       //std::cout<< current->val << std::endl;
       if (current->val == n)
       {
           if (head == current) {
               head = current->next;
               /* remove current */
               current = current->next;
           }
           else{
               temp=head;
               while (temp->next!=current)
               {
                   temp=temp->next;
                   
               }
               temp->next=current->next;
               /* remove current */
               current = current->next;
               
               /* remove head */
               if (head->val ==n)
               {
                   head=current;
                   
               }
               
           }
       }
       else{
       if (current!=nullptr)
       current = current->next;
       }
    }
        
    
        
    
    
    
    /* verify */
    current =head;
    while (current !=nullptr)
    {
     std::cout<< current->val << " ";
     current = current->next;
    }
    std::cout << std::endl;
    return head;
    
}
};
//implement deleteNode(int n,ListNode* head)

ListNode* insertNode (int n, ListNode* head)
{
    ListNode* newNode = new ListNode(n);
    ListNode* current ;
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        current = head;
        while (current->next !=nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }
    
    /* verify */
    /*current =head;
    while (current !=nullptr)
    {
     std::cout<< current->val << " ";
     current = current->next;
    }
    std::cout << std::endl;*/
    return head;
    
}
int main(){
    Solution s;
    //case 1
    /*std::vector<int> nums={1,2,3};
    // create a linklist [1,2,3,4,5]
    ListNode* head=nullptr;
    head = insertNode(1,head);
    head = insertNode(2,head);
    head = insertNode(3,head);
    head = insertNode(4,head);
    head = insertNode(5,head);*/
    
    //case 2
    /*std::vector<int> nums={1};
    // create a linklist [1,2,1,2,1,2]
    ListNode* head=nullptr;
    head = insertNode(1,head);
    head = insertNode(2,head);
    head = insertNode(1,head);
    head = insertNode(2,head);
    head = insertNode(1,head);
    head = insertNode(2,head);*/
    //case 3
    /*std::vector<int> nums={9,2,5};
    // create a linklist [2,10,9]
    ListNode* head=nullptr;
    head = insertNode(2,head);
    head = insertNode(10,head);
    head = insertNode(9,head);*/
    //case 3
    std::vector<int> nums={4,9};
    // create a linklist [4,4,5,6]
    ListNode* head=nullptr;
    head = insertNode(4,head);
    head = insertNode(4,head);
    head = insertNode(5,head);
    head = insertNode(6,head);
    
    //head=deleteNode(1,head);
    s.modifiedList(nums,head);
    return 0;
    
    
}
