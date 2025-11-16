file_wordcnt(){
    local file="$1"
    if [ ! -e "$file" ]; then
        echo "$file 파일이 존재하지 않습니다."
        return 1
    fi
    local cnt=$(wc -w < "$file")
    echo "$file 파일의 단어는 $cnt개 입니다."
}

read -p "ENTER A FILE NAME : " FILE
file_wordcnt "$FILE"
echo "file_wordcnt 함수의 종료상태 : $? "