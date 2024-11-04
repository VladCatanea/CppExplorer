#include <iostream>
#include <fstream>
#include <string>
#include <filesystem> // Include the filesystem library

#define FILENAME "students.txt"
#define MAX_STUDENTS 50

using namespace std;
namespace fs = std::filesystem; // Alias for easier usage

class StudentList{
    private:
    char* students[MAX_STUDENTS];

    public:

    StudentList(){
    }

    ~StudentList(){}

    void init(string filename){
        ifstream file (filename);
        string buffer;
        char* student_name;
        int i = 0;

        cout << "Current directory: " << fs::current_path() << endl;

        if(file.is_open()){

            while(getline(file, buffer) && i < MAX_STUDENTS){
                student_name = new char[buffer.size()];
                buffer.copy(student_name, buffer.size());
                students[i] = student_name;
                i++;
            }
            students[i] = NULL;
            file.close();
        }
        else{
            cout << "ERROR: Couldn't open file \"" << filename << "\"" << endl;
        }
    };

    void print(){
        for(int i = 0; students[i] != NULL; i++){
            cout << students[i] << endl;
        }
    };
};


int main()
{
    cout << endl;
    
    StudentList student_list = StudentList();
    student_list.init(FILENAME);
    student_list.print();

    return 0;
}
