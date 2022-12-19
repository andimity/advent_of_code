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
        latestDirectory = currentPath.rsplit(sep='/')[-1]
        # print(f"path removed: {currentPath.rsplit(sep='/')[-2]}")
        currentPath.removesuffix(f"/{latestDirectory}")
    else:
        currentPath += (f"{targetDir}/")


def directory_size(directoryName:str)->int:
    global filesystem
    directorySize = 0
    for file in filesystem:
        if file.parents.count(directoryName):
            directorySize += file.size

    return directorySize


if __name__ == "__main__":
    
    currentPath:str = ''
    filesystem:list[item] = []
    directories:list[str] = ['/']

    with open("./7/test.txt") as inputfile:
        lines = inputfile.readlines()

    for line in lines:
        if line.startswith('$'):    
            execute_command(command=line.removeprefix("$ "))
            continue

        elif line.startswith('dir'):
            directoryName = line.removeprefix('dir ').removesuffix('\n')
            directories.append(directoryName)
            continue

        itemSize,itemName =  re.search(f"(.+) (.+)", line).groups()
        itemParents = currentPath.split(sep='/')[2:-1]
        itemParents.append('/')
        newItem = item(name=itemName,size=int(itemSize),parents=itemParents)
        filesystem.append(newItem)

    for directory in directories:
        print(f"{directory}:{directory_size(directory)}")