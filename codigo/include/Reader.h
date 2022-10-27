#ifndef PROJETOAED_READER_H
#define PROJETOAED_READER_H

#include <string>
#include <vector>
#include "Class.h"
#include "Student.h"

using namespace std;

class Reader {
public:
    vector<Class> ReadClasses();
    vector<Student> ReadStudent();
};


#endif //PROJETOAED_READER_
