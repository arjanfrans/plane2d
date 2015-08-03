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
    // auto path = "data/config/";
    boost::filesystem::path path = boost::filesystem::current_path() / "data/config/";
    auto cwd = boost::filesystem::canonical(path).string();

    auto configFiles = std::vector<std::string>();
    boost::filesystem::recursive_directory_iterator itr(path);
    LOG(INFO) << "Starting walk";
    boost::regex yamlRegex{"(.*.[(yaml|yml)])$", boost::regex_constants::ECMAScript};
    while (itr != boost::filesystem::recursive_directory_iterator()) {
        auto dirPath = itr->path().string();
        LOG(INFO) << "Original: " + dirPath;
        LOG(INFO) << boost::regex_match(dirPath, yamlRegex);
        if (boost::regex_match(dirPath, yamlRegex)) {
            LOG(INFO) << "Cwd: " + cwd;
            auto configPath = dirPath.replace(dirPath.find(cwd), cwd.length(), "");
            LOG(INFO) << dirPath;
        } else {
            LOG(INFO) << "Not a YAML file.";
        }
        // std::cout << itr->path().string() << std::endl;
        ++itr;
    }

    // YAML::Node node = YAML::Load("[1, 2, 3]");
}
}
