#include <iostream>
#include <stack>
using namespace std;

int main()
{
    // stacks operate in LIFO conrext (last in first out) elements are inserted and extracted from one end 
    stack<int>st1;

    // push() -> inserts a new element at the top of the stack, above its current top element
    st1.push(10);
    st1.push(100);
    for(int i=0;i<10;i++)
        st1.push(i);

    st1.push(20);
    
    //empty() -> returns whether stack is empty
    while(!st1.empty())
    {
        cout<<st1.top()<<" ";    //top() -> returns a reference to the top element in the stack (last entered element)
        st1.pop();              // pop() -> remove the element on the top of the stack
    }
    cout<<endl<<st1.empty()<<endl;
    if(st1.empty())                 // returns true {1} if stack is empty else returns false {0}
        cout<<"Stack is  empty\n";
    else
        cout<<"Stack is not empty\n";

    // size() -> returns the number of elements in stack
    cout<<"Size of st1 is "<<st1.size()<<endl;

    // emplace() -> adds a new element at the top of the stack,above its current top element
    st1.emplace(10);
    st1.emplace(20);
    cout<<"Size of st1 is "<<st1.size()<<endl;
    int sum=0;
    while(!st1.empty())
    {
        sum+=st1.top();
        st1.pop();
    }
    cout<<"\nSum of element of st1 is "<<sum<<endl;

    stack<string>st2;
    st2.emplace("Abhijeet");
    st2.push("Kumar");
    st2.emplace("Singh");


    cout<<"\nSize of st2 is "<<st2.size()<<endl;

    stack<string>st3;
    st3.emplace("Raju");
    st3.emplace("Sohan");

    cout<<"Size of st3 is "<<st3.size()<<endl;

    // swap() -> echanges the content of the continer
    st2.swap(st3);
    cout<<"\nSize of st2 is "<<st2.size()<<endl;
    cout<<"Size of st3 is "<<st3.size()<<endl;


    
}