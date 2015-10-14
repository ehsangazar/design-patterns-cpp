#include <iostream>

using namespace std;

class Singleton
{
  private:
      static bool instanceFlag;
      static Singleton *single;
  public:
      static Singleton* getInstance(){
          single = new Singleton();
          instanceFlag = true;
          return single;
      }
      void method(){
         cout << "Method of the singleton class" << endl;
      };
};

int main() {
    Singleton *sc1,*sc2;
    sc1 = Singleton::getInstance();
    sc1->method();
    sc2 = Singleton::getInstance();
    sc2->method();
    return 0;
}