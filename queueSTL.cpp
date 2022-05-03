#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // queue -> operates in a FIFO context (first-int-first-out)
    queue<int>que1;

    // push() -> inserts a new element at the end of the queue
    que1.push(10);
    que1.push(50);
    que1.push(20);
    que1.push(60);

    // emplace() -> adds a new insert at the end of the queue,after its current last element
    que1.emplace(100);

    //empty() -> returns whether the queue is empty (size is zero or not);
    while(!que1.empty())
    {
        cout<<que1.front()<<" ";        // front() -> returns a refernce to the first element
        que1.pop();                     // pop() -> removes element in the queue
    }
    cout<<endl;

    // back() -> returns reference to the last element in the queue
    cout<<"Last element of que1 is "<<que1.back()<<endl;

    // size() -> returns number of elements in the queue
    cout<<"\nSize of que1 is "<<que1.size()<<endl;

    queue<string>que2;
    que2.emplace("rock");
    que2.emplace("tree");
    cout<<"\nSize of que2 is "<<que2.size()<<endl;

    queue<string>que3;
    que3.emplace("rock");
    que3.emplace("tree");
    que3.emplace("river");
    cout<<"Size of que3 is "<<que3.size()<<endl;

    // swap() -> echange the contents of continers
    que3.swap(que2);
    cout<<"\nSize of que2 and que3 after swapping\n";
    cout<<"Size of que2 is "<<que2.size()<<endl;
    cout<<"Size of que3 is "<<que3.size()<<endl;

    while(!que2.empty())
    {
        cout<<que2.front()<<" ";
        que2.pop();
    }
    cout<<endl;





    return 0l;
}