#include <iostream>
#include <string>

class Observer
{
public:
        virtual ~Observer() { }
        virtual void on_message(const std::string &)=0;
};

class MessageBoard
{
        Observer & observer;
public:
        MessageBoard(Observer & obs) : observer(obs) { }

        void post(const std::string & str)
        {
                observer.on_message(str);
        };
};

class Writer : public Observer
{
public:
        void on_message(const std::string & str)
        {
                std::cout << str << std::endl;
        }
};

void hello_world(MessageBoard & message_board)
{
        message_board.post("Hello world!");
}

int main()
{
        Writer writer;
        MessageBoard message_board(writer);
        hello_world(message_board);
        return 0;
}