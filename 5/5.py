import re

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



def execute_inctruction(stacks:list, quantity:int, source:int, target:int):
    for _ in range(quantity):
        cargo = stacks[source].pop()
        stacks[target].append(cargo)


if __name__ == "__main__":

    stacks = INITIAL_STACKS

    with open(FILENAME, 'r') as f:
        instructions = f.readlines()

    for instruction in instructions:
        variables = re.search(f"move (.+) from (.+) to (.+)",instruction)
        quantity = int(variables.group(1))
        source = int(variables.group(2)) - 1
        target = int(variables.group(3)) - 1

        execute_inctruction(stacks,quantity,source,target)
    
    result = "".join(stack[-1] for stack in stacks)
    print(result)