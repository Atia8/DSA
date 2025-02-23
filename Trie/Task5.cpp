#include<iostream>
#include<vector>
using namespace std;


struct node
{
  node* links[26]={nullptr};
  bool endmark=false;
};

class trie
{
  public:
  void insert(node*root,string s)
  {
    node*curr=root;
    for(int i=0;s[i]!=0;i++)
    {
      int idx=s[i]-'a';
      if(curr->links[idx]==nullptr)
      {
        curr->links[idx]=new node();
      }
      curr=curr->links[idx];
    }
    curr->endmark=true;
  }

  node* search(node*root,string s)
  {
    node*curr=root;
    for(int i=0;s[i]!=0;i++)
    {
      int idx=s[i]-'a';
      if(curr->links[idx]==nullptr)
      return nullptr;
      curr=curr->links[idx];
    }
    return curr;
  }

  bool wordbreak(string s,node*root)
  {
    int j;
     node*curr=root;
     vector<bool>v(s.size(),false);
     for(int i=0;s[i]!=0;i++)
     {
        
       if(i==0||v[i-1]==true)
       {
        

        curr=root;
        for( j=i;s[j]!=0;j++)
        {

          string k="";
          k=k+s[j];
          curr=search(curr,k);
          if(curr==nullptr)
    return v[s.size()-1];
         
          if(curr->endmark==true)
          v[j]=true;
        }
  
       }
      
        
        
     }
    return v[s.size()-1];
  }

};

int main()
{
  string s,k;
  node*root=new node();
  trie t;
  while(1)
  {
    cin>>s;
    if(s=="-1")
    break;
    t.insert(root,s);
  }
  cin>>k;
  bool y;
  y=t.wordbreak(k,root);
  if(y==true)
  cout<<"TRUE\n";
  else  
  cout<<"FALSE\n";
}