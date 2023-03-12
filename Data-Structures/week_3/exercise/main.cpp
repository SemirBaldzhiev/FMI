#include <iostream>
#include <set>

int countBeautifulMasks(int masks[], int n) {
    std::set<int> s;
    s.insert(0);
    unsigned invertMask = 0;
    for (unsigned i = 0; i < n; ++i) {
        invertMask = ~masks[i];
        s.insert(masks[i]);
        for (unsigned j = 1; j <= masks[i]; ++j) {

            if (((invertMask & j) != j)) {
                if (((invertMask & j)^j) == j){
                    s.insert(j);
                }
            }
        }
    }

    return s.size();
}

int main() {
    int n;

    std::cin >> n;
    int masks[n];

    for (int i = 0; i < n; ++i) {
        std::cin >> masks[i];
    }

    std::cout << countBeautifulMasks(masks, n) << '\n'; 
}