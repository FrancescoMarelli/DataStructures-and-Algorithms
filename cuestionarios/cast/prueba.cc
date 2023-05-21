#include <iostream>

class padre{
    public:

    virtual void display() {
        std::cout << "soy el padre"<< std::endl;
    }
};

class hijo : public padre {

    public:
    void display() {
        std::cout << "soy el hijo"<< std::endl;
    } 
};

int main() {
        hijo * hi = new hijo;
        padre* ptr = hi;
        ptr->display();

        hijo* hijo2 = dynamic_cast<hijo*>(ptr);
        hijo2->display();
    
        return 0;
}