#include "process_utils.h"
#include "memory_utils.h"
#include "websocket_utils.h"

void inject_executor() {
    int pid = find_process_running("Roblox");
    if (pid == -1) {
        printf("Roblox not running.\n");
        return;
    }
    
    void* base_address = get_base_address(pid);
    if (!base_address) {
        printf("Failed to get base address.\n");
        return;
    }
    
    void* executor_code = load_executor_code("executor.bin.ms-v2");
    if (!executor_code) {
        printf("Failed to load executor code.\n");
        return;
    }
    
    inject_code(pid, base_address, executor_code);
    printf("Injection complete.\n");
}

void* load_executor_code(const char* file_path) {
    return load_binary(file_path);
}

int main() {
    printf("Plant Engine initialising");
    initialize_websocket();
    inject_executor();
    prinf("Plant Engine initialised!");
    return 0;
}
