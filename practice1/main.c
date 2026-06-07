#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    const char* name;
    
    if (argc > 1) {
        name = argv[1];
    }
    else {
        // Windows
        name = getenv("USERNAME");
        
        // Linux/macOS
        if (name == NULL) {
            name = getenv("USER");
        }
        
        if (name == NULL) {
            name = "мир";
        }
    }
    
    printf("Привет, %s!\n", name);
    return 0;
}