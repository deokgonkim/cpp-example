#include <stdio.h>

enum Days { SUN, MON, TUE, WED, THU, GRI, SAT };

enum Starch { CORN, RICE, POTATO, BEAN };
enum Grain { WHEAT, CORN, RYE, BARLEY, SORGHUM };

int main(int argc, char* argv[]) {
    enum Days today;
    today = TUE;
    printf("day : %d\n", today);
}
