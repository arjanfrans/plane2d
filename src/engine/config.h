#ifndef CONFIG_H
#define CONFIG_H

#include "yaml-cpp/yaml.h"

namespace pl {
class Config {

public:
    void load();
    YAML::Node get(std::string);

private:
    std::map<std::string, YAML::Node> configs;
};
}
#endif
