#include <stdio.h>

int main() {
    float speed_mbps, size_mb;
    printf("Enter download speed (Mbps): ");
    scanf("%f", &speed_mbps);
    printf("Enter file size (MB): ");
    scanf("%f", &size_mb);
    
    float size_bits = size_mb * 1024 * 1024 * 8;
    float speed_bits_per_sec = speed_mbps * 1000000;
    float time_sec = size_bits / speed_bits_per_sec;
    
    printf("At %.2f megabits per second, a file of %.2f megabytes\n", speed_mbps, size_mb);
    printf("downloads in %.2f seconds.\n", time_sec);
    
    return 0;
}