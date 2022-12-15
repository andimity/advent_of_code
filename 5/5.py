import re
import copy

FILENAME = "5/input.txt"

# for simplicity I imported the initial stacks manually from the input (bottom to top!)
INITIAL_STACKS = [
    list("NSDCVQT"),
    list("MFV"),
    list("FQWDPNHM"),
    list("DQRTF"),
    list("RFMNQHVB"),
    list("CFGNPWQ"),
    list("WFRLCT"),
    list("TZNS"),
    list("MSDJRQHN"),
]


def move_single_crates(stacks:list, quantity:int, source:int, target:int):
    for _ in range(quantity):
        crate = stacks[source].pop()
        stacks[target].append(crate)


def move_multiple_crates(stacks:list, quantity:int, source:int, target:int):
    crates:list = stacks[source][-quantity:]
    for _ in range(quantity):
        stacks[source].pop()
    stacks[target].extend(crates)


if __name__ == "__main__":
    stacksPart1 = copy.deepcopy(INITIAL_STACKS)
    stacksPart2 = copy.deepcopy(INITIAL_STACKS)

    with open(FILENAME, 'r') as f:
        instructions = f.readlines()

    for instruction in instructions:
        variables = re.search(f"move (.+) from (.+) to (.+)",instruction)
        quantity = int(variables.group(1))
        source = int(variables.group(2)) - 1
        target = int(variables.group(3)) - 1

        move_single_crates(stacksPart1,quantity,source,target)
        move_multiple_crates(stacksPart2,quantity,source,target)
    
    result1 = "".join(stack[-1] for stack in stacksPart1)
    result2 = "".join(stack[-1] for stack in stacksPart2)
    print(f"solution to part 1: {result1}")
    print(f"solution to part 2: {result2}")