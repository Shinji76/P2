#ifndef JSON_FILE_H
#define JSON_FILE_H

#include "../AbstractCard.h"
#include "../Mazzo.h"

#include <string>
#include <vector>

class JsonFile {
private:
	std::string path;
    Mazzo mazzo;

public:
	JsonFile(const std::string& path);
	const std::string& getPath() const;
	JsonFile& setPath(const std::string& path);
    
    JsonFile& store(const Mazzo mazzo);
    Mazzo& load();
};

#endif  //JSON_FILE_H