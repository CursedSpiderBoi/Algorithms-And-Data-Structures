#include<iostream>
#include<stdlib.h>
#include<vector>

using namespace std;

template<typename t>
class queue{
	vector<t> data;
	//int limit;//normally a queue has a certain limit which can't be crossed
public:
	queue(){
	}
//	queue(int lim){
//		limit=lim;
//	}
	bool isEmpty(){
		return data.empty();
	}
	int size(){
		return data.size();
	}
	void enqueue(t val){
//		if(data.size()==limit){
//			cout<<"Queue Limit Reached.\nAction can't be performed.\n"
//			return;
//		}
		data.push_back(val);
	}
	void dequeue(){
		if(this->isEmpty()){
			cout<<"Queue is Empty.\nAction can't be performed.\n";
			return;
		}
		data.erase(data.begin());
	}
	t top(){
		if(this->isEmpty()){
			cout<<"Queue is Empty.\nAction can't be performed.\n";
			return;
		}
		return data.front();
	}
};
