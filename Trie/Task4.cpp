#include<iostream>
#include<sstream>
#include<vector>
#include<ctype.h>
using namespace std;

struct node
{
  node*links[2]={nullptr};
};

class trie
{
  public:
  void insert(int num,node*root)
  {
     node*curr=root;
     for(int i=31;i>=0;i--)
     {
       int bit=(num>>i)&1;
       if(curr->links[bit]==nullptr)
       {
        curr->links[bit]=new node();
       }
       curr=curr->links[bit];
     }
  }
  
  int check(int num,node*root)
  {
    node*curr=root;
    int max=0;
    for(int i=31;i>=0;i--)
    {
      int bit=(num>>i)&1;
      int check=1-bit;
      if(curr->links[check]!=nullptr)
      {
      curr=curr->links[check];
      max=max|(check<<i);// Set the i-th bit of max to check
      }
      else
      {
      curr=curr->links[bit];
      max=max|(bit<<i);
      }
    }

    return max^num;
  }

  







  
};

int main()
{
  int x,y,maximum=0;
  trie t;
  node*root=new node();
  vector<int>v;
  while(1)
  {
    cin>>x;
    if(x==-1)
    break;
    t.insert(x,root);
    v.push_back(x);
  }

  for(int i=0;i<v.size();i++)
  {
    y=t.check(v[i],root);
    //cout<<y;
    maximum=max(maximum,y);
  }
  cout<<maximum;
  
}