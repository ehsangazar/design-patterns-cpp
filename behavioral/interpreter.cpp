#include <string>
#include <iostream>
#include <stdexcept>

class Interpreter
{
public:
        template<typename It>
        void run(It from, It to)
        {
                for(It i=from; i!=to; ++i)
                {
                        switch(*i)
                        {
                        case 'h': std::cout << "Hello";         break;
                        case ' ': std::cout << ' ';                     break;
                        case 'w': std::cout << "world";         break;
                        case '!': std::cout << '!';                     break;
                        case 'n': std::cout << std::endl;       break;
                        default:  throw std::runtime_error("Unknown command");
                        }
                }
        }
};

void hello_world(const std::string & script)
{
        Interpreter().run(script.begin(), script.end());
}

int main()
{
        hello_world("h w!n");
        return 0;
}