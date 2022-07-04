#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint-gcc.h>

#define MAXSIZE_P   400
#define MAXLENGTH   100
#define DEFAULT_N   10
char *line_buffer[MAXSIZE_P];
char alloc_buffer[10000];
int32_t alloc_buffer_p;
int32_t line_buffer_p;
int32_t temp;
int32_t number_of_lines = DEFAULT_N;
void input();
void input_to_buffer(char *[], char[]);
void output(char *[]);

int main(int argc, char *argv[]) 
{
    input();
    if(argc == 2) {
        for(int i = 0; i < 10; i++) {
            if(line_buffer_p-- > 0)
                printf("%s\n", line_buffer[line_buffer_p]);
        }       
    }
    else if(argc == 3 || argc > 4)
        printf("wrong input");
    else if(argc == 4 && argv[2][0] == '-' && argv[2][1] == 'n') {
        int32_t t = atoi(argv[3]);
        for(int i = 0; i < t; i++) {
            if(line_buffer_p-- > 0)
            printf("%s\n", line_buffer[line_buffer_p]);
        }
    }
    return 0;
}

void input() 
{
    char c;
    int32_t count;
    while((c = getchar()) != EOF) {
        count++;
        if(alloc_buffer_p < 10000)
            alloc_buffer[alloc_buffer_p++] = c;
        if(c == '\n' && line_buffer_p < MAXSIZE_P) {
            alloc_buffer[alloc_buffer_p - 1] = '\0';
            line_buffer[line_buffer_p] = &alloc_buffer[temp];
            // printf("%d %s \n", alloc_buffer_p, *line_buffer);
            temp = alloc_buffer_p;
            line_buffer_p++;
            count = 0;
        }
    }
    if(count > 0 && line_buffer_p < MAXSIZE_P) {
        alloc_buffer[alloc_buffer_p - 1] = '\0'; 
        line_buffer[line_buffer_p] = &alloc_buffer[temp];
        temp = alloc_buffer_p;       
        line_buffer_p++;
    }
}
