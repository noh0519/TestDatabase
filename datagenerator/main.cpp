#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
    printf("Hello!\n");

    // generate data
    int data_cnt = 10000000;
    nlohmann::json j;
    for (int i = 0; i < data_cnt; i++) {
        j["idx"][i] = i;
        std::string name = "이름" + std::to_string(i);
        j["name"][i] = name.c_str();
        std::string address = "주소" + std::to_string(i);
        j["address"][i] = address.c_str();
    }

    // store file
    ofstream ofs;
    ofs.open("./data.json", ios_base::trunc);
    ofs << setw(4) << j << endl;

    return 0;
}