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

string db_userAccount[6][5] = {
    // idUser, nama,  password, role, idKaryawan
    {"UR-1", "admin", "admin123", "admin", "-"},
    {"UR-2", "adit", "adit123", "staff", "ST-1"},
    {"UR-3", "alif", "alif123", "staff", "ST-2"},
    {"UR-4", "sisil", "sisil123", "staff", "ST-3"},
    {"UR-5", "vino", "vino123", "staff", "ST-4"},
    {"UR-6", "iqbaal", "iqbaal", "staff", "ST-3"},
};
string db_karyawan[4][4] = {
    // idKaryawan, namaLengkap, statusKerja, idShift
    {"ST-1", "Adit Praditia", "active", "Shift-1"},
    {"ST-2", "Muhammad Nur Alif", "active", "Shift-1"},
    {"ST-3", "Suci Fransica Sisilia", "active", "Shift-2"},
    {"ST-4", "Mohammad Vino Arystio", "active", "Shift-2"}
};
string db_dataShift[2][8] = {
    // idShift, waktuMulai, waktuAkhir, 
    {"Shift-1", "08", "09", "10", "11", "12", "13", "14"},
    {"Shift-2", "15", "16", "17", "18", "19", "20", "20"},
};
string db_listService[4][3] = {
    // idService, jenisLayanan, harga
    {"LS-1", "Cukur Anak-anak", "30000"},
    {"LS-2", "Cukur Anak-anak + Cuci", "35000"},
    {"LS-3", "Cukur Dewasa", "40000"},
    {"LS-4", "Cukur Dewasa + Cuci", "45000"},
};
string db_transaksi[100][7] = {
    // idQueue, nama,  code, idShift, idService, status, idKaryawan
    // {"QU-1",  "asep", "25122024-10001", "SF-1", "LS-3", "wating", "ST-2"}
};
string db_userlogin[5];
int nQueue = 0;
string codeQueue;
int acQueue = 0;
int doQueue = 0;

void login();
void menuAdmin();
void menuStaff();
void staffManagement();
void serviceReport();
void queueManagement();
void bookingManagement(); 
void logout(); 

// =============== UNIVERSAL FUNCTION ===============
string idShift(string time) {
    string id;
    for(int i=0; i < 2; i++){
        for(int a=1; a < 7; a++){
            if(time == db_dataShift[i][a]){
                id = db_dataShift[i][0];
            }
        }
    }
    return id;
};
string nameSatff(const string& idStaff) {
    string name;
    for(int i=0; i < 4; i++){
        if(idStaff == db_karyawan[i][0]){
            name = db_karyawan[i][1];
        }
    }
    return name;
};

// =============== RUN ===============
int main() {
    int choice;
    cout << "=============================" << endl;
    cout << "=== Welcome to App Barber ===" << endl;
    cout << "=============================" << endl;
    cout << "" << endl;
    cout << "1. Login" << endl;
    cout << "0. Quit" << endl;
    cout << "" << endl;
    cout << "=============================" << endl;
    cout << "Enter Your Choice : ";
    cin >> choice;

    switch (choice){
    case 1:
        login();
        break;
    case 0:
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
                message = "password tidak sesuai !";
            }
            // cout << message << endl;
            // break;
        }
    }

    if (!found) {
        system("cls");
        cout << "=============================" << endl;
        cout << "===" << message << "===" << endl;
        cout << "=============================" << endl;
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
        cout << "=============================" << endl;
        cout << "=== Thankyou for coming! ====" << endl;
        cout << "=============================" << endl;
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
            break;
        default:
            system("cls");
            cout << "Your input not found!" << endl;
            menuAdmin();
    }
}

// =============== STAFF FUNCTION
void editStaff() {
    int idStaff = 5;
    string id, name, status, shift;
    cout << "Enter ID Staff: ";
    cin >> id;
    cout << "Enter Full Name: ";
    cin >> name;
    cout << "Enter Status: ";
    cin >> status;
    cout << "=============================" << endl;
    cout << "ID Shift" << " || " << "Start Time"  << " - " << "End Time" <<  endl;
    for(int a=0; a < 2; a++){
        cout <<  db_dataShift[a][0] << " || " << db_dataShift[a][1] << " - " << db_dataShift[a][7]  << endl;
    }
    cout << "=============================" << endl;
    cout << "Enter ID Shift: ";
    cin >> shift;
}

void dataStaff() {
    system("cls");
    int choice;
    cout << "=============================" << endl;
    cout << "======== List Staff  ========" << endl;
    cout << "=============================" << endl;
    cout << "No" << " || " << "Full Name"  << " || " << "Status"  <<  " || " << "Shift"  <<  endl;
    for(int a=0; a < 4; a++){
        cout << a;
        for(int i=1; i < 7; i++){
            cout << db_karyawan[a][i] << " || ";
        }
        cout << endl;
    }
    cout << "=============================" << endl;
    cout << "" << endl;
    cout << "1. Edit Staff" << endl;
    cout << "20. Back" << endl;
    cout << "" << endl;
    cout << "=============================" << endl;

    cout << "" << endl;
    cout << "Enter Your Choice : ";
    cin >> choice;

    switch (choice){
        case 1:
            editStaff();
            break;
        case 20:
            staffManagement();
            break;
        default:
            system("cls");
            cout << "Your input not found!" << endl;
            dataStaff();
    }
}
void dataShift() {
    system("cls");
    int choice;
    cout << "=============================" << endl;
    cout << "======== List Shift  ========" << endl;
    cout << "=============================" << endl;
    cout << "=============================" << endl;
    cout << "ID Shift" << " || " << "Start Time"  << " - " << "End Time" <<  " || " << "Staff Operation"<< endl;
    for(int a=0; a < 2; a++){
        cout <<  db_dataShift[a][0] << " || " << db_dataShift[a][1] << " - " << db_dataShift[a][7] << " || ";
        for(int i=0; i<4; i++){
            if (db_dataShift[a][0] == db_karyawan[i][3]){
                cout << db_karyawan[i][1] << "  ";
            }
        }
        cout << endl;
    }
    cout << "=============================" << endl;
    cout << "" << endl;
    cout << "20. Back" << endl;
    cout << "" << endl;
    cout << "=============================" << endl;
    cout << "" << endl;
    cout << "Enter Your Choice : ";
    cin >> choice;

    switch (choice){
        case 20:
            staffManagement();
            break;
        default:
            cout << "Your input not found!" << endl;
            dataShift();
    }
};

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
    cout << "=============================" << endl;
    cout << "===== Welcome to Staff  =====" << endl;
    cout << "=============================" << endl;
    cout << "" << endl;
    cout << "1. Queue Management" << endl;
    cout << "2. Booking Management" << endl;
    cout << "99. Logout" << endl;
    cout << "0. Quit" << endl;
    cout << "" << endl;
    cout << "=============================" << endl;
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
            break;
        default:
            system("cls");
            cout << "Your input not found!" << endl;
            menuStaff();
    }
}

// =============== QUEUE FUNCTION
void addQueue(){
    system("cls");
    string name, date, time;
    int service;
    cout << "=============================" << endl;
    cout << "========= Add Queue  ========" << endl;
    cout << "=============================" << endl;
    cout << "" << endl;
    cout << "20. Back" << endl;
    cout << "" << endl;
    cout << "=============================" << endl;
    cout << "Enter name: ";
    cin >> name;

    if (name == "20") {
        return queueManagement();
    }
    cout << "Enter date (ex : 251224): ";
    cin >> date;
    cout << "Enter time (ex : 09 (Only Hours)): ";
    cin >> time;
    for(int a=0; a < 4; a++){
        cout << a << "." << db_listService[a][1] << endl;
    }
    cout << "Enter service: ";
    cin >> service;

    string queue = to_string(nQueue + 1);
    string code = date + "-" + time + queue; 
    string idQue = "QU-" + queue; 

    db_transaksi[nQueue][0] = idQue;
    db_transaksi[nQueue][1] = name;
    db_transaksi[nQueue][2] = code;
    db_transaksi[nQueue][3] = idShift(time);
    db_transaksi[nQueue][4] = db_listService[service][1];
    db_transaksi[nQueue][5] = "waiting";
    db_transaksi[nQueue][6] = "---";

    for(int a=0; a < 6; a++){
        cout  << db_transaksi[nQueue][a] << endl;
    }
    
    nQueue++;
    queueManagement();
};
void nextQueue(){
    system("cls");
    string code, staff;
    bool isFound = false;
    cout << "=============================" << endl;
    cout << "======== Next Queue  ========" << endl;
    cout << "=============================" << endl;
    cout << "Code" << " || " << "Customer Name"  << endl;
    for(int a=0; a < nQueue; a++){
        if("waiting" == db_transaksi[a][5]){
            cout << db_transaksi[a][1] << " || " << db_transaksi[a][2]  << endl;
        }
    }
    cout << "=============================" << endl;
    cout << "" << endl;
    cout << "20. Back" << endl;
    cout << "" << endl;
        cout << "=============================" << endl;
    cout << "Enter Code : ";
    cin >> code;
    if (code == "20") {
        return queueManagement();
    }
    cout << "=============================" << endl;
    cout << "Code" << " || " << "Staff Name"  << endl;
    for(int a=0; a < 4; a++){
        cout << db_karyawan[a][0] << " || " << db_karyawan[a][1]  << endl;
    }
    cout << "=============================" << endl;

    cout << "Staff Code : ";
    cin >> staff;

    for(int a=0; a < nQueue; a++){
        if(code == db_transaksi[a][2]){
            isFound = true;
            db_transaksi[a][5] = "prosess"; 
            db_transaksi[a][6] = nameSatff(staff); 
        }
    }
    if(isFound){
        acQueue++;
    }
    if(code != "20"){
        codeQueue = code;
    }
    queueManagement();
};
void doneQueue(){
    system("cls");
    string code;
    bool isFound = false;
    cout << "=============================" << endl;
    cout << "======== Done Queue  ========" << endl;
    cout << "=============================" << endl;
    cout << "Code" << " || " << "Customer Name"  << endl;
    for(int a=0; a < nQueue; a++){
        if("prosess" == db_transaksi[a][5]){
        cout << a << "." << db_transaksi[a][1] << "||" << db_transaksi[a][2]  << endl;
        }
    }
    cout << "=============================" << endl;
    cout << "" << endl;
    cout << "20. Back" << endl;
    cout << "" << endl;
    cout << "=============================" << endl;    
    cout << "Enter Code : ";
    cin >> code;

    if (code == "20") {
        return queueManagement();
    }

    for(int a=0; a < nQueue; a++){
        if(code == db_transaksi[a][2]){
            isFound = true;
            db_transaksi[a][5] = "done"; 
        }
    }
    if(isFound){
        acQueue--;
        doQueue++;
    }
    queueManagement();
};
void listQueue(){
    system("cls");
    int choice;
    cout << "=============================" << endl;
    cout << "======== List Queue  ========" << endl;
    cout << "=============================" << endl;
    cout << "idQueue" << " || " << "Customer Name"  << " || " << "Customer Code"  <<  " || " << "Shift"  << " || " << "Service" << " || " << "Status"  << " || " << "Staff" <<  endl;
    for(int a=0; a < nQueue; a++){
        cout << a;
        for(int i=0; i < 7; i++){
            cout << db_transaksi[a][i] << " || ";
        }
        cout << endl;
    }
   cout << "=============================" << endl;
    cout << "" << endl;
    cout << "20. Back" << endl;
    cout << "" << endl;
    cout << "=============================" << endl;

    cout << "" << endl;
    cout << "Enter Your Choice : ";
    cin >> choice;

    if (choice == 20) {
        return queueManagement();
    }
};

void queueManagement() {
    system("cls");
    int choice;
    cout << "=============================" << endl;
    cout << "===== Queue Management  =====" << endl;
    cout << "=============================" << endl;
    cout << "Queue : " << codeQueue << endl;
    cout << "Active Queue : " << acQueue << endl;
    cout << "Done Queue : " << doQueue << endl;
    cout << "Total Queue : " << nQueue << endl;
    cout << "=============================" << endl;
    cout << "" << endl;
    cout << "=============================" << endl;
    cout << "1. Add Queue" << endl;
    cout << "2. Next Queue" << endl;
    cout << "3. Done Queue" << endl;
    cout << "4. List Queue" << endl;
    cout << "10. Menu" << endl;
    cout << "99. Logout" << endl;
    cout << "0. Quit" << endl;
    cout << "" << endl;
    cout << "=============================" << endl;
    cout << "" << endl;
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
        case 4:
            listQueue();
        case 10:
            menuStaff();
        case 99:
            logout();
            main();
        case 0:
            break;
        default:
            system("cls");
            cout << "Your input not found!" << endl;
            queueManagement();
    }
};

// =============== BOOKING FUNCTION
void newBooking() {
    system("cls");
    string name, date, time;
    int service;
    cout << "=============================" << endl;
    cout << "======= New Booking   =======" << endl;
    cout << "=============================" << endl;
    cout << "" << endl;
    cout << "20. Back" << endl;
    cout << "" << endl;
    cout << "=============================" << endl;
    cout << "Enter name: ";
    cin >> name;

    if (name == "20") {
        return bookingManagement();
    }
    cout << "Enter date (ex : 251224): ";
    cin >> date;
    cout << "Enter time (ex : 09 (Only Hours)): ";
    cin >> time;
    for(int a=0; a < 4; a++){
        cout << a << "." << db_listService[a][1] << endl;
    }
    cout << "Enter service: ";
    cin >> service;

    string queue = to_string(nQueue + 1);
    string code = date + "-" + time + queue; 
    string idQue = "QU-" + queue; 

    db_transaksi[nQueue][0] = idQue;
    db_transaksi[nQueue][1] = name;
    db_transaksi[nQueue][2] = code;
    db_transaksi[nQueue][3] = idShift(time);
    db_transaksi[nQueue][4] = db_listService[service][1];
    db_transaksi[nQueue][5] = "booking";
    db_transaksi[nQueue][6] = "---";

    for(int a=0; a < 6; a++){
        cout  << db_transaksi[nQueue][a] << endl;
    }
    
    nQueue++;
    bookingManagement();
};
void confBooking() {
system("cls");
    string code, staff;
    cout << "=============================" << endl;
    cout << "=== Confirmation Booking  ===" << endl;
    cout << "=============================" << endl;
    bool isFound = false;
    cout << "Code" << " || " << "Customer Name"  << endl;
    for(int a=0; a < nQueue; a++){
        if("booking" == db_transaksi[a][5]){
            cout << db_transaksi[a][1] << " || " << db_transaksi[a][2]  << endl;
        }
    }
    cout << "=============================" << endl;
    cout << "" << endl;
    cout << "20. Back" << endl;
    cout << "" << endl;
    cout << "=============================" << endl;
    cout << "Enter Code : ";
    cin >> code;
    if (code == "20") {
        return bookingManagement();
    }
    for(int a=0; a < nQueue; a++){
        if(code == db_transaksi[a][2]){
            isFound = true;
            db_transaksi[a][5] = "waiting"; 
        }
    }
    return bookingManagement();
};
void timeTabel() {
    system("cls");
    cout << "=============================" << endl;
    cout << "======== Time Tabel  ========" << endl;
    cout << "=============================" << endl;
    int choice;
    for(int a=0; a < 4; a++){
        cout << db_karyawan[a][0] << " || " << db_karyawan[a][1]  << endl;
    }

    cout << "=============================" << endl;
    cout << "" << endl;
    cout << "20. Back" << endl;
    cout << "" << endl;
    cout << "=============================" << endl;

    cout << "" << endl;
    cout << "Enter Your Choice : ";
    cin >> choice;

    if (choice == 20) {
        return bookingManagement();
    }
};

void bookingManagement() {
    system("cls");
    int choice;
    cout << "=============================" << endl;
    cout << "==== Booking Management  ====" << endl;
    cout << "=============================" << endl;
    cout << "" << endl;
    cout << "1. New Booking" << endl;
    cout << "2. Confirmation Booking" << endl;
    cout << "3. Timetable " << endl;
    cout << "10. Menu" << endl;
    cout << "99. Logout" << endl;
    cout << "0. Quit" << endl;
    cout << "" << endl;
    cout << "=============================" << endl;
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
            break;
        default:
            system("cls");
            cout << "Your input not found!" << endl;
            bookingManagement();
    }
};