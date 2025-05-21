#include "playlist.cpp"

int main()
{
    music pemandu_sorak = new Element_list("Pemandu sorak", "Porter Robinson", "Mom + Pop", 3.57);
    music sendirian = new Element_list("Sendirian", "Alan jalan", "Mer Musikk", 3.41);
    music kasih_sayang = new Element_list("Kasih sayang kepada orang tua", "mawang", "Mer Musikk", 2.27);

    playlist pop = playlist("pop");

    pop.insertLast(pemandu_sorak);
    pop.insertLast(sendirian);
    pop.insertLast(kasih_sayang);
    std::cout << pop.name << "\n";
    pop.display();
}