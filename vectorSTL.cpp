#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    // Vectors are sequence containers representing arrays that can change in size.
    //vectors use a dynamically allocated array to store their elements
    vector<int>vec1;

    // push_back(x) -> Adds a new element at the end of the vector, after its current last element
    vec1.push_back(10);
    vec1.push_back(20);
    vec1.push_back(30);

    // size() -> Returns the number of elements currently in vector
    cout<<"Size "<<vec1.size()<<endl;

    // capacity() -> Returns the size of the storage space currently allocated for the vector
    cout<<"Capacity "<<vec1.capacity()<<endl;

    //max_size() -> returns the maximum number of elements that the vector can hold
    cout<<"Maximum size "<<vec1.max_size()<<endl;

    cout<<"Is empty "<<vec1.empty()<<endl;

    // pop_back() -> Removes the last element in the vector, effectively reducing the container size by one.
    vec1.pop_back();
    vec1.pop_back();
    vec1.pop_back();

    // empty() -> Returns whether the vector is empty (i.e. whether its size is 0).
    cout<<"Is vec 1 empty "<<vec1.empty()<<endl;




    vector<int>vec2;
    for(int i=1;i<10;i++)
        vec2.push_back(i);
    
    // resizes the container so that it contains n elements
    // if n is smaller than the current container size,the content is reduced to the first n elements,removing those beyond.
    // if n is greater than the current size the content is expanded by inserting at the end as many elements needed to reach the size of n.
    vec2.resize(5);
    vec2.resize(10,200);
    vec2.resize(14,1);

    for(auto i:vec2)
        cout<<i<<" ";
    cout<<endl;



    // reserve -> requests that the vector capacity be at least enough to contain n elements.
    // if n is greater than the current vector capacity, the function causes the container to reallocate its storage increasing its capacity to n(or greater).
    vector<int>vec3;
    int sz=vec3.capacity();
    cout<<"Making vec2 grow\n";
    for(int j=0;j<100;j++)
    {
        vec3.push_back(j);
        if(sz!=vec3.capacity())
        {
            sz=vec3.capacity();
            cout<<"capacity changed: "<<sz<<endl;

        }
    }

    vector<int>vec4;
    sz=vec4.capacity();
    vec4.reserve(100);
    cout<<"\n\nMaking vec4 grow\n";  // this is the only differnece with vec3 above
    for(int i=0;i<410;i++)
    {
        vec4.push_back(i);
        if(sz!=vec4.capacity())
        {
            sz=vec4.capacity();
            cout<<"capacity changed: "<<sz<<endl;
        }
    }



    vector<int>vec5;
    for(int i=1;i<11;++i)
        vec5.push_back(i);
    
    for(auto i:vec5)
        cout<<i<<" ";
    cout<<endl;
    
    // erase() -> removes the first element
    vec5.erase(vec5.begin()+4);

    for(auto i:vec5)
        cout<<i<<" ";
    cout<<endl;

    // removes the first 5 elements
    vec5.erase(vec5.begin(),vec5.begin()+5);

    for(auto i:vec5)
        cout<<i<<" ";
    cout<<endl;


    vector<int>vec6(100);
    for(auto i:vec6)
        cout<<i<<" ";
    cout<<"\ncapacity : "<<vec6.capacity()<<endl;

    vec6.resize(10);
    for(auto i:vec6)
        cout<<i<<" ";
    cout<<endl;
    cout<<"capacity : "<<vec6.capacity()<<endl;



    // shrink_to_fit() -> requests the continer to reduce its capacity to fit its size.
    vec6.shrink_to_fit();
    for(auto i:vec6)
        cout<<i<<" ";
    cout<<endl;
    cout<<"capacity : "<<vec6.capacity()<<endl;



    //at(k) -> enters at kth index;
    for(int i=0;i<10;i++)
        vec6.at(i)=i;

    vec6.at(5) = 100;
    
    for(auto j:vec6)
        cout<<j<<" ";
    cout<<endl;



    // front() -> to access first element
    cout<<"First element is "<<vec6.front()<<endl;

    // back() -> to access last element
    cout<<"Last element is "<<vec6.back()<<endl;



    //insert(k) -> inserts 3 at front 
    auto it=vec6.insert(vec6.begin(),3);
    // inserts 200 at front
    vec6.insert(it,200);

    int i=2;
    // inserts 300 at ith index
    it=vec6.insert(vec6.begin()+i,300);

    it=vec6.insert(vec6.end(),900);

    for(auto i:vec6)
        cout<<i<<" ";
    cout<<endl;
    cout<<"capacity : "<<vec6.capacity()<<endl;

    // inserting multiple elements at specific positions
    int x=-5;
    vec6.insert(vec6.begin()+2,{0,-1,x,-2});

    for(auto i:vec6)
        cout<<i<<" ";
    cout<<endl;
    cout<<"capacity : "<<vec6.capacity()<<endl;

    // insert 0 one times at front
    auto itt=vec6.insert(vec6.begin(),1,0);
    // insert 1000 two times at front
    vec6.insert(itt,2,1000);
    for(auto i:vec6)
        cout<<i<<" ";
    cout<<endl;
    cout<<"capacity : "<<vec6.capacity()<<endl;

    vector<int>vec7;
    // inserts at the beginning of vec7
    vec7.insert(vec7.begin(),vec6.begin(),vec6.end());
    for(auto i:vec7)
        cout<<i<<" ";
    cout<<endl;
    cout<<"capacity : "<<vec6.capacity()<<endl;



    vec1.push_back(10);
    vec1.push_back(20);
    vec1.push_back(30);

    // swap() -> exchanges the content of one vector with another
    vec1.swap(vec7);
    for(auto i:vec1)
        cout<<i<<" ";
    cout<<endl;
    cout<<"capacity of vec1 : "<<vec1.capacity()<<endl;

    for(auto i:vec7)
        cout<<i<<" ";
    cout<<endl;
    cout<<"capacity of vec7 : "<<vec7.capacity()<<endl;



    // emplace() -> inserts new element at poisition
    // emplace() is faster than insert()
    auto a=vec7.emplace(vec7.begin()+1,70);
    vec7.emplace(a,200);
    vec7.emplace(vec7.end(),300);
    for(auto i:vec7)
        cout<<i<<" ";
    cout<<endl;
    cout<<"capacity of vec7 : "<<vec7.capacity()<<endl; 



    //emplace_back() -> inserts a new element at the end of the vector
    vec7.emplace_back(800);
    vec7.emplace_back(700);

    for(auto x:vec7)
        cout<<x<<" ";
    cout<<endl;

    sort(vec7.begin(),vec7.end());
    for(auto x:vec7)
        cout<<x<<" ";
    cout<<endl;
    // lower_bound() -> An iterator pointing to the first element not less than val, or end() if every element is less than val.
    auto c=lower_bound(vec7.begin(),vec7.end(),31);
    cout<<"Lower bound of 31 is "<<*c<<endl;


    // upper_bound() -> returns iterator pointing to next element or vec7.end() if element is not present 
    c=upper_bound(vec7.begin(),vec7.end(),200);
    cout<<"Upper bound of 200 is "<<*c<<endl;




    
    
    



    
    


    
    
    return 0;
}