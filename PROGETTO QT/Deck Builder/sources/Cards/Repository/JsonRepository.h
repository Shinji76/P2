#ifndef JSON_REPOSITORY_H
#define JSON_REPOSITORY_H

#include "../AbstractCard.h"
#include "../DataMapper/JsonFile.h"

#include <string>
#include <map>

class JsonRepository {
private:
    JsonFile data_mapper;
    std::map<unsigned int, AbstractCard*> repository;

public:
    JsonRepository(JsonFile data_mapper);
    virtual ~JsonRepository();
    
    static JsonRepository fromPath(const std::string path);
    const std::string& getPath() const;
    JsonRepository& setPath(std::string path);
    
    const JsonFile& getDataMapper() const;
    const std::map<unsigned int, AbstractCard*>& getRepository() const;

    virtual JsonRepository& create(AbstractCard* card);
    virtual AbstractCard* read(const unsigned int ID) const;
    virtual JsonRepository& update(AbstractCard* card);
    virtual JsonRepository& remove(const unsigned int ID);
    virtual std::vector<AbstractCard*> readAll() const;
    virtual std::vector<AbstractCard*> readClass(AbstractCard::Classe classe) const;
    JsonRepository& store();
};

#endif  //JSON_REPOSITORY_H