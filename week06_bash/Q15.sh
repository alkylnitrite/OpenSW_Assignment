file_wordcnt(){
    local file="$1"
    local cnt=$(wc -w < "$file")
    echo "$file 파일의 단어는 $cnt개 입니다."
}

read -p "ENTER A FILE NAME : " FILE
file_wordcnt "$FILE"