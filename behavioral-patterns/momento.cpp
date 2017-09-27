#include <iostream>
#include <string>

class Memento
{
        std::string oldString;
public:
        Memento(std::string & str, const std::string newString) : oldString(str)
        {
                str = newString;
        }
        void undo(std::string & str)
        {
                str = oldString;
        }
};

void hello_world(Memento & memento)
{
        std::string message;
        memento.undo(message);
        std::cout << message << std::endl;
}

int main()
{
        std::string hw("Hello world!");
        Memento mem(hw, "Goodbye, cruel world!");
        hello_world(mem);
        return 0;
}