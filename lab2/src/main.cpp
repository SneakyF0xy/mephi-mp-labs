#include <iostream>
#include <vector>
#include <string>

#include "./models/student.h"
#include "./util/bst/bst.h"
#include "./util/array.h"
#include "./algos/binary_search.h"

using std::cout;
using std::cin;
using std::endl;


int main() {
    BST<int, Student> bst;
    ArraySortedSequence<Student> seq;

    cout << "1 - insert BST (key + student)" << endl;
    cout << "2 - print BST size" << endl;
    cout << "3 - search BST key" << endl;
    cout << "4 - add to array" << endl;
    cout << "5 - binary search in array" << endl;
    cout << "0 - exit\n" << endl;

    while (true) {
        int cmd;
        cout << "cmd> ";
        cin >> cmd;

        switch (cmd) {
            case 0:
                exit(0);
            
            case 1: {
                int key, group;
                std::string last, first;

                cout << "key: ";
                cin >> key;
                cout << "last name: ";
                cin >> last;
                cout << "first name: ";
                cin >> first;
                cout << "group number: ";
                cin >> group;

                Student s{last, first, group};
                bst.Insert(key, s);

                cout << "inserted into BST" << endl;
                break;
            }

            case 2: {
                cout << "BST size: " << bst.GetLength() << "" << endl;
                break;
            }

            case 3: {
                int key;
                cout << "search key: ";
                cin >> key;

                if (bst.ContainsKey(key)) {
                    Student s = bst.At(key);
                    cout << "found: " << s.last_name
                            << " " << s.first_name
                            << " group=" << s.group_number << "" << endl;
                } else {
                    cout << "not found" << endl;
                }
                break;
            }

            case 4: {
                std::string last, first;
                int group;

                cout << "last name: ";
                cin >> last;
                cout << "first name: ";
                cin >> first;
                cout << "group number: ";
                cin >> group;

                Student s{last, first, group};
                seq.Add(s);

                cout << "added to array" << endl;
                break;
            }

            case 5: {
                int group;
                cout << "search group number: ";
                cin >> group;

                Student key{"", "", group};

                int pos = BinarySearch(&seq, key, Mode::HALF);

                if (pos == -1) {
                    cout << "not found" << std::endl; 
                    continue;
                }

                cout << "found at: " << pos << endl;
                cout << "value: " << seq.Get(pos).group_number << endl;

                if (pos > 0)
                    cout << "left: " << seq.Get(pos - 1).group_number << endl;
                if (pos < seq.GetLength() - 1)
                    cout << "right: " << seq.Get(pos + 1).group_number << endl;
                break;
            }

            default:
                cout << "unknown command" << endl;;
        }
    }

    return 0;
}