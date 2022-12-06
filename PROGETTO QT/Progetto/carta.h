#ifndef CARTA_H
#define CARTA_H

#include <iostream>

class carta {
private:
    unsigned int ID;
    std::string nome_carta;
public:
    
    carta();
    std::string getNome() const;
    virtual ~carta() = 0;
};
#endif // CARTA_H
