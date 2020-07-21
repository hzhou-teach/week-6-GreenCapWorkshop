// Brian Lu
// After 15 mins *xxxxxxx** what?
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
    std::vector<int> fields[N];
    for (int i = 0; i < N; i++) {
        int f1, f2;
        fscanf(input, "%d %d", &f1, &f2);
        fields[f1-1].push_back(f2-1);
        fields[f2-1].push_back(f1-1);
    }
    fclose(input);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("i: %d, j: %d, value: %d\n", i, j, fields[i][j]);
        }
    }

    int max = 0;
    for (int i = 0; i < N; i++) 
        if ((size_t) max < fields[i].size())
            max = fields[i].size();

    FILE *output = fopen("planting.out", "w");
    fprintf(output, "%d\n", max);
    fclose(output);

    return 0;
}