#include <iostream>
#include <memory>
using namespace std;

struct linkList {
    int val;
    shared_ptr<linkList> last, next;
};

shared_ptr<linkList> createNew( int n=INT32_MIN ) {
    shared_ptr<linkList> t( new linkList{n,NULL,NULL} );
    return t;
}

void printLinkList( shared_ptr<linkList> ptr ) {
    if ( ptr != NULL ) {
        cout<<ptr->val;
        if( ptr->next != NULL ) {
            cout<<' ';
            printLinkList(ptr->next);
        }
        else cout<<'\n';
    }    
}

void swapPtr( shared_ptr<linkList> a, shared_ptr<linkList> b ) {
    a->last->next=b;
    if( b->next != NULL ) b->next->last=a;
    b->last=a->last;
    a->last=b;
    a->next=b->next;
    b->next=a;
}

void bubbleSort( shared_ptr<linkList> ptr, int num) {
    for( int i=0 ; i < num ; i++ ) {
        shared_ptr<linkList> cur=ptr->next;
        while ( cur->next != NULL ) {
            if( cur->val > cur->next->val ) swapPtr(cur,cur->next);
            else cur=cur->next;
        }
    }
}

int main()
{
    int n, num=0;
    shared_ptr<linkList> start=createNew(), cur=start;
    while (cin>>n) {
        shared_ptr<linkList> t=createNew(n);
        cur->next=t, t->last=cur, cur=t;
        num++;
    }
    bubbleSort(start,num);
    printLinkList(start->next);
}