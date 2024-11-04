#include <iostream>
#include <fstream>
#include <string>

#define FILENAME "students.txt"
#define MAX_STUDENTS 50

using namespace std;

class StudentList{
    private:
    char* students[MAX_STUDENTS];

    public:
    void init(string filename){
        ifstream file (filename);
        string buffer;
        char* student_name;
        int i = 0;

        cout << "File open success?: " << file.is_open() << endl;

        if(file.is_open()){

            while(getline(file, buffer) && i < MAX_STUDENTS){
                cout << "Reading line " << i << endl;
                student_name = new char[buffer.size()];
                buffer.copy(student_name, buffer.size());
                students[i] = student_name;
                i++;
            }
            cout << "end: " << i << endl;
            students[i] = NULL;
            file.close();
        }
        else{
            cout << "ERROR: Couldn't open file \"" << filename << "\"" << endl;
        }
    };

    void print(){
        cout << students[0];
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
