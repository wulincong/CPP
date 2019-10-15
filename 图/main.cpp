#include "MGraph.cpp"

int main(){
    MGraph G;
    FILE *fp;
    fp = fopen("TestData.txt","w");
    printf("OK");
    CreateGraph_M(fp,G);
    fclose(fp);

}
