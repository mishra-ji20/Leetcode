func minExtraChar(s string, dictionary []string) int {
    wordsAvailable := make (map[string]int)
    for _,word := range dictionary {
        wordsAvailable[word]=1;
    }
    minLeftAloneLetter := make([]int,len(s)+1)
    for i := 1;i<=len(s);i++ {
        minLeftAloneLetter[i] = math.MaxInt64;
        word := ""
        for j :=i ;j>0;j-- {
            word = string(s[j-1]) + word;
            var wordCheck = wordsAvailable[word]
            helperSum := 0
            if(wordCheck == 1){
                helperSum = 0
            }else{
                helperSum = len(word)
            }
            minLeftAloneLetter[i] = int(math.Min(float64(helperSum + minLeftAloneLetter[j-1]),float64(minLeftAloneLetter[i])))
        }
        // fmt.Println(minLeftAloneLetter[i])
        
    }
    return minLeftAloneLetter[len(s)];
    
}