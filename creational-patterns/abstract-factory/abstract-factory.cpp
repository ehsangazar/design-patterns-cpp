#include <iostream>
using namespace std;

class Shape {
public:
	virtual void draw() = 0;
};

class Circle : public Shape {
public:
	void draw() {
		cout<<"Circle\n";
	}
};

class Square : public Shape {
public:
	void draw() {
		cout<<"Square\n";
	}
};

class AbstractFactory {
public:
	virtual Shape* get() = 0;
};

class ShapeAbstractFactory : public AbstractFactory {
	public:
		Shape* get(){
			if (true){
				return new Circle;
			}else {
				return new Square;
			}
		}
};

int main(){
	AbstractFactory* abstractFactory = new ShapeAbstractFactory;
	Shape* shapes[3];

	shapes[0] = abstractFactory->get();
	shapes[1] = abstractFactory->get();
	shapes[2] = abstractFactory->get();

	for (int i = 0; i < 3; i++){
		shapes[i]->draw();
	}
}
