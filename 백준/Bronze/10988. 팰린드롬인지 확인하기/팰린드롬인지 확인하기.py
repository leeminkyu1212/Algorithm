

word=list(input())
word2=word.copy()
word2.reverse()

word=''.join(word)
word2=''.join(word2)

if word==word2 :
  print(1)
else : print(0)