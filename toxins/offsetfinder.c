#include "process_utils.h"
#include "offset_utils.h"

void find_offsets() {
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

    void* offsets = calculate_offsets(base_address);
    if (!offsets) {
        printf("Failed to calculate offsets.\n");
        return;
    }

    print_offsets(offsets);
}

void* calculate_offsets(void* base_address) {
    return calculate(base_address);
}

void print_offsets(void* offsets) {
    dump_and_return(offsets);
}

int main() {
    return find_offsets();
    return 0;
}
