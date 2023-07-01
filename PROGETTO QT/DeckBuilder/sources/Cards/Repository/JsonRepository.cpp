#include "JsonRepository.h"
#include "../JSONConverter/Json.h"
#include "../JSONConverter/Reader.h"

#include <stdexcept>

JsonRepository::JsonRepository(JsonFile data_mapper) : data_mapper(data_mapper) {
    std::vector<AbstractCard*> cards(data_mapper.load());   //leggo tutte le carte puntate dal datamapper 
    for(auto cit = cards.begin(); cit != cards.end(); cit++) {
        repository[(*cit)->getID()] = *cit;
    }
}

JsonRepository::~JsonRepository() {
    for(auto it = repository.begin(); it != repository.end(); it++) {
        delete it->second;
    }
}

JsonRepository JsonRepository::fromPath(std::string path) {
    Reader reader;
    Json converter(reader);
    JsonFile data_mapper(path, converter);
    JsonRepository repository(data_mapper);
    return repository;
}

const JsonFile& JsonRepository::getDataMapper() const {
    return data_mapper;
}

const std::map<unsigned int, AbstractCard*>& JsonRepository::getRepository() const {
    return repository;
}

const std::string& JsonRepository::getPath() const {
    return data_mapper.getPath();
}

JsonRepository& JsonRepository::setPath(std::string set) {
    data_mapper.setPath(set);
}

std::vector<AbstractCard*> JsonRepository::readAll() const {
    std::vector<AbstractCard*> cards;
    for(auto cit = repository.begin(); cit != repository.end(); cit++) {
        cards.push_back(cit->second);
    }
    return cards;
}

JsonRepository& JsonRepository::store() {
    data_mapper.store(readAll());
    return *this;
}