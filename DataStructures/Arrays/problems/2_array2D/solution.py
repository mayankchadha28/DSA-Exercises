
# Step1: State the problem
# Given is a 2D array that contains 6 rows and 6 cols. An hour glass shape is represented in sub elements of array. Calculate the possible array elements that form an hour glass and calculate the sum.
# return the sum of the highest hourglass

# Step2: IDENTIFY INPUTS & OUTPUTS, Funtion Signature 
# INPUT: A 2D Array
# OUTPUT: Number

def hourGlass(arr):
    pass


# Step3: CREATE TEST CASES & LIST EDGE CASES
arr = [
    [-9, -9, -9,  1, 1, 1 ], 
    [ 0, -9,  0,  4, 3, 2], 
    [-9, -9, -9,  1, 2, 3], 
    [0,  0,  8,  6 ,6, 0],
    [0,  0,  0, -2, 0, 0],
    [0,  0,  1 , 2, 4, 0]  
    ]

# 1. Index at last array

# Step4: Solution in English
# loop through each row and each array inside row. as it is also fixed the hour glass cannot cnavigate more than 4 times to right and down
# its always the first 3 elements in the first row. followed by 2nd element in second row and first 3 in the second row
# create an array to store sum of all the hourglasses
# loop to the result arrray to return the highest number

def hourGlass(arr):
    finalArr = []
    largestVal = None
    maxLoopLimit = 4

    for i, row in enumerate(arr): 
        
        for j, val in enumerate(arr[i]):
            if i < maxLoopLimit and j < maxLoopLimit:
                
                first_sum = arr[i][j] + arr[i][j+1] + arr[i][j+2]
                second_sum = arr[i+1][j+1] 
                third_sum = arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2]

                total = first_sum + second_sum + third_sum
                finalArr.append(total)


    largestVal = finalArr[0]
    for currentVal in finalArr:
        if currentVal > largestVal:
            largestVal = currentVal

    # print("FinalArr", finalArr)
    
    return largestVal
    
print(hourGlass(arr))

