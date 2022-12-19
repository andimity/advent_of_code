import re

class item:
    def __init__(self, name:str, size:int, parents:str):
        self.name = name
        self.size = size
        self.parents = parents

    def __repr__(self) -> str:
        return f"{self.name}:{self.size}:{self.parents}"


def execute_command(command:str):

    if not command.startswith('cd'):
        return

    global currentPath
    targetDir = command.removeprefix('cd ').removesuffix('\n')
    if targetDir == '..':
        latestDirectory = currentPath.rsplit(sep='/')[-2]
        currentPath = currentPath.removesuffix(f"{latestDirectory}/")
    else:
        currentPath += (f"{targetDir}/")


def directory_size(directoryName:str)->int:
    global filesystem
    directorySize = 0
    for file in filesystem:
        if file.parents.count(directoryName):
            directorySize += file.size

    return directorySize


def sum_directory_sizes_smaller_than(limit:int)->int:
    global directories
    sum = 0
    for directory in directories:
        size = directory_size(directory)
        if size<=limit:
            sum += size
    
    return sum


def smallest_directory_larger_than(limit:int)->int:
    global directories
    smallestDirectorySize = None

    for directory in directories:
        size = directory_size(directory)
        if size>=limit:
            if (smallestDirectorySize==None or size<smallestDirectorySize):
                smallestDirectorySize = size
    
    return smallestDirectorySize


if __name__ == "__main__":

    DISC_SIZE = 70000000
    UPDATE_SIZE = 30000000
    
    currentPath:str = ''
    filesystem:list[item] = []
    directories:list[str] = ['/']

    with open("./7/input.txt") as inputfile:
        lines = inputfile.readlines()

    for line in lines:
        if line.startswith('$'):    
            execute_command(command=line.removeprefix("$ "))
            continue

        elif line.startswith('dir'):
            directoryName = line.removeprefix('dir ').removesuffix('\n')
            directories.append(f"{currentPath}{directoryName}")
            continue

        itemSize,itemName =  re.search(f"(.+) (.+)", line).groups()
        newItem = item(name=itemName,size=int(itemSize),parents=currentPath)
        filesystem.append(newItem)
    
    print(f"solution to part 1: {sum_directory_sizes_smaller_than(100000)}")

    missingSpace = UPDATE_SIZE - (DISC_SIZE - directory_size('/'))
    print(f"solution to part 2: {smallest_directory_larger_than(missingSpace)}")