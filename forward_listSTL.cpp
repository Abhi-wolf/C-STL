#include <iostream>
#include <forward_list>
#include <cmath>
using namespace std;

bool single_digit(int x)
    {   
        if(x<10)
            return true;
        else
            return false;
    }

class is_odd_class
{
public:
  bool operator() (const int& value) 
  {
    return (value%2)==1;
  }
} is_odd_object;


// a binary predicate implemented as a function:
bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

// a binary predicate implemented as a class:
class is_near_class
{
public:
  bool operator() (double first, double second)
  { return (fabs(first-second)<5.0); }
} is_near_object;



int main()
{
    forward_list<int>fl1 ={20,40,50,30};
    fl1.insert_after(fl1.begin(),11);

    // insert_after() -> inserts new elements after the element at position
    // before_begin() -> returns an iterator pointing to the position before the first element in the container.
    fl1.insert_after(fl1.before_begin(),2);

    cout<<"\nfl1 : ";
    for(auto i:fl1)
        cout<<i<<"  ";
    cout<<endl;

    // OR
/*  cout<<"\nfl1 : ";
    for(auto it=fl1.begin();it!=fl1.end();it++)
        cout<<*it<<"  ";
    cout<<endl; */

    if(!fl1.empty())
        cout<<"fl1 is not empty\n";
    else
        cout<<"fl1 is empty\n";

    cout<<"Maximum size of fl1 can be "<<fl1.max_size()<<endl;

    cout<<"Front element is "<<fl1.front()<<endl;

    fl1.assign(4,10);

    forward_list<int>fl2;
    fl2.assign(fl1.begin(),fl1.end());

    cout<<"\nfl1 : ";
    for(auto i:fl1)
        cout<<i<<"  ";
    cout<<endl;

    cout<<"fl2 : ";
    for(auto i:fl2)
        cout<<i<<"  ";
    cout<<endl;
    
    // emplace_front() -> Inserts a new element at the beginning of the forward_list, right before its current first element
    fl2.emplace_front(11);

    // push_front() -> Inserts a new element at the beginning of the forward_list, right before its current first element
    fl2.push_front(15);

    // 
    cout<<"\nfl2 : ";
    for(auto i:fl2)
        cout<<i<<"  ";
    cout<<endl;

    // emplace_after() -> inserts a new element after the element at poisition c
    auto c = fl2.begin();
    fl2.emplace_after(c,105);

    cout<<"fl2 : ";
    for(auto i:fl2)
        cout<<i<<"  ";
    cout<<endl;

    // pop_front() -> removes first element form forward_list
    fl2.pop_front();

    cout<<"fl2 : ";
    for(auto i:fl2)
        cout<<i<<"  ";
    cout<<endl;

    auto q=fl2.begin();
    // erase_after() -> Removes from the forward_list container either a single element (the one after position) or a range of elements ((position,last)
    fl2.erase_after(q);
    fl2.erase_after(q,fl2.end());
    cout<<"fl2 : ";
    for(auto i:fl2)
        cout<<i<<"  ";
    cout<<endl;

    
    fl1.swap(fl2);
    cout<<"After swapping\n";
    cout<<"fl1 : ";
    for(auto i:fl1)
        cout<<i<<"  ";
    cout<<endl;

    cout<<"fl2 : ";
    for(auto i:fl2)
        cout<<i<<"  ";
    cout<<endl;

    // clear() ->  Removes all elements from the forward_list container (which are destroyed), and leaving the container with a size of 0.
    fl1.clear();
    if(!fl1.empty())
        cout<<"fl1 is not empty\n";
    else
        cout<<"fl1 is empty\n";


    forward_list<int>fl3 ={10,20,30,40,50};
    fl3.resize(3);
    fl3.resize(5,100);
    fl3.resize(8,1);

    cout<<"fl3 : ";
    for(auto i:fl3)
        cout<<i<<"  ";
    cout<<endl;

    // remove() -> removes from the container all the elements that compare equal to val.
    fl3.remove(100);
    cout<<"fl3 : ";
    for(auto i:fl3)
        cout<<i<<"  ";
    cout<<endl;

    // remove_if() -> removes from the container all the elements for which Predicate pred returns true    
    fl3.remove_if(single_digit);
    cout<<"fl3 : ";
    for(auto i:fl3)
        cout<<i<<"  ";
    cout<<endl;

    fl3.push_front(11);
    fl3.push_front(12);

    fl3.remove_if(is_odd_object);
    cout<<"fl3 : ";
    for(auto i:fl3)
        cout<<i<<"  ";
    cout<<endl;

    // unique() -> removes all but the first element from every consecutive group of equal elements in the container
    // an element is only removed from the forward_list container if it compares equal to the element immediately preceding it.
    //   Thus,this function is especially useful for sorted lists.
    forward_list<double> mylist = { 15.2, 73.0, 3.14, 15.85, 69.5,73.0, 3.99, 15.2, 69.2,  18.5 };

    cout << "mylist contains :";
    for (double& x: mylist) 
        cout <<"  " << x;
    cout << '\n';

    mylist.sort();                       // 3.14,  3.99, 15.2, 15.2, 15.85, 18.5,  69.2,  69.5, 73.0, 73.0

    mylist.unique();                     //  3.14,  3.99, 15.2, 15.85, 18.5,  69.2,  69.5, 73.0

    mylist.unique (same_integral_part);  //  3.14, 15.2, 18.5,  69.2, 73.0

    mylist.unique (is_near_object);      //  3.14, 15.2, 69.2

    cout << "mylist contains :";
    for (double& x: mylist) 
        cout <<"  "<< x;
    cout << '\n';



    forward_list<double> first = {4.2, 2.9, 3.1};
    forward_list<double> second = {1.4, 7.7, 3.1};
    forward_list<double> third = {6.2, 3.7, 7.1};

    // sort() -> Sorts the elements in the forward_list, altering their position within the container
    first.sort();
    second.sort();
    
    // merge() -> Merges x into the forward_list by transferring all of its elements at their respective ordered positions 
    //   into the container (both containers shall already be ordered).
    first.merge(second);

    cout<<"\nfirst contains :";
    for (double& x: first) 
        cout << "  " << x;
    cout<<endl;

    first.sort (greater<double>());
    third.sort (greater<double>());
    first.merge (third,greater<double>());

    cout << "first contains :";
    for (double& x: first) 
        cout << "  " << x;
    cout << endl;

    // reverse() -> Reverses the order of the elements in the forward_list container.
    first.reverse();

    cout<<"first contains : ";
    for(auto q:first)
        cout<<" "<<q;
    cout<<endl;



    

    



    










    return 0;
}