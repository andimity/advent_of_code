def find_common_item(itemList1:str, itemList2:str)->str:
    return list(set(itemList1).intersection(set(itemList2)))[0]


def calculate_item_priority(item:str)->int:
    if ord('a')<=ord(item):
        return 1 + ord(item)-ord('a')
    else:
        return 27 + ord(item)-ord('A')


if __name__ == "__main__":
    
    prioritySum = 0

    with open("3/input.txt") as inputfile:
        for itemList in inputfile:
            itemListHalf = int(len(itemList) / 2)
            compartment1 = itemList[0:itemListHalf]
            compartment2 = itemList[itemListHalf:]

            commonItem = find_common_item(compartment1,compartment2)
            prioritySum += calculate_item_priority(commonItem)
    
    print(f"solution to part1: {prioritySum}")

