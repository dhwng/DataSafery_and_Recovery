#include <iostream>
#include "Header.h"

using namespace std;
int main()
{
    uint64_t volumeSize = 1024 * 1024;
    VolumeSys volumeSys = VolumeSys(volumeSize);

    string name = "";
    string nn = "";
    int inputSize = 0;

    char id[9];

    int choice = 0;

    cout << sizeof(Teacher) << endl;
    cout << (volumeSize * 10) / sizeof(Teacher) << endl;
    cout << round(((volumeSize * 10) / sizeof(Teacher)) * 0.1);

    do
    {
        cout << "1. Tao va dinh dang file." << endl;
        cout << "2. Them sinh vien." << endl;
        cout << "3. Hien thi danh sach sinh vien." << endl;
        cout << "4. Xoa sinh vien." << endl;
        cout << "5. Phuc hoi sinh vien da xoa." << endl;
        cout << "6. Them giao vien." << endl;
        cout << "7. Hien thi danh sach giao vien." << endl;
        cout << "8. Xoa giao vien." << endl;
        cout << "9. Phuc hoi giao vien da xoa." << endl;

        cout << "Lua chon: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Nhap ten file (VD: filename.bin): " << endl;
            cin >> name;

            cout << "Nhap kich thuoc file (MB): " << endl;
            cin >> inputSize;

            if (createVolume(name, (volumeSize * inputSize)))
            {
                formatVolume(name, volumeSys);
            }
            cout << endl;
            break;

        case 2:
            cout << "Nhap ten file (VD: filename.bin): " << endl;
            cin >> name;
            Student student;
            volumeSys.ReadVolume(name);
            student.InputStudent();
            volumeSys.AddStudent(student, name);
            cout << endl;
            break;

        case 3:
            cout << "Nhap ten file (VD: filename.bin): " << endl;
            cin >> name;
            volumeSys.ReadVolume(name);
            volumeSys.ReadStudentList(name);
            cout << endl;
            break;

        case 4:
            cout << "Nhap ten file (VD: filename.bin): " << endl;
            cin >> name;
            cout << "Nhap ma so sinh vien cua sinh vien can xoa:" << endl;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.getline(id, sizeof(id));

            volumeSys.ReadVolume(name);
            volumeSys.DeleteOrRestoreStudent(name, id, true);
            break;

        case 5:
            cout << "Nhap ten file (VD: filename.bin): " << endl;
            cin >> name;
            cout << "Nhap ma so sinh vien cua sinh vien can phuc hoi:" << endl;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.getline(id, sizeof(id));

            volumeSys.ReadVolume(name);
            volumeSys.DeleteOrRestoreStudent(name, id, false);
            break;

        case 6:
            cout << "Nhap ten file (VD: filename.bin): " << endl;
            cin >> name;
            Teacher teacher;
            volumeSys.ReadVolume(name);

            teacher.InputTeacher();
            volumeSys.AddTeacher(teacher, name);
            volumeSys.UpdateTeacherSize(name);

            cout << endl;
            break;

        case 7:
            cout << "Nhap ten file (VD: filename.bin): " << endl;
            cin >> name;
            volumeSys.ReadVolume(name);
            volumeSys.ReadTeacherList(name);
            cout << endl;
            break;

        case 8:
            cout << "Nhap ten file (VD: filename.bin): " << endl;
            cin >> name;
            cout << "Nhap ma so cua giao vien can xoa:" << endl;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.getline(id, sizeof(id));

            volumeSys.ReadVolume(name);
            volumeSys.DeleteOrRestoreTeacher(name, id, true);
            break;

        case 9:
            cout << "Nhap ten file (VD: filename.bin): " << endl;
            cin >> name;
            cout << "Nhap ma so cua giao vien can phuc hoi:" << endl;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.getline(id, sizeof(id));

            volumeSys.ReadVolume(name);
            volumeSys.DeleteOrRestoreTeacher(name, id, false);
            break;

        default:
            break;
        }

    } while (choice != 0);

    return 0;
}