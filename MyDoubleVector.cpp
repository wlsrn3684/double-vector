// 2018203055 김진구
#include <iostream>
#include <assert.h>
#include "MyDoubleVector.h"
using namespace std;

MyDoubleVector::MyDoubleVector() {
	data = NULL; //값이 들어가는 공간
	capacityValue = NULL; //벡터의 최대크기
	sizeValue = NULL; //벡터의 현재크기
} // MyDoubleVector 초기화

MyDoubleVector::MyDoubleVector(const MyDoubleVector& v) {
	data = new double[v.sizeValue]; // 벡터의 데이터에 대해 벡터 요소의 실제 개수만큼 동적할당 해준다.
	capacityValue = v.capacityValue; 
	sizeValue = v.sizeValue;

	for (int i = 0; i < v.sizeValue; i++) {
		data[i] = v.data[i];
	}
} // postcondition : data에 새로운 배열을 동적 할당

MyDoubleVector::~MyDoubleVector() { // precondition : 객체 안에 데이터가 존재 
	delete data;
} // postcondition : 객체안에 있는 데이터를 삭제

MyDoubleVector::MyDoubleVector(int capacityValue) {
	data = new double[capacityValue];
	sizeValue = 0;
	capacityValue = capacityValue;
}

void MyDoubleVector::push_back(double x) { // precondition : 입력 값은 실수
	if (capacityValue == sizeValue) {
		reserve(capacityValue + 1);
	}
	data[sizeValue++] = x;
} // postcondition : 벡터의 마지막에 입력 값을 추가

void MyDoubleVector::pop_back() { // precondition : 객체 안에 데이터가 존재 
	assert(sizeValue != 0);
	data[--sizeValue] = NULL;
} // postcondition : 객체의 마지막 데이터를 삭제하고 사이즈를 1 줄여준다.

size_t MyDoubleVector::capacity() const {
	return capacityValue;
} // postcondition : 할당된 사이즈를 반환

size_t MyDoubleVector::size() const {
	return sizeValue;
} // postcondition : 데이터의 개수를 반환

void MyDoubleVector::reserve(size_t newCapacity) {
	double *largerArray;

	if (newCapacity <= capacityValue) {
		return;
	}

	largerArray = new double[newCapacity];
	copy(data, data + sizeValue, largerArray); 
	delete[] data;
	data = largerArray;
	capacityValue++;
} // postcondition : capacity가 size와 같을 때, capacity 의 값을 늘려줍니다.

bool MyDoubleVector::empty() const {
	if (sizeValue == 0) {
		return true;
	}
	return false;
}// postcondition : 벡터가 비어있는지에 따라 true 또는 false를 반환

void MyDoubleVector::clear() {
	delete data;
	data = 0;
	capacityValue = 0;
	sizeValue = 0;
} // postcondition : 벡터의 모든 요소를 삭제하고 크기를 0으로 바꾼다.

double& MyDoubleVector::operator[] (int num) { // precondition : 입력 값은 벡터의 현재크기보다 작아야 한다.
	assert(num < sizeValue);
	return data[num];
} // postcondition : 입력 받은 위치에 있는 벡터 요소의 레퍼런스를 반환

MyDoubleVector MyDoubleVector::operator-() { // precondition : 벡터가 비어 있으면 안된다.
	MyDoubleVector tempArray(sizeValue);
	tempArray.reserve(capacityValue);
	tempArray.sizeValue = size();

	for (int i = 0; i < size(); i++) {
		tempArray[i] = data[i] * -1.0;
	}

	return tempArray;
} // postcondition : 벡터 각각의 요소를 부호를 바꿔서 반환

MyDoubleVector MyDoubleVector::operator-(const MyDoubleVector& v) { // precondition : 두 벡터의 현재크기가 같아야 한다.
	assert(size() == v.size());
	
	MyDoubleVector tempArray(size());
	tempArray.reserve(capacityValue);
	tempArray.sizeValue = size();
	for (int i = 0; i < size(); i++) {
		tempArray.data[i] = data[i] - v.data[i];
	}
	return tempArray;
	
} // postcondition : 같은 위치에 있는 벡터 각각의 요소끼리 뺀 값을 반환

MyDoubleVector MyDoubleVector::operator+(const MyDoubleVector& v) { // precondition : 두 벡터의 현재크기가 같아야 한다.
	assert(size() == v.size());
	MyDoubleVector tempArray(size());
	tempArray.reserve(capacityValue);
	tempArray.sizeValue = size();

	for (int i = 0; i < size(); i++) {
		tempArray.data[i] = data[i] + v.data[i];
	}

	return tempArray;

} // postcondition : 같은 위치에 있는 벡터 각각의 요소끼리 더한 값을 반환

MyDoubleVector MyDoubleVector::operator=(const MyDoubleVector& v) { // precondition : 두 벡터의 현재크기가 같아야 한다.
	double *tempArray;

	tempArray = new double[v.capacity()];
	copy(v.data, v.data + v.sizeValue, tempArray);
	delete[] data;
	data = tempArray;
	return 0;
} // postcondition : 첫번째 벡터의 값을 모두 지우고 두번째 벡터의 값으로 채운다.

double MyDoubleVector::operator*(const MyDoubleVector& v) { // precondition : 두 벡터의 현재크기가 같아야 한다.
	assert(size() == v.size());
	double sum = 0.0;

	for (int i = 0; i < size(); i++) {
		sum += data[i] * v.data[i];
	}

	return sum;

} // postcondition : 두 벡터의 내적 값을 반환

void MyDoubleVector::operator += (const MyDoubleVector& v) { 
	if (sizeValue + v.sizeValue > capacityValue) {
		reserve(sizeValue + v.sizeValue);
	}

	copy(v.data, v.data + v.sizeValue, data + sizeValue);
	sizeValue += v.sizeValue;
} // postcondition : 첫번째 벡터의 끝에 두번째 벡터의 모든 요소를 추가

bool MyDoubleVector::operator == (const MyDoubleVector& v) { 
	if (sizeValue != v.sizeValue || capacityValue != v.capacityValue)  {
		return false;
	}

	for (int i = 0; i < size(); i++) {
		if (data[i] != v.data[i]) {
			return false;
		}	
	}

	return true;
} // postcondition : 두 벡터의 요소가 모두 동일한가에 따라 true 또는 false를 반환

void MyDoubleVector::operator() (double num) { // precondition : 입력 값은 실수
	for (int i = 0; i < size(); i++) {
		data[i] = num;
	}
} // postcondition : 벡터의 요소들을 전부 입력 값으로 변환