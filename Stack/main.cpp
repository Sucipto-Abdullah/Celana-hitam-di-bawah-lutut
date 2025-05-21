#include "stack.cpp"

int main()
{
    dosa dosa_1 = new node_stack("Joki tugas", 20, "17-april-2025", false);
    dosa dosa_2 = new node_stack("Copy Paste Chat-GPT", 5, "12-april-2025", false);
    dosa dosa_3 = new node_stack("Maling Gorengan", 30, "12-april-2025", false);
    dosa dosa_4 = new node_stack("Ngirim stiker Hitam", 45, "12-april-2025", true);
    dosa dosa_5 = new node_stack("nggak bayar hutang", 20, "18-april-2025", false);

    stack gunawan = stack();

    gunawan.push(dosa_1);
    gunawan.push(dosa_2);
    gunawan.tobat();

    gunawan.push(dosa_3);
    gunawan.push(dosa_4);
    gunawan.push(dosa_5);

    gunawan.display();

}