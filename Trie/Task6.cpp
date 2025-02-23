#include<iostream>
#include<vector>
using namespace std;


struct node
{
  node* links[10]={nullptr};
  bool endmark=false;
};

class trie
{
  public:
  void insert(node*root,string s)
  {
    node*curr=root;
    //cout<<s;
    for(int i=0;s[i]!=0;i++)
    {
      int idx=s[i]-'0';
      if(curr->links[idx]==nullptr)
      {
        curr->links[idx]=new node();
      }
      curr=curr->links[idx];
    }
    curr->endmark=true;
    
  }

  int search(node*root,string s)
  {
    node*curr=root;
    int match=0;
    for(int i=0;s[i]!=0;i++)
    {
      int idx=s[i]-'0';
      if(curr->links[idx]==nullptr)
      return match;
      curr=curr->links[idx];
      match++;
    }
    return match;
  }

  
};

int main()
{
  int len1,len2,match,maxmatch=0;
  cin>>len1>>len2;
  trie t;
  node*root=new node();
  int arr1[len1],arr2[len2];
  for(int i=0;i<len1;i++)
  {
    cin>>arr1[i];
    //cin.sync();
    string s=to_string(arr1[i]);
    //cout<<s;
    //cin.sync();
    t.insert(root,s);
    //cout<<"ssssss"<<endl;
  }
  
  for(int i=0;i<len2;i++)
  {
    cin>>arr2[i];
    string s=to_string(arr2[i]);
    //cin.sync();
    match=t.search(root,s);
    maxmatch=max(match,maxmatch);
  }
  cout<<maxmatch;
}