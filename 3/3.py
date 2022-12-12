def find_common_item(itemList1:str, itemList2:str)->str:
    return list(set(itemList1).intersection(set(itemList2)))[0]


def find_common_badge(itemList1:str, itemList2:str, itemList3:str)->str:
    commonSet = set(itemList1).intersection(set(itemList2))
    commonItems = list(commonSet.intersection(set(itemList3)))
    
    if commonItems.count('\n'):
        commonItems.remove('\n')
    
    return commonItems[0]


def calculate_item_priority(item:str)->int:
    if ord('a')<=ord(item):
        return 1 + ord(item)-ord('a')
    else:
        return 27 + ord(item)-ord('A')


def solve_part1()->int:
    prioritySum = 0

    with open("3/input.txt") as inputfile:
        for itemList in inputfile:
            itemListHalf = int(len(itemList) / 2)
            compartment1 = itemList[0:itemListHalf]
            compartment2 = itemList[itemListHalf:]

            commonItem = find_common_item(compartment1,compartment2)
            prioritySum += calculate_item_priority(commonItem)
    
    return prioritySum


def solve_part2()->int:
    prioritySum = 0

    with open("3/input.txt") as f:
        itemList1 = f.readline()
        itemList2 = f.readline()
        itemList3 = f.readline()
        while(itemList3):
            commonBadge = find_common_badge(itemList1, itemList2, itemList3)
            prioritySum += calculate_item_priority(commonBadge)
            itemList1 = f.readline()
            itemList2 = f.readline()
            itemList3 = f.readline()
    
    return prioritySum



if __name__ == "__main__":
    
    print(f"solution to part1: {solve_part1()}")
    print(f"solution to part2: {solve_part2()}")

