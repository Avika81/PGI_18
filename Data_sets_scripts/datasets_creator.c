#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#define NUM_OF_PRINTF_FILES 0
#define NUM_OF_ARITMETIC_FILES 1000
#define MAX_PRINTF_STRING 150

#define NEW_FILE_MOD 0640

void Reverse(char* s) {
    /**************************************************************
   * function name:Reverse
   * Input: char* buffer
   * output: none
   * The function operation: Reverse the letters in the buffer
     * (used in atoi),in example :[1,2,3,4] will become [4,3,2,1]
   * ************************************************************/
    int i, j;
    char c;

    for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void IntToString(int n, char* s) {
    /**************************************************************
    * function name:Itoa
    * Input: int n,and a char* buffer
    * output: none
    * The function operation: make the integer into a astring and put
     * it into the buffer,(this code was taken from wikipedia)
    * ************************************************************/
    int i, sign;

    if ((sign = n) < 0)  /* record sign */
        n = -n;          /* make n positive */
    i = 0;
    do {       /* generate digits in reverse order */
        s[i++] = n % 10 + '0';   /* get next digit */
    } while ((n /= 10) > 0);     /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    Reverse(s);
}

int CompileCFile(char* buffer,char* name) {
    /**************************************************************
     * function name:CompileCFile
     * Input: string
     * output: compiling the string and returns the compilers answer
     * ************************************************************/

    pid_t pid;
    int status;
    int resultFromSon;
    char* toExe[10];
    //toExe will contain: gcc fileName.c,this is the line I want to run
    //with execvp
    toExe[0] = "gcc";
    toExe[1] = "-O0";
    toExe[2] = "-S";
    toExe[3] = "-o";
    toExe[4] = name;
    toExe[5] = buffer;
    toExe[6] = NULL;
    pid=fork();//open new process child
    if(pid==0) {
        execvp("gcc", (char *const *) toExe);//the proccess ends here
        perror("execvp of compilation failed");
    }
    else
    {
        wait(&status);
        resultFromSon=WEXITSTATUS(status);
        if(resultFromSon == 0)
            return 1; // return true because the compilation succeeded.
        else
            return -1;//Can't compile:
    }//threre is only 1 c file
}

char* newString(char* buffer) {
    int r = rand() % MAX_PRINTF_STRING;
    for(int i=0;i < r;i++)
    {
        buffer[i]=( rand() % ('z'-'a') ) +'a';
    }
}

void CreatePrintfFiles() {
    int i;
    for(i=0;i<NUM_OF_PRINTF_FILES;i++)
    {
        char name[100] = "printFile";
        char newName[100];
        char temp[400];
        IntToString(i,temp);
        strcat(name,temp);
        strcpy(newName,name);
        strcat(name,".c");
        strcat(newName,".asm");
        int newF = open(name,O_CREAT | O_RDWR ,NEW_FILE_MOD);//opening results.cs
        char buffer[1000] = "#include <stdio.h>\nint main(){\nprintf(\"";
        newString(temp);
        strcat(buffer,temp);
        strcat(buffer,"\");\n}\n");
        write(newF,buffer,strlen(buffer));
        CompileCFile(name,newName);
    }

}

void RandArithmetic(char *buffer) {
    int length;
    length = rand() % 5 + 1;
    for (int i=0;i<length;i++)
    {
        char temp[40] = "";
        int r = rand() % 100 + 1;

        IntToString(r,temp);
        strcat(buffer,temp);

        int a = rand() % 4;
        switch(a)
        {
            case 0:strcat(buffer," + ");break;
            case 1:strcat(buffer," - ");break;
            case 2:strcat(buffer," * ");break;
            case 3:strcat(buffer," / ");break;
        }
    }
    strcat(buffer,"5;\n");
}

void CreateAritmeticFiles() {
    int i;
    for(i=0;i<NUM_OF_ARITMETIC_FILES;i++)
    {
        char name[100] = "aritmeticFile";
        char newName[100];
        char temp[20];
        IntToString(i,temp);
        strcat(name,temp);
        strcpy(newName,name);
        strcat(name,".c");
        strcat(newName,".asm");
        int newF = open(name,O_CREAT | O_RDWR ,NEW_FILE_MOD);//opening results.cs
        char buffer[200] = "#include <stdio.h>\nint main(){\n int a=0;\na = ";
        char aritmeticThingi[1000] = {};
        RandArithmetic(aritmeticThingi);
        strcat(buffer,aritmeticThingi);
        strcat(buffer,"printf(\" a = %d\",a);\n}");

        write(newF,buffer,strlen(buffer));
        CompileCFile(name,newName);
    }
}

int main() {
    CreatePrintfFiles();
    CreateAritmeticFiles();
}
