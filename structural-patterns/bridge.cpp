#include <iostream>
#include <string>
using namespace std;

class AbstractInterface {
    public:
        virtual void someFunctionality() = 0;
};

class ImplementationInterface
{
    public:
        virtual void anotherFunctionality() = 0;
};

class Bridge : public AbstractInterface
{
    protected:
        ImplementationInterface* implementation;
    
    public:
        Bridge(ImplementationInterface* backend) {
            implementation = backend;
        }
};

class UseCase1 : public Bridge {
    public:
        UseCase1(ImplementationInterface* backend) : Bridge(backend) {}

        void someFunctionality(){
            cout << "UseCase1 on ";
            implementation->anotherFunctionality();
        }
};

class UseCase2 : public Bridge {
    public:
        UseCase2(ImplementationInterface* backend): Bridge(backend) {}

        void someFunctionality() {
            cout << "UseCase2 on ";
            implementation->anotherFunctionality();
        }
};

class Windows : public ImplementationInterface {
    public:
        void anotherFunctionality(){
            cout << "Windows :-!" << endl;
        }
};

class Linux : public ImplementationInterface
{
    public:
        void anotherFunctionality() {
            cout << "Linux! :-)" << endl;
        }
};

int main() {
    AbstractInterface *useCase = 0;
    ImplementationInterface *osWindows = new Windows;
    ImplementationInterface *osLinux = new Linux;


    /* First case */
    useCase = new UseCase1(osWindows);
    useCase->someFunctionality();

    useCase = new UseCase1(osLinux);
    useCase->someFunctionality();

    /* Second case */
    useCase = new UseCase2(osWindows);
    useCase->someFunctionality();

    useCase = new UseCase2(osLinux);
    useCase->someFunctionality();

    return 0;
}