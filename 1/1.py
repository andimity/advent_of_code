def array_from_inputfile(filename:str)->list:
    rows = []
    column = []

    with open(filename, 'r') as f:
        lines = f.readlines()

    for line in lines:
        if line == '\n':
            rows.append(column)
            column = []
        else:
            column.append(int(line.strip()))
    
    return rows


def vector_sum(vector:list):
    sum = 0
    for entry in vector:
        sum += entry
    
    return sum


elves = array_from_inputfile(filename='./1/input.txt')
calories = [vector_sum(elf) for elf in elves]
calories.sort(reverse=True)

print(f"solution to part 1: {calories[0]}")
print(f"solution to part 2: {vector_sum(calories[0:3])}")
    