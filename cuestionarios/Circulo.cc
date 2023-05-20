#include <iostream>

class Circulo {
    private:
        double x, y;
        double radio = 1;
    public:
        Circulo() {}
        Circulo(double cx, double cy, double r) {
            x = cx;
            y = cy;
            radio = r;
        }

        double circunferencia() const {
            return 2 * 3.141592 * radio;
        }

        double area() const {
            return 3.141592 * radio * radio;
        }
};

int main() {

    Circulo c(1, 2, 3);
    std::cout << c.circunferencia() << std::endl;
    std::cout << c.area() << std::endl;
    Circulo c2;
    std::cout << c2.circunferencia() << std::endl;
    std::cout << c2.area() << std::endl;
    return 0;

}

