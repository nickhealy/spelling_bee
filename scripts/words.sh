WORD_LIST_URL='https://raw.githubusercontent.com/dwyl/english-words/master/words_alpha.txt'
OUTPUT='words.txt'
TEMP=${OUTPUT}_temp.txt
EXTRA_WORDS='extra_words.txt'
EXCLUDE_WORDS='exclude_words.txt'
BEE_ARCHIVE_URLS='urls.txt'

ARCHIVE_URL_BASE='https://www.shunn.net/bee/s/'
ARCHIVE_ID_OFFSET=21 # seemingly arbitrary, this is just where it starts

# rm $OUTPUT

# cp $EXCLUDE_WORDS "${EXCLUDE_WORDS}_bak.txt"
# rm $EXCLUDE_WORDS

num_bees() {
    # there has been a bee every day since this date
    first_online_bee="2018-05-29"
    now=$(date +%s)
    past=$(date +%s --date $first_online_bee)
    difference=$(($now-$past))
    echo $(($difference/(3600*24)))
}

get_archive_paths() {
    rm $BEE_ARCHIVE_URLS
    NUM_BEES=$(num_bees)
    for (( i=0; i<=$NUM_BEES; i++ ))
    do  
        # echo $1 >> urls.txt
        BEE_ID=$(($i + $ARCHIVE_ID_OFFSET))
        echo "url=$ARCHIVE_URL_BASE$BEE_ID" >> $BEE_ARCHIVE_URLS
    done
    echo "urls to archives written to $BEE_ARCHIVE_URLS"
}

refresh_word_list() {
    get_archive_paths
}

filtered() {
    # filter words for length
    awk 'length($0) > 4' $1 | \
    grep -v -w -f $EXCLUDE_WORDS >> $OUTPUT
}

# curl | htmlq --attribute string input[name='string']

refresh_word_list

# wget -O $TEMP $WORD_LIST_URL
# filtered $TEMP
# filtered $EXTRA_WORDS

# rm $TEMP
