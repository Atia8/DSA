#include<iostream>
#include<sstream>
#include<vector>
#include<ctype.h>
#include<unordered_map>
using namespace std;

struct node
{
  node*links[123]={nullptr};
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
       int idx=s[i];
       if(curr->links[idx]==nullptr)
       {
         curr->links[idx]=new node();
       }
       curr=curr->links[idx];
     }
     curr->endmark=true;
     //return root;
  }
  

//   vector<string> search(node*root,string s)
//   {
//     node*curr=root;
//     vector<string>result;
//     string word="";
//     //int level=0;
//     for(int i=0;s[i]!=0;i++)
//     {
//       int idx=s[i];
//       if(curr->links[idx]==nullptr)
//       {
//      // cout<<tolower(s[i]);
//       return result;
//       }
//       word+=s[i];
//       curr=curr->links[idx];
//       //str[level]=s[i];
//       //level++;
//     }
//     start(curr,word,result);
//     return result;
//   }

    void display(node*root,char str[],int level)
  {
     if(root->endmark==true)
     {
      str[level]='\0';
      cout<<str<<endl;
     }
     for(int i=0;i<123;i++)
     {
       if(root->links[i]!=nullptr)
       {
        str[level]=i;
        display(root->links[i],str,level+1);
       }
     }
      
  }






void start(node*root,string word,string findword,int count,unordered_map<string,char>&map)
{
  
   if(count>=findword.size()&&root->endmark==true)
   {
    //cout<<word<<" ";
     map[word]='T';
   }
 
   char find=findword[count];
   if(count>=findword.size())
   find='Z';

    for(int i=0;i<123;i++)
    {
    //    char find=findword[count];
    //    if(count>=findword.size())
    //    find='a';
       if((root->links[i]!=nullptr))
       {
        // if(count>=findword.size()&&)
         if((find==i)||(find<='Z'&&i>='a'))
         //||((count>=findword.size())&&(i>='a')))
         {
            
            //cout<<find<<" "<<i;
          //word+=i;
          word=word+char(i);
            //cout<<word<<" ";
            if(find==i)
          start(root->links[i],word,findword,count+1,map);
          else
          start(root->links[i],word,findword,count,map);

          word.pop_back();
         }
         else
         {
            //cout<<"rrrrr";
            return;
         }
       }
    }
    
}
};

int main()
{
  string s,word;
  trie t;
  node*root=new node();
  unordered_map<string,char>map;
  vector<string>v;
  while(1)
  {
    cin>>word;
    map[word]='F';
    if(word=="-1")
    break;
    t.insert(word,root);
    v.push_back(word);
  }
  cin.sync();
  string c;
  node*curr;

  cin>>c;
  string worrd="";
  t.start(root,worrd,c,0,map);
  for(auto i:v)
  {
    cout<<map[i]<<" ";
  }








//   string k="";
//   for(int i=0;c[i]!=0;i++)
//   {
 
//   int level=0,count=0;
//   char str[123];
//   k=k+c[i];
  
//   vector<string>result;
//   result=t.search(root,k);
//   if(result.empty())
//   cout<<"NULL"<<endl;
// else
// {
//     for(auto i:result)
//     {
//         cout<<i<<" ";
//     }
//     cout<<endl;
// }


//   if(curr!=nullptr)
//   {
//     //cout<<"hh";
//     vector<string>result;
//     string word="";
//  //   t.start(curr,str,level,count);
//     t.start(curr,word,result);
    
//   }
//   else
//   cout<<"Null";
//   cout<<endl;
  
}