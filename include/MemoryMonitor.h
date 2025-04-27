#include <fstream>
#include <string>
#include <iostream>
using namespace std ;
struct MemoryInfo {
    long total;
    long free;
    long used;
};
MemoryInfo getMemoryInfo() {
    ifstream meminfo("/proc/meminfo");
    string line;
    long total_memory = 0, free_memory = 0, available_memory = 0;
    while (std::getline(meminfo, line)) {
        if (line.find("MemTotal:") == 0) {
            sscanf(line.c_str(), "MemTotal: %ld kB", &total_memory);
        }
        else if (line.find("MemAvailable:") == 0) {
            sscanf(line.c_str(), "MemAvailable: %ld kB", &available_memory);
            break;
        }
    }
    free_memory = available_memory;
    long used_memory = total_memory - free_memory;
    return {total_memory, free_memory, used_memory};
}
