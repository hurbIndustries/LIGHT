//  LIGHT
//  update.cpp
//  Copyright 2024 - hurbIndustries
//  JPD

#include <cstdio>
#include <fstream>
#include <filesystem>
#include <iostream>
#include <curl/curl.h>
#include <json/json.h>
#include <opencxx-cli/cli.h>
#include "../include/funcs.h"
#include "curl/easy.h"

using namespace std;
using namespace light;
opencxx_cli::CLI cli;

size_t writeFile(char *ptr, size_t size, size_t nmemb, void *userdata) {
    FILE *stream = (FILE*)userdata;
    if(!stream) {
        cli.error("writeFile(): NO STREAM.");
        return 1;
    }

    size_t written = fwrite((FILE*)ptr, size, nmemb, stream);
    return written;
}

int downloadEach(string url, string name) {
    CURLcode res;
    CURL *easy = curl_easy_init();
    string fn = "/var/light/"+name+"/repo.json";

    if(!filesystem::exists(fn)) {
        cli.info("NEW REPOSITORY: "+name);
        //filesystem::create_directories(fn);
    }

    FILE *fp = fopen(fn.c_str(), "wb");

    url = url.append("/light/repo.json");
    cli.info("Downloading: "+url);

    curl_easy_setopt(easy, CURLOPT_URL, url.c_str());
    curl_easy_setopt(easy, CURLOPT_USERAGENT, "libcurl-agent/1.0");
    curl_easy_setopt(easy, CURLOPT_WRITEDATA, fp);
    curl_easy_setopt(easy, CURLOPT_WRITEFUNCTION, writeFile);
    res = curl_easy_perform(easy);
    if(res != CURLE_OK) {
        cli.error("CURL: "+res);
        return 1;
    }
    curl_easy_cleanup(easy);
    return 0;
}

int updateRepositories() {
    Json::Reader reader;
    Json::Value data;
    ifstream f;
    std::string s;
    if(filesystem::exists("/etc/light/repositories.json")) {
        f.open("/etc/light/repositories.json");
        reader.parse(f, data);
        for(int i = 0; i < data.size(); i++) {
            cli.info("Downloading repository: "+data[i]["name"].asString());
            downloadEach(data[i]["url"].asString(), data[i]["name"].asString());
        }
    } else {
        cli.error("/etc/repositories.json not found! Try reinstalling LIGHT.");
        return 1;
    }
}

int funcs::update() {
    updateRepositories();
}