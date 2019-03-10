class PropertyTest:
    def __init__(self, name, score):
        self._name = name
        self._score = score

    @property
    def score(self):
        return self._score

    @score.setter
    def score(self, value):
        self._score = value

s = PropertyTest('huyang', 100)
print (s.score)

s.score = 120
print (s.score)