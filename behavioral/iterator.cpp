#include <iostream>
#include <cstring>

class StringIterator
{
        const char *position, *end;
public:
        StringIterator(const char * str) : 
                position(str), 
                end(str + strlen(str))  { }
        bool at_end() const { return position == end; }
        void advance() { ++position; }
        char get_char() const { return *position; }
};

void hello_world(StringIterator & iterator)
{
        for(StringIterator i=iterator; !i.at_end(); i.advance())
        {
                std::cout << i.get_char();
        }
}

int main()
{
        StringIterator iterator("Hello world!\n");
        hello_world(iterator);
        return 0;
}
