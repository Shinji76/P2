//enum class per la rarità con underlying type definito (in teoria se non specificato dovrebbe essere comunque int, ma l'ho messo per sicurezza), le enum class Razza e Classe sono equivalenti a questa
enum class Rarita : int {
    Comune,
    Rara,
    Epica,
    Leggendaria
};

//Metodo readMostro per la creazione della classe concreta leggendo un QJsonObject
AbstractCard* Reader::readMostro(const QJsonObject& object) const {
    return new Mostro(
        object.value("ID").toInt(),
        object.value("Nome").toString().toStdString(),
        object.value("Effetto").toString().toStdString(),
        object.value("Mana").toInt(),
        object.value("Rarita").toInt(),     //da sistemare con enum
        object.value("Classe").toInt(),     //da sistemare con enum
        object.value("Path").toString().toStdString(),
        object.value("Razza").toInt(),      //da sistemare con enum
        object.value("Attacco").toInt(),
        object.value("Difesa").toInt(), 
    );
}

//Esempio di costruttore funzionante di mostro
new Mostro(01,"nome", "effetto", 1, Rarita::Epica , Classe::Cacciatore, "image_path", Razza::Murloc, 1, 1);

//Esempio di cosa vorrei avere
new Mostro(01,"nome", "effetto", 1, 0 , 1, "image_path", 5, 1, 1);

//Oltre a questo problema principale del costruttore, nel file Album.json ho salvato i valori di Rarita Classe e Razza come stringhe per rendere come mi aveva detto a ricevimento il JSON leggibile senza per forza conoscere il contenuto del programma, quindi nel caso si riuscisse a chiamare il costruttore con gli interi, sarebbe meglio cambiare il JSON o dovrei scrivere un "interprete" che legge la stringa e ritorna un intero corrispondente?