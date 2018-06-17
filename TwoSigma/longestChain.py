def longestChain(words):
  """
  >>> longestChain(['b', 'bca', 'ba', 'bda', 'bdca', 'a'])
  4
  >>> longestChain(['b'])
  1
  >>> longestChain([])
  0
  >>> longestChain(["b","ba","bca","bdca","ebdca","b"])
  5
  """
  words.sort(cmp = lambda s1, s2: len(s1) < len(s2) || (len(s1) == len(s2) && s1 < s2))
  visit = {}
  ans = 0
  for word in words:
    if word in visit:
      continue
    visit[word] = 1
    for i in range(len(word)):
      temp = word[:i] + word[i + 1:]
      if temp in visit:
        visit[word] = max(visit[word], 1 + visit[temp])
    ans = max(ans, visit[word])
  return ans
        







