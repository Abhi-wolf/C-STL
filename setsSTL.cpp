#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

int main()
{
    // Sets are containers that store unique elements in increasing order.sets are implemented as binary search trees.
    set<int>sets1; 
    for(int i=1;i<11;i++)
        sets1.insert(i*10);

    // begin() -> returns an iterator to the first element in the set
    // end() -> returns an iterator referring to the element after the last element (points to right of last element)
    cout<<"Set1   ";
    for(auto it=sets1.begin();it!=sets1.end();it++)
        cout<<*it<<" ";
    cout<<"\nSize of set1  "<<sets1.size()<<endl;

    auto a=sets1.insert(sets1.begin(),25);
    sets1.insert(a,26);
    sets1.insert(a,27);

    int myints[]={1,20,3,4,5,6,7,8};              // 20 is already in set,not inserted
    sets1.insert(myints,myints+3);   

    cout<<"Set1   ";
    for(auto a:sets1)
        cout<<a<<" ";
    // size() -> return continer size
    cout<<"\nSize of set1  "<<sets1.size()<<endl;

    // rbegin() -> return reverse iterator to reverse beginning
    // rend() -> return reverse iterator to reverse end()
    cout<<"Set1 in reverse order   ";
    for(auto a=sets1.rbegin();a!=sets1.rend();a++)
        cout<<*a<<" ";
    cout<<endl;

    // empty() -> test whether continer is empty, 0 means false 1 menas true
    cout<<"Is set1 empty  "<<sets1.empty()<<endl;
    cout<<"Max size of set  "<<sets1.max_size()<<endl;

    // erase() -> removes form the set continer either a single element or a range of elements
    // find() -> searches for the given element and returns an iterator if found,otherwise returns an iterator to set::end 
    sets1.erase(sets1.begin());
    auto q=sets1.find(50);
    sets1.erase(q);
    sets1.erase(sets1.find(100));

    sets1.erase(sets1.find(70),sets1.end());
    cout<<"Set1   ";
    for(auto i:sets1)
        cout<<i<<" ";
    cout<<endl;


    set<int>sets2(myints+3,myints+8);
    cout<<"Set2   ";
    for(auto a:sets2)
        cout<<a<<" ";
    cout<<endl;

    // swap() -> exchanges the content of one set with another set
    sets1.swap(sets2);
    cout<<"\nAfter swap\n";
    cout<<"Set1   ";
    for(auto a:sets1)
        cout<<a<<" ";
    cout<<endl;

    cout<<"Set2   ";
    for(auto a:sets2)
        cout<<a<<" ";
    cout<<endl;

    // count() -> returns the number of times that element is present in set
    cout<<"Count of 30 in set2 = "<<sets2.count(30)<<endl;
    cout<<"Count of 50 in set2 = "<<sets2.count(50)<<endl;

    // lower_bound() -> return an iterator pointing to that element or if element is not present than it gives an iterator that points to next large element 
    auto it=sets2.lower_bound(30);
    cout<<"Lower bound of 30 is "<<*it<<endl;
    it=sets2.lower_bound(21);
    cout<<"Lower bound of 21 is "<<*it<<endl;

    //upper_bound() -> returns an iterator pointing to the immediate next element which is just greater than k.if the key passed is greater than the maximum value than
    // the iterator returned points to next of last element (set.end())
    it=sets2.upper_bound(40);
    cout<<"Upper bound of 40 is "<<*it<<endl;
    it=sets2.upper_bound(3);
    cout<<"Upper bound of 3 is  "<<*it<<endl;


    set<string>sets3;
    //emplace() -> inserts new element in the set, if unoque
    sets3.emplace("Abhi");
    sets3.emplace("Anu");
    sets3.emplace("kriti");
    sets3.emplace("Ashana");

    // stores string also in alphabatical order
    cout<<"\nSETS3 \n";
    for(auto it:sets3)
        cout<<it<<"  ";
    cout<<endl;


    // emplace_hint() -> inserts a new element in the set. A position is passed in the parameter of the function which acts as a hint from where the searching operation starts before inserting the element at its current position. 
    // The position only helps the process to get faster, it does not decide where the new element is to be inserted. The new element is inserted following the property of the set container only.
    auto x=sets3.begin();
    sets3.emplace_hint(x,"AA");

    cout<<"\nSETS3 \n";
    for(auto it:sets3)
        cout<<it<<"  ";
    cout<<endl;

    // unordered_set -> store unique elements in no particular order, and which allow for fast retrieval of individual elements based on their value.(stores in random order)
    unordered_set<string>sets4;
    cout<<"\nUNORDERED SET\n";
    auto y=sets4.insert(sets4.begin(),"Rock");
    sets4.insert(y,"Tree");
    sets4.insert(y,"Mountain");

    for(auto y:sets4)
        cout<<y<<" ";
    cout<<"\nSize of sets4 is "<<sets4.size()<<endl;
    cout<<"Max size of sets4 is "<<sets4.max_size()<<endl;



    multiset<int>sets5;
    sets5.insert(10);
    sets5.insert(30);
    sets5.insert(40);
    sets5.insert(60);
    sets5.insert(30);

    cout<<"\nMultiset\n";
    for(auto i:sets5)
        cout<<i<<" ";
    cout<<endl;

    for(auto d=sets5.rbegin();d!=sets5.rend();d++)
        cout<<*d<<" ";
    cout<<endl;


    return 0;
}