# 1 "main.cpp"
# 1 "<built-in>"
# 1 "<命令行>"
# 1 "main.cpp"
# 1 "student.h" 1
# 1 "human.h" 1


class Human {
public:
 void eat (void) {}
};
# 2 "student.h" 2
class Student : public Human {
public:
 void learn (void) {}
};
# 2 "main.cpp" 2
# 1 "teacher.h" 1

class Teacher : public Human {
public:
 void teach (void) {}
};
# 3 "main.cpp" 2
int main (void) {
 Student s;
 Teacher t;
 return 0;
}
