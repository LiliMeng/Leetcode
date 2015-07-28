#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct ListNode {
     int val;
     ListNode* next;
     ListNode(int x) : val(x), next(NULL){}  
  };
  
 class mycomparison
{
  
public:
  mycomparison()
    { }
  bool operator() (const ListNode *n1, const ListNode *n2) const
  {
    return n1->val > n2->val;
  }
}; 

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode *> &lists) 
    {
	//	priority_queue<ListNode*, vector<ListNode*>, std::greater<ListNode*>> pq;
	priority_queue<ListNode*, vector<ListNode*>, mycomparison > pq;
		
		ListNode* Head=NULL;
		ListNode* prev=NULL;
		
		for(auto ite=lists.begin();ite!=lists.end();ite++)
		{
			ListNode *t= *ite;
	        if(t!=NULL){
				pq.push(t);
				cout<<"head is "<<t->val<<endl;
			}
	    }
	    
	    while(!pq.empty())  //pq is not empty
	    {
			ListNode* current = pq.top();
			cout<<"current value "<<current->val<<endl;
			
		    if(Head==NULL)
		    {
				Head=current;
				prev=current;
				pq.pop();
				if(current->next!=NULL)
				{ 
					pq.push(current->next);
				}
			}
			else
			{
				pq.pop();
			
				if(current->next!=NULL)
				{ 
					pq.push(current->next);
				}
			
				prev->next=current;
				prev=current;
			}
		}
		
        return Head;
        
        
    }
};

int main()
{
	
		ListNode *n1 = new ListNode(1);
		ListNode *n2 = new ListNode(6);
		
		ListNode *n3 = new ListNode(2);
		ListNode *n4 = new ListNode(3);
		ListNode *n5 = new ListNode(4);
		
		ListNode *n6 = new ListNode(4);
		ListNode *n7 = new ListNode(5);
		
		n1->next=n2;
		n2->next=NULL;
		
		n3->next=n4;
		n4->next=n5;
		n5->next=NULL;
		
		n6->next=n7;
		n7->next=NULL;
		
		vector<ListNode *> v1;
		v1.push_back(n1);
		v1.push_back(n3);
		v1.push_back(n6);
		
		
	
		Solution s;
		ListNode* result=s.mergeKLists(v1);
		
		while(result)
		{
			cout<<result->val<<endl;
			result=result->next;
			}
		
	   
		return 0;
}
