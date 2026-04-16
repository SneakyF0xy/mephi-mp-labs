#ifndef MODELS_STUDENT_H_
#define MODELS_STUDENT_H_

#include <bits/std_thread.h>
#include <string>

class Student {
  public:
    std::string last_name;
    std::string first_name;
    int group_number;
    Student() : last_name(""), first_name(""), group_number(0) {}

    Student(std::string ln, std::string fn, int gn) 
        : last_name(std::move(ln)), first_name(std::move(fn)), group_number(gn) {}

    bool operator<(const Student& other) const {
        return this->group_number < other.group_number;
    }

    bool operator<=(const Student& other) const {
      return this->group_number <= other.group_number;
    }

    bool operator>(const Student& other) const {
      return this->group_number > other.group_number;
    }

    bool operator>=(const Student& other) const {
      return this->group_number >= other.group_number;
    }

    bool operator==(const Student& other) const {
        return this->group_number == other.group_number;
    }

    operator int() const { return group_number; }
    operator std::string() const { return last_name; }
};

#endif