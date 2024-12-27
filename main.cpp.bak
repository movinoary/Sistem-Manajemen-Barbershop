#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

string db_userAccount[5][5] = {
    // idUser, nama,  password, role, idKaryawan
    {"UR-01", "admin", "admin123", "admin", "-"},
    {"UR-02", "adit", "adit123", "staff", "ST-01"},
    {"UR-03", "alif", "alif123", "staff", "ST-02"},
    {"UR-04", "sisil", "sisil123", "staff", "ST-03"},
    {"UR-05", "vino", "vino123", "staff", "ST-04"}
};
string db_karyawan[4][4] = {
    // idKaryawan, namaLengkap, statusKerja, idShift
    {"ST-01", "Adit Praditia" "active", "SF-01"},
    {"ST-02", "Muhammad Nur Alif", "active", "SF-01"},
    {"ST-03", "Suci Fransica Sisilia", "active", "SF-02"},
    {"ST-04", "Mohammad Vino Arystio", "active", "SF-02"}
};
string db_dataShift[2][3] = {
    // idShift, waktuMulai, waktuAkhir, 
    {"SF-01", "08:00", "14:00"},
    {"SF-02", "14:00", "20:00"}
};
string db_istService[4][3] = {
    // idService, jenisLayanan, harga
    {"LS-01", "Cukur Anak-anak", "30000"},
    {"LS-02", "Cukur Anak-anak + Cuci", "35000"},
    {"LS-03", "Cukur Dewasa", "40000"},
    {"LS-04", "Cukur Dewasa + Cuci", "45000"},
};
string db_customer[0][3] = {
    // idCustomer, nama, customerRating
    // {"CS-01", "asep", "7"}
};
string db_queue[0][5] = {
    // idQueue, number, idCustomer, idShift, idService, status
    // {"QU-01", "25122024-10001" "CS-01", "SF-01", "LS-03", "wating"}
};
string db_userlogin[5];

void login();
void menuAdmin();
void menuStaff();
void staffManagement();
void serviceReport();
void queueManagement();
void bookingManagement(); 
void logout(); 

int main() {
    int choice;
    cout << "1. Login" << endl;
    cout << "0. Quit" << endl;
    cout << "Enter Your Choice : ";
    cin >> choice;

    switch (choice){
    case 1:
        login();
        break;
    case 0:
        cout << "Thankyou for coming!";
        break;
    default:
        system("cls");
        cout << "Your input not found!" << endl;
        main();
    }
    
    return 0;
}


// =============== AUTH FUNCTION ===============
void login() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    string message = "username tidak ditemukan!";
    bool found = false;

    for (int i = 0; i < 5; i++) {
        if (username == db_userAccount[i][1]) {
            found = true;
            if (password == db_userAccount[i][2]) {
                for(int a=0; a < 5; a++){
                    db_userlogin[a] = db_userAccount[i][a];
                }
                message = "Login berhasil!\nSelamat Datang " + db_userAccount[i][1];
            } else {
                found = false;
                message = "password tidak sesuai!";
            }
            // cout << message << endl;
            // break;
        }
    }

    if (!found) {
        system("cls");
        cout << message << endl;
        main();
    } else {
        if(db_userlogin[3] == "admin"){
            cout << message << endl;
            menuAdmin();
        } else if (db_userlogin[3] == "staff"){
            cout << message << endl;
            menuStaff();
        }
    }
}

void logout(){
    system("cls");
    cout << "Thankyou for coming!" << endl;
    for(int a=0; a < 5; a++){
        db_userlogin[a] = "";
    }
}

// =============== MENU ADMIN ===============
void menuAdmin () {
    system("cls");
    int choice;
    cout << "Welcome Admin" << endl;
    cout << "1. Staff Management" << endl;
    cout << "2. Service Report" << endl;
    cout << "99. Logout" << endl;
    cout << "0. Quit" << endl;
    cout << "Enter Your Choice : ";
    cin >> choice;

    switch (choice){
        case 1:
            staffManagement();
            break;
        case 2:
            serviceReport();
            break;
        case 99:
            logout();
            main();
        case 0:
            cout << "Thankyou for coming!";
            break;
        default:
            system("cls");
            cout << "Your input not found!" << endl;
            menuAdmin();
    }
}

// =============== STAFF FUNCTION
void dataStaff() {};
void dataShift() {};

void staffManagement(){    
    system("cls");
    int choice;
    cout << "Staff Management" << endl;
    cout << "1. Data Staff" << endl;
    cout << "2. Data Shift" << endl;
    cout << "10. Menu" << endl;
    cout << "99. Logout" << endl;
    cout << "0. Quit" << endl;
    cout << "Enter Your Choice : ";
    cin >> choice;

    switch (choice){
        case 1:
            dataStaff();
            break;
        case 2:
            dataShift();
            break;
        case 10:
            menuAdmin();
            break;
        case 99:
            logout();
            main();
        case 0:
            cout << "Thankyou for coming!";
            break;
        default:
            system("cls");
            cout << "Your input not found!" << endl;
            staffManagement();
    }
}

// =============== REPORT FUNCTION

void reportService(){};
void trackingStaff(){};

void serviceReport(){
    system("cls");
    int choice;
    cout << "Service Report" << endl;
    cout << "1. Report Customer" << endl;
    cout << "2. Tracking Staff" << endl;
    cout << "10. Menu" << endl;
    cout << "99. Logout" << endl;
    cout << "0. Quit" << endl;
    cout << "Enter Your Choice : ";
    cin >> choice;

    switch (choice){
        case 1:
            reportService();
            break;
        case 2:
            trackingStaff();
            break;
        case 10:
            menuAdmin();
            break;
        case 99:
            logout();
            main();
        case 0:
            cout << "Thankyou for coming!";
            break;
        default:
            system("cls");
            cout << "Your input not found!" << endl;
            serviceReport();
    }
}

// =============== MENU STAFF ===============
void menuStaff() {
    system("cls");
    int choice;
    cout << "Welcome Staff" << endl;
    cout << "1. Queue Management" << endl;
    cout << "2. Booking Management" << endl;
    cout << "99. Logout" << endl;
    cout << "0. Quit" << endl;
    cout << "Enter Your Choice : ";
    cin >> choice;

    switch (choice){
        case 1:
            queueManagement();
            break;
        case 2:
            bookingManagement();
            break;
        case 99:
            logout();
            main();
        case 0:
            cout << "Thankyou for coming!";
            break;
        default:
            system("cls");
            cout << "Your input not found!" << endl;
            menuStaff();
    }
}

// =============== QUEUE FUNCTION
void addQueue(){};
void nextQueue(){};
void doneQueue(){};

void queueManagement() {
    system("cls");
    int choice;
    cout << "Queue Management" << endl;
    cout << "Queue Active : 10" << endl;
    cout << "Queue Complate : 10" << endl;
    cout << "Queue : 0010" << endl;
    cout << "1. Add Queue" << endl;
    cout << "2. Next Queue" << endl;
    cout << "3. Done Queue" << endl;
    cout << "10. Menu" << endl;
    cout << "99. Logout" << endl;
    cout << "0. Quit" << endl;
    cout << "Enter Your Choice : ";
    cin >> choice;


    switch (choice){
        case 1:
            addQueue();
            break;
        case 2:
            nextQueue();
            break;
        case 3:
            doneQueue();
        case 10:
            menuStaff();
        case 99:
            logout();
            main();
        case 0:
            cout << "Thankyou for coming!";
            break;
        default:
            system("cls");
            cout << "Your input not found!" << endl;
            queueManagement();
    }
};

// =============== BOOKING FUNCTION

void newBooking() {};
void confBooking() {};
void timeTabel() {};

void bookingManagement() {
    system("cls");
    int choice;
    cout << "Booking Management" << endl;
    cout << "1. New Booking" << endl;
    cout << "2. Confirmation Booking" << endl;
    cout << "3. Timetable " << endl;
    cout << "10. Menu" << endl;
    cout << "99. Logout" << endl;
    cout << "0. Quit" << endl;
    cout << "Enter Your Choice : ";
    cin >> choice;

    switch (choice){
        case 1:
            newBooking();
            break;
        case 2:
            confBooking();
            break;
        case 3:
            timeTabel();
        case 10:
            menuStaff();
        case 99:
            logout();
            main();
        case 0:
            cout << "Thankyou for coming!";
            break;
        default:
            system("cls");
            cout << "Your input not found!" << endl;
            bookingManagement();
    }
};