#include<iostream>
#include<set>
#include<map>


//binary tree, all sorted

using namespace std;

int main() {


/*
* SET
* no duplicates
* insert anywhere log(n)
* search log(n), key feature of set
* 
*/


	set<int> mset;
	mset.insert(3);
	mset.insert(8);
	mset.insert(11);
	mset.insert(5); 
	mset.insert(7);  //sorted when insert/remove, 3 5 7 8 11

	for (set<int>::iterator its=mset.begin(); its!=mset.end(); ++its)
		cout<<' '<<*its;
	cout<<endl;

	set<int>::iterator it;
	it = mset.find(7);  //associate container has find() member, it point to 7
	
	pair<set<int>::iterator, bool> ret; //ret.first is iterator, ret.second is bool

	ret = mset.insert(5); //cannot duplicate vale, bool = false, it point to 5

	if (ret.second == false) it = ret.first;

	mset.insert(it, 9); //it provides a reference for insert, if it at a good position, insert can only take O(1) time, 3 5 7 8 9 11

	mset.erase(it);  //it point to 5 previously, 3 7 8 9 11

	mset.erase(8); //can also erase value, 3 7 9 11

	mset.erase(2);  //nothing happen

	for (set<int>::iterator its=mset.begin(); its!=mset.end(); ++its)
		cout<<' '<<*its;
	cout<<endl;

/*
* multiset<int> myset;
* Multiset is a set allows duplicated items
* set/multiset, value cannot be modified: *it = 10 invalid
* set/multiset: fast search log(n), traverse is slow than vector & deque
* no random access
*/

	cout<<"******************End of SET example*******************"<<endl;
	cout<<endl;


/*
* MAP is a set with item(key, value), item.key is unique
* MultiMap is a map allows duplicated item.key 
* keys cannot be modified
*/


	map<string, int> mmap;
	mmap.insert(pair<string, int> ("jim", 27038));
	mmap.insert(make_pair("mike", 29783));

//insert to a position
	map<string, int>::iterator itm;
	itm = mmap.begin();
	mmap.insert(itm, pair<string, int> ("bill", 26032)); //itm is a hint which can make insert O(1) time if proper positioned
	cout<<"map contains: "<<endl;
	for (itm=mmap.begin(); itm != mmap.end(); ++itm)
		cout<<(*itm).first<<" => "<<(*itm).second<<endl;

//search
	itm = mmap.find("jim");    //O(log(n))
	cout<<"find: "<<(*itm).first<<" => "<<(*itm).second<<endl;

	itm = mmap.find("kate");    //itm->NULL
	//cout<<"find: "<<(*itm).first<<" => "<<(*itm).second<<endl; //error


	cout<<"******************End of MAP example*******************"<<endl;
	cout<<endl;
	
 

	return 0;
}
