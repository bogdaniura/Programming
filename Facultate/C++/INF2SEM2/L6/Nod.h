#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <Student.h>


class Nod {
public:
    Student student;
    Nod* next;

    Nod(const Student& s) : student(s), next(nullptr) {}
};