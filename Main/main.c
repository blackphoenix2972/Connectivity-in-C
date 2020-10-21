#include <stdio.h>
#include <stdlib.h>

#define N 10
#define NMAX 10

int arr[N];



void connect(int p, int q) {

    if (p == q  || p < 0 || p >= N || q < 0 || q >= N) {
         //if p and q are the same, or if p is invalid index or q is
        //invalid index, ignore the inputs and return early!
        return;
    }

    int valP = arr[p]; //find the respective position for p
    int valQ = arr[q]; //find the respective position for q
    arr[p] = arr[q]; //move arr[p]

    //whatever P turns into, the old valP must take over that new value... do a search on this criteria. this is what the for-loop below does
    int i;

    for(i = 0; i < N; i++) {
        if (arr[i] == valP) {
            arr[i] = arr[q];

        }
    }
    FILE *fptr;
     fptr = fopen("program.txt","a");

   if(fptr == NULL)
   {
      printf("Error!");
      exit(1);
   }
    for (i = 0; i < 1; i++) {


   fprintf(fptr,"%d %d",p, q);
    }
 for (i = 0; i < N; i++) {


   fprintf(fptr,"\t%d ",arr[i]);
    }
    fprintf(fptr,"\n",0);
   fclose(fptr);


}

void printArr(){

    int i;

    for(i = 0; i < NMAX; i++){ //at a maximum, go to only the 10th element.
       printf("%d ", arr[i]); //print each element separated by a space
    }

    printf("\n"); //insert a new line indicating end of printing

}

int main() {

    int i, p, q;
    int counter = 0;


    // Initialises the array {0,1,2,3,4,5,6,7,8,9}
    for(i = 0; i < N; i++) {

        arr[i] = i;

     }



    while(counter <= NMAX) {


     /*   if (scanf("%d %d", &p, &q) == EOF) {
            printf("LOOOL");
           break;

        }*/
    printf("Enter P: ");
    scanf("%d", &p);
    printf("Enter Q: ");
    scanf("%d", &q);
    printf("\n");
        connect(p, q);



        counter = counter + 1;



    }
    printf("p q     0\t1\t2\t3\t4\t5\t6\t7\t8\t9 \n"); //header of the table


    FILE *fp;
    char str[1000];
    char* filename = "program.txt";

    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }
    while (fgets(str, 1000, fp) != NULL)
        printf("%s", str);
        fclose(fopen("program.txt", "w"));
    fclose(fp);
    return 0;



    printArr();



}
