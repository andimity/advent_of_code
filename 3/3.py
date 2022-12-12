with open("3/input.txt") as f:
    # itemList = f.readline()
    itemList = "vJrwpWtwJgWrhcsFMMfFFhFp"
    itemListHalf = int(len(itemList) / 2)
    compartment1 = itemList[0:itemListHalf]
    compartment2 = itemList[itemListHalf:-1]

    print(f"itemList: {itemList} \nfirst half: {compartment1} \nsecond half: {compartment2}")
    