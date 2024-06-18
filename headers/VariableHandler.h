//
// Created by May Thu Htun on 13/04/2024.
//

#ifndef SDICWK_VARIABLEHANDLER_H
#define SDICWK_VARIABLEHANDLER_H

#include <vector>
#include <string>
#include <iostream>
#include <curl/curl.h>
#include "json.hpp"
#include "LocationManager.h"

using json = nlohmann::json;

class VariableHandler{
public:
    /* function writeCallback() is modified from
     * https://gist.github.com/alghanmi/c5d7b761b2c9ab199157
     * date accessed 6 March 2024
     */
    static size_t writeCallback(void *ptr, size_t size, size_t nmemb, std::string *stream) {
        size_t dataSize = size * nmemb;
        stream->append(static_cast<char*>(ptr), dataSize);
        return dataSize;
    }
    std::string sendGetRequest(const std::string&);
    bool chooseVariables(std::string);
    std::string formatVariables (std::vector<std::pair<std::string, std::string>>, std::string);
    void getDataFromAPI (std::string, std::string, std::string);
    void exportDataToJson (json& , std::string );
};


#endif //SDICWK_VARIABLEHANDLER_H
