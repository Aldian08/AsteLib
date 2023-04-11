#include <iostream>
using namespace std;

class Stack {
private: // Struktur Stack
    int size; // Ukuran Stack
    int top; // Variabel untuk data paling atas
    int* S; // Pointer untuk nilai
public:
    Stack(int size); // Membuat parameter untuk nilai data 
    ~Stack(); // Untuk menghapus dari memori
    void push(int x); // Fungsi push (untuk menambah data)
    int pop(); // Fungsi pop (untuk mengambil/ menghapus data)
    int peek(int index); // Fungsi peek (untuk melihat data berada) 
    int isFull(); // Fungsi isFull, mengecek apakah Stack penuh atau tidak
    int isEmpty(); // Fungsi isEmpty, mengcek apakah Stack kosong atau tidak
    void display(); // Fungsi untuk menamplikan data
    int stackTop(); // Fungsi untuk mengecek data yang berada paling atas
};

Stack::Stack(int size) { // Membuat ukuran Stack dahulu
    this->size = size; // size di public sama dengan size di private diatas
    top = -1; // Atur top Stack ke -1
    S = new int[size]; // Membuat head ke memori 
}

Stack::~Stack() {
    delete[] S; // setelah menggunakannya untuk head 
}

void Stack::push(int x) { // Fungsi untuk menambahkan data ke top Stack
    if (isFull()) { // Mengecek jika Stack penuh maka data tidak bisa ditambahkan 
        cout << "Stack Overflow!" << endl; // Untuk menampilkan bahwa Stack penuh 
    }
    else { // Jika Stack tidak penuh maka
        top++; // Increment top 
        S[top] = x; // Dan tambahkan data ke Stack 
    }
}

int Stack::pop() {// Mengambil atau menghapus data dari Stack 
    int x = 1; // Atur variabel x menjadi 1
    if (isEmpty()) { // Mengecek jika Stack kosong maka data tidak bisa dihapus
        cout << "Stack Underflow!" << endl; // Untuk menampilkan bahwa Stack kosong 
    }
    else { // Jika Stack tidak kosong maka
        x = S[top]; // Mengambil data dan mengurangi jumlah Stack sebelumnya
        top--; // Mengurangi ukuran Stack sebelumnya
    }
    return x;
}

int Stack::peek(int index) { // Mengetahui data dari Stack dengan index tertentu
    int x = -1;
    if (top - index + 1 < 0 || top - index + 1 == size) { // Mengecek apakah index tersedia atau tidak; Harus lebih dari 0 dan kurang dari ukuran Stack
        cout << "Invalid position!" << endl; // Menampilkan ini jika index tidak tersedia
    }
    else {
        x = S[top - index + 1]; // Dan jika index tersedia, maka akan diambil
    }
    return x; // Dan mengembalikannya
}

int Stack::isFull() { // Mengecek apakah Stack penuh atau tidak
    if (top == size - 1) { 
        return 1;
    }
    return 0;
}

int Stack::isEmpty() { // Mengecek apakah Stack kosong atau tidak
    if (top == -1) {
        return 1;
    }
    return 0;
}

void Stack::display() { // Fungsi untuk menampilkan Stack secara wajar
    for (int i = top; i >= 0; i--) {
        cout << S[i] << " | " << flush;
    }
    cout << endl;
}

int Stack::stackTop() {
    if (isEmpty()) {
        return -1;
    }
    return S[top];
}


int main() {

    int A[] = { 1, 3, 5, 7, 9 };
// Disini kita membuat data Stack
    Stack stk(sizeof(A) / sizeof(A[0]));

    // Ubah Stack dengan Array
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
        stk.push(A[i]);
    }
    stk.push(11);

    cout << "Stack full: " << stk.isFull() << endl;

    // Menampilkan Stack;
    cout << "Stack: " << flush;
    stk.display();

    // Peek data
    cout << "Peek at 0th: " << stk.peek(0) << endl;
    cout << "Peek at 3rd: " << stk.peek(3) << endl;
    cout << "Peek at 10th: " << stk.peek(10) << endl;

    // Top data
    cout << "Top element: " << stk.stackTop() << endl;

    // Mengambil data
    cout << "Popped out elements: " << flush;
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
        cout << stk.pop() << ", " << flush;
    }
    cout << endl;
    stk.pop();

    cout << "Stack empty: " << stk.isEmpty() << endl;

    return 0;
}
