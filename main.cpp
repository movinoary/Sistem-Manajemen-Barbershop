#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

// ===== Variabel =====
int nQueue = 0;
string codeQueue;
int acQueue = 0;
int doQueue = 0;
const int toLine = 50;
const int toListMenu = 22;

// ===== Data =====
string db_userAccount[6][5] = {
    // idUser, nama,  password, role, idKaryawan
    {"UR-1", "admin", "admin123", "admin", "-"},
    {"UR-2", "adit", "adit123", "staff", "ST-1"},
    {"UR-3", "alif", "alif123", "staff", "ST-2"},
    {"UR-4", "sisil", "sisil123", "staff", "ST-3"},
    {"UR-5", "vino", "vino123", "staff", "ST-4"},
    {"UR-6", "iqbaal", "iqbaal", "staff", "ST-3"},
};
string db_karyawan[4][5] = {
    // idKaryawan, namaLengkap, statusKerja, idShift
    {"ST-1", "Adit Praditia", "active", "Shift-1", "10"},
    {"ST-2", "Muhammad Nur Alif", "active", "Shift-1", "5"},
    {"ST-3", "Suci Fransica Sisilia", "active", "Shift-2", "3"},
    {"ST-4", "Mohammad Vino Arystio", "active", "Shift-2", "12"},
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
    // idQueue, nama,  code, Shift, Name Service, status, Staff Name
    // {"QU-1",  "asep", "25122024-10001", "SF-1", "LS-3", "wating", "ST-2"}
};
string listMenu[toListMenu][3] = {
    // id, code, title
    {"99", "99", "quit"},
    {"88", "88", "logout"},
    {"01", "1", "login"},
    {"02", "10", "Menu Admin"},
    {"03", "1", "Staff Management"},
    {"04", "2", "Service Report"},
    {"05", "1", "editStaff"},
    {"06", "1", "Data Staff"}, 
    {"07", "2", "Data Shift"}, 
    {"08", "1", "Report Service"},
    {"09", "2", "Tracking Staff"}, 
    {"10", "10", "menuStaff"},
    {"11", "1", "Queue Management"},
    {"12", "2", "Booking Management"},
    {"13", "1", "addQueue"},
    {"14", "2", "nextQueue"},
    {"15", "3", "doneQueue"},
    {"16", "4", "listQueue"},
    {"17", "1", "New Booking"},
    {"18", "2", "Confirmation Booking"},
    {"19", "3", "Time Table"},
    {"77", "77", "Back"},
};
string db_userlogin[5];

// ===== RUN =====
int main();
// ===== AUTH FUNCTION =====
void logout(); 
void login();
// ===== MENU ADMIN =====
void menuAdmin();
void staffManagement();
void serviceReport();
// ===== FUNCTION ADMIN =====
void editStaff();
void dataStaff();
void dataShift();
void reportService();
void trackingStaff();
// ===== MENU STAFF =====
void menuStaff();
void queueManagement();
void bookingManagement(); 
// ===== STAFF ADMIN =====
void addQueue();
void nextQueue();
void doneQueue();
void listQueue();
void newBooking();
void confBooking();
void timeTabel();

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
// ===== VIEW =====
void printView(int e) {
    for (int i = 0; i < e; i++) {
        cout << "=";
    }
}
void printHeader(const string& title) {
    int lineTitle = (toLine - title.length()) / 2;
    system("cls");
    cout << endl;
    printView(toLine);
    cout << endl;
    printView(lineTitle);
    cout << title;
    printView(lineTitle);
    cout << endl;
    printView(toLine);
    cout << endl;
}
void printMenuTop(){
    cout << endl;
    printView(toLine);
    cout << endl;
    cout << endl;
}
void printMenuBottom() {
    cout << endl;
    printView(toLine);
    cout << endl;
    cout << "Enter Your Choice: ";
}
void loopMenu(int length, const string view[]) {
    for (int i = 0; i < length; i++) {
        for (int a = 0; a < toListMenu; a++) {
            if (view[i] == listMenu[a][0]) {
                cout << listMenu[a][1] << " - " << listMenu[a][2] << endl;
            }
        }
    }
}
void printMenu(const string& type) {
    const string mainMenu[] = {"01", "99"};
    const string menuAdmin[] = {"03", "04", "88", "99"};
    const string dataStaff[] = {"05", "02", "77", "88", "99"};
    const string dataShift[] = {"02", "77", "88", "99"};
    const string staffManagement[] = {"06", "07", "02", "88", "99"};
    const string reportService[] = {"77", "88", "99"};
    const string trackingStaff[] = {"77", "88", "99"};
    const string serviceReport[] = {"08", "09", "02", "88", "99"};
    const string menuStaff[] = {"11", "12", "88", "99"};
    const string queueManagement[] = {"13", "14", "15", "16", "10", "88", "99"};
    const string bookingManagement[] = {"17", "18", "19", "10", "88", "99"};

    if (type == "main") {
        printMenuTop();
        loopMenu(2, mainMenu);
    } else if (type == "menuAdmin") {
        printMenuTop();
        loopMenu(4, menuAdmin);
    } else if (type == "dataStaff") {
        printMenuTop();
        loopMenu(5, dataStaff);
    } else if (type == "dataShift") {
        printMenuTop();
        loopMenu(4, dataShift);
    } else if (type == "staffManagement") {
        printMenuTop();
        loopMenu(5, staffManagement);
    } else if (type == "reportService") {
        printMenuTop();
        loopMenu(3, reportService);
    } else if (type == "trackingStaff") {
        printMenuTop();
        loopMenu(3, trackingStaff);
    } else if (type == "serviceReport") {
        printMenuTop();
        loopMenu(5, serviceReport);
    } else if (type == "menuStaff") {
        printMenuTop();
        loopMenu(4, menuStaff);
    } else if (type == "queueManagement") {
        printMenuTop();
        loopMenu(7, queueManagement);
    } else if (type == "bookingManagement") {
        printMenuTop();
        loopMenu(6, bookingManagement);
    }
    printMenuBottom();
}
void route(const string& type, int number) {
    if (type == "main") {
        switch (number) {
            case 1: login(); break;
            case 99: break;
            default: main(); break;
        }
    } else if (type == "menuAdmin") {
        switch (number) {
            case 1: staffManagement(); break;
            case 2: serviceReport(); break;
            case 88: logout(); main(); break;
            case 99: break;
            default: menuAdmin(); break;
        }
    } else if (type == "dataStaff") {
        switch (number) {
            case 1: editStaff(); break;
            case 77: staffManagement(); break;
            case 10: menuAdmin(); break;
            case 88: logout(); main(); break;
            case 99: break;
            default: dataStaff(); break;
        }
    } else if (type == "dataShift") {
        switch (number) {
            case 10: menuAdmin(); break;
            case 77: staffManagement(); break;
            case 88: logout(); main(); break;
            case 99: break;
            default: dataShift(); break;
        }
    } else if (type == "staffManagement") {
        switch (number) {
            case 1: dataStaff(); break;
            case 2: dataShift(); break;
            case 10: menuAdmin(); break;
            case 88: logout(); main(); break;
            case 99: break;
            default: staffManagement(); break;
        }
    } else if (type == "reportService") {
        switch (number) {
            case 77: serviceReport(); break;
            case 88: logout(); main(); break;
            case 99: break;
            default: reportService(); break;
        }
    } else if (type == "trackingStaff") {
        switch (number) {
            case 77: serviceReport(); break;
            case 88: logout(); main(); break;
            case 99: break;
            default: trackingStaff(); break;
        }
    } else if (type == "serviceReport") {
        switch (number) {
            case 1: reportService(); break;
            case 2: trackingStaff(); break;
            case 10: menuAdmin(); break;
            case 88: logout(); main(); break;
            case 99: break;
            default: serviceReport(); break;
        }
    } else if (type == "menuStaff") {
        switch (number) {
            case 1: queueManagement(); break;
            case 2: bookingManagement(); break;
            case 88: logout(); main(); break;
            case 99: break;
            default: menuStaff(); break;
        }
    } else if (type == "queueManagement") {
        switch (number) {
            case 1: addQueue(); break;
            case 2: nextQueue(); break;
            case 3: doneQueue(); break;
            case 4: listQueue(); break;
            case 10: menuStaff(); break;
            case 88: logout(); main(); break;
            case 99: break;
            default: queueManagement(); break;
        }
    } else if (type == "bookingManagement") {
        switch (number) {
            case 1: newBooking(); break;
            case 2: confBooking(); break;
            case 3: timeTabel(); break;
            case 10: menuStaff(); break;
            case 88: logout(); main(); break;
            case 99: break;
            default: bookingManagement(); break;
        }
    }
}

// =============== RUN ===============
int main() {
    int choice;
    printHeader(" Welcome to App Barber ");
    printMenu("main");
    cin >> choice;

    route("main", choice);
    
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
        printView(toLine);
        cout << "===" << message << "===" << endl;
        printView(toLine);
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
        printView(toLine);
        cout << "=== Thankyou for coming! ====" << endl;
        printView(toLine);
        for(int a=0; a < 5; a++){
        db_userlogin[a] = "";
    }
}

// =============== MENU ADMIN ===============
void menuAdmin () {
    int choice;
    printHeader(" Welcome  Admin ");
    printMenu("menuAdmin");
    cin >> choice;

    route("menuAdmin", choice);
}

// =============== STAFF FUNCTION
void editStaff() {
    int idStaff = 5;
    int id = 0;
    string name, status, shift;
    cout << "Enter No Staff: ";
    cin >> id;
    cout << "Enter Full Name: ";
    cin >> name;
    cout << "Enter Status: ";
    cin >> status;
    printView(toLine);
    cout <<  " || "  << "ID Shift" << " || " << "Start Time"  << " - " << "End Time" <<  " || "  <<  endl;
    for(int a=0; a < 2; a++){
        cout <<  " || " <<   db_dataShift[a][0] << " || " << db_dataShift[a][1] << " - " << db_dataShift[a][7] <<  " || "  << endl;
    }
    printView(toLine);
    cout << "Enter ID Shift: ";
    cin >> shift;

    db_karyawan[id][1] = name;
    db_karyawan[id][2] = status;
    db_karyawan[id][3] = shift;

    dataStaff();
}

void dataStaff() {
    int choice;
    printHeader(" List Staff ");
    cout <<  " || " << "No" << " || " << "Full Name"  << " || " << "Status"  <<  " || " << "Shift"  <<  " || " <<  endl;
    for(int a=0; a < 4; a++){
        cout <<  " || " << a << " || ";
        for(int i=1; i < 4; i++){
            cout << db_karyawan[a][i] << " || ";
        }
        cout << endl;
    }
    printView(toLine);

    printMenu("dataStaff");
    cin >> choice;

    route("dataStaff", choice);
}
void dataShift() {
    int choice;
    printHeader(" List Shift ");
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
    printView(toLine);
    printMenu("dataShift");
    cin >> choice;

    route("dataShift", choice);
};

void staffManagement(){    
    int choice;
    printHeader(" Staff Management ");
    printMenu("staffManagement");
    cin >> choice;

    route("staffManagement", choice);
}

// =============== REPORT FUNCTION
void reportService(){
    int choice;
    printHeader(" Report Service ");

    for(int i=0; i < 4; i++){
        int totalCustomer = 0;
        for(int a=0; a < nQueue; a++){
            if(db_karyawan[i][1] == db_transaksi[a][6]){
                totalCustomer++;
            }
        }
        db_karyawan[i][4] = to_string(totalCustomer);
    }

    cout << "Total Days Customer  : " << nQueue << endl;
    cout <<  " || "  << "Full Name"  << " || " << "Total "  <<  " || " << "Shift"  <<  " || " <<  endl;
    for(int a=0; a < 4; a++){
        cout <<  " || " <<   db_karyawan[a][1] << " || " << db_karyawan[a][4] << " || " << db_karyawan[a][3] <<  " || "  << endl;
    }
    printView(toLine);
    printMenu("reportService");
    cin >> choice;

    route("reportService", choice);
};
void trackingStaff(){
    int choice;
    printHeader(" Tracking Staff ");

    cout << "Total Days Customer  : " << nQueue << endl;
    cout <<  " || " << "Ranking"  <<  " || " <<  "Full Name"  << " || " << "Total "  <<  " || " << "Shift"  <<  " || " <<  endl;
    for (int i = 0; i < 4 - 1; i++) {
        for (int j = 0; j < 4 - i - 1; j++) {
            if (stoi(db_karyawan[j][4]) > stoi(db_karyawan[j + 1][4])) {
                for (int k = 0; k < 5; k++) {
                    string temp = db_karyawan[j][k]; 
                    db_karyawan[j][k] = db_karyawan[j + 1][k];
                    db_karyawan[j + 1][k] = temp;
                }
            }
        }
        cout << " || " << i << " || " << db_karyawan[i][1] << " || " << db_karyawan[i][4] << "/" << nQueue << " || " << db_karyawan[i][3] << " || " << endl;
    }
    printView(toLine);
    cout << "" << endl;
    cout << "1. Edit Staff" << endl;
    cout << "20. Back" << endl;
    cout << "" << endl;
    printView(toLine);
    
    printMenu("trackingStaff");
    cin >> choice;

    route("reportService", choice);
};

void serviceReport(){
    int choice;
    printHeader(" Service Report ");
    printMenu("serviceReport");
    cin >> choice;

    route("serviceReport", choice);
}

// =============== MENU STAFF ===============
void menuStaff() {
    int choice;
    printHeader(" Welcome  Staff ");
    printMenu("menuStaff");
    cin >> choice;

    route("menuStaff", choice);
}

// =============== QUEUE FUNCTION
void addQueue(){
    printHeader(" Add Queue ");
    string name, date, time;
    int service;
    cout << "" << endl;
    cout << "20. Back" << endl;
    cout << "" << endl;
    printView(toLine);
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
    printHeader(" Next Queue ");
    string code, staff;
    bool isFound = false;
    cout << "Code" << " || " << "Customer Name"  << endl;
    // Todo Sort Queue Code
    for(int a=0; a < nQueue; a++){
        if("waiting" == db_transaksi[a][5]){
            cout << db_transaksi[a][2] << " || " << db_transaksi[a][1]  << endl;
        }
    }
    printView(toLine);
    cout << "" << endl;
    cout << "20. Back" << endl;
    cout << "" << endl;
        printView(toLine);
    cout << "Enter Code : ";
    cin >> code;
    if (code == "20") {
        return queueManagement();
    }
    printView(toLine);
    cout << "Code" << " || " << "Staff Name"  << endl;
    for(int a=0; a < 4; a++){
        cout << db_karyawan[a][0] << " || " << db_karyawan[a][1]  << endl;
    }
    printView(toLine);

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
    printHeader(" Done Queue ");
    string code;
    bool isFound = false;
    cout << "Code" << " || " << "Customer Name"  << endl;
    for(int a=0; a < nQueue; a++){
        if("prosess" == db_transaksi[a][5]){
        cout << a << "." << db_transaksi[a][1] << "||" << db_transaksi[a][2]  << endl;
        }
    }
    printView(toLine);
    cout << "" << endl;
    cout << "20. Back" << endl;
    cout << "" << endl;
    printView(toLine);    
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
    printHeader(" List Queue ");
    int choice;
    cout << "idQueue" << " || " << "Customer Name"  << " || " << "Customer Code"  <<  " || " << "Shift"  << " || " << "Service" << " || " << "Status"  << " || " << "Staff" <<  endl;
    for(int a=0; a < nQueue; a++){
        cout << a;
        for(int i=0; i < 7; i++){
            cout << db_transaksi[a][i] << " || ";
        }
        cout << endl;
    }
   printView(toLine);
    cout << "" << endl;
    cout << "20. Back" << endl;
    cout << "" << endl;
    printView(toLine);

    cout << "" << endl;
    cout << "Enter Your Choice : ";
    cin >> choice;

    if (choice == 20) {
        return queueManagement();
    }
};

void queueManagement() {
    int choice;
    printHeader(" Queue Management ");
    cout << "Queue : " << codeQueue << endl;
    cout << "Active Queue : " << acQueue << endl;
    cout << "Done Queue : " << doQueue << endl;
    cout << "Total Queue : " << nQueue << endl;
    printMenu("queueManagement");
    cin >> choice;

    route("queueManagement", choice);
};

// =============== BOOKING FUNCTION
void newBooking() {
    printHeader(" New Booking ");
    string name, date, time;
    int service;

    cout << "" << endl;
    cout << "20. Back" << endl;
    cout << "" << endl;
    printView(toLine);
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
    printHeader(" Confirmation Booking ");
    string code, staff;

    bool isFound = false;
    cout << "Code" << " || " << "Customer Name"  << endl;
    for(int a=0; a < nQueue; a++){
        if("booking" == db_transaksi[a][5]){
            cout << db_transaksi[a][1] << " || " << db_transaksi[a][2]  << endl;
        }
    }
    printView(toLine);
    cout << "" << endl;
    cout << "20. Back" << endl;
    cout << "" << endl;
    printView(toLine);
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
    printHeader(" Time Tabel ");
    int choice;
    for(int a=0; a < 4; a++){
        cout << db_karyawan[a][0] << " || " << db_karyawan[a][1]  << endl;
    }

    printView(toLine);
    cout << "" << endl;
    cout << "20. Back" << endl;
    cout << "" << endl;
    printView(toLine);

    cout << "" << endl;
    cout << "Enter Your Choice : ";
    cin >> choice;

    if (choice == 20) {
        return bookingManagement();
    }
};

void bookingManagement() {
    printHeader(" Booking Management ");
    printMenu("bookingManagement");
    int choice;
    cin >> choice;

    route("bookingManagement", choice);
};