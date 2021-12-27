WORD_LIST_URL='https://raw.githubusercontent.com/dwyl/english-words/master/words_alpha.txt'
OUTPUT='words.txt'
TEMP=${OUTPUT}_temp.txt
EXTRA_WORDS='extra_words.txt'

rm $OUTPUT

filtered() {
    # filter words for length
    awk 'length($0) > 4' $1 >> $OUTPUT
}

wget -O $TEMP $WORD_LIST_URL
filtered $TEMP
filtered $EXTRA_WORDS

rm $TEMP
