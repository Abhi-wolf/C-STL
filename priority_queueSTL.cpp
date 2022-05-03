#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // priority_queue -> stores elements in descending order and follows queue properties
    priority_queue<int>pr1;

    // push() -> inserts new element
    pr1.push(20);
    pr1.push(10);
    pr1.push(40);
    pr1.push(30);

    // top() -> returns a const reference to the top element
    cout<<"\nTop element is "<<pr1.top()<<endl;

    // size() -> returns number of elements in the priority_queue
    cout<<"Size of pr1 is "<<pr1.size()<<endl;

    int sum=0;

    // empty() -> returns whether it is empty (whether its size is zero)
    while(!pr1.empty())
    {
        cout<<pr1.top()<<"  ";
        sum+=pr1.top();
        pr1.pop();          // pop() -> removes the element on the top of the priority_queue(largest number is removed )
    }
    cout<<endl;
    cout<<"Sum = "<<sum<<endl;
    cout<<"Size of pr1 after pop operation is "<<pr1.size()<<endl;

    priority_queue<string>pr2;
    
    // emplace() -> adds a new element
    pr2.emplace("cow");
    pr2.push("horse");
    pr2.push("goat");
    pr2.emplace("cat");

    cout<<"\n";
    while(!pr2.empty())
    {
        cout<<pr2.top()<<"  ";
        pr2.pop();
    }
    cout<<endl;

    priority_queue<string>pr3;

    pr3.push("India");
    pr3.push("US");

    
    cout<<"Size of pr2 is "<<pr2.size()<<endl;
    cout<<"Size of pr3 is "<<pr3.size()<<endl;

    // swap() -> exchanges the contents of one priority_queue with another priority queue
    // for swapping data type of both the priority_queues must be same
    pr3.swap(pr2);

    cout<<"\nSize of pr2 and pr3 after swap\n";
    cout<<"\nSize of pr2 is "<<pr2.size()<<endl;
    cout<<"Size of pr3 is "<<pr3.size()<<endl;


    
    return 0;
}