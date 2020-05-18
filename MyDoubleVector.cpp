// 2018203055 ������
#include <iostream>
#include <assert.h>
#include "MyDoubleVector.h"
using namespace std;

MyDoubleVector::MyDoubleVector() {
	data = NULL; //���� ���� ����
	capacityValue = NULL; //������ �ִ�ũ��
	sizeValue = NULL; //������ ����ũ��
} // MyDoubleVector �ʱ�ȭ

MyDoubleVector::MyDoubleVector(const MyDoubleVector& v) {
	data = new double[v.sizeValue]; // ������ �����Ϳ� ���� ���� ����� ���� ������ŭ �����Ҵ� ���ش�.
	capacityValue = v.capacityValue; 
	sizeValue = v.sizeValue;

	for (int i = 0; i < v.sizeValue; i++) {
		data[i] = v.data[i];
	}
} // postcondition : data�� ���ο� �迭�� ���� �Ҵ�

MyDoubleVector::~MyDoubleVector() { // precondition : ��ü �ȿ� �����Ͱ� ���� 
	delete data;
} // postcondition : ��ü�ȿ� �ִ� �����͸� ����

MyDoubleVector::MyDoubleVector(int capacityValue) {
	data = new double[capacityValue];
	sizeValue = 0;
	capacityValue = capacityValue;
}

void MyDoubleVector::push_back(double x) { // precondition : �Է� ���� �Ǽ�
	if (capacityValue == sizeValue) {
		reserve(capacityValue + 1);
	}
	data[sizeValue++] = x;
} // postcondition : ������ �������� �Է� ���� �߰�

void MyDoubleVector::pop_back() { // precondition : ��ü �ȿ� �����Ͱ� ���� 
	assert(sizeValue != 0);
	data[--sizeValue] = NULL;
} // postcondition : ��ü�� ������ �����͸� �����ϰ� ����� 1 �ٿ��ش�.

size_t MyDoubleVector::capacity() const {
	return capacityValue;
} // postcondition : �Ҵ�� ����� ��ȯ

size_t MyDoubleVector::size() const {
	return sizeValue;
} // postcondition : �������� ������ ��ȯ

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
} // postcondition : capacity�� size�� ���� ��, capacity �� ���� �÷��ݴϴ�.

bool MyDoubleVector::empty() const {
	if (sizeValue == 0) {
		return true;
	}
	return false;
}// postcondition : ���Ͱ� ����ִ����� ���� true �Ǵ� false�� ��ȯ

void MyDoubleVector::clear() {
	delete data;
	data = 0;
	capacityValue = 0;
	sizeValue = 0;
} // postcondition : ������ ��� ��Ҹ� �����ϰ� ũ�⸦ 0���� �ٲ۴�.

double& MyDoubleVector::operator[] (int num) { // precondition : �Է� ���� ������ ����ũ�⺸�� �۾ƾ� �Ѵ�.
	assert(num < sizeValue);
	return data[num];
} // postcondition : �Է� ���� ��ġ�� �ִ� ���� ����� ���۷����� ��ȯ

MyDoubleVector MyDoubleVector::operator-() { // precondition : ���Ͱ� ��� ������ �ȵȴ�.
	MyDoubleVector tempArray(sizeValue);
	tempArray.reserve(capacityValue);
	tempArray.sizeValue = size();

	for (int i = 0; i < size(); i++) {
		tempArray[i] = data[i] * -1.0;
	}

	return tempArray;
} // postcondition : ���� ������ ��Ҹ� ��ȣ�� �ٲ㼭 ��ȯ

MyDoubleVector MyDoubleVector::operator-(const MyDoubleVector& v) { // precondition : �� ������ ����ũ�Ⱑ ���ƾ� �Ѵ�.
	assert(size() == v.size());
	
	MyDoubleVector tempArray(size());
	tempArray.reserve(capacityValue);
	tempArray.sizeValue = size();
	for (int i = 0; i < size(); i++) {
		tempArray.data[i] = data[i] - v.data[i];
	}
	return tempArray;
	
} // postcondition : ���� ��ġ�� �ִ� ���� ������ ��ҳ��� �� ���� ��ȯ

MyDoubleVector MyDoubleVector::operator+(const MyDoubleVector& v) { // precondition : �� ������ ����ũ�Ⱑ ���ƾ� �Ѵ�.
	assert(size() == v.size());
	MyDoubleVector tempArray(size());
	tempArray.reserve(capacityValue);
	tempArray.sizeValue = size();

	for (int i = 0; i < size(); i++) {
		tempArray.data[i] = data[i] + v.data[i];
	}

	return tempArray;

} // postcondition : ���� ��ġ�� �ִ� ���� ������ ��ҳ��� ���� ���� ��ȯ

MyDoubleVector MyDoubleVector::operator=(const MyDoubleVector& v) { // precondition : �� ������ ����ũ�Ⱑ ���ƾ� �Ѵ�.
	double *tempArray;

	tempArray = new double[v.capacity()];
	copy(v.data, v.data + v.sizeValue, tempArray);
	delete[] data;
	data = tempArray;
	return 0;
} // postcondition : ù��° ������ ���� ��� ����� �ι�° ������ ������ ä���.

double MyDoubleVector::operator*(const MyDoubleVector& v) { // precondition : �� ������ ����ũ�Ⱑ ���ƾ� �Ѵ�.
	assert(size() == v.size());
	double sum = 0.0;

	for (int i = 0; i < size(); i++) {
		sum += data[i] * v.data[i];
	}

	return sum;

} // postcondition : �� ������ ���� ���� ��ȯ

void MyDoubleVector::operator += (const MyDoubleVector& v) { 
	if (sizeValue + v.sizeValue > capacityValue) {
		reserve(sizeValue + v.sizeValue);
	}

	copy(v.data, v.data + v.sizeValue, data + sizeValue);
	sizeValue += v.sizeValue;
} // postcondition : ù��° ������ ���� �ι�° ������ ��� ��Ҹ� �߰�

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
} // postcondition : �� ������ ��Ұ� ��� �����Ѱ��� ���� true �Ǵ� false�� ��ȯ

void MyDoubleVector::operator() (double num) { // precondition : �Է� ���� �Ǽ�
	for (int i = 0; i < size(); i++) {
		data[i] = num;
	}
} // postcondition : ������ ��ҵ��� ���� �Է� ������ ��ȯ