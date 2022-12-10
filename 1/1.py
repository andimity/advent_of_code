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


elves = array_from_inputfile(filename='./1/input.txt')
print(elves[0])
    