#include <iostream>
#include <string>

int main() {
    std::cout << "Choose example to run (1-5): " << std::endl;
    std::cout << "1. Hello World with threads" << std::endl;
    std::cout << "2. Vector summation with reduction" << std::endl;
    std::cout << "3. Vector summation in function" << std::endl;
    std::cout << "4. Vector summation with sections" << std::endl;
    std::cout << "5. Matrix-vector multiplication" << std::endl;
    
    int choice;
    std::cout << "Enter choice (1-5): ";
    std::cin >> choice;
    
    switch(choice) {
        case 1:
            system("LD_LIBRARY_PATH=build ./build/example_1_1");
            break;
        case 2:
            system("LD_LIBRARY_PATH=build ./build/example_1_2");
            break;
        case 3:
            system("LD_LIBRARY_PATH=build ./build/example_1_3");
            break;
        case 4:
            system("LD_LIBRARY_PATH=build ./build/example_1_4");
            break;
        case 5:
            system("LD_LIBRARY_PATH=build ./build/example_1_5");
            break;
        default:
            std::cout << "Invalid choice! Please select 1-5." << std::endl;
    }
    
    return 0;
}