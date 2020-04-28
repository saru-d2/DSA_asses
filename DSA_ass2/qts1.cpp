#include<iostream>
//#include<stdio.h>
#include<deque>


using namespace std;
typedef long long int lint;

int main()
{
    lint q,x,y;
    cin>>q;
    //getchar();
    char ar;
    deque<int> stk;
   // stk.push_back(0);
    while(q--)
    {
      //  cout<<"ready"<<endl;
        cin>>ar;
        switch(ar)
        {
            case 'a':
                
                //cout<<<<endl;
                cin>>y;
                stk.push_back(y);
                break;
            case 't' :
                stk.pop_back();
                break;
            case 'e' :
                lint n = stk.size();
          //      cout<<"n= "<<n<<endl;
                n/=2;
               
                for(int i=0;i<n;i++)
                {
                    x = stk.front();
                    stk.pop_front();
                    stk.push_back(x);
                }
            
        }
    }

   // cout<<stk.size()<<endl;
    lint size = stk.size();
    for(lint i=0;i<size;i++)
    {
        cout<<stk.front()<<" ";
        stk.pop_front();
    }
    cout<<endl;

        
}