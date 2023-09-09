#ifndef JSON_FILE_ALBUM_H
#define JSON_FILE_ALBUM_H

#include "../AbstractCard.h"
#include "../Mazzo.h"
#include "../JSONConverter/JsonAlbum.h"
#include "../JSONConverter/Reader.h"
#include "../../Vector_template.h"
#include "../Album.h"

#include <vector>
#include <string>

class JsonFileAlbum {
private:
	std::string path;
	JsonAlbum& converter;
    FixedVector<AbstractCard*> album;

    int parser(QJsonValue value);

public:
    JsonFileAlbum(const std::string& path, JsonAlbum& Jconverter);
    
	static JsonFileAlbum& fromPath(const std::string& path);
	const std::string& getPath() const;    
	const JsonAlbum& getConverter() const;
    const Album& loadAlbum();
    const std::vector<const AbstractCard*>& loadClass(AbstractCard::Classe classe) const;
};

#endif  //JSON_FILE_ALBUM_H
