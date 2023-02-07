#include "JsonRepository.h"
#include "../JSONConverter/Json.h"
#include "../JSONConverter/Reader.h"

#include <stdexcept>

JsonRepository::JsonRepository(JsonFile data_mapper) : data_mapper(data_mapper) {
    std::vector<AbstractCard*> items(data_mapper.load());
    for (auto it = items.begin(); it != items.end(); it++) {
        repository[(*it)->getID()] = *it;
    }
}

JsonRepository::~JsonRepository() {
    for (auto it = repository.begin(); it != repository.end(); it++) {
        delete it->second;
    }
}

JsonRepository fromPath(std::string path) {
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

JsonRepository& JsonRepository::setPath(std::string path) {
    data_mapper.setPath(path);
    return *this;
}

JsonRepository& JsonRepository::create(AbstractCard* card) {
    repository[card->getID()] = card;
    return *this;
}

AbstractCard* JsonRepository::read(const unsigned int ID) const {
    std::map<unsigned int, AbstractCard*>::const_iterator cit = repository.find(ID);
    if (cit == repository.end()) {
        throw std::out_of_range("Trying to read an undefined id.");
    }
    return cit->second;
}

JsonRepository& JsonRepository::update(AbstractCard* card) {
    return create(card);
}

JsonRepository& JsonRepository::remove(const unsigned int ID) {
    std::map<unsigned int, AbstractCard*>::const_iterator cit = repository.find(ID);
    if (cit != repository.end()) {
        delete cit->second;
        repository.erase(cit);
    }
    return *this;
}

std::vector<AbstractCard*> JsonRepository::readAll() const {
    std::vector<AbstractCard*> items;
    for(auto cit = repository.begin(); cit != repository.end(); cit++) {
        items.push_back(cit->second);
    }
    return items;
}

JsonRepository& JsonRepository::store() {
    data_mapper.store(readAll());
    return *this;
}