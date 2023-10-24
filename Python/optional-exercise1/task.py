import math

class Player:
    def __init__(self, name):
        self.__name = name
        self.hp = 10
        self.xp = 0
    
    @property
    def level(self):
        if self.xp < 300: return 1
        else: return 2 + int(math.log2(int(self.xp/300)))
    
    @property
    def name(self):
        return self.__name

    def increase_xp(self, inc_xp):
        self.xp += inc_xp
        
    def decrease_hp(self, damage):
        if self.hp - damage < 0: self.hp = 0
        else: self.hp -= damage
    
    def __str__(self):
        return f"Player: {self.name}, XP: {self.xp}, HP: {self.hp}, Level: {self.level}"

p = Player("p1")
print(p)
p.increase_xp(10)
p.decrease_hp(5)
print(p)
p.decrease_hp(10)
print(p)
p.increase_xp(600)
print(p)
print(p.name)
print(p.level)