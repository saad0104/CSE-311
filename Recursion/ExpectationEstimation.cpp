#include <iostream>

int main() {
    // Calculate the sum of constant terms divided by the number of scenarios
    double a = (4.0 + 5 + 7 + 15) / 4;
    // Calculate the total probability of scenarios with recursive E(T)
    double b = 3.0 / 4;
    // Solve for E using the formula E = a / (1 - b)
    double E = a / (1 - b);
    
    std::cout << "Expected time E(T) = " << E << " minutes" << std::endl;
    return 0;
}