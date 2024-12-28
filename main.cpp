#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

// ===== Variabel Queue =====
int nQueue = 0;
string codeQueue;
int acQueue = 0;
int doQueue = 0;

// ===== Variabel Print =====
const int toLine = 75;
const int toListMenu = 22;

// ===== Data =====
string db_userAccount[6][5] = {
    {"UR-1", "admin", "admin123", "admin"},
    {"UR-2", "staff", "staff123", "staff"},
};
string db_karyawan[4][5] = {
    // idKaryawan, namaLengkap, statusKerja, idShift
    {"ST-1", "Adit Praditia", "active", "Shift-1", "0"},
    {"ST-2", "Muhammad Nur Alif", "active", "Shift-1", "0"},
    {"ST-3", "Suci Fransica Sisilia", "active", "Shift-2", "0"},
    {"ST-4", "Mohammad Vino Arystio", "active", "Shift-2", "0"},
};
string db_dataShift[2][8] = {
    // idShift, waktuMulai, waktuAkhir, 
    {"Shift-1", "08", "09", "10", "11", "12", "13", "14"},
    {"Shift-2", "15", "16", "17", "18", "19", "20", "20"},
};
string db_listService[4][5] = {
    // idService, jenisLayanan, harga, totalCustomer, rating
    {"LS-1", "Cukur Anak-anak", "30000", "0", "0"},
    {"LS-2", "Cukur Anak-anak + Cuci", "35000", "0", "0"},
    {"LS-3", "Cukur Dewasa", "40000", "0", "0"},
    {"LS-4", "Cukur Dewasa + Cuci", "45000", "0", "0"},
};
string db_transaksi[100][8] = {
    // idQueue, nama,  code, Shift, Name Service, status, Staff Name, rating
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

// ===== VIEW =====
void printView(int e) {
    for (int i = 0; i < e; i++) {
        cout << "=";
    }
}
void printMenuTop(){
    printView(toLine);
    cout << endl;
    cout << endl;
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
    printMenuTop();
}
void printMenuBottom(bool value) {
    cout << endl;
    printMenuTop();
    if(!value){
        cout << "Enter Your Choice: ";
    }
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
int printMenu(const string& type) {
    int choice = 0;
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
    const string back[] = {"77", "88", "99"};
    bool viewInput = type == "backQueue" || type == "backBooking"  ? true : false;

    printMenuTop();
    if (type == "main") {
        loopMenu(2, mainMenu);
    } else if (type == "menuAdmin") {
        loopMenu(4, menuAdmin);
    } else if (type == "dataStaff") {
        loopMenu(5, dataStaff);
    } else if (type == "dataShift") {
        loopMenu(4, dataShift);
    } else if (type == "staffManagement") {
        loopMenu(5, staffManagement);
    } else if (type == "reportService") {
        loopMenu(3, reportService);
    } else if (type == "trackingStaff") {
        loopMenu(3, trackingStaff);
    } else if (type == "serviceReport") {
        loopMenu(5, serviceReport);
    } else if (type == "menuStaff") {
        loopMenu(4, menuStaff);
    } else if (type == "queueManagement") {
        loopMenu(7, queueManagement);
    } else if (type == "bookingManagement") {
        loopMenu(6, bookingManagement);
    } else if (type == "backQueue") {
        loopMenu(3, back);
    } else if (type == "backBooking") {
        loopMenu(3, back);
    }
    printMenuBottom(viewInput);

    if(
        type != "backQueue" 
        || type != "backBooking" 
        || type != "addQueue"
        || type != "addQueue"
        ) {
        cin >> choice;
    }

    return choice;
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
    } else if (type == "backQueue") {
        switch (number) {
            case 77: queueManagement(); break;
            default: queueManagement(); break;
        }
    } else if (type == "backBooking") {
        switch (number) {
            case 77: bookingManagement(); break;
            default: bookingManagement(); break;
        }
    } 
}
// ===== Tabel =====
void tabelStaffschedule(){
    cout << " || " << "ID Staff" <<" || " << "Shift" << " || " << "Name" << " || " << endl;
    for(int a=0; a < 4; a++){
        cout << " || " << db_karyawan[a][0] <<" || " << db_karyawan[a][2] << " || " << db_karyawan[a][1] << " || " << endl;
    }
}
void tabelQueue(string status){
    cout << " || " << "Code" << " || " << "Customer Name" << " || "  << endl;
    for(int a=0; a < nQueue; a++){
        if(status == db_transaksi[a][5]){
            cout << " || " << db_transaksi[a][1] << " || " << db_transaksi[a][2] << " || "  << endl;
        }
    }
}
void tabelTransaction(){
    cout << " || " << "idQueue" << " || " << "Customer Name"  << " || " << "Customer Code"  <<  " || " << "Shift"  << " || " << "Service" << " || " << "Status"  << " || " << "Staff"  << " || " <<  endl;
    for(int a=0; a < nQueue; a++){
        cout << " || ";
        for(int i=0; i < 7; i++){
            cout << db_transaksi[a][i] << " || ";
        }
        cout << " || "<< endl;
    }
}
void tabelStaff(){
    cout<< " || " << "Full Name"  << " || " << "Status"  <<  " || " << "Shift"  <<  " || " <<  endl;
    for(int a=0; a < 4; a++){
        cout <<  " || ";
        for(int i=1; i < 4; i++){
            cout << db_karyawan[a][i] << " || ";
        }
        cout << endl;
    }
}
void tabelStaffPerform(){
    cout <<  " || " << "Ranking"  <<  " || " <<  "Full Name"  << " || " << "Total Customer "  <<  " || " << "Shift"  <<  " || " <<  endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (stoi(db_karyawan[j][4]) > stoi(db_karyawan[j + 1][4])) {
                for (int k = 0; k < 5; k++) {
                    string temp = db_karyawan[j][k]; 
                    db_karyawan[j][k] = db_karyawan[j + 1][k];
                    db_karyawan[j + 1][k] = temp;
                }
            }
        }
        cout << " || " << i + 1 << " || " << db_karyawan[i][1] << " || " << db_karyawan[i][4] << "/" << nQueue << " || " << db_karyawan[i][3] << " || " << endl;
    }
}
void tabelService(){
    cout << endl;
    cout <<  " || "  << "No"  << " || " << "Service"  << " || " << "Price"  <<  " || " << "Total Customer"  << " || " << "Rating" << " || " <<  endl;
    for(int a=0; a < 4; a++){
        cout <<  " || " << a << "."  << " || "<<   db_listService[a][1] << " || " << "Rp."<< db_listService[a][2] << " || " << db_listService[a][3] <<  " || " << db_listService[a][4] << "||"  << endl;
    }
}
void tabelShift(bool status){
    cout << "||" <<  "||" << "ID Shift" << " || " << "Start Time"  << " - " << "End Time" <<  " || " << "Staff Operation"<< endl;
    for(int a=0; a < 2; a++){
        cout  << "||" <<  db_dataShift[a][0] << " || " << db_dataShift[a][1] << " - " << db_dataShift[a][7] << " || ";
        if(status){
            for(int i=0; i<4; i++){
                if (db_dataShift[a][0] == db_karyawan[i][3]){
                    cout << db_karyawan[i][1] << "  ";
                }
            }
        }    
        cout << endl;
    }
}
// ===== Function =====
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
string nameService(int num){
    int totalCustomer = stoi(db_listService[num][3]) + 1;
    db_listService[num][3] = to_string(totalCustomer);

    return db_listService[num][1];
}
void addQueue(string type){
    int service;
    string name, date, time;

    cout << "Enter name : ";
    cin >> name;

    if(name == "77" && type == "booking"){
        route("backBooking", 77);
    } else if(name == "77" && type == "waiting"){
        route("backQueue", 77);
    }

    cout << "Enter date (ex : 251224 'DDMMYY') : ";
    cin >> date;
    cout << "Enter time (ex : 09 'Only Hours') : ";
    cin >> time;
    tabelService();
    cout << "Enter service: ";
    cin >> service;

    string queue = to_string(nQueue + 1);
    string code = date + "-" + time + queue; 
    string idQue = "QU-" + queue; 

    db_transaksi[nQueue][0] = idQue;
    db_transaksi[nQueue][1] = name;
    db_transaksi[nQueue][2] = code;
    db_transaksi[nQueue][3] = idShift(time);
    db_transaksi[nQueue][4] = nameService(service);
    db_transaksi[nQueue][5] = type;
    db_transaksi[nQueue][6] = "---";
    db_transaksi[nQueue][7] = "0";

    for(int a=0; a < 6; a++){
        cout  << db_transaksi[nQueue][a] << endl;
    }
    nQueue++;
}

// =============== RUN ===============
int main() {
    printHeader(" Welcome to App Barber ");
    int input = printMenu("main");
    route("main", input);
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

        cout << "===" << message << "===" << endl;

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
    cout << "=== Thankyou for coming! ====" << endl;
    for(int a=0; a < 5; a++){
        db_userlogin[a] = "";
    }
}

// =============== MENU ADMIN ===============
void menuAdmin () {
    printHeader(" Welcome  Admin ");
    int input = printMenu("menuAdmin");
    route("menuAdmin", input);
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
    tabelShift(false);
    cout << "Enter ID Shift: ";
    cin >> shift;

    db_karyawan[id][1] = name;
    db_karyawan[id][2] = status;
    db_karyawan[id][3] = shift;

    dataStaff();
}

void dataStaff() {
    printHeader(" List Staff ");
    tabelStaff();
    int input = printMenu("dataStaff");
    route("dataStaff", input);
}
void dataShift() {
    printHeader(" List Shift ");
    tabelShift(true);
    int input = printMenu("dataShift");
    route("dataShift", input);
};

void staffManagement(){    
    printHeader(" Staff Management ");
    int input = printMenu("staffManagement");
    route("staffManagement", input);
}

// =============== REPORT FUNCTION
void reportService(){
    printHeader(" Report Service ");
    cout << "Total Days Customer  : " << nQueue << endl;
    tabelStaffPerform();
    printView(toLine);
    tabelService();
    cout << endl;
    int input = printMenu("reportService");

    route("reportService", input);
};
void trackingStaff(){
    printHeader(" Tracking Staff ");

    cout << "Total Days Customer  : " << nQueue << endl;
    tabelStaffPerform();
    int input = printMenu("trackingStaff");

    route("trackingStaff", input);
};

void serviceReport(){

    // fungsi hitung jumlah customer
    for(int i=0; i < 4; i++){
        int totalCustomer = 0;
        for(int a=0; a < nQueue; a++){
            if(db_karyawan[i][1] == db_transaksi[a][6]){
                totalCustomer++;
            }
        }
        db_karyawan[i][4] = to_string(totalCustomer);
    }

    printHeader(" Service Report ");
    int input = printMenu("serviceReport");
    route("serviceReport", input);
}

// =============== MENU STAFF ===============
void menuStaff() {
    printHeader(" Welcome  Staff ");
    int input = printMenu("menuStaff");
    route("menuStaff", input);
}

// =============== QUEUE FUNCTION
void addQueue(){
    printHeader(" Add Queue ");
    printMenu("backQueue");
    addQueue("waiting");
    queueManagement();
};
void nextQueue(){
    string code, staff;
    bool isFound = false;
    printHeader(" Next Queue ");
    tabelQueue("waiting");
    printMenu("backQueue");
    cout << "Enter Code : ";
    cin >> code;

    if (code == "77") {
        route("backQueue", 77);
    }

    tabelStaff();
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
    string code, rating;
    bool isFound = false;
    printHeader(" Done Queue ");
    tabelQueue("prosess");
    printMenu("backQueue");
    
    cout << "Enter Code : ";
    cin >> code;
    cout << "Enter Rating (1-10): ";
    cin >> rating;

    if (code == "77") {
        route("backQueue", 77);
    }

    for(int a=0; a < nQueue; a++){
        if(code == db_transaksi[a][2]){
            isFound = true;
            db_transaksi[a][5] = "done"; 
            db_transaksi[a][5] = rating; 
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
    tabelTransaction();
    printMenu("backQueue");
    cout << "Enter Your Choice: ";
    cin >> choice;

    route("backQueue", choice);
};

void queueManagement() {
    printHeader(" Queue Management ");
    cout << "Queue : " << codeQueue << endl;
    cout << "Active Queue : " << acQueue << endl;
    cout << "Done Queue : " << doQueue << endl;
    cout << "Total Queue : " << nQueue << endl;
    cout << endl;
    int input = printMenu("queueManagement");
    route("queueManagement", input);
};

// =============== BOOKING FUNCTION
void newBooking() {
    printHeader(" New Booking ");
    printMenu("backBooking");
    addQueue("booking");
    bookingManagement();
};
void confBooking() {
    system("cls");
    string code, staff;
    bool isFound = false;
    printHeader(" Confirmation Booking ");
    tabelQueue("booking");

    cout << "Enter Code : ";
    cin >> code;

    for(int a=0; a < nQueue; a++){
        if(code == db_transaksi[a][2]){
            isFound = true;
            db_transaksi[a][5] = "waiting"; 
        }
    }

    nQueue++;
    return bookingManagement();
};
void timeTabel() {
    int choice;
    printHeader(" Time Tabel ");
    tabelStaffschedule();
    printMenu("backBooking");
    cout << "Enter Your Choice: ";
    cin >> choice;
    route("backBooking", choice);
};

void bookingManagement() {
    printHeader(" Booking Management ");
    int input = printMenu("bookingManagement");
    route("bookingManagement", input);
};