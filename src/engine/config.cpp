#include <string>
#include <vector>
// #include <regex>

#include "config.h"
#include "yaml-cpp/yaml.h"
#include <boost/filesystem.hpp>
#include <boost/regex.hpp>
#include <iostream>

#include "utils/logger.h"

namespace pl {

void Config::load() {
    // TODO Replace boost regex with std regex. libc++ issues right now
    // TODO If C++ supports filesystem, implement that instead of boost

    // auto path = "data/config/";
    boost::filesystem::path path = boost::filesystem::current_path() / "data/config/";
    auto cwd = boost::filesystem::canonical(path).string();
    LOG(INFO) << "Cwd: " + cwd;

    boost::filesystem::recursive_directory_iterator itr(path);
    boost::regex yamlRegex{"(.*.[(yaml|yml)])$",
                           boost::regex_constants::ECMAScript | boost::regex_constants::icase};

    YAML::Node newConfig;
    while (itr != boost::filesystem::recursive_directory_iterator()) {
        if (!boost::filesystem::is_directory(itr->path())) {
            auto dirPath = itr->path().string();
            LOG(INFO) << "Original: " + dirPath;
            if (boost::regex_match(dirPath, yamlRegex)) {
                YAML::Node node = YAML::LoadFile(dirPath);
                auto key = parsePath(dirPath, cwd);
                newConfig[key] = node;
                // this->configs.emplace(key, node);
            } else {
                LOG(INFO) << "Not a YAML file.";
            }
        }
        ++itr;
    }
    this->config = newConfig;
    return;
}

YAML::Node Config::get(std::string key) {
    return this->config[key];
}

std::string Config::parsePath(std::string path, std::string cwd) {
    path.replace(path.find(cwd), cwd.length(), "");
    path.replace(path.find("/"), 1, "");
    boost::regex yamlFile{"(.yaml|.yml)$",
                          boost::regex_constants::ECMAScript | boost::regex_constants::icase};
    auto result = boost::regex_replace(path, yamlFile, "");
    LOG(INFO) << result;
    return result;
}
}
