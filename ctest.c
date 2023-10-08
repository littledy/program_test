#include <time.h>
#include <stdio.h>

int main() {

    time_t ct;
    struct tm* tmInfo;
    char tmString[100];
    time(&ct);
    tmInfo = localtime(&ct);
    strftime(tmString, sizeof(tmString), "%Y-%m-%d %H:%M:%S", tmInfo);
    printf("%s\n", tmString);

    return 0;
}