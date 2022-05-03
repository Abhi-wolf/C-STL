#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
    // maps store elements as a combination of a key vlaue and a mapped value,
    //key values are generally used to sort and uniquely identify the elements 
    map<char,int>map1;
    map1['c']=100;
    map1['a']=200;
    map1['d']=400;
    map1['b']=300;


    // find() -> Searches the container for an element with a key equivalent to k and returns an iterator to it if found, otherwise it returns an iterator to map::end.
    auto k=map1.find('b');
    if(k!=map1.end())
        map1.erase(k);
    for(auto i=map1.begin();i!=map1.end();i++)
        cout<<i->first<<" "<<i->second<<endl;
    cout<<"Count of a is "<<map1.count('a')<<endl;    

    map<int,char>map2;
    map2[1]='a';
    map2[4]='b';
    map2[3]='d';
    map2[2]='c';
    for(auto i=map2.begin();i!=map2.end();i++)
        cout<<i->first<<"  "<<i->second<<endl;
    cout<<"Size of Map1 "<<map1.size()<<endl;


    map2.at(2)='b';
    map2.at(3)='c';
    map2.at(4)='d';
    for(auto i:map2)
        cout<<i.first<<"  "<<i.second<<endl;
    cout<<"Maximum size of Map1 "<<map1.max_size()<<endl;

    // insert() -> used to insert elements with a particular key in the map 
    map2.insert({6,'f'});
    map2.insert({5,'e'});
    map2.insert({0,'a'});

    for(auto i:map2)
        cout<<i.first<<"  "<<i.second<<endl;
    cout<<"Size of Map2 "<<map2.size()<<endl;

    // clear() -> clear content
  //  map2.clear();
    if(map2.empty())
        cout<<"Map2 is empty\n";
    else
        cout<<"Map2 is not empty\n";
    cout<<"Size of Map2 "<<map2.size()<<endl;

    // empalce() -> inserts new element in the map if its key is unique
    map2.emplace(10,'z');


    // lower_bound(k) -> returns iterator pointing to the key k in contianer if k is present
    //             if k is not present than it returns new large number
    // upper_bound() -> always returns iterator pointing to greater than key k
    auto it=map2.lower_bound(2);
    auto itt=map2.upper_bound(3);

    cout<<"Lower bound of 2 is  "<<(*it).first<<"  "<<(*it).second<<endl;
    cout<<"Upper bound of 3 is  "<<(*itt).first<<"  "<<(*itt).second<<endl;


    for(auto itt=map2.begin();itt!=map2.end();itt++)
        cout<<itt->first<<" "<<itt->second<<endl;




    // MULTIMAP
    // stores element formed by a combination of a key vlaue and a mapped value,following a specific order
    // and where multiple elements can have equivalent keys

    multimap<int,string>multi1;
    multi1.emplace(1,"Abhi");
    multi1.emplace(1,"Rock");   // double inverted comas must be used
    multi1.emplace(3,"Anu");

    multi1.emplace(2,"asdf");

    multi1.insert({4,"qwsd"});
    

    for(auto i:multi1)
        cout<<i.first<<"  "<<i.second<<endl;
    cout<<endl;


    // UNORDERED MAP
    // stores elements similar to map but in unordered fashion(random order)

    unordered_map<string,string>unor1;
    unor1={{"Australia","Canberra"},{"U.S","Washington"},{"France","Paris"}};

    for(auto k:unor1)
        cout<<k.first<<" : "<<k.second<<endl;
    cout<<"Size of unordered map is "<<unor1.size()<<endl;
    cout<<"Max size of unordered map is "<<unor1.max_size()<<endl;



    return 0;

}