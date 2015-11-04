
#include <iostream>
#include <string>

class Printer
{
public:
        void print(const std::string & str) const
        {
                std::cout << str << std::endl;
        }
};

class Message
{
public:
        virtual ~Message() { }
        virtual void print(const class Mediator & mediator) const;
};

class Mediator
{
        const Printer & printer;
        const Message & message;
public:
        Mediator(const Printer & pr, const Message & msg) :
                printer(pr),
                message(msg) { }
        void print() const
        {
                message.print(*this);
        }
        void print(const std::string & str) const
        {
                printer.print(str);
        }
};

void Message::print(const Mediator & mediator) const
{
        mediator.print("Hello world!");
}

void hello_world(const Mediator & mediator)
{
        mediator.print();
}

int main()
{
        Printer printer;
        Message message;
        hello_world(Mediator(printer,message));
        return 0;
}