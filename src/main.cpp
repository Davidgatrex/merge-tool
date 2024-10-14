#include <iostream>

int main(int argc, char **argv){
    if(argc < 4){
        printf("Not enough arguments\n");
        return 1;
    }
    const char *F1 = argv[1];
    const char *F2 = argv[2];
    FILE *df = fopen(argv[3], "w");
    FILE *fa = fopen(F1, "r");
    FILE *fb = fopen(F2, "r");
    fseek(fa, 0L, SEEK_END);
    int l1 = ftell(fa);
    rewind(fa);
    fseek(fb, 0L, SEEK_END);
    int l2 = ftell(fb);
    rewind(fb);
    char *buff1 = (char *)malloc(l1*sizeof(char));
    char *buff2 = (char *)malloc(l2*sizeof(char));
    fread(buff1, sizeof(char), l1, fa);
    fread(buff2, sizeof(char), l2, fb);
    fwrite(buff1, sizeof(char), l1, df);
    fseek(df, 0L, SEEK_END);
    fwrite(buff2, sizeof(char), l2, df);
    fclose(df);
    fclose(fa);
    fclose(fb);
    printf("Done\n");
}