#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include "yaml-cpp/yaml.h"

namespace pl {
class Config {

public:
    void load();
    YAML::Node get(std::string);

private:
    YAML::Node config;
    // std::map<std::string, YAML::Node> configs;
    std::string parsePath(std::string path, std::string cwd);
};
}
#endif
