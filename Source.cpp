#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class coord {
	int x, y;
public:
	coord(int x, int y) :x(x), y(y) {

	}

	int get_area() {
		return sqrt(x * x + y * y);
	}

	void print_xy() {
		cout << "x:" << x << "; y: " << y << '\n';
	}

};

void foo(vector<coord> v, int x, int y) {
	v.push_back(coord(x, y));
	cout << v.size() << endl;
}

int main() {
	vector<coord> v(5, coord(5, 5));
	
	//A compilation error
	//vector<coord> v1(3);
	//v1[0].print_xy();
	
	cout << v.size() << endl;
	foo(v, 1, 2);
	cout << "Size: " << v.size() << endl;

	v.push_back(coord(2, 3));
	vector<coord>::iterator p = v.end();

	//Runtime error here
	//cout << (*p).get_area()<<endl;

	//last element
	p = v.end() - 1;
	cout << "Area: " << (*p).get_area() << endl;
	(*p).print_xy();

	cout << "Size: " << v.size() << endl;
	p = v.end();
	v.insert(p, 3, coord(3, 4));

	//p gets destroyed
	//the line is a runtime error
	//(*p).print_xy();

	
	cout << v.size() << endl << endl;

	p = v.begin();
	for (int i = 0; i < v.size(); i++) {
		(*p).print_xy();
		p++;
	}
	cout << endl << endl;

	p = v.begin() + 6;
	v.erase(p, p+3);
	p = v.begin();
	for (int i = 0; i < v.size(); i++) {
		(*p).print_xy();
		p++;
	}

	getchar();
	return 0;

}