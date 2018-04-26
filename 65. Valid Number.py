class Solution:
    def isNumber(self, s):
        return bool(re.match(r'^\s*[+-]?((\d+)|(\d+\.\d+)|(\.\d+)|(\d+\.))(e[+-]?\d+)?\s*$', s))