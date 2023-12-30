#include "Header.h"

bool createVolume(const string& volumeName, uint64_t volumeSize) {
    ifstream checkFile(volumeName);
    if (checkFile.is_open())
    {
        checkFile.close();
        cout << "Volume '" << volumeName << "' da ton tai." << endl;
        return false;
    }
    ofstream volumeFile(volumeName, ios::out | ios::binary);
    if (volumeFile.is_open())
    {
        volumeFile.seekp(0, ios::beg);
        char emptyByte = 0;
        for (uint64_t i = 0; i < volumeSize; ++i)
        {
            volumeFile.write(&emptyByte, sizeof(char));
        }
        cout << "Volume " << volumeName << " duoc tao thanh cong." << endl;

        volumeFile.close();
        return true;
    }
    else
    {
        cout << "Khong the tao volume." << endl;
        return false;
    }
}

void formatVolume(const string& volumeName, VolumeSys& vls) {
    ofstream volumeFile(volumeName, ios::out | ios::binary);

    if (volumeFile.is_open()) {
        string checkfile;
        string password;

        while (true) {
            cout << "Do you want to set Password to file(Yes/No) : ";
            cin >> checkfile;
            if (checkfile == "Yes" || checkfile == "No") {
                break;
            }
            else {
                cout << "The request to select Yes or No must not select another request" << endl;
            }

        }
        if (checkfile == "Yes") {
            cout << "Password : ";
            cin >> password;
        }
        vls.setPassword(password);

        volumeFile.seekp(0, ios::beg);
        vls.WriteVolume(volumeFile);


        cout << "File '" << volumeName << "' duoc dinh dang thanh cong." << endl;
        volumeFile.close();
    }
    else
    {
        cout << "Khong the mo volume/ volume khong ton tai." << endl;
    }
}