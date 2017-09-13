#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <numeric>

typedef double(*FUNC)(double);

class DemoObject {
public:
	DemoObject(int N) {
		n = N;
	}
	double power(double exp) const {
		return pow(n, exp);
	}
	double inversePower(double exp) const {
		return pow(n, 1 / exp);
	}
private:
	int n;
};

typedef double (DemoObject::*DemoMethod)(double) const;

double sumIt(const DemoObject &obj, DemoMethod f, int N) {
	double sum = 0;
	for (int i = 1; i <= N; i++) {
		sum += (obj.*f)(i);
	}
	return sum;
}

void functionPointerExample() {
	std::cout << "Function pointer example" << std::endl;
	FUNC f1 = acos;
	std::cout << (*f1)(-1) << std::endl;

	DemoObject d1(3);
	DemoObject d2(10);

	std::cout << sumIt(d1, &DemoObject::power, 2) << std::endl;
	std::cout << sumIt(d2, &DemoObject::inversePower, 5) << std::endl;
	std::cout << std::endl;
}

int isEven(int a) {
	return a % 2 == 0;
}

int add(int a, int b) {
	return a + b;
}

void lambdaExample() {
	std::cout << "lambda example" << std::endl;

	int evenCount = 0;
	std::vector<int> v;
	for (int i = 1; i <= 10; i++)
		v.push_back(i);

	int sum = 0;
	for (auto i = v.begin(); i != v.end(); i++) {
		sum += *i;
	}
	std::cout << "Sum of all numbers: " << sum << std::endl;
	std::cout << "Sum of all numbers: " << accumulate(v.begin(), v.end(), 0, [](int a, int b) { return a + b; }) << std::endl;
	std::cout << "Sum of all numbers: " << accumulate(v.begin(), v.end(), 0, add) << std::endl;
	std::cout << "Sum of all numbers: " << accumulate(v.begin(), v.end(), 0) << std::endl;

	int cnt = 0;
	for (auto i = v.begin(); i != v.end(); i++) {
		if (*i % 2 == 0) {
			cnt++;
		}
	}
	std::cout << "There are " << cnt << " even numbers.\n";
	std::cout << "There are " << count_if(v.begin(), v.end(), isEven) << " even numbers.\n";
	std::cout << "There are " << count_if(v.begin(), v.end(), [](int a) { return a % 2 == 0; }) << " even numbers.\n";

	for_each(v.begin(), v.end(), [&evenCount](int n) {
		if (n % 2 == 0) {
			evenCount++;
		}
	});
	std::cout << "There are " << evenCount << " even numbers.\n";
}

int main(int argc, char *argv[]) {
	functionPointerExample();
	lambdaExample();
}
