package main

import "fmt"

func fullJustify(words []string, maxWidth int) []string {
	var res []string
	var i int = 0
	for i < len(words) {
		word := words[i]
		if len(word) == maxWidth {
			res = append(res, word)
		} else if i == len(words)-1 {
			for n := len(word); n < maxWidth; n++ {
				word += " "
			}

			res = append(res, word)
		} else {
			var l = len(word) + 1
			var lineWord string = word + " "
			var tmpWords = []string{word}

			for l <= maxWidth+1 && i < len(words)-1 {
				i++
				lineWord += words[i] + " "
				l = len(lineWord)
				tmpWords = append(tmpWords, words[i])
			}

			i--
			if i == len(words)-2 && l <= maxWidth+1 {
				lineWord := lineWord[:len(lineWord)-1]
				for n := len(lineWord); n < maxWidth; n++ {
					lineWord += " "
				}

				res = append(res, lineWord)
				break
			}

			tmpWords = tmpWords[:len(tmpWords)-1]
			allWordsLen := 0
			for _, w := range tmpWords {
				allWordsLen += len(w)
			}

			var blacnkLen = maxWidth - allWordsLen
			if len(tmpWords) == 1 {
				tmpWord := tmpWords[0]
				for n := len(tmpWord); n < maxWidth; n++ {
					tmpWord += " "
				}

				res = append(res, tmpWord)
			} else {
				var count int = 0
				var rightSpace = blacnkLen / (len(tmpWords) - 1)
				var leftSpecialNum = blacnkLen % (len(tmpWords) - 1)
				var lineWord = ""
				for count < 2*len(tmpWords)-1 {
					if count%2 == 0 {
						lineWord += tmpWords[count/2]
					} else {
						for n := 0; n < rightSpace; n++ {
							lineWord += " "
						}

						if leftSpecialNum > 0 {
							leftSpecialNum--
							lineWord += " "

						}
					}
					count++
				}

				res = append(res, lineWord)
			}
		}
		i++
	}

	return res
}

func main() {
	// words := []string{"This", "is", "an", "example", "of", "text", "justification."}
	words := []string{"ask", "not", "what", "your", "country", "can", "do", "for", "you", "ask", "what", "you", "can", "do", "for", "your", "country"}
	r := fullJustify(words, 16)
	for _, w := range r {
		r := fmt.Sprintf("%s_", w)
		fmt.Println(r)
	}
}
