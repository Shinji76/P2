#ifndef JSON_REPOSITORY_H
#define JSON_REPOSITORY_H

#include "../AbstractCard.h"
#include "../DataMapper/JsonFile.h"

#include <string>
#include <map>

class JsonRepository {
private:
    JsonFile data_mapper;
    FixedVector<AbstractCard*, 50> repository;
    //potrebbe essere il caso di sostituire la mappa con il fixed vector per gestire i mazzi

public:
    JsonRepository(JsonFile data_mapper);
    virtual ~JsonRepository();
    
    static JsonRepository fromPath(const std::string path);
    const std::string& getPath() const;
    JsonRepository& setPath(std::string set);
    const JsonFile& getDataMapper() const;
    const std::map<unsigned int, AbstractCard*>& getRepository() const;

    virtual std::vector<AbstractCard*> readAll() const;
    JsonRepository& store();
};

#endif  //JSON_REPOSITORY_H