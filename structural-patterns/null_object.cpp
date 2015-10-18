#include <iostream>
#include <string>

class Recipient
{
public:
        virtual ~Recipient() { }
        virtual std::string name() const=0;
};

class NullRecipient : public Recipient
{
public:
        std::string name() const { return "nobody"; }
};

class World : public Recipient
{
public:
        std::string name() const { return "world"; }
};

void hello_world(const Recipient & recipient = NullRecipient())
{
        std::cout << "Hello " << recipient.name() << "!" << std::endl;
}

int main()
{
        hello_world(World());
        return 0;
}