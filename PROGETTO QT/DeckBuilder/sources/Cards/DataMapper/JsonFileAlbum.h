#ifndef JSON_FILE_ALBUM_H
#define JSON_FILE_ALBUM_H

#include "../AbstractCard.h"
#include "../Mazzo.h"
#include "../JSONConverter/Json.h"
#include "../JSONConverter/Reader.h"

#include <string>
#include <vector>

class JsonFileAlbum {
private:
	std::string path;
	Json& converter;

public:
	JsonFileAlbum(const std::string& path, Json& Jconverter); 
	static JsonFileAlbum fromPath(const std::string& path);
	const std::string& getPath() const;    
	const Json& getConverter() const;
    std::vector<AbstractCard*> loadAlbum() const;
};

#endif  //JSON_FILE_ALBUM_H