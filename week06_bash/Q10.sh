#!/bin/bash

print_param(){
    echo "1.스크립트 이름 : $0"
    echo "2.첫 번째 파라미터 : $1"
    echo "3.두 번째 파라미터 : $2"
    echo "4.모든 파라미터 : $@"
    echo "5.파라미터의 개수 : $#"
}

print_param "Hello" "World" "!"