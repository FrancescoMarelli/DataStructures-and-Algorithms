#include <iostream>
#include <vector>

void ord(std::vector<int>& sec, int size) {

    int ini = 1;
    int fin = size-1;
    int cam = size;

    while(ini < fin) {
        for(int i = ini-1; i <= fin; ++i) {
            int min = i;
            for(int j = i+1; j <= fin; j++) {
                if(sec[j] < sec[min])
                    min = j;
            }
            std::swap(sec[i], sec[min]);
        }
        ini = cam+1;

        for(int i = fin; i >= ini; --i) {
            int max = i;
            for(int j = i-1; j >= ini; j--) {
                if(sec[j] > sec[max])
                    max = j;
            }
            std::swap(sec[i], sec[max]);
        }
        fin = cam - 1;
    }

    for(auto& i : sec)
        std::cout << i << " ";
    std::cout << std::endl;

}


int main() {
    std::vector<int> sec = {11, 21, 13, 9, 7, 8, 15, 17, 19, 1};
    int size = sec.size();

    ord(sec, size);


    return 0;
}