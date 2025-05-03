
struct MemoryInfo {
    DWORDLONG total;
    DWORDLONG free;
    DWORDLONG used;
};

MemoryInfo getMemoryInfo() {
    MEMORYSTATUSEX memInfo;
    memInfo.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&memInfo);

    DWORDLONG total_memory = memInfo.ullTotalPhys;
    DWORDLONG free_memory = memInfo.ullAvailPhys;
    DWORDLONG used_memory = total_memory - free_memory;

    return {total_memory, free_memory, used_memory};
}
