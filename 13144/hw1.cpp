#include "function.h"
#include <iostream>

template <class T>
BaseStack<T>::BaseStack() {
	_top = -1;
	capacity = 1;
	_stack = new T[capacity];
}

template <class T>
BaseStack<T>::~BaseStack() {
	delete[] _stack;
}

template <class T>
void BaseStack<T>::push(const T& item) {
	if (_top == capacity - 1) {
		capacity *= 2;
		T* newStack = new T[capacity];
		for (int x = 0; x < (capacity / 2); x++) {
			newStack[x] = _stack[x];
		}
		delete[] _stack;
		_stack = newStack;
	}
	_stack[++_top] = item;
	return;
}

template <class T>
T& BaseStack<T>::top() {
	if (empty()) {
	}
	else {
		return _stack[_top];
	}
}

template <class T>
void BaseStack<T>::pop() {
	if (empty()) {
	}
	else {
		_top--;
	}
	return;
}

template <class T>
bool BaseStack<T>::empty() {
	return _top == -1 ? true : false;
}

template <class T>
int BaseStack<T>::size() {
	return (_top + 1);
}


template<class T>
BaseQueue<T>::BaseQueue() {
	_front = -1;
	_rear = -1;
	capacity = 1;
	_queue = new T[capacity];
}

template<class T>
BaseQueue<T>::~BaseQueue() {
	delete[] _queue;
}

template<class T>
void BaseQueue<T>::push(const T& item) {
	if (_rear == capacity - 1) {
		capacity *= 2;
		T* newQueue = new T[capacity];
		int newIndex = -1;
		for (int i = _front + 1; i <= _rear; i++) {
			newIndex++;
			newQueue[newIndex] = _queue[i];
		}
		_front = -1;
		_rear = newIndex;
		_queue = newQueue;
	}
	_queue[++_rear] = item;
	return;
}

template<class T>
T& BaseQueue<T>::front() {
	if (!empty()) {
		return _queue[_front + 1];
	}
}

template<class T>
bool BaseQueue<T>::empty() {

	return _front == _rear;
}

template<class T>
void BaseQueue<T>::pop() {
	if (!empty()) {
		_front = (_front + 1) % capacity;
	}
	return;
}

template<class T>
int BaseQueue<T>::size() {
	return _rear - _front;
}


string E[10];

BaseQueue<string> a[10];
BaseStack<string> b;

int front, rear, fptr, SIZE, SIZER , sidx,sptr;
int rptr = 11;
string str, temp;

void insert(int L) {

	int input;

	cin >> input;
	if (cin.fail()) {
		cin.clear();
		cin.sync();
		return;
	}
	else {
		temp = getchar();

		while (temp == " ") {
			temp = getchar();
		}

		E[input] = temp;
		front = input;

		for (int k = input; k < L; k++) {
			if (k > input) E[k] = getchar();
			if (E[k] == "\n") {
				rear = k - 1;
				break;
			}
			else if (k == L - 1) {
				rear = k;
			}
		}

		if (((rptr - front) * (rptr - rear) > 0) && ((fptr - front) * (fptr - rear) > 0)) {
			for (int k = front; k <= rear; k++) {
				a[k].push(E[k]);
				SIZE = a[k].size();
			}
		}
		else {
			for (int k = front; k <= rear; k++) {

				if (k < fptr) {
					int ASIZE = a[k].size();
					for (int j = 0; j < (SIZE - ASIZE); j++) {
						a[k].push("@");
					}
					a[k].push(E[k]);
				}
				else if (k > rptr) {
					int ASIZE = a[k].size();
					for (int j = 0; j < (SIZE - ASIZE - 1); j++) {
						a[k].push("@");
					}
					a[k].push(E[k]);
				}
				else {
					a[k].push(E[k]);
					SIZE = a[k].size();
				}
			}
		}

		fptr = front;
		rptr = rear;

		for (int k = 0; k < L; k++) {
			E[k] = "";
		}
	}
}

string first_row(int L, bool print) {
	cout << "BOTTOM_ROW" << endl;
	for (int k = 0; k < L; k++) {
		if (a[k].size() == 0) {
			cout << "~";
		}
		else {
			str = a[k].front();
			cout << str;
		}
	}
	cout << endl;
	return "\n";
}

void query(int L) {
	string out = "";

	int k1 = 0;
	int ss = 0;

	temp = getchar();
	while (temp == " ") {
		temp = getchar();
	}

	E[0] = temp;

	while (ss == 0) {
		if (k1 > 0) E[k1] = getchar();
		if (E[k1] == "\n") {
			sidx = k1 - 1;
			break;
		}
		if (k1 == L + 1) ss = 0;
		k1 = k1 + 1;
	}

	if (ss == 0) {
		for (int k = 0; k < L; k++) {
			if (a[k].size() > 0) {
				for (int j = 0; j < (sidx + 1); j++) {
					if (a[k + j].size() > 0) {
						if (E[j] != a[k + j].front()) {
							break;
						}
						if (j == sidx) {
							for (int m = 0; m < (sidx + 1); m++) {
								out = out + E[m];
								a[k + m].pop();
							}
							b.push(out);
							sptr = 1;
							break;
						}
					}

				}
				if (sptr == 1) {
					SIZE = SIZE-1;
					break;
				}
			}
		}
		sptr = 0;
		for (int k = 0; k < L; k++) {
			E[k] = "";
		}

	}
	else {
		for (int k = 0; k < L + 1; k++) {
			E[k] = "";
		}
	}
}

void flush() {
	cout << "FLUSH" << endl;
	SIZER = b.size();
	for (int k = 0; k < SIZER; k++) {
		cout << b.top() << endl;
		b.pop();
	}
}

void reset(int L) {
	SIZER = b.size();
	for (int k = 0; k < SIZER; k++) {
		b.pop();
	}
	for (int k = 0; k < L; k++) {
		SIZER = a[k].size();
		for (int m = 0; m < SIZER; m++) {
			a[k].pop();
		}
	}
	front = 0;
	rear = 0;
	fptr = 0;
	SIZE = 0;
	rptr = 11;
}