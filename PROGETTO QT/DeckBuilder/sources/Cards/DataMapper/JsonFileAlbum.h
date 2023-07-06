#ifndef JSON_FILE_ALBUM_H
#define JSON_FILE_ALBUM_H

#include "../AbstractCard.h"
#include "../Mazzo.h"
#include "../JSONConverter/JsonAlbum.h"
#include "../JSONConverter/Reader.h"
#include "../../Vector_template.h"

#include <string>

class JsonFileAlbum {
private:
	std::string path;
	JsonAlbum& converter;
    FixedVector<AbstractCard*, 50> album;

public:
    JsonFileAlbum(const std::string& path, JsonAlbum& Jconverter);
    
	static JsonFileAlbum& fromPath(const std::string& path);
	const std::string& getPath() const;    
	const JsonAlbum& getConverter() const;
    FixedVector<AbstractCard*,50> loadAlbum() const;
    FixedVector<AbstractCard*, 50> loadClass(AbstractCard::Classe classe) const;
};

#endif  //JSON_FILE_ALBUM_H
