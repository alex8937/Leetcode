class Robot:
  def __init__(self, mapping, i, j):
    self.mapping = mapping
    self.i = i
    self.j = j
  def move(self, dir):
    if dir == 0:
      if self.j == len(self.mapping[0]) - 1 or self.mapping[self.i][self.j + 1] == 1:
        return False
      self.j += 1
    if dir == 1:
      if self.i == 0 or self.mapping[self.i - 1][self.j] == 1:
        return False
      self.i -= 1    
    if dir == 2:
      if self.j == 0 or self.mapping[self.i][self.j - 1] == 1:
        return False
      self.j -= 1
    if dir == 3:
      if self.i == len(self.mapping) - 1 or self.mapping[self.i + 1][self.j] == 1:
        return False
      self.i += 1
    return True

x = [0, 1, 0, -1]
y = [1, 0, -1, 0]


def getArea(rob):
  """
  >>> rob = Robot([[1,0,0,0,0,0],[1,1,1,0,1,0],[0,0,1,0,0,0],[0,0,0,1,0,0],[1,0,0,0,0,0],[1,1,0,0,1,0],[0,0,0,1,0,0]], 0, 3)
  >>> getArea(rob)
  30
  >>> rob = Robot([[0,1,0],[0,0,0],[0,0,0],[0,0,1]], 0, 0)
  >>> getArea(rob)
  10
  """
  def dfs(visit, i, j):
    visit.add((i, j))
    for k in range(4):
      newi, newj = i + x[k], j + y[k]
      if (newi, newj) in visit or not rob.move(k):
        continue
      dfs(visit, newi, newj)
      rob.move((k + 2) % 4)
  visit = set()
  dfs(visit, 0, 0)
  return len(visit)
    
def main():
  map1 = [[1,0,0,0,0,0],[1,1,1,0,1,0],[0,0,1,0,0,0],[0,0,0,1,0,0],[1,0,0,0,0,0],[1,1,0,0,1,0],[0,0,0,1,0,0]]
  ans = 0
  for i in map1:
    for j in i:
      ans += (j == 0)
  print(ans)
  rob = Robot(map1, 0, 3)
  print(getArea(rob))
  
if __name__== "__main__":
  main()    

