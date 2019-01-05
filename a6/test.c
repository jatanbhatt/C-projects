int read_data(const char* name){

  float val;
  int res=3;
  int i = 0;
  FILE* fp=fopen(name,"r");

  if(fp==0)printf("\nFile not found\n");
  printf("\nREADING FILE '%s' \n",name);
  while((res==3)&&(i<SIZE)){
      res=fscanf(fp, "%f",&val);//x
      sensordata.x[i]=val;

      res+=fscanf(fp,"%f",&val);//y
      sensordata.y[i]=val;

      res+=fscanf(fp,"%f",&val);//z
      sensordata.z[i]=val;
      i++;






      // Assignment 3

      #include <stdio.h>
      #include <stdlib.h>
      #include <string.h>

      #define SIZE 1024

      typedef char stuname[32];
      typedef struct records{
        int num[SIZE];
        stuname name[SIZE];
      }stdrec;

      stdrec rec;
      FILE * fp;
      int matchingStudent(int j);
      void removeStudent(const int p, const int j);


      int read_data(const char* fname){
        int val;
        char nm[32];
        int count = 2;
        int i = 0;
        fp = fopen(fname,"r");
        printf("\n\nREADING FILE '%s' \n", fname);
        if (fp==0)printf("\nFile not found\n");
        else{
          while((count==2)&&(i<SIZE)){
          count = fscanf(fp, "%d", &val);
          rec.num[i] = val;

          count += fscanf(fp, "%s", nm);
          strcpy(rec.name[i], nm);
          i++;
        }
        i--;
        printf("\nNumber of students enrolled: %d\n\n", i);
      }
        fclose(fp);
        matchingStudent(i);
        return(i);
      }

      int matchingStudent(int j){
        int obj1 = 0;
        int obj2 = 0;
        while(obj1<j){
          while(obj2<j){
            if((rec.num[obj1]==rec.num[obj2])&&(obj1!=obj2)){
              printf("\n%s and %s have the same student number %d", rec.name[obj1], rec.name[obj2], rec.num[obj1]);
              removeStudent(obj2, j);
              return(0);
            }
            obj2++;
          }
          obj2=0;
          obj1++;
        }
        return (0);
      }

      void removeStudent(const int p, const int j){
        int k = p;
        while(k<j){
          //*rec.name[k] = rec.name[k+1];
          k++;
        }
      }

      void writeData(const char* fname, int start, int end){
          fp = fopen(fname, "w");
        while(start<=end){
          fprintf(fp, "%d\t", rec.num[start]);
          fprintf(fp, "%s\n", rec.name[start]);
          start++;
        }
      fclose(fp);
      }


      int findStudent(int number){
        int i = 0;
          while(rec.num[i]){
            if(number==rec.num[i]){
              printf("\nStudent number %d belongs to %s\n",number, rec.name[i]);
              return(i);
            }
            i++;
          }
        i--;
        return(-1);
      }

      void sort(){
        int r=0;
        int temp;
          while(r<rec.num[r]){
          int a = strcmp(rec.name[r],rec.name[r+1]);
            if(a<0){
              temp = rec.name[r];
              rec.name[r] = rec.name[r+1];
              rec.name[r+1] = temp;
              r = 0;
          }
          r++;
        }
      }


      int main(){
          read_data("students.txt");
          writeData("newstudents.txt",0,116);
          //findStudent(9516855);
          //sort();

          return(0);
      }
