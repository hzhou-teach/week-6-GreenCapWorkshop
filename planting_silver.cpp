// Brian Lu
// 15 mins in *xxxxxxx** what?
// 35 mins in *xxxxxxx** what?
// 40 mins in ********** turns out I just cannot read. 
// Input was N-1 lines and I was some other garbage from an extra line or something
//
// For the design of this i just started drawing a lot of trees on paper and this strategy looked ok.
// Pulled my hair out thinking it was wrong for a little while though.
// I think the moral of the story is to read more when in doubt.

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
    for (int i = 0; i < N-1; i++) {
        int f1, f2;
        fscanf(input, "%d %d", &f1, &f2);
        fields[f1-1].push_back(f2-1);
        fields[f2-1].push_back(f1-1);
    }
    fclose(input);

    int max = 0;
    for (int i = 0; i < N; i++) 
        max = std::max((size_t) max, fields[i].size());

    FILE *output = fopen("planting.out", "w");
    fprintf(output, "%d\n", max+1);
    fclose(output);

    return 0;
}