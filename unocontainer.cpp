#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<vector>

using namespace std;
/*
* unordered containers (-std=c++11)
* hash table
* order not defined
* hash functon -> buckets -> linked list
* O(1) time search with good hash function
* may hash collision
* element value cannot be changed
*/







int main() {

/*
* unordered set
*
*/

	unordered_set<string> mset = {"red", "yellow", "blue"};

//insert entry
	mset.insert("black");   //O(1)

	vector<string> vec = {"white", "tangerina", "purple"};
	mset.insert(vec.begin(), vec.end());   //insert other container

//search unordered set
	unordered_set<string>::const_iterator itu = mset.find("white"); //O(1)
	if (itu != mset.end())  //will return end() if white not in mset
		cout<<*itu<<" find"<<endl;

//hash table specific APIs:
	cout<<"load factor = "<<mset.load_factor()<<endl; //N/M
	string x = "purple";
	cout<<x<<" is in the bucket #"<<mset.bucket(x)<<endl; //bucket position
	cout<<"total bucket #"<<mset.bucket_count()<<endl; //table size
	
	for (itu = mset.cbegin(); itu!= mset.cend(); ++itu)
		cout<<' '<<*itu;
	cout<<endl;

	

	cout<<"****************End of Unordered Set example*****************"<<endl;
	cout<<endl;


/*
* unordered map
*
*/

	unordered_map<string, int> tmap = {{"Beijing", 20}, {"Shanghai", 25}};

//insert: O(1)
	tmap.insert(make_pair("Chengdu", 29));
	tmap["Guangzhou"] = 30;  //same as insert(make_pair...if Guangzhou not in map
	tmap.insert(make_pair("Beijing", 25)); //failed to modify 20->29 
	tmap["Beijing"] = 25; //correct way to modify

//search: O(1) but may degrade to O(n)
	cout<<"beijing: "<<tmap["Beijing"]<<endl; //no range check
	cout<<"Guangzhou: "<<tmap.at("Guangzhou")<<endl; //has range check
	cout<<"unknown: "<<tmap["unknown"]<<endl;  //will create unknown: 0
	cout<<endl;

	for (auto itu1 = tmap.cbegin(); itu1!= tmap.cend(); ++itu1)
		cout<<(*itu1).first<<" :"<<(*itu1).second<<endl;
	cout<<endl;

//hash table API:
	cout<<"load factor = "<<mset.load_factor()<<endl; //N/M
	cout<<"total bucket #"<<tmap.bucket_count()<<endl; //table size

	cout<<"unknown2: "<<tmap.at("unknown2")<<endl; //throw error

	
	return 0;
}

/*
* container adapter, provide a restricted interface to meet special needs
* implemented with fundamental container classes
* 1. stack: LIFO, push(), pop(), top()
* 2. queue: FIFO, push(), pop(), front(), back()
* 3 priority queue: first item always has greatest priority
*	pop(), push(), top()
*/

