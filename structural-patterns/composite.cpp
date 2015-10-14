#include <vector>
#include <iostream> 
#include <algorithm> 
#include <functional> 
using namespace std;

class Graphic {
  public:
    virtual void draw() const = 0;
    virtual void remove(Graphic *g) {}
    virtual void add(Graphic *g) {}
    virtual void getChild(int) {}
    virtual ~Graphic() {}
};

class Line : public Graphic {
  public:
    void draw() const {
      cout << "Line draw()\n";
    }
};

class Rectangle : public Graphic {
  public:
    void draw() const {
      cout << "Rectangle draw() \n";
    }
};

class Text : public Graphic {
  public:
    void draw() const {
      cout << "Text draw() \n";
    }
};

// Composite
class Picture : public Graphic {
  public:
    void draw() const {
      // for each element in gList, call the draw member function
      for_each(gList.begin(), gList.end(), mem_fun(&Graphic::draw));
    }

    void add(Graphic *aGraphic) {
      gList.push_back(aGraphic);
    }

  private:
    vector<Graphic*> gList;
};

int main()
{
  Line line;
  line.draw();
  Rectangle rect;
  rect.draw();
  Text text;
  text.draw();
  cout<<"Composite:"<<endl;
  Picture pic;
  pic.add(&line);
  pic.add(&rect);
  pic.add(&text);
  pic.add(&rect);
  pic.draw();

  return 0;
}