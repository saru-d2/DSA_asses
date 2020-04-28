#include<iostream>
#include<deque>
typedef long long int lint;
using namespace std;
struct node
{
    lint info;
    node *next;
    node *prev;
} *head, *tail, *np, *mid;

lint num = 0;

void traverse()
{
    if (num ==0)
    {
        return;
    }
    node *temp;
    temp= head;
    while(temp!= NULL)
    {
        cout<<temp->info<<" ";
        temp = temp-> next;
    }
    cout<<endl;
}

void push(lint n)
{
    num++;
    np = new node;
    if (num==1 )
    {
        head = np;
        tail = np;
        mid = NULL;
        head -> info = n;
        
    }
    else
    {
        //cout<<"hi "<<num<<endl;
        
        if (num==2)
        {
           // cout<<"cunt"<<endl;
            mid = head;
        }
        else if (num>2)
        {
            if ( num%2 == 0 )
            {
             //  cout<<"ass"<<endl;;
                mid = mid->next;
            }
        }
        tail ->next = np;
        np ->prev=tail;
        np -> info = n;
        tail = np;
    }
    
}

void pop()
{
    if (num==1)
    {
        num =0;
        tail = NULL;
        head = NULL;
        mid = NULL;
        return;
    }
    if(num==2){
        mid=head;
        np = new node;
        np = tail;
        tail = tail->prev;
        tail->next = NULL;
        num--;
        free(np);
        return;
    }
    np = new node;
    np = tail;
    tail = tail->prev;
    tail->next = NULL;
    num--;
    
    if (num%2==1)
    {
        mid = mid ->prev;
    }
    free(np);

void shuffle()
{
    if (num == 0||num==1)
        return;
    node *tempmid, *temphead, *temptail;
    temphead = head;
    temptail = tail;
    tempmid = mid;
    
    if (num == 2)
    {
        lint temp= head->info;
        head ->info = tail ->info;
        tail ->info= temp;
        return;
    }
    tail->next = head;
    head ->prev = tail;

    node *amid;
    amid = mid ->next;
    amid->prev = NULL;
    mid->next = NULL;

    tail = tempmid;
    head= amid;
    mid=temptail;
    if(num%2==1){
        mid=mid->prev;
    }
}

int main()
{
    lint t;
    cin>>t;
    while(t--)
    {
        char ch;
        cin>>ch;
        switch (ch)
        {
        case 'a':
            lint n;
            cin>>n;
            push(n);
            break;
        case 't' :
            pop();
            break;
        case 'e' :
            shuffle();
            break;
        }
      // traverse();
        //if (num != 0)
        //{
        //    cout <<"\t"<<num;
          // if(num>=2){
         //   cout<<"\t"<< head->info << "\t" <<mid->info << "\t"<< tail->info << "\t"<<endl;
           // }
        //else
        //cout<<"is empty bitch\n";
        
    
    }
    cout<<num<<endl;
    traverse();
}