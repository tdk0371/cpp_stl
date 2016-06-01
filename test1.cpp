#include<iostream>
#include<set>
#include<algorithm>

using namespace std;

int main() {
	
	set<int> iset;
	iset.insert(5);
	iset.insert(8);
	iset.insert(7);
	iset.insert(6);

	cout<<"iset contains: ";
	set<int>::iterator it;
	for (it=iset.begin(); it != iset.end(); it++)
		cout<<" "<<*it;
	cout<<endl;

	cout<<*iset.begin()<<" "<<*iset.end()<<endl;

	int searchFor;
	cin>>searchFor;
	if(binary_search(iset.begin(), iset.end(), searchFor))
		cout<<"Found "<<searchFor<<endl;
	else
		cout<<"Did not find "<<searchFor<<endl;


	return 0;

}
