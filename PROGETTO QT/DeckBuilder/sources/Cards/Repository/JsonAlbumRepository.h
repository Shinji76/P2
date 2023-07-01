#ifndef JSON_ALBUM_REPOSITORY_H
#define JSON_ALBUM_REPOSITORY_H

#include "../AbstractCard.h"
#include "../DataMapper/JsonFileAlbum.h"

#include <string>
#include <map>

class JsonAlbumRepository {
private:
    JsonFileAlbum data_mapper;
    FixedVector<AbstractCard*, 50> repository;

public:
    JsonAlbumRepository(JsonFileAlbum data_mapper);
    virtual ~JsonAlbumRepository();
    
    static JsonAlbumRepository fromPath(const std::string path);
    const std::string& getPath() const;

    const JsonFileAlbum& getDataMapper() const;
    const std::map<unsigned int, AbstractCard*>& getRepository() const;

    virtual std::vector<AbstractCard*> readAll() const;
    virtual std::vector<AbstractCard*> readClass(AbstractCard::Classe classe) const;
};

#endif  //JSON_ALBUM_REPOSITORY_H