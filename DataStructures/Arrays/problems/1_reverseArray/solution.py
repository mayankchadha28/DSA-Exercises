#SOURCE - HackerRank
# PROBLEM STATEMENT:
# Reverse the Elements of an Array 
# reverseArray has the following parameter(s):
# int A[n]: the array to reverse
# Returns - int[n]: the reversed array

#STEP 1: STATE THE PROBLEM CLEARLY
# task is to reverse the elements of an array

#STEP 2: IDENTIFY INPUTS & OUTPUTS, Funtion Signature  
# INPUT: A = [1,2,3]
# OUTPUT: [3,2,1]

def reverseArray(arr):
    pass

#STEP 3: CREATE TEST CASES & LIST EDGE CASES
arr1 = [5, 3, 6, 1]

#1. Empty Array
#2. Single Element 

#STEP4: SOLUTION IN ENGLISH
# use the python reverse method

# STEP 5: IMPLEMENT THE SOLUTION (CAN BE BRUTE FORCE)
def reverseArray(arr):
    arr.reverse()
    return arr

sln = reverseArray(arr1)
print(sln)

# STEP 6: ANALYZE COMPLEXITIES & IDENTIFY INEFFICIENCIES
# N/A

# FINAL: IMPROVISE THE SOLUTION

