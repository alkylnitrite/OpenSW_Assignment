#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>

#define BUF_SIZE 32

int main(int argc, char *argv[]){
    if(argc < 3){
        printf("Usage: %s [source file] [destination file1] [destination file2] ...\n", argv[0]);
        exit(1);
    }

    char *src = argv[1];

    int src_fd = open(src, O_RDONLY);
    if(src_fd < 0){
        perror("Source file open error");
        exit(1);
    }

    int dest_count = argc - 2;
    int *dest_fd = (int *)malloc(sizeof(int) * dest_count);
    if(dest_fd == NULL){
        perror("malloc error");
        close(src_fd);
        exit(1);
    }

    for(int i = 0; i < dest_count; i++){
        dest_fd[i] = open(argv[i + 2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if(dest_fd[i] < 0){
            perror("Destination file open error");
            for(int j = 0; j < i; j++) close(dest_fd[j]);
            free(dest_fd);
            close(src_fd);
            exit(1);
        }
    }
    char buffer[BUF_SIZE];
    int read_result;

    while(1){
        read_result = read(src_fd, buffer, BUF_SIZE);

        if(read_result < 0){
            perror("read error");
            break;
        }
        else if(read_result == 0){
            break;
        }

        if(write(STDOUT_FILENO, buffer, read_result) != read_result){
            perror("stdout write error");
            break;
        }

        for(int i = 0; i < dest_count; i++){
            if(write(dest_fd[i], buffer, read_result) != read_result){
                perror("destination write error");
                break;
            }
        }
    }

    for(int i = 0; i < dest_count; i++)
        close(dest_fd[i]);

    close(src_fd);
    free(dest_fd);

    return 0;
}

