#include <iostream>
#include <string>
using namespace std;

// Maksimal jumlah data
const int MAX_STAFF = 10;
const int MAX_QUEUE = 20;
const int MAX_BOOKINGS = 20;
const int MAX_REPORT = 1000;

// Struktur data untuk staff
string staff[MAX_STAFF][5]; // [ID, Nama, Password, Status Aktif, Shift]
int staffCount = 0;

// Struktur data untuk antrian pelanggan
string queue[MAX_QUEUE][4]; // [Nomor Antrian, Nama Pelanggan, Jenis Layanan, Status]
int queueCount = 0;

// Struktur data untuk booking
string bookings[MAX_BOOKINGS][3]; // [Nama Pelanggan, Tanggal & Jam, Jenis Layanan]
int bookingCount = 0;

// Struktur data untuk report
string reports[MAX_REPORT][4]; // [Tanggal & Jam, ID Staff, Nama Pelanggan, Jenis Layanan]
int reportCount = 0;

// Fungsi untuk menampilkan menu utama
void showMenu();
void adminMenu();
void staffMenu(string staffID);

// Fungsi untuk fitur Admin
void addStaff();
void viewStaff();
void setShift();

// Fungsi untuk fitur Staff
void manageQueue(string staffID);
void viewQueue();
void setStatusQueue(string staffID);

// Fungsi login staff
bool loginStaff(string &staffID);

int main()
{
    showMenu();
    return 0;
}

void showMenu()
{
    int choice;
    do
    {
        cout << "\n==== Sistem Manajemen Barbershop ====" << endl;
        cout << "1. Admin" << endl;
        cout << "2. Staff" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            adminMenu();
            break;
        case 2:
        {
            string staffID;
            if (loginStaff(staffID))
            {
                staffMenu(staffID);
            }
            break;
        }
        case 3:
            cout << "Keluar dari sistem. Terima kasih!" << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Coba lagi!" << endl;
        }
    } while (choice != 3);
}

void adminMenu()
{
    int choice;
    do
    {
        cout << "\n==== Menu Admin ====" << endl;
        cout << "1. Tambah Staff" << endl;
        cout << "2. Lihat Data Staff" << endl;
        cout << "3. Atur Shift" << endl;
        cout << "4. Kembali ke Menu Utama" << endl;
        cout << "Pilih menu: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addStaff();
            break;
        case 2:
            viewStaff();
            break;
        case 3:
            setShift();
            break;
        case 4:
            return;
        default:
            cout << "Pilihan tidak valid. Coba lagi!" << endl;
        }
    } while (choice != 4);
}

void addStaff()
{
    if (staffCount >= MAX_STAFF)
    {
        cout << "Data staff penuh! Tidak bisa menambahkan lebih banyak." << endl;
        return;
    }

    cout << "\n==== Tambah Staff ====" << endl;
    cout << "Masukkan ID Staff: ";
    cin >> staff[staffCount][0];
    cout << "Masukkan Nama Staff: ";
    cin.ignore();
    getline(cin, staff[staffCount][1]);
    cout << "Masukkan Password Staff: ";
    cin >> staff[staffCount][2];
    staff[staffCount][3] = "Aktif";        // Default status aktif
    staff[staffCount][4] = "Belum diatur"; // Default shift

    staffCount++;
    cout << "Staff berhasil ditambahkan!" << endl;
}

void viewStaff()
{
    cout << "\n==== Data Staff ====" << endl;
    if (staffCount == 0)
    {
        cout << "Belum ada staff yang terdaftar." << endl;
        return;
    }

    for (int i = 0; i < staffCount; i++)
    {
        cout << "ID: " << staff[i][0] << ", Nama: " << staff[i][1]
             << ", Status: " << staff[i][3] << ", Shift: " << staff[i][4] << endl;
    }
}

void setShift()
{
    string id;
    cout << "\n==== Atur Shift Staff ====" << endl;
    cout << "Masukkan ID Staff: ";
    cin >> id;

    for (int i = 0; i < staffCount; i++)
    {
        if (staff[i][0] == id)
        {
            cout << "Pilih Shift: \n1. Pagi (08.00-14.00) \n2. Siang (14.00-20.00)\nPilihan: ";
            int shiftChoice;
            cin >> shiftChoice;
            if (shiftChoice == 1)
            {
                staff[i][4] = "Pagi";
            }
            else if (shiftChoice == 2)
            {
                staff[i][4] = "Siang";
            }
            else
            {
                cout << "Pilihan shift tidak valid." << endl;
            }
            cout << "Shift berhasil diatur untuk Staff ID " << id << endl;
            return;
        }
    }

    cout << "Staff dengan ID " << id << " tidak ditemukan." << endl;
}

bool loginStaff(string &staffID)
{
    string id, password;
    cout << "\n==== Login Staff ====" << endl;
    cout << "Masukkan ID Staff: ";
    cin >> id;
    cout << "Masukkan Password: ";
    cin >> password;

    for (int i = 0; i < staffCount; i++)
    {
        if (staff[i][0] == id && staff[i][2] == password)
        {
            staffID = id;
            cout << "Login berhasil. Selamat datang, " << staff[i][1] << "!" << endl;
            return true;
        }
    }
    cout << "ID atau Password salah." << endl;
    return false;
}

void staffMenu(string staffID)
{
    int choice;
    do
    {
        cout << "\n==== Menu Staff ====" << endl;
        cout << "1. Kelola Antrian" << endl;
        cout << "2. Lihat Antrian Aktif" << endl;
        cout << "3. Ubah Status Antrian" << endl;
        cout << "4. Kembali ke Menu Utama" << endl;
        cout << "Pilih menu: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            manageQueue(staffID);
            break;
        case 2:
            viewQueue();
            break;
        case 3:
            setStatusQueue(staffID);
            break;
        case 4:
            return;
        default:
            cout << "Pilihan tidak valid. Coba lagi!" << endl;
        }
    } while (choice != 4);
}

void manageQueue(string staffID)
{
    if (queueCount >= MAX_QUEUE)
    {
        cout << "Antrian penuh!" << endl;
        return;
    }

    cout << "\n==== Tambah Antrian ====" << endl;
    queue[queueCount][0] = to_string(queueCount + 1); // Nomor antrian otomatis
    cout << "Masukkan Nama Pelanggan: ";
    cin.ignore();
    getline(cin, queue[queueCount][1]);
    cout << "Masukkan Jenis Layanan: ";
    getline(cin, queue[queueCount][2]);
    queue[queueCount][3] = "Menunggu";
    queueCount++;
    cout << "Antrian berhasil ditambahkan!" << endl;
}

void setStatusQueue(string staffID)
{
    if (queueCount == 0)
    {
        cout << "\n==== Update Status Antrian ====" << endl;
        cout << "Tidak ada antrian aktif." << endl;
        return;
    }

    int choice;

    do
    {
        cout << "\n==== Update Status Antrian ====" << endl;
        cout << "1. Antrian Saat ini Selesai" << endl;
        cout << "2. Proses Antrian Berikutnya" << endl;
        cout << "3. Kembali" << endl;
        cout << "Pilih menu: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            // Menyelesaikan Status Antrian Saat ini "Selesai"
            cout << "\n==== Status Antrian ====" << endl;
            for (int i = 0; i < queueCount; i++)
            {
                if (queue[i][3] == "Proses")
                {
                    cout << "Nomor Antrian " << queue[i][0] << " Atas Nama " << queue[i][1] << " Selesai" << endl;
                    queue[i][3] = "Selesai"; // Mengubah status antrian menjadi "Selesai"
                    viewQueue();

                    reports[reportCount][1] = staffID;
                    reports[reportCount][2] = queue[i][1];
                    reports[reportCount][3] = queue[i][2];
                    reportCount++;

                    return;
                }
            }
            cout << "Belum ada antrian yang di Proses" << endl;
            break;
        case 2:
            // Menjadikan Status Antrian Berikutnya "Proses"
            cout << "\n==== Status Antrian ====" << endl;
            for (int i = 0; i < queueCount; i++)
            {
                if (queue[i][3] == "Menunggu")
                {
                    cout << "Nomor Antrian " << queue[i][0] << " Atas Nama " << queue[i][1] << " di Proses" << endl;
                    queue[i][3] = "Proses"; // Mengubah status antrian menjadi "Proses"
                    viewQueue();
                    return;
                }
            }
            cout << "Belum ada antrian Menunggu" << endl;
            break;
        case 3:
            return;
        default:
            cout << "Pilihan tidak valid. Coba lagi!" << endl;
        }
    } while (choice != 3);
}

void viewQueue()
{
    cout << "\n==== Antrian Aktif ====" << endl;
    if (queueCount == 0)
    {
        cout << "Tidak ada antrian aktif." << endl;
        return;
    }

    for (int i = 0; i < queueCount; i++)
    {
        cout << "Nomor: " << queue[i][0] << ", Nama: " << queue[i][1]
             << ", Layanan: " << queue[i][2] << ", Status Antrian: " << queue[i][3] << endl;
    }
}
