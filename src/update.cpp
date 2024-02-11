//  LIGHT
//  update.cpp
//  Copyright 2024 - hurbIndustries
//  JPD

#include <fstream>
#include <filesystem>
#include <iostream>
#include <curl/curl.h>
#include <json/json.h>
#include <opencxx-cli/cli.h>
#include "../include/funcs.h"

using namespace std;
using namespace light;

int downloadEach(std::string url) {
    CURLcode res;
    CURL *easy = curl_easy_init();

}

int updateRepositories() {
    Json::Reader reader;
    Json::Value data;
    opencxx_cli::CLI cli;
    fstream f;
    std::string s;
    if(filesystem::exists("/etc/repositories.json")) {
        f.open("/etc/repositories.json");
        reader.parse(f, data);
        for(int i = 0; i < data.size(); i++) {
            cli.info("Downloading repository: "+data[i]["name"].asString());
        }
    } else {
        cli.error("/etc/repositories.json not found! Try reinstalling LIGHT.");
        return 1;
    }
}

int funcs::update() {

}