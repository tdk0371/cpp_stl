#include<iostream>
#include<array>
#include<algorithm>
#include<vector>
#include<deque>
#include<list>


//sequence container (array and linked list): vector, deque, list, forward list,array
//associative container (binary tree): set, multiset, map, multimap
//unordered container (hash table): unordered set, unordered map


//-std=c++11
using namespace std;

//array, vector and deque may invalidates pointers (pointers are affected by insert/remove action, may point to invalid position after insert/remove)

int main() {


/******************    example: array   *************************************/
	array<int, 5> arr;
	arr[0] = 10;
	arr[1] = 5;
	arr[2] = 14;
	arr[3] = 8;
	arr[4] = 2;

	array<int, 5> arr1;
	arr1.fill(9);


	auto it = arr.cbegin();

	cout<<*it<<endl;
	cout<<"arr.at(3) =  "<<arr.at(3)<<endl;
	cout<<"arr.front() =  "<<arr.front()<<endl;

	cout<<"array contains: ";
	for (auto it=arr.cbegin(); it != arr.cend(); it++) cout<<' '<<*it;
	cout<<endl;   //end() points to the element past the end, no value


	arr.front() = 20; //front() return reference

	cout<<"array contains: ";
	for (int& x : arr) cout<<' '<<x;
	cout<<endl;

	cout<<"arr.back() =  "<<arr.back()<<endl;
	cout<<"arr.size() = "<<arr.size()<<endl;

	arr.swap(arr1);  //for same type same size

	cout<<"array contains after swap: ";
	for (int& x : arr) cout<<' '<<x;
	cout<<endl;

	cout<<get<1>(arr)<<endl;
	
	array<int, 5>::iterator it1 = arr1.begin();  //same as below
	auto it2 = arr1.end();  //auto can automatically determine data type

	sort(it1, it2);  //algorithm take iterator argu
	cout<<"array contains after sort: ";
	for (int& y : arr1) cout<<' '<<y;
	cout<<endl;
	cout<<"******************End of array example*******************"<<endl;
	cout<<endl;


/*
* Example: Vector
* Vector is a dynamically allocated contiguous array in memory
* random access
* 1. Fast insert/remove at the end O(1)
* 2. SLow insert/remove at the beginning or middle O(n)
* 3. slow search O(n)
*/

	vector<int> vec = {4, 1, 8}; //vector initialize
	vec.push_back(2);
	vec.push_back(9);  //add element;

	cout<<vec[3]<<endl;
	cout<<vec.at(3)<<endl; //at() will check if out of size

	cout<<"traverse container: "; 
	for (vector<int>::const_iterator it = vec.cbegin(); it != vec.cend(); ++it)
		cout<<' '<<*it;   //faverable way to traverse container
	cout<<endl;



/*
* common member function for all containers
*/

//apply myfunction to each member in container:
	//for_each(vec.cbegin(), vec.cend(), myfunction);

//copy constructor
	vector<int> vec2(vec);

//check empty
	if (vec2.empty()) cout<<"empty!"<<endl;

//remove all elements
	vec2.clear();

//swap
	vec2.swap(vec);
	if (vec.empty()) cout<<"empty!"<<endl;

//container size
	cout<<vec.size()<<endl;
	cout<<vec2.size()<<endl;

	cout<<"******************End of Vector example**********************"<<endl;
	cout<<endl;


/*
* Example: Deque
* a vector which can also grow at the beginning (push_front())
* random access
* slow insert/remove at middle
* slow search O(n)
*/

	deque<int> deq = {3, 5, 8};
	deq.push_front(1);
	deq.push_back(20);

//remove by position
	//deq.erase(5); cannot remove by value
	deq.erase(deq.begin()+2);  //remove element at position3
	//random access iterator can move by + or - value
	//can be compared with other iterator

	cout<<"deque contains: ";
	for (deque<int>::iterator itd = deq.begin(); itd != deq.end(); ++itd)
		cout<<' '<<*itd;
	cout<<endl;
	cout<<"******************End of Deque example**********************"<<endl;
	cout<<endl;


/*
* Example: List
* is a double linked list
* insert/remove anywhere O(1)
* slow search O(n), slower than deque and vector (address not continuous)
* no random access ( at(), operator[] )
*/

	list<int> mylist = {2, 3, 5, 7, 9};
	mylist.push_front(0);
	mylist.push_back(12); //0, 2, 3, 5, 7, 9, 12
	
	cout<<"traverse list: ";
	for (list<int>::iterator itl = mylist.begin(); itl != mylist.end(); ++itl)
		cout<<' '<<*itl;
	cout<<endl;

//algorithm: find()
	list<int>::iterator itf = find(mylist.begin(), mylist.end(), 3); //position3
//insert
	mylist.insert(itf, 22); //0, 2, 22, 3, 5, 7, 9, 12
//move to position5 (previous position4)
	itf++; //list, set, map iterator can only do ++ or --, no + or -
//remove
	mylist.erase(itf); //0, 2, 22, 3, 7, 9, 12

	cout<<"traverse list: ";
	for (list<int>::iterator itl = mylist.begin(); itl != mylist.end(); ++itl)
		cout<<' '<<*itl;
	cout<<endl;

//unique of list: splice list
	list<int> mylist1 = {0,0}; //0 0
	list<int>::iterator itf_a = mylist.begin();
	list<int>::iterator itf_b = itf_a;
	advance(itf_a,3);   //@22
	advance(itf_b,5);   //@7
	list<int>::iterator itl1 = mylist1.begin();
	advance(itl1, 1);  //@0
	mylist1.splice(itl1, mylist, itf_a, itf_b); //O(1)
	//0 2 22 9 12
	//0 3 7 0

	cout<<"traverse list: ";
	for (list<int>::iterator itl = mylist.begin(); itl != mylist.end(); ++itl)
		cout<<' '<<*itl;
	cout<<endl;
	cout<<"traverse list: ";
	for (list<int>::iterator itl1 = mylist1.begin(); itl1 != mylist1.end(); ++itl1)
		cout<<' '<<*itl1;
	cout<<endl;
		
	cout<<"******************End of List example**********************"<<endl;
	cout<<endl;



/*
* Example: Forward-List
* is a single linked list -> end
* insert/remove anywhere O(1)
* slow search O(n), slower than deque and vector (address not continuous)
* no random access ( at(), operator[]
*/



	return 0;
}

