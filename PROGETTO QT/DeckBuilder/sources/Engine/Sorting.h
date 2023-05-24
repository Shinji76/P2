#include "../Cards/Repository/JsonRepository.h"

#include <map>

class Sorting {
private:
    JsonRepository read;
public:

};

/*
Leggere JSON
Salvare Nome/Mana con relativo ID in mappa locale
Ordinare vettore locale
Leggere ID corrispondente e visualizzare carta nell'ordine della mappa locale 
*/

class Sorting {
public:
    Sorting(const std::map<unsigned int, AbstractCard*> &cards) : cards(cards) {}

    std::vector<AbstractCard*> sortByNameAscending() {
        std::vector<AbstractCard*> result;
        for (const auto &pair : cards) result.push_back(pair.second);
        std::sort(result.begin(), result.end(), [](const auto &a, const auto &b) {
            return a->getNome() < b->getNome();
            }
            );
        return result;
    }

    std::vector<AbstractCard*> sortByNameDescending() {
        std::vector<AbstractCard*> result;
        for (const auto &pair : cards)
            result.push_back(pair.second);
        std::sort(result.begin(), result.end(), [](const auto &a, const auto &b) { return a->getNome() > b->getNome(); });
        return result;
    }

    std::vector<AbstractCard*> sortByManaCostAscending() {
        std::vector<AbstractCard*> result;
        for (const auto &pair : cards) result.push_back(pair.second);
        std::sort(result.begin(), result.end(), [](const auto &a, const auto &b) { return a->getManaCost() < b->getManaCost(); });
        return result;
    }

    std::vector<AbstractCard*> sortByManaCostDescending() {
        std::vector<AbstractCard*> result;
        for (const auto &pair : cards) result.push_back(pair.second);