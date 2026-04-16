#include <iostream>
#include <string>

int main() {
    std::cout << "Lab4 - OpenMP Examples" << std::endl;
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
            std::cout << "\n=== Example 1.1: Hello World with threads ===" << std::endl;
            system("g++ -fopenmp src/example_1_1.cpp -o build/example_1_1 && LD_LIBRARY_PATH=build ./build/example_1_1");
            break;
        case 2:
            std::cout << "\n=== Example 1.2: Vector summation with reduction ===" << std::endl;
            system("g++ -fopenmp src/example_1_2.cpp -o build/example_1_2 && LD_LIBRARY_PATH=build ./build/example_1_2");
            break;
        case 3:
            std::cout << "\n=== Example 1.3: Vector summation in function ===" << std::endl;
            system("g++ -fopenmp src/example_1_3.cpp -o build/example_1_3 && LD_LIBRARY_PATH=build ./build/example_1_3");
            break;
        case 4:
            std::cout << "\n=== Example 1.4: Vector summation with sections ===" << std::endl;
            system("g++ -fopenmp src/example_1_4.cpp -o build/example_1_4 && LD_LIBRARY_PATH=build ./build/example_1_4");
            break;
        case 5:
            std::cout << "\n=== Example 1.5: Matrix-vector multiplication ===" << std::endl;
            system("g++ -fopenmp src/example_1_5.cpp -o build/example_1_5 && LD_LIBRARY_PATH=build ./build/example_1_5");
            break;
        default:
            std::cout << "Invalid choice! Please select 1-5." << std::endl;
    }
    
    return 0;
}