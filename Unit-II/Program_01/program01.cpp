#include <iostream>
#include <string>

class Person {
protected:
    std::string name;

public:
    explicit Person(const std::string& personName)
        : name(personName) {}

    void displayName() const {
        std::cout << "Name: " << name << '\n';
    }
};

class Student : public Person {
private:
    int rollNumber;

public:
    Student(const std::string& studentName, int roll)
        : Person(studentName), rollNumber(roll) {}

    void display() const {
        displayName();
        std::cout << "Roll Number: " << rollNumber << '\n';
    }
};

int main() {
    Student student("Amit", 101);
    student.display();

    return 0;
}
