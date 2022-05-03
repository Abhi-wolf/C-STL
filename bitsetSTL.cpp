#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    // bitset stores bits only (stroes 0 or 1,true or false)
    //          INDEXING STARTS FROM BACK
    bitset<5>bset1;         // by default all indexes are set to 0
    //  cin>>bset1;
    cout<<"bset1 : "<<bset1<<endl;

    // operator[k] -> return sthe value (or a reference) to the bit at position k
    bset1[1]=1;
    bset1[4]=1;
    cout<<"bset1 : "<<bset1<<endl;

    // all() -> tests if all bits are set (set means 1) (1 if true else false)
    cout<<"bset1(tests if all bits are set) : "<<bset1.all()<<endl;
    cout<<"bset1[4]: "<<bset1[4]<<endl;

    // none() -> tests if no bits are set (1 if true else false)
    cout<<"bset1 (tests if no bits are set) : "<<bset1.none()<<endl;
    
    // any() -> tests if any bit is set  (1 if true else false)
    cout<<"bset1 (tests if any bit is set) : "<<bset1.any()<<endl;


    // test(k) -> returns whether the bit at position k is set(i.e. whether it is one)
    // size() -> returns size of bitset(number of elements present)
    for(int i=0;i<bset1.size();i++)
        cout<<bset1.test(i)<<endl;
    cout<<"Size of bset1 : "<<bset1.size()<<endl;

    // count() -> returns the number of bits in the bitset that are set(i.e. that have a value of one)
    cout<<bset1<<" has "<<bset1.count()<<" ones and "<<(bset1.size()-bset1.count())<<" zeros\n";
    
    // set() -> sets(to one) all bits in bitset
    cout<<"bset1 : "<<bset1.set()<<endl;
    cout<<"bset1 : "<<bset1.set(2,0)<<endl;     // set zero at 2nd index
    cout<<"bset1 : "<<bset1.set()<<endl;

    // reset() -> resets (to zero) all bits of bitset
    cout<<"\nbset1 : "<<bset1.reset(3)<<endl;
    cout<<"bset1 : "<<bset1.reset()<<endl;

    // flip() -> flips bit values converting zeros into ones and ones into zeros
    cout<<"\nbset1 : "<<bset1.flip(3)<<endl;          // flips only at position 3
    cout<<"bset1 : "<<bset1.flip(0)<<endl;
    cout<<"bset1 : "<<bset1.flip()<<endl;

    int num=10;
    cout<<"\nDecimal number: "<<num<<"  Binary equivalent: "<<bitset<4>(num);
    cout<<endl;

    num=90;
    cout<<"\nDecimal number: "<<num<<"  Binary equivalent: "<<bitset<8>(num);
    cout<<endl;

    // to_ulong() -> convert to unsigned long integer
    // to_ullong() -> convert to unsigned long long
    cout<<endl<<bset1<<" as an integer is : "<<bset1.to_ulong()<<"\n";

    return 0;
}