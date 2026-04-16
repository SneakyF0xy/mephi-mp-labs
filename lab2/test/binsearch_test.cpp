#include "../src/algos/binary_search.h"
#include "../src/models/student.h"
#include "../src/util/array.h"
#include <algorithm>
#include <gtest/gtest.h>
#include <vector>
#include <random>
#include <chrono>
#include <functional>

using std::cout;
using std::endl;

std::vector<Student> generate_random_list(int size) {
    std::vector<Student> lst(size);
    std::mt19937 gen{std::random_device{}()};
    std::uniform_int_distribution<int> dist(1, 100);
    
    std::generate(lst.begin(), lst.end(), [&] {
        return Student{"Last Name " + std::to_string(dist(gen)),
                       "First Name " + std::to_string(dist(gen)), 
                       dist(gen)};
    });

    return lst;
}

double measure_ms(std::function<void()> f) {
    auto start = std::chrono::high_resolution_clock::now();
    f();
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double, std::milli>(end - start).count();
}

auto make_seq(std::vector<Student> &v) {
    ArraySortedSequence<Student> seq;
    for (const Student& x : v)
        seq.Add(x);
    return seq;
}

TEST(BinarySearch, CheckContains) {
    std::vector<Student> random_list = generate_random_list(20);
    Student key = random_list.at(1337 % random_list.size());

    ArraySortedSequence<Student> seq = make_seq(random_list);
    for (int i = 0; i < seq.GetLength(); i++) {
        cout << seq.Get(i).group_number << " ";
    }
    cout << endl;
    int pos = BinarySearch(&seq, key, Mode::HALF); 
    
    cout << "Element position: " << pos << endl;
    cout << "Neighbor elements: " << seq.Get(pos - 1).group_number \
    << " " << seq.Get(pos).group_number << " " << seq.Get(pos + 1).group_number << endl;
    cout.flush();
}

TEST(BinarySearch, HalfMode) {
    std::vector<Student> random_list = generate_random_list(10000);
    Student key = random_list.at(1337 % random_list.size());
    ArraySortedSequence<Student> seq = make_seq(random_list);
    
    double sortedMs = measure_ms([&] { 
        BinarySearch(&seq, key, Mode::HALF); 
    });
    cout << "Half Mode: " << sortedMs << " ms" << endl;
    cout.flush();
}

TEST(BinarySearch, GoldenRatioMode) {
    std::vector<Student> random_list = generate_random_list(10000);
    Student key = random_list.at(1337 % random_list.size());
    ArraySortedSequence<Student> seq = make_seq(random_list);

    double sortedMs = measure_ms([&] { BinarySearch(&seq, key, Mode::GOLDEN_RATIO); });
    cout << "Golden Ratio Mode: " << sortedMs << " ms" << endl;
    cout.flush();
}

TEST(BinarySearch, FractionMode) {
    std::vector<Student> random_list = generate_random_list(10000);
    Student key = random_list.at(1337 % random_list.size());

    ArraySortedSequence<Student> seq = make_seq(random_list);

    double sortedMs = measure_ms([&] { BinarySearch(&seq, key, Mode::FRACTION, 2, 3); });
    cout << "Fraction Mode: " << sortedMs << " ms" << endl;
    cout.flush();
}

TEST(BinarySearch, FibonacciMode) {
    std::vector<Student> random_list = generate_random_list(10000);
    Student key = random_list.at(1337 % random_list.size());

    ArraySortedSequence<Student> seq = make_seq(random_list);

    double sortedMs = measure_ms([&] { BinarySearch(&seq, key, Mode::FIBONACCI, 13); });
    cout << "Fibonacci Mode: " << sortedMs << " ms" << endl;
    cout.flush();
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}