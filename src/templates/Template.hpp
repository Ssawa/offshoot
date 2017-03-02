#ifndef Template_hpp
#define Template_hpp

#include <string>
#include <map>
#include <stdio.h>

class Template {
public:
	
private:
	std::string platform;
};

std::map<std::string, Template> gatherTemplates(std::string ofPath) {
	std::map<std::string, Template> templates;
	return templates;
}

#endif
