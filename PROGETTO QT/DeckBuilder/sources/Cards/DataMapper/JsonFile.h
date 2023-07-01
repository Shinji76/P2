#ifndef JSON_FILE_H
#define JSON_FILE_H

#include "../AbstractCard.h"
#include "../Mazzo.h"
#include "../JSONConverter/Json.h"
#include "../JSONConverter/Reader.h"

#include <string>
#include <vector>

class JsonFile {
private:
	std::string path;
	Json& converter;

public:
	JsonFile(const std::string& path, Json& Jconverter);
	static JsonFile fromPath(const std::string& path);
	const std::string& getPath() const;
	JsonFile& setPath(const std::string& path);
    
	const Json& getConverter() const;
    
    JsonFile& store(const Mazzo mazzo);
    Mazzo load();
};

#endif  //JSON_FILE_H