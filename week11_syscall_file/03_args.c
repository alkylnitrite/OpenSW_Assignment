//프로그램 실행 시 전달된 모든 인자를 인덱스와 함께 출력하는 03_args.c를 작성하시오. 인자의 개수에는 제한이 없습니다.
#include <stdio.h>

int main(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    return 0;
}