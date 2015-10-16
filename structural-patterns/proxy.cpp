#include<iostream>
#include<string>
using namespace std;

class RealImage {
    int m_id;
    public:
        RealImage(int i) {
            m_id = i;
            cout << "   $$ ctor: " << m_id << '\n';
        }
        ~RealImage() {
            cout << "   dtor: " << m_id << '\n';
        }
        void draw() {
            cout << "   drawing image " << m_id << '\n';
        }
};

class Image {
    RealImage *m_the_real_thing;
    int m_id;
    static int s_next;
    public:
        Image() {
            m_id = s_next++;
            m_the_real_thing = 0;
        }
        ~Image() {
            delete m_the_real_thing;
        }
        void draw() {
            if (!m_the_real_thing)
                m_the_real_thing = new RealImage(m_id);
            m_the_real_thing->draw();
        }
};
int Image::s_next = 1;

int main() {
    Image images[5];
    for (int i; true;) {
        cout << "Exit[0], Image[1-5]: ";
        cin >> i;
        if (i == 0)
            break;
        images[i - 1].draw();
    }
}