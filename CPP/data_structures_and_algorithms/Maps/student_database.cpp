#include <iostream>
#include <map>
#include <string>

using namespace std;

struct Student
{
  string name;
  int age;
  string grade;

  Student(const string &n, int a, const string &g) : name(n), age(a), grade(g) {}
};

int main()
{
  map<int, Student> studentDB;

  // Add students to the database
  studentDB[101] = Student("Alice", 20, "A");
  studentDB[102] = Student("Bob", 21, "B");
  studentDB[103] = Student("Charlie", 19, "A");

  // Access and display student information
  cout << "Student Database:" << endl;
  for (const auto &pair : studentDB)
  {
    int studentID = pair.first;
    const Student &student = pair.second;

    cout << "Student ID: " << studentID << endl;
    cout << "Name: " << student.name << endl;
    cout << "Age: " << student.age << endl;
    cout << "Grade: " << student.grade << endl;
    cout << endl;
  }

  // Find a student by ID
  int searchID = 102;
  auto it = studentDB.find(searchID);
  if (it != studentDB.end())
  {
    cout << "Student found!" << endl;
    cout << "Name: " << it->second.name << endl;
    cout << "Age: " << it->second.age << endl;
    cout << "Grade: " << it->second.grade << endl;
  }
  else
  {
    cout << "Student not found." << endl;
  }

  return 0;
}

/**
 * @brief Student database using maps explanation
 *
 * In this program, we define a Student struct to represent the student information, including the name, age, and grade.
 * The student database is created using a map<int, Student>, where the keys are
 * student IDs (integer values) and
 * the values are instances of the Student struct.
 *
 * The program demonstrates adding students to the database, accessing and displaying the student information using a loop, and
 * finding a student by ID.
 * The student database is implemented using a map, which provides efficient lookup and retrieval of student information based on their IDs.
 *
 * In the given example, the student database includes three students with their respective information.
 * The program outputs the student database and searches for a student with ID 102, displaying their information if found.
 *
 * Remember to include appropriate headers (<map> and <string>) and namespace declarations (using namespace std;)
 * for the program to compile and run successfully.
 *
 */
