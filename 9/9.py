import copy

FILENAME = "9/test.txt"

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
        self.update_visited_positions()


# TODO
def tail_adjacent_to_head() -> bool:
    return False


def move_head_and_tail(direction:str, steps:int) -> None:
    global head
    global tail
    for _ in range(steps):
        head.move(direction)
        if not tail_adjacent_to_head():
            tail.move(direction)
            
        


if __name__ == "__main__":

    head = Knot()
    tail = Knot()

    with open(FILENAME, 'r') as f:
        instructions = f.readlines()

    for instruction in instructions:
        direction = instruction.split()[0]
        steps = int(instruction.removeprefix(f"{direction} ").removesuffix('\n'))
        move_head_and_tail(direction,steps)
    
    print(f"{tail.visitedPositions}")
    