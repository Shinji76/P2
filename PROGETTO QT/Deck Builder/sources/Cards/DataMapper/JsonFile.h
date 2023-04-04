#ifndef JSON_FILE_H
#define JSON_FILE_H

#include "../AbstractCard.h"
#include "../JSONConverter/Json.h"
#include "../JSONConverter/Reader.h"

#include <string>
#include <vector>

class JsonFile {
private:
	std::string path;
	Json& converter;

public:
	JsonFile(const std::string& path, Json& Jconverter);        //costruttore 
	static JsonFile fromPath(const std::string& path);
    
	const std::string& getPath() const;
	JsonFile& setPath(const std::string& path);
    
	const Json& getConverter() const;
    
	JsonFile& store(const std::vector<AbstractCard*> cards);	//salvataggio in Json
	std::vector<AbstractCard*> load();
};

#endif  //JSON_FILE_H