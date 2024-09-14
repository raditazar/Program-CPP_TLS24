#include <iostream>
#include <vector> //list
#include <fstream> //file
#include <string> //manipulasi string
#include <algorithm> //search, sort, dll

using namespace std;

struct Task{ 
    int priority;
    string name;
    string deadline;
    string description;
};

vector<Task> tasks;
void saveFile(){
    ofstream file("tasks.txt");
    for(const auto &task : tasks){
        file << task.priority << "," << task.name << "," << task.deadline << "," << task.description << endl;
    }
    file.close();
}

void loadFile(){
    ifstream file("tasks.txt");
    if(!file.is_open()) return;

    string name, description, deadline;
    int priority;
    while(file >> priority) { 
        file.ignore();  
        getline(file, name, ',');  // Baca nama tugas
        getline(file, deadline, ',');  // Baca deadline tugas
        getline(file, description);  // Baca deskripsi tugas 
        tasks.push_back({priority, name, deadline, description});  // Tambahkan ke vektor
    }
    file.close();
}
bool sortPriority(const Task &a, const Task &b){
    return a.priority < b.priority;
}
void viewTasks(){
    if(tasks.empty()){
        cout << "Tidak ada tugas yang dapat ditampilkan." << endl;
        return;
    }
    sort(tasks.begin(), tasks.end(), sortPriority);
    for(size_t i = 0; i < tasks.size(); i++){
        cout << (i+1) << ". " << tasks[i].name
            
            << "\nDeadline: " << tasks[i].deadline
            << "\nDeskripsi: " << tasks[i].description 
            << "\n--------------------------" <<endl;
    }
}

void addTask(){
    Task task; 
    cout << "Masukkan nama tugas: ";
    cin.ignore();
    getline(cin, task.name);
    cout << "Deskripsi: ";
    getline(cin, task.description);
    cout << "Deadline (yyyy-mm-dd): ";
    getline(cin, task.deadline);
    cout << "Prioritas: ";
    cin >> task.priority;
    tasks.push_back(task);
    saveFile();
    cout << "Tugas telah ditambahkan!"<< endl;

}

void deleteTask(){
    int i;
    viewTasks();
    if(tasks.empty()){
        return;
    }

    cout << "Masukkan nomor tugas yang ingin dihapus: ";
    cin >> i;
    if(i > 0 && i <= tasks.size()){
        tasks.erase(tasks.begin()+i - 1);
        saveFile();
        cout << "Tugas berhasil dihapus!" << endl;
    }else{
        cout << "Nomor tugas tidak ditemukan" << endl;
    }
}

void editTask(){
    int i;
    viewTasks();
    if(tasks.empty()){
        cout << "Kamu belum punya tugas." << endl;
        return;
    }
    cout << "Masukkan nomor tugas yang ingin diedit: ";
    cin >> i;
    if(i > 0 && i <= tasks.size()){
        Task &task = tasks[i - 1];
        cout << "Masukkan deskripsi baru (sekarang: " << task.description << "): ";
        cin.ignore();
        getline(cin, task.description);
        cout << "Masukkan deadline baru (sekarang: " << task.deadline << "): ";
        getline(cin, task.deadline);
        cout << "Masukkan prioritas baru (sekarang: " << task.priority << "): ";
        cin >> task.priority;
        saveFile();
        cout << "Tugas berhasil diedit!" << endl;
    }else{
        cout << "Nomor tugas tidak ditemukan" << endl;
    }
}

int main(){
    loadFile();
    int choice;
    do{
        cout<<"=========Your To-Do List========\n";
        cout<<"1. Tampilkan tugas\n";
        cout<<"2. Tambah tugas\n";
        cout<<"3. Hapus tugas\n";
        cout<<"4. Edit tugas\n";
        cout<<"0. Keluar";
        cout<<"\nMasukkan pilihan: ";
        cin>>choice;

        switch (choice)
        {
        case 1:
            viewTasks();
            break;
        case 2:
            addTask();
            break;
        case 3:
            deleteTask();
            break;
        case 4:
            editTask();
            break;
        default:
            break;
        }
    }while(choice != 0);
}