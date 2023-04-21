import sys
import itertools

# Checking Memory Usage of Any Object
dic = {'a': 3, 'b': 2, 'c': 1, 'd': 1}
print(sys.getsizeof(dic))

# Sort List of Tuples by Any Index of Tuple Value
val = [('first', 3, 9), ('second', 4, 6), ('third', 2, 3)]
val.sort(key = lambda x: x[2], reverse=False)
print(val)

# Wise Use of Python Dictionary Comprehension
dic = [(str(i), i*2) for i in range(5)]
print(dict(dic))

# Permutation (list_elements, #elements_x_group)
list(itertools.permutations('HAPPY', 2))

# combitation with repetitions (list_elements, #elements_x_group)
list(itertools.combinations_with_replacement('HAPPY', 2))

# combitation without repetitions (list_elements, #elements_x_group)
list(itertools.combinations('HAPPY', 2))