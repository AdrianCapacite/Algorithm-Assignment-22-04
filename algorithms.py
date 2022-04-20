# make a programming containing sorting algorithms

# sorting algorithms
# bubble sort
def bubble_sort(array):
    for i in range(len(array)):
        for j in range(len(array) - 1):
            if array[j] > array[j + 1]:
                array[j], array[j + 1] = array[j + 1], array[j]
    return array

# recursive bubble sort
def recursive_bubble_sort(array):
    if len(array) < 2:
        return array
    else:
        for i in range(len(array) - 1):
            if array[i] > array[i + 1]:
                array[i], array[i + 1] = array[i + 1], array[i]
        return recursive_bubble_sort(array[:-1]) + [array[-1]]