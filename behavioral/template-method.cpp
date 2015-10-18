#include <string>
#include <iostream>

class HelloWorld
{
public:
        virtual ~HelloWorld() { }
        void output()
        {
                write_string("Hello world!");
                write_endl();
        };
        virtual void write_string(const std::string &)=0;
        virtual void write_endl()=0;
};

class HelloWorldImpl : public HelloWorld
{
public:
        void write_string(const std::string & str)
        {
                std::cout << str;
        }
        void write_endl() 
        { 
                std::cout << std::endl; 
        }
};

void hello_world(HelloWorld & hw)
{
        hw.output();
}

int main()
{
        HelloWorldImpl hw;
        hello_world(hw);
        return 0;
}