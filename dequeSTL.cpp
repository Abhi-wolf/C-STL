#include <iostream>
#include <deque>
using namespace std;

int main()
{   // deque (double-ended queue) -> Double-ended queues are sequence containers with dynamic sizes that can be expanded or contracted on both ends (either its front or its back).
    deque<int>dq1;

    // push_back() -> adds new element at the end of the deque continer
    // push_front() -> adds new element at the beginning of the deque continer,right before its current first element 
    dq1.push_back(10);
    dq1.push_front(30);
    dq1.push_back(40);
    dq1.push_back(50);
    dq1.push_front(20);

    cout<<"dq1 : ";

    // begin() -> returns an iterator pointing to the first element int the deque continer
    // end() -> returns an iterator pointing to the past-the-end element int the deque continer (points to box after last element,means right of last element)
    for(auto it=dq1.begin();it!=dq1.end();it++)
        cout<<*it<<"  ";
    cout<<endl;

    //   OR
/*  for(auto it:dq1)
       cout<<it<<"  ";   */

    // rbegin() -> returns an iterator pointing to the last element
    // rend() -> Returns a reverse iterator pointing to the theoretical element preceding the first element in the deque container
    cout<<"dq1 : ";
    for(auto itt=dq1.rbegin();itt!=dq1.rend();itt++)
        cout<<*itt<<"  ";
    cout<<"  (in reverse order)"<<endl;

    // size() -> returns number of element in deque
    cout<<"Size of dq1 is "<<dq1.size()<<endl;

    // max_size() -> returns maximum number of element deque can store
    cout<<"Maximum size of dq1 is "<<dq1.max_size()<<endl;

    // empty() -> test whether continer is empty
    if(dq1.empty())
        cout<<"dq1 is empty\n";
    else
        cout<<"dq1 is not empty\n";

    // pop_back() -> removes the last element 
    // pop_front() -> removes the first element
    dq1.pop_back();
    dq1.pop_front();

    cout<<"dq1 : ";
    for(auto i:dq1)
        cout<<i<<"  ";
    cout<<"  (after one pop_back and one pop_front)"<<endl;


    deque<int>dq2;
    for(int i=1;i<=10;i++) dq2.push_back(i);

    cout<<"dq2 : ";
    for(auto it=dq2.begin();it!=dq2.end();it++)
        cout<<*it<<"  ";
    cout<<"\tsize of dq2 is "<<dq2.size()<<endl;

    // resize() -> resizes the container so that it contains n elements
    // if n is smaller than the current container size, the content is reduced to its first n elements, removing those beyond (and destroying them)
    // If n is greater than the current container size, the content is expanded by inserting at the end as many elements as needed to reach a size of n.
    dq2.resize(5);
    dq2.resize(7,100);
    dq2.resize(11);

    cout<<"dq2 : ";
    for(auto it=dq2.begin();it!=dq2.end();it++)
        cout<<*it<<"  ";
    cout<<"\tsize of dq2 is "<<dq2.size()<<"   \t(after resize)"<<endl;

    //   OR 
/*
    for(int i=0;i<12;i++)
        cout<<dq2[i]<<" "; */  // operato[] -> Returns a reference to the element at position n in the deque container


    // Shrinks to the size
    // till which elements are
    // destroys the elements after 11
    dq2.shrink_to_fit();
    cout<<"size of dq2 is "<<dq2.size()<<endl;

    // front() -> returns a reference to the first element in the deque container
    // back() -> returns a reference to the last element in the container
    cout<<"Front element of dq2 is "<<dq2.front()<<endl;
    cout<<"Back element of dq2 is "<<dq2.back()<<endl;

    cout<<"dq1 : ";
    // at() -> returns a reference to the element at position n in the deque container
    for(int i=0;i<dq1.size();i++)
        cout<<dq1.at(i)<<"  ";
    cout<<endl;
    
    
    // assign() -> assigns new contents to the deque container, replacing its current contents, and modifying its size accordingly
    dq1.assign(7,100);

    cout<<"dq1 : ";
    for(int i=0;i<dq1.size();i++)
        cout<<dq1.at(i)<<"  ";
    cout<<endl;

    // insert() -> inserts new element before the element at the specified poisition (it does not replaces instead creates spaces in between)
    auto it=dq1.begin();
    dq1.insert(++it,3);
    dq1.insert(it+2,5);   //it is pointing to 100
    dq1.insert(it,2,1);

    cout<<(*it)<<endl;

    cout<<"dq1 : ";
    for(int i=0;i<dq1.size();i++)
        cout<<dq1.at(i)<<"  ";
    cout<<endl;


    // erase() -> removes from the deque container either a single element (position) or a range of elements ([first,last))
    dq1.erase(dq1.begin()+5);
    cout<<"dq1 : ";
    for(int i=0;i<dq1.size();i++)
        cout<<dq1.at(i)<<"  ";
    cout<<endl;


    dq1.erase(dq1.begin()+1,dq1.begin()+3);  //[ )  (first one include and second one excluded)
    cout<<"dq1 : ";
    for(int i=0;i<dq1.size();i++)
        cout<<dq1.at(i)<<"  ";
    cout<<endl;



    deque<int>dq3 (4,10);
    deque<int>dq4 (5,100);

    cout<<"Size of dq3 is "<<dq3.size()<<endl;
    cout<<"Size of dq4 is "<<dq4.size()<<endl;

    //swap() -> exchanges the content of one dq with another
    dq3.swap(dq4);

    cout<<"\nSize after swap\n";
    cout<<"Size of dq3 is "<<dq3.size()<<endl;
    cout<<"Size of dq4 is "<<dq4.size()<<endl;

    //clear() -> removes all elements from the deque, leaving the container with a size of 0.
    dq3.clear();
    cout<<"Size of dq3 (after clear) is "<<dq3.size()<<endl;

    cout<<"\ndq4 : ";
    for(int i=0;i<dq4.size();i++)
        cout<<dq4.at(i)<<"  ";
    cout<<endl;

    // emplace() -> the container is extended by inserting a new element at position
    auto d=dq4.emplace(dq4.begin()+1,20);
    dq4.emplace(d,40);
    dq4.emplace(dq4.end(),60);
    cout<<"dq4 : ";
    for(int i=0;i<dq4.size();i++)
        cout<<dq4.at(i)<<"  ";
    cout<<endl;

    // emplace_front() -> inserts a new element at the beginning of the deque, right before its current first element
    // emplace_back() -> inserts a new element at the end of the deque, right after its current last element
    dq4.emplace_front(111);
    dq4.emplace_back(222);
    cout<<"dq4 : ";
    for(int i=0;i<dq4.size();i++)
        cout<<dq4.at(i)<<"  ";
    cout<<endl;
    


    return 0;
}