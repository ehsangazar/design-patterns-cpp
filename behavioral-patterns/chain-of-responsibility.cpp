#include <string>
#include <iostream>

class Output
{
public:
        void output(const std::string & str)
        {
                std::cout << str << std::endl;
        }
};

class World
{
        Output & out;
public:
        World(Output & out) : out(out) { }
        void output(const std::string & str)
        {
                out.output(str + " world!");
        }
};

class Hello
{
        World & world;
public:
        Hello(World & world) : world(world) { }
        void output()
        {
                world.output("Hello");
        }
};

void hello_world(Hello & hello)
{
        hello.output();
}

int main()
{
        Output output;
        World world(output);
        Hello hello(world);
        hello_world(hello);
        return 0;
}