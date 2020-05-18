// ±èÁø±¸ 2018203055


struct MyDoubleVector
{
private:
	double* data;
	size_t sizeValue;
	size_t capacityValue;
public:
	MyDoubleVector();
	MyDoubleVector(const MyDoubleVector& v);
	~MyDoubleVector();
	MyDoubleVector(int capacity_value);
	void push_back(double x);
	void pop_back();
	size_t capacity() const;
	size_t size() const;
	void reserve(size_t n);
	bool empty() const;
	void clear();
	double& operator[] (int num);
	MyDoubleVector operator-();
	MyDoubleVector operator-(const MyDoubleVector& v1);
	MyDoubleVector operator+(const MyDoubleVector& v1);
	MyDoubleVector operator=(const MyDoubleVector& v1);
	double operator*(const MyDoubleVector& v1);
	void operator += (const MyDoubleVector& v1);
	bool operator == (const MyDoubleVector& v1);
	void operator() (double num);
};


