#include <iostream>
#include <utility>
#include <string>
#include <vector>
using namespace std;

int main()
{
    pair<int,char>pair1;
    pair<string,int>pair2 ("GeeksForGeeks",2);
    pair<string,double>pair3;

    pair1.first=100;
    pair1.second='A';


    // make_pair() -> used to make pairs
    pair3 = make_pair("GFG is Best",5.92);

    cout<<"Pair1: "<<pair1.first<<" "<<pair1.second<<endl;
    cout<<"Pair2: "<<pair2.first<<" "<<pair2.second<<endl;
    cout<<"Pair3: "<<pair3.first<<" "<<pair3.second<<endl;


    pair<string,int>pair_array[3];
    pair_array[0] = {"Abhi",10};
    pair_array[1] = {"Rock",30};
    pair_array[2] = {"Tree",20};
    cout<<"Array of Pairs\n";
    for(int i=0;i<3;i++)
        cout<<pair_array[i].first<<" "<<pair_array[i].second<<endl;

    vector<pair<int,string>>vec1;

    // vec1.push_back("Abhijeet",1);
    vec1.push_back(make_pair(10,"Asdf"));
    vec1.push_back(make_pair(20,"qwer"));
    vec1.push_back(make_pair(30,"zxcv"));

    cout<<"\nVector and pair combination\n";
    for(int i=0;i<vec1.size();i++)
        cout<<vec1[i].first<<"  "<<vec1[i].second<<endl;

    pair<string,int>pair5;
    pair5 = {"qwer",100};

    cout<<"\nBefore swapping\n";
    cout<<"Pair5: "<<pair5.first<<" "<<pair5.second<<endl;
    cout<<"Pair2: "<<pair2.first<<" "<<pair2.second<<endl;

    // swaps contents of pair2 with pair 5
    pair5.swap(pair2);

    cout<<"\nAfter swapping\n";
    cout<<"Pair5: "<<pair5.first<<" "<<pair5.second<<endl;
    cout<<"Pair2: "<<pair2.first<<" "<<pair2.second<<endl;

    pair<int,char> foo (10,'z');
    pair<int,char> bar (90,'a');

  if (foo==bar) cout << "\nfoo and bar are equal\n";
  if (foo!=bar) cout << "\nfoo and bar are not equal\n";
  if (foo< bar) cout << "foo is less than bar\n";
  if (foo> bar) cout << "foo is greater than bar\n";
  if (foo<=bar) cout << "foo is less than or equal to bar\n";
  if (foo>=bar) cout << "foo is greater than or equal to bar\n";

    return 0;   
}