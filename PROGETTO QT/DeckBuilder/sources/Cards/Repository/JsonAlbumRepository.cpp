#include "JsonAlbumRepository.h"
#include "../JSONConverter/Json.h"
#include "../JSONConverter/Reader.h"

#include <stdexcept>

JsonAlbumRepository::JsonAlbumRepository(JsonFile data_mapper) : data_mapper(data_mapper) {
    std::vector<AbstractCard*> cards(data_mapper.load());   //leggo tutte le carte puntate dal datamapper 
    for(auto cit = cards.begin(); cit != cards.end(); cit++) {
        repository[(*cit)->getID()] = *cit;
    }
}

JsonAlbumRepository::~JsonAlbumRepository() {
    for(auto it = repository.begin(); it != repository.end(); it++) {
        delete it;
    }
}

JsonAlbumRepository JsonAlbumRepository::fromPath(std::string path) {
    Reader reader;
    Json converter(reader);
    JsonFileAlbum data_mapper(path, converter);
    JsonAlbumRepository repository(data_mapper);
    return repository;
}

const JsonFile& JsonAlbumRepository::getDataMapper() const {
    return data_mapper;
}

const std::map<unsigned int, AbstractCard*>& JsonAlbumRepository::getRepository() const {
    return repository;
}

const std::string& JsonAlbumRepository::getPath() const {
    return data_mapper.getPath();
}

std::vector<AbstractCard*> JsonAlbumRepository::readAll() const {
    std::vector<AbstractCard*> cards;
    for(auto cit = repository.begin(); cit != repository.end(); cit++) {
        cards.push_back(*cit);
    }
    return cards;
}

std::vector<AbstractCard*> JsonAlbumRepository::readClass(AbstractCard::Classe classe) const {
    std::vector<AbstractCard*> cards;
    for(auto cit = repository.begin(); cit != repository.end(); cit++) {
        if(cit->getClasse() == classe || cit->getClasse() == 0) //Filto la classe scelta + le neutrali
            cards.push_back(*cit);
    }
    return cards;
}

JsonAlbumRepository& JsonAlbumRepository::store() {
    data_mapper.store(readAll());
    return *this;
}