// Brian Lu
// 15 mins in *xxxxxxx** what?
// 35 mins in *xxxxxxx** what?
// 

#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <algorithm>
#include <limits>

int main()
{
    int N;
    FILE *input = fopen("planting.in", "r");
    fscanf(input, "%d", &N);
    int fields[N];
    for (int i = 0; i < N; i++) {
        fields[i] = 0;
    }
    for (int i = 0; i < N; i++) {
        int f1, f2;
        fscanf(input, "%d", &f1);
        fields[f1-1]++;
        fscanf(input, "%d", &f2);
        fields[f2-1]++;
    }
    fclose(input);
    int max = 0;
    for (int i = 0; i < N; i++) 
        max = std::max(max, fields[i]);

    FILE *output = fopen("planting.out", "w");
    fprintf(output, "%d\n", max);
    fclose(output);

    return 0;
}