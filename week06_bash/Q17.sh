file_wordcnt(){
    files=$(ls *.txt)
    for file in $files; do
        cnt=$(cat $file | wc -w)
        echo "$file 파일의 단어는 $cnt개 입니다."
    done
}
file_wordcnt 