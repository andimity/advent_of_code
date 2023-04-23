import copy

FILENAME = "9/input.txt"

class Position:
    def __init__(self, x:int, y:int) -> None:
        self.x = x
        self.y = y
    
    def __eq__(self, other) -> bool:
        return self.x == other.x and self.y == other.y
    
    def __repr__(self) -> str:
        return f"({self.x},{self.y})"


class Knot:
    def __init__(self) -> None:
        self.position = Position(0,0)
        self.visitedPositions = [Position(0,0)]
    
    def update_visited_positions(self) -> None:
        newPosition = copy.deepcopy(self.position)
        if newPosition not in self.visitedPositions:
            self.visitedPositions.append(newPosition)

    def move(self, direction:str) -> None:
        if direction == 'U':
            self.position.y += 1
        elif direction == 'D':
            self.position.y -= 1
        elif direction == 'R':
            self.position.x += 1
        elif direction == 'L':
            self.position.x -= 1
        else:
            raise Exception("invalid direction")


class Rope:
    def __init__(self) -> None:
        self.head = Knot()
        self.tail = Knot()

    def tail_adjacent_to_head(self) -> bool:
        distanceX = abs(self.head.position.x - self.tail.position.x)
        distanceY = abs(self.head.position.y - self.tail.position.y)
        return not (distanceX > 1 or distanceY > 1)

    
    def tail_adjacent_to_head_vertically(self) -> bool:
        distanceX = abs(self.head.position.x - self.tail.position.x)
        distanceY = abs(self.head.position.y - self.tail.position.y)
        return distanceX == 1 and distanceY == 1


    def update_tail_position(self, direction:str):
        self.tail.move(direction)
        if self.tail_adjacent_to_head_vertically():
            if direction == 'U' or direction == 'D':
                self.tail.position.x = self.head.position.x
            elif direction == 'L' or direction == 'R':
                self.tail.position.y = self.head.position.y
        self.tail.update_visited_positions()


    def move_head(self, direction:str) -> None:
        self.head.move(direction)
        self.head.update_visited_positions()
        if not self.tail_adjacent_to_head():
            self.update_tail_position(direction)
            
        


if __name__ == "__main__":

    rope = Rope()

    with open(FILENAME, 'r') as f:
        instructions = f.readlines()

    for instruction in instructions:
        direction = instruction.split()[0]
        steps = int(instruction.removeprefix(f"{direction} ").removesuffix('\n'))
        for _ in range(steps):
            rope.move_head(direction)
    
    print(f"solution to part 1: {len(rope.tail.visitedPositions)}")
    