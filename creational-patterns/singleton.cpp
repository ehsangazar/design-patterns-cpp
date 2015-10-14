#include <iostream>
#include <string>
using namespace std;

class GlobalClass
{
    int m_value;
    static GlobalClass *s_instance;
    GlobalClass(int v = 0) {
        m_value = v;
    }
  public:
    int get_value() {
        return m_value;
    }
    void set_value(int v) {
        m_value = v;
    }
    static GlobalClass *instance() {
        if (!s_instance)
          s_instance = new GlobalClass;
        return s_instance;
    }
};

GlobalClass *GlobalClass::s_instance = 0;

void foo(void) {
  GlobalClass::instance()->set_value(1);
  cout << "foo: global_ptr is " << GlobalClass::instance()->get_value() << '\n';
}

void bar(void) {
  GlobalClass::instance()->set_value(2);
  cout << "bar: global_ptr is " << GlobalClass::instance()->get_value() << '\n';
}

int main() {
  cout << "main: global_ptr is " << GlobalClass::instance()->get_value() << '\n';
  foo();
  bar();
}