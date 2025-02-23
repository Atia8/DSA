#include<iostream>
#include<sstream>
using namespace std;

struct node
{
  node*links[26]={nullptr};
  bool endmark=false;

};

class trie
{
  public:
  void insert(string s,node*root)
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
     //return root;
  }
  
  bool search(node*root,string s)
  {
    node*curr=root;
    for(int i=0;s[i]!=0;i++)
    {
      int idx=s[i]-'a';
      if(curr->links[idx]==nullptr)
      return false;
      curr=curr->links[idx];
    }
    return (curr->endmark==true);
  }

  void display(node*root,char str[],int level)
  {
     if(root->endmark==true)
     {
      str[level]='\0';
      cout<<str<<endl;
     }
     for(int i=0;i<26;i++)
     {
       if(root->links[i]!=nullptr)
       {
        str[level]=i+'a';
        display(root->links[i],str,level+1);
       }
     }
      
  }
};

int main()
{
  string s,word,y;
  getline(cin,s);
  cin.ignore();
  stringstream ss(s);
  trie t;
  node*root=new node();
  while(ss>>word)
  {
    t.insert(word,root);
  }
  int level=0;
  char str[26];
  t.display(root,str,level);

  getline(cin,y);
  stringstream sw(y);
  while(sw>>word)
  {
   if(t.search(root,word)==true)
   cout<<"T ";
   else
   cout<<"F ";
  }

}