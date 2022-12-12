def find_common_item(itemList1:str, itemList2:str)->str:
    return list(set(itemList1).intersection(set(itemList2)))[0]


with open("3/input.txt") as f:
    # itemList = f.readline()
    itemList = "vJrwpWtwJgWrhcsFMMfFFhFp"
    itemListHalf = int(len(itemList) / 2)
    compartment1 = itemList[0:itemListHalf]
    compartment2 = itemList[itemListHalf:]

    print(f"itemList: {itemList} \nfirst half: {compartment1} \nsecond half: {compartment2}")
    print(f"common item: {find_common_item(compartment1,compartment2)}")
    