#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>   // random variable
#include <numeric>     // accumulate(sum) function
#include <limits.h>     // INT_MIN -> specifies that an integer variable cannot store any value below this limit (-2147483648)
                        //INT_MAX is a macro that specifies that an integer variable cannot store any value beyond this limit (+2147483647)
using namespace std;

int main()
{
    int n=6,x;
    int arr[n];
    cout<<"Elements of array : ";
    for(int i=0;i<n;i++) {
        arr[i] = rand()%10;
        cout<<arr[i]<<" ";
    }
    
    // sort(startItrator,endItrator) -> sorts in increasing order
    sort(arr,arr+n);
    cout<<"\nArray in sorted order : ";
    for(int i=0;i<n;i++)  cout<<arr[i]<<" ";
    cout<<endl;

    vector<int>vec1;
    cout<<"Elements of vector : ";
    for(int i=0;i<n;i++){
        x=rand()%10;
        vec1.push_back(x);
        cout<<vec1[i]<<" ";
    }
    sort(vec1.begin(),vec1.end());

    cout<<"\nVector in sorted order : ";
    for(auto i:vec1)  cout<<i<<" ";
    cout<<endl;

    // to sort numbers in a range 
    sort(arr+1,arr+4);
    sort(vec1.begin()+1,vec1.begin()+4);    // sort indexex from 1 to 3      [ )

    // reverse(startIterator,endIterator)
    reverse(arr,arr+n);
    reverse(vec1.begin(),vec1.end());

    cout<<"Array in reverse order : ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    cout<<"Vector in reverse order : ";
    for(auto i:vec1)
        cout<<i<<" ";
    cout<<endl;

    // reverse in a range of index
    reverse(vec1.begin()+1,vec1.begin()+4);
    cout<<"Reverse vector form 1 to 4th index : ";
    for(auto i:vec1)
        cout<<i<<" ";
    cout<<endl;

    // *max_element(firstIterator,endIterator) -> to find maximim element
    cout<<"\nMaximum element in array : "<<*max_element(arr,arr+n)<<endl;
    cout<<"Maximum element in vector : "<<*max_element(vec1.begin(),vec1.end())<<endl;

/*    int maxi=INT_MIN;
    int i=1,j=4;
    for(int k=i;i<=j;k++){
        if(arr[k]>maxi)
            maxi=arr[k];
    } 
    cout<<maxi;     */

    // *mini_element(firstIterator,endIterator) -> to find minimim element
    cout<<"Minimum element in array : "<<*min_element(arr,arr+n)<<endl;
    cout<<"Minimum element in vector : "<<*min_element(vec1.begin(),vec1.end())<<endl;

    // accumulate(firstIterator,endIterator,initial_sum) -> returns sum
    cout<<"Sum of vector elements : "<<accumulate(vec1.begin(),vec1.end(),0)<<endl;
    cout<<"Sum of array elements from 1 to 3rd element : "<<accumulate(arr+1,arr+3,0)<<endl;
/*
    int sum=0;
    for(int k=i;k<j;k++){
        sum+=arr[k];
    } 
    cout<<sum;       */


    // count(startIterator,endIterator,valueto_count) -> find number of occurances of valueto_count
    cout<<"Count number of 9's in vector : "<<count(vec1.begin(),vec1.end(),9)<<endl;
    int z=count(arr,arr+n,2);
/*
    int count=0;
    for(auto i:vec1){
        if(i==x)
            count++;
    } 
    cout<<count;    */

    // find(startIterator,endIterator,k) -> returns iterator pointing to first occurance of k       O(N) complexity
    auto it = find(vec1.begin(),vec1.end(),2);
    if(it==vec1.end()){
        cout<<"Element is not present\n";
    }
    else{
        cout<<"2 is first present at : "<<(it-vec1.begin())<<endl;
    }


    //binary_search(startIterator,endIterator,k) -> returns true if k is present else returns false
    // works on sorted array,vector
    // works in logn complexity
    sort(vec1.begin(),vec1.end());
    cout<<"\nIs 2 present in vecctor : "<<binary_search(vec1.begin(),vec1.end(),2)<<endl;
    cout<<"Is 8 present in vecctor : "<<binary_search(vec1.begin(),vec1.end(),8)<<endl;


    // lower_bound(startIterator,endIterator,k) -> returns an iterator pointing to the first element
    //  which is not less than k
    // works in sorted array,vector ; logn complexity
    auto q=lower_bound(vec1.begin(),vec1.end(),6);
    cout<<"Lower bound of 6 is "<<*q<<endl;
    if(q==vec1.end())
        cout<<"Element is not present\n";
    else
        cout<<"6 is present at "<<(q-vec1.begin())<<" index"<<endl;


    // upper_bound(startIterator,endIterator,k) ->returns an iterator which points to element which is just greater than k
    // arr[] -> {1,5,7,7,8,10,10,10,11,11,12}
    // if k=7       prints 8
    // if k=6       prints 7
    // if k=12      points to end() iterator
    // if k=15      points to end() iterator

    int k,index;
    auto w = upper_bound(arr,arr+n,k);
    index = w-arr;

    auto v = upper_bound(vec1.begin(),vec1.end(),k);
    index = v-vec1.begin();





    // Q1. find the first index where the element x lies, array is sorted(wihout using find fun).
    cout<<endl;
    n=10;
    int arr1[n]={1,2,3,4,5,6,7,7,9,10};
    int f=9;

    //  1st Method
    if(binary_search(arr1,arr1+n,f)==true){
        cout<<f<<" found at index "<<(lower_bound(arr1,arr1+n,f)-arr1)<<endl;
    }
    else
        cout<<f<<" not found\n";


    // 2nd Method
    f=11;
    index = lower_bound(arr1,arr1+n,f)-arr1;
    if(index!=n  &&  arr1[index]==f){
        cout<<f<<" found at index "<<index<<endl;
    }
    else
        cout<<f<<" not found\n";



    
    // Q2. find the last occurance of x in an array (array is sorted)

    // 1st Method
    f=7;
    if(binary_search(arr1,arr1+n,f)==true){
        cout<<"Last occurance of "<<f<<" is at index "<<(upper_bound(arr1,arr1+n,f)-arr1-1)<<endl;
    }
    else
        cout<<f<<" not found\n";


    // 2nd Method
    index = upper_bound(arr1,arr1+n,f)-arr1;
    index -= 1;
    if(index>=0  &&  arr1[index] == f)
        cout<<"Last occurance of "<<f<<" is at index "<<index<<endl;
    else
        cout<<f<<" not found\n";



    // Q3. find the number of times the 7 appears in arr
    index = upper_bound(arr1,arr1+n,7)-arr1;
    int ind1 = lower_bound(arr1,arr1+n,7)-arr1;
    cout<<"\n7 occurs "<<(index-ind1)<<" times\n";


    index = upper_bound(arr1,arr1+n,11)-arr1;
    ind1 = lower_bound(arr1,arr1+n,11)-arr1;
    cout<<"11 occurs "<<(index-ind1)<<" times\n";


    // next_permutation(firstIterator,lastIterator) -> returns true if next permutation exits else returns false
    // O(N) time complexity
    string str="acb";
    sort(str.begin(),str.end());
    cout<<"\nDifferent permutations of "<<str<<" are\n";
    do{
        cout<<str<<endl;
    } while(next_permutation(str.begin(),str.end()));

    reverse(str.begin(),str.end());
    cout<<"\nDifferent permutations of "<<str<<" are (in reverse)\n";
    do{
        cout<<str<<endl;
    }while(prev_permutation(str.begin(),str.end()));







    return 0;
}