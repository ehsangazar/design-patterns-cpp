#include <iostream>
 
using namespace std;
 
class Circle {
 public:
    virtual void draw() = 0;
};
 
class StandardCircle {
public:
    StandardCircle(double radius) {
        radius_ = radius;
        cout << "StandardCircle:  create. radius = "<< radius_ << endl;
    }
    void oldDraw() {
        cout << "StandardCircle:  oldDraw. " << radius_ << endl;
    }
private:
    double radius_ ;
};
 
class CAdapter : public Circle, private StandardCircle {
public:
    CAdapter( double diameter) : StandardCircle(diameter/2) {
        cout << "CAdapter: create. diameter = " << diameter << endl;
    }
    virtual void draw() {
        cout << "CAdapter: draw." << endl;
        oldDraw();
    }
};
 
int main() {
    Circle*  c = new CAdapter(14);
    c->draw();
}