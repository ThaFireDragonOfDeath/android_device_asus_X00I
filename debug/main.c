#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

bool fm_checkFileExist(const char* sFilePath) {
    FILE* objTargetFile = fopen(sFilePath, "r");
    
    if(!objTargetFile) {
        return false;
    }
    else {
        fclose(objTargetFile);
        return true;
    }
}

int main(int argc, char* argv[]) {
    while(fm_checkFileExist("/data/lastdmesg_service/enable") == true) {
        system("/system/bin/dmesg > /data/lastdmesg_service/mast_dmesg.txt");
        sleep(30);
    }
    
    return 0;
}
