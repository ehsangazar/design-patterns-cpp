#include<iostream>
using namespace std;

class Object {
public:
  Object(int value_one) {
    m_value_one = value_one;
    cout << "ctor: " << m_value_one << '\n';
  }
  ~Object() {
    cout << m_value_one << ' ';
  }
  void report(int value_two) {
    cout << m_value_one << value_two << ' ';
  }
private:
  int m_value_one;
};

class FlyWeight {
  public:    
    static int X, Y;
    static Object *get_record(int in) {
      if (!myArray[in])
        myArray[in] = new Object(in);
      return myArray[in];
    }
    static void clean_up() {
      cout << "dtors: ";
      for (int i = 0; i < X; ++i){
        if (myArray[i]){
          delete myArray[i];
        }
      }
      cout << '\n'; 
    }
  private:
      static Object *myArray[];
};


int FlyWeight::X = 6, FlyWeight::Y = 10;
Object *FlyWeight::myArray[] =  {
  0, 0, 0, 0, 0, 0
};

int main() {
  for (int i = 0; i < FlyWeight::X; ++i){
    for (int j = 0; j < FlyWeight::Y; ++j)
      FlyWeight::get_record(i)->report(j);
    cout << '\n';
  }
  FlyWeight::clean_up();
}