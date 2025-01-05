#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;

// Variable untuk datetime
string currentDateTime;

// Maksimal jumlah data
const int MAX_STAFF = 10;
const int MAX_QUEUE = 20;
const int MAX_BOOKINGS = 20;
const int MAX_REPORT = 1000;
const int MAX_SERVICES = 20;

// Struktur data untuk staff
string staff[MAX_STAFF][5]; // [ID, Nama, Password, Status Aktif, Shift]
int staffCount = 0;

// Struktur data untuk antrian pelanggan
string queue[MAX_QUEUE][5]; // [Nomor Antrian, Nama Pelanggan, Jenis Layanan, Status, HandleBy]
int queueCount = 0;

// Struktur data untuk booking
string bookings[MAX_BOOKINGS][3]; // [Nama Pelanggan, Tanggal & Jam, Jenis Layanan]
int bookingCount = 0;

// Struktur data untuk report
string reports[MAX_REPORT][4]; // [Tanggal & Jam, ID Staff, Nama Pelanggan, Jenis Layanan]
int reportCount = 0;

// Struktur data untuk layanan
string services[MAX_SERVICES][4]; // [ID Layanan, Nama Layanan, Harga, Status]
int serviceCount = 0;

// Fungsi untuk menampilkan menu utama
void showMenu();
void adminMenu();
void staffMenu(string staffID);

// Fungsi untuk fitur Admin
void addStaff();
void viewStaff();
void setShift();

// fungsi untuk fitur Layanan
void addService();
void viewServices();
string chooseService();
void viewPopularServices();

// Fungsi untuk fitur report
void viewReportDaily();
void viewReportStaff();
void viewStaffPerformance();

// Fungsi untuk fitur Staff
void manageQueue(string staffID);
void viewQueue();
void setStatusQueue(string staffID);

// Fungsi login staff
bool loginStaff(string &staffID);

// Fungsi untuk datetime
void updateDateTime();

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
        cout << "4. Tambah Layanan" << endl;
        cout << "5. Lihat Layanan" << endl;
        cout << "6. Laporan Harian" << endl;
        cout << "7. Laporan Per Staff" << endl;
        cout << "8. Kinerja Staff" << endl;
        cout << "9. Lihat Layanan Populer" << endl;
        cout << "10. Kembali ke Menu Utama" << endl;
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
            addService();
            break;
        case 5:
            viewServices();
            break;
        case 6:
            viewReportDaily();
            break;
        case 7:
            viewReportStaff();
            break;
        case 8:
            viewStaffPerformance();
            break;
        case 9:
            viewPopularServices();
            break;
        case 10:
            return;
        default:
            cout << "Pilihan tidak valid. Coba lagi!" << endl;
        }
    } while (choice != 7);
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

// Fungsi untuk fitur Layanan
void addService()
{
    if (serviceCount >= MAX_SERVICES)
    {
        cout << "Data layanan penuh! Tidak bisa menambahkan lebih banyak." << endl;
        return;
    }

    cout << "\n==== Tambah Layanan ====" << endl;
    cout << "Masukkan ID Layanan: ";
    cin >> services[serviceCount][0];
    cout << "Masukkan Nama Layanan: ";
    cin.ignore();
    getline(cin, services[serviceCount][1]);
    cout << "Masukkan Harga Layanan: ";
    cin >> services[serviceCount][2];
    services[serviceCount][3] = "Aktif"; // Default status aktif

    serviceCount++;
    cout << "Layanan berhasil ditambahkan!" << endl;
}

void viewServices()
{
    cout << "\n==== Data Layanan ====" << endl;
    if (serviceCount == 0)
    {
        cout << "Belum ada layanan yang terdaftar." << endl;
        return;
    }

    for (int i = 0; i < serviceCount; i++)
    {
        cout << "ID: " << services[i][0] << ", Nama: " << services[i][1]
             << ", Harga: Rp" << services[i][2] << ", Status: " << services[i][3] << endl;
    }
}

// Fungsi untuk memilih layanan
string chooseService()
{
    if (serviceCount == 0)
    {
        cout << "Belum ada layanan yang terdaftar." << endl;
        return "";
    }

    cout << "\n==== Pilih Layanan ====" << endl;
    // Menampilkan layanan dengan nomor urut
    for (int i = 0; i < serviceCount; i++)
    {
        if (services[i][3] == "Aktif")
        {
            cout << (i + 1) << ". " << services[i][1]
                 << " (Rp" << services[i][2] << ")" << endl;
        }
    }

    int choice;
    cout << "Pilih nomor layanan: ";
    cin >> choice;

    // Validasi pilihan
    if (choice > 0 && choice <= serviceCount)
    {
        if (services[choice - 1][3] == "Aktif")
        {
            return services[choice - 1][1]; // Mengembalikan nama layanan
        }
    }

    cout << "Pilihan layanan tidak valid." << endl;
    return "";
}

void viewPopularServices()
{
    string startDate, endDate;
    cout << "\n==== Layanan Populer ====" << endl;
    cout << "Masukkan tanggal awal (YYYYMMDD): ";
    cin >> startDate;
    cout << "Masukkan tanggal akhir (YYYYMMDD): ";
    cin >> endDate;

    string serviceNames[MAX_SERVICES];
    int serviceCounts[MAX_SERVICES];

    for (int i = 0; i < serviceCount; i++)
    {
        serviceNames[i] = services[i][1];
        serviceCounts[i] = 0;
    }

    // Menghitung penggunaan layanan dalam periode
    int totalTransactions = 0;
    for (int i = 0; i < reportCount; i++)
    {
        string transactionDate = reports[i][0].substr(0, 8);
        if (transactionDate >= startDate && transactionDate <= endDate)
        {
            totalTransactions++;
            // Mencari dan menambah counter layanan yang sesuai
            string serviceName = reports[i][3];
            for (int j = 0; j < serviceCount; j++)
            {
                if (serviceNames[j] == serviceName)
                {
                    serviceCounts[j]++;
                    break;
                }
            }
        }
    }

    // Mengurutkan layanan berdasarkan populer
    for (int i = 0; i < serviceCount - 1; i++)
    {
        for (int j = 0; j < serviceCount - i - 1; j++)
        {
            if (serviceCounts[j] < serviceCounts[j + 1])
            {
                // Tukar jumlah penggunaan
                int tempCount = serviceCounts[j];
                serviceCounts[j] = serviceCounts[j + 1];
                serviceCounts[j + 1] = tempCount;

                // Tukar nama layanan
                string tempName = serviceNames[j];
                serviceNames[j] = serviceNames[j + 1];
                serviceNames[j + 1] = tempName;
            }
        }
    }

    // Menampilkan hasil
    cout << "\nPeriode: " << startDate << " sampai " << endDate << endl;
    cout << "Total transaksi dalam periode: " << totalTransactions << endl;
    cout << "\nUrutan Layanan Berdasarkan Popularitas:" << endl;
    cout << "----------------------------------------" << endl;

    for (int i = 0; i < serviceCount; i++)
    {
        if (serviceCounts[i] > 0)
        {
            double percentage = (serviceCounts[i] * 100.0) / totalTransactions;
            cout << (i + 1) << ". " << serviceNames[i]
                 << "\n   Jumlah: " << serviceCounts[i] << " kali"
                 << " (" << fixed << setprecision(1) << percentage << "%)"
                 << endl;
        }
    }
}

void viewReportDaily()
{
    string targetDate;
    cout << "\n==== Laporan Harian ====" << endl;
    cout << "Masukkan tanggal (YYYYMMDD): ";
    cin >> targetDate;

    // Menghitung total pelanggan untuk hari sebelumnya
    string previousDate = to_string(stoll(targetDate) - 1);
    int previousCustomers = 0;
    for (int i = 0; i < reportCount; i++)
    {
        if (reports[i][0].substr(0, 8) == previousDate)
        {
            previousCustomers++;
        }
    }

    // Menghitung total pelanggan untuk hari target
    int targetCustomers = 0;
    for (int i = 0; i < reportCount; i++)
    {
        if (reports[i][0].substr(0, 8) == targetDate)
        {
            targetCustomers++;
        }
    }

    // Menghitung total pelanggan untuk hari setelahnya
    string nextDate = to_string(stoll(targetDate) + 1);
    int nextCustomers = 0;
    for (int i = 0; i < reportCount; i++)
    {
        if (reports[i][0].substr(0, 8) == nextDate)
        {
            nextCustomers++;
        }
    }

    // Menghitung rata-rata pelanggan per hari
    double averageCustomers = (previousCustomers + targetCustomers + nextCustomers) / 3.0;

    // Menampilkan laporan
    cout << "\nLaporan Tanggal " << targetDate << endl;
    cout << "--------------------------------" << endl;
    cout << "Total pelanggan hari sebelumnya (" << previousDate << "): " << previousCustomers << endl;
    cout << "Total pelanggan hari ini (" << targetDate << "): " << targetCustomers << endl;
    cout << "Total pelanggan hari berikutnya (" << nextDate << "): " << nextCustomers << endl;
    cout << "\nRata-rata pelanggan per hari: " << fixed << setprecision(1) << averageCustomers << endl;

    // Analisis tren
    cout << "\nAnalisis Tren Kunjungan:" << endl;
    cout << "--------------------------------" << endl;

    // Tren dari hari sebelumnya ke hari target
    if (targetCustomers > previousCustomers)
    {
        cout << "- Kunjungan meningkat " << (targetCustomers - previousCustomers)
             << " pelanggan dari hari sebelumnya" << endl;
    }
    else if (targetCustomers < previousCustomers)
    {
        cout << "- Kunjungan menurun " << (previousCustomers - targetCustomers)
             << " pelanggan dari hari sebelumnya" << endl;
    }
    else
    {
        cout << "- Kunjungan stabil dari hari sebelumnya" << endl;
    }

    // Tren ke hari berikutnya
    if (nextCustomers > targetCustomers)
    {
        cout << "- Kunjungan meningkat " << (nextCustomers - targetCustomers)
             << " pelanggan di hari berikutnya" << endl;
    }
    else if (nextCustomers < targetCustomers)
    {
        cout << "- Kunjungan menurun " << (nextCustomers - targetCustomers)
             << " pelanggan di hari berikutnya" << endl;
    }
    else
    {
        cout << "- Kunjungan stabil ke hari berikutnya" << endl;
    }
}

void viewReportStaff()
{
    string staffID;
    cout << "\n==== Laporan Per Staff ====" << endl;
    cout << "Masukkan ID Staff: ";
    cin >> staffID;

    int totalCustomers = 0;

    // Mencari nama staff
    string staffName;
    for (int i = 0; i < staffCount; i++)
    {
        if (staff[i][0] == staffID)
        {
            staffName = staff[i][1];
            break;
        }
    }

    cout << "\nLaporan Staff: " << staffName << " (ID: " << staffID << ")" << endl;
    cout << "--------------------------------" << endl;

    for (int i = 0; i < reportCount; i++)
    {
        if (reports[i][1] == staffID)
        {
            totalCustomers++;
            cout << "Pelanggan: " << reports[i][2] << ", Layanan: " << reports[i][3] << endl;
        }
    }

    cout << "\nTotal pelanggan dilayani: " << totalCustomers << endl;
}

void viewStaffPerformance()
{
    cout << "\n==== Kinerja Staff ====" << endl;
    cout << "--------------------------------" << endl;

    // Hitung total pelanggan per staff
    for (int i = 0; i < staffCount; i++)
    {
        int customerCount = 0;
        for (int j = 0; j < reportCount; j++)
        {
            if (reports[j][1] == staff[i][0])
            {
                customerCount++;
            }
        }
        cout << "Staff: " << staff[i][1] << " (ID: " << staff[i][0] << ")" << endl;
        cout << "Total pelanggan dilayani: " << customerCount << endl;
        cout << "Shift: " << staff[i][4] << endl;
        cout << "--------------------------------" << endl;
    }
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
    queue[queueCount][0] = to_string(queueCount + 1);
    cout << "Masukkan Nama Pelanggan: ";
    cin.ignore();
    getline(cin, queue[queueCount][1]);

    string selectedService = chooseService();
    if (selectedService.empty())
    {
        cout << "Gagal menambahkan antrian: Layanan tidak valid" << endl;
        return;
    }
    queue[queueCount][2] = selectedService;
    queue[queueCount][3] = "Menunggu";
    queue[queueCount][4] = "";

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
                if (queue[i][3] == "Proses" && queue[i][4] == staffID)
                {
                    cout << "Nomor Antrian " << queue[i][0] << " Atas Nama " << queue[i][1] << " Selesai" << endl;
                    queue[i][3] = "Selesai"; // Mengubah status antrian menjadi "Selesai"
                    viewQueue();

                    updateDateTime(); // Update waktu saat ini
                    reports[reportCount][0] = currentDateTime;
                    reports[reportCount][1] = staffID;
                    reports[reportCount][2] = queue[i][1];
                    reports[reportCount][3] = queue[i][2];
                    reportCount++;

                    return;
                }
            }
            cout << "Belum ada antrian yang di Proses oleh Anda" << endl;
            break;
        case 2:
            // Menjadikan Status Antrian Berikutnya "Proses"
            cout << "\n==== Status Antrian ====" << endl;
            for (int i = 0; i < queueCount; i++)
            {
                if (queue[i][3] == "Menunggu")
                {
                    cout << "Nomor Antrian " << queue[i][0] << " Atas Nama " << queue[i][1] << " di Proses" << endl;
                    queue[i][3] = "Proses";
                    queue[i][4] = staffID;
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

void updateDateTime()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);

    char datetime[20];
    strftime(datetime, sizeof(datetime), "%Y%m%d %H:%M", ltm);
    currentDateTime = datetime;
}
