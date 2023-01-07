#include <iostream>
#include <string>
#include <list>

using namespace std;

int N;
long long int x,a,d,L,R;
string str;
list<long long int> Mylist;
list<long long int>::iterator it,itr;
list<long long int>::reverse_iterator ir;

void House(), Bomb(), PrintFront(), PrintEnd();

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		if (str == "House") {
			House();
		}
		else if (str == "Bomb") {
			Bomb();
		}else if (str == "PrintFront") {
			PrintFront();
		}else if (str == "PrintEnd") {
			PrintEnd();
		}
	}
}

void House() {
	cin >> x;
	if (Mylist.size() > 0) {
		if (x > Mylist.front()) {
			for (it = Mylist.begin(); it != Mylist.end(); ++it) {
				if (*it>x) {
					Mylist.insert(it, x);
					break;
				}
				else if (*it == x) {
					break;
				}
				else if (*it == Mylist.back()) {
					Mylist.push_back(x);
					break;
				}
			}
		}else if(x<Mylist.front()){
			Mylist.push_front(x);
		}
	}else {
		Mylist.push_back(x);
	}
}

void Bomb() {
	cin >> a >> d;
	for (it = Mylist.begin(); it != Mylist.end(); ++it) {
		if (*it >= a - d && *it <= a + d) {
			itr = it;
			--it;
			Mylist.erase(itr);
		}
	}
}

void PrintFront() {
	cout << "PrintFront" << endl;
	for (it = Mylist.begin(); it != Mylist.end(); ++it) {
		cout << *it << endl;
	}
}

void PrintEnd() {
	cout << "PrintEnd" << endl;
	for (ir = Mylist.rbegin(); ir != Mylist.rend(); ir++) {
		cout << *ir << endl;
	}
}