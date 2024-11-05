#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <filesystem> // Include the filesystem library

#define FILENAME "students.txt"
#define MAX_STUDENTS 50

using namespace std;
namespace fs = std::filesystem; // Alias for easier usage


class StudentList{
    private:
    char* students[MAX_STUDENTS] = {0};

    void swap(char* &a, char* &b)
    {
        char* tmp;
        tmp = a;
        a = b;
        b = tmp;
    }

    int compare(char* a, char* b){
        // return 1 if a is bigger, and 2 if b is bigger, 0 if equal
        for(int i = 0; a[i] != NULL; i++)
        {
            if(a[i] > b[i])
            {
                return 1;
            }
            if (a[i] < b[i])
            {
                return 2;
            }
        }
        if(strlen(b) > strlen(a))
        {
            return 2;
        }
        return 0;
    }

    public:

    StudentList(){
    }

    ~StudentList(){
        cout << "DESTRUCTOR" << endl;
        for(int i = 0; students[i] != NULL; i++){
            delete students[i];
        }
    }

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
            file.close();
        }
        else{
            cout << "ERROR: Couldn't open file \"" << filename << "\"" << endl;
        }
    };

    void sort(){
        cout << "sort" << endl;
        int swapped;
        do
        {
            swapped = 0;
            for(int i = 0; students[i + 1] != NULL; i++)
            {
                if(compare(students[i], students[i+1]) == 1){
                    swap(students[i], students[i+1]);
                    swapped = 1;
                }
            }
        }
        while(swapped);
    };

    void print(){
        for(int i = 0; students[i] != NULL; i++){
            cout << students[i] << endl;
        }
    };

    char* find_student_name(char* student_name){
        return student_name;
    }
};


int main()
{
    cout << endl;
    
    StudentList student_list = StudentList();
    student_list.init(FILENAME);
    student_list.sort();
    student_list.print();

    // delete student_list;
    return 0;
}
