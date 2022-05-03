#include <bits/stdc++.h>
using namespace std;



int main()
{

	array<int,10>a;   // size of array is compulsory to give

	a.fill(5);  //fill all the index with 5;

	for(int i=0;i<10;i++)
		cout<<a.at(i)<<" ";     //fill at index i OR for accessing element at ith index


    array<int,10>b;

    for(int i=0;i<10;i++)
    	b.at(i)=i+1;
	
	cout<<endl;

	// prints from first to last
	// begin -> return iterator to beginning (points to first element)
	// end -> return iterator pointing to the element after last element (points to right of last element)
    for(auto it=b.begin();it!=b.end();it++)   
		cout<<*it<<" ";						  
	cout<<endl;

	// prints from last to first
	//rebegin -> return reverse iterator to reverse beginning (points to last element)
	// rend -> return reverse iterator to reverse end (points to right before the first element )
	for(auto i=b.rbegin();i!=b.rend();++i)    
		cout<<*i<<" ";						  
	cout<<endl;

	// prints form last to first
	for(auto i=b.end()-1;i!=b.begin()-1;i--)
		cout<<*i<<" ";
	cout<<endl;

	// prints form first to last
	for(auto i:b)
		cout<<i<<" ";
		
	// size() -> returns the number of elements in the array container 
	cout<<"\nSize of Array is "<<b.size()<<endl;

	// max_size() -> returns maximum number of elements that the array container can hold 
	cout<<"Maximum size of Array is "<<b.max_size()<<endl;

	// empty() -> returns bool value whether array is empty, i.e whether its size is 0
	array<int,0>c;
	cout<<"Is array empty "<<c.empty()<<endl;  // 1 means yes empty
	cout<<"Is array empty "<<b.empty()<<endl;  // 0 means not empty

	b.at(9)=100000;

	// front() -> return first element  back() -> return last element
	cout<<"Front element "<<b.front()<<endl;
	cout<<"Back element "<<b.back()<<endl;

	// data() -> get pointer to data
	cout<<b.data()<<" \n";

	a.swap(b);

	for(auto i:a)
		cout<<i<<" ";
	cout<<endl;

	for(auto i:b)
		cout<<i<<" ";
	cout<<endl;



	return 0;


































}