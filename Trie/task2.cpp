#include<iostream>
#include<sstream>
#include<vector>
#include<ctype.h>
using namespace std;

struct node
{
  node*links[26]={nullptr};
  bool endmark=false;
  int countword=0;
  int countprefix=0;
};

class trie
{
  public:

 void erase(string s,node*root)     
 {
   node*curr=root;
   for(int i=0;s[i]!=0;i++)
   {
     int idx=tolower(s[i])-'a';
     /*
     here we don't check whether links in that index is present or not
     because here we only call this function when duplicates r present
     which confirms links on that index is not null.
     */
     curr=curr->links[idx];
     curr->countprefix--;
   }
   curr->countword--;
 }


  void insert(string s,node*root)
  {
     node*curr=root;
    /*
    here we use tolower due to the question statement.
    tolower only works for character not for string.
    so we use tolower while inserting each character
    */
     for(int i=0;s[i]!=0;i++)
     {
       int idx=tolower(s[i])-'a';
       if(curr->links[idx]==nullptr)
       {
         curr->links[idx]=new node();
       }
       curr=curr->links[idx];
       curr->countprefix++;
     }
     curr->countword++;

    /* to avoid duplicate words..we check countword. if countword>1 implies
    there are duplicate words. so we erase them by calling erase 
    function.
    */

     if(curr->countword>1)
     {
      erase(s,root);
     }
    
  }
  

 int startwith(node*root,string s)
 {
   node*curr=root;
   for(int i=0;s[i]!=0;i++)
   {
     int idx=tolower(s[i])-'a';
     if(curr->links[idx]==nullptr)
     {
      return 0;
     }
     else
     {
       curr=curr->links[idx];
     }
   }
   return curr->countprefix;
 }
};

int main()
{
  string s;
  int w,y;
  cin>>w>>y;
  trie t;
  node*root=new node();
  while(w--)
  {
    cin>>s;
    t.insert(s,root);
  }
  string c;
  node*curr;
  while(y--)
  {
  cin>>c;
  cout<<t.startwith(root,c)<<endl;

  }
}