import sys

def merge(list1, list2, compare):
    answer_list = []
    i = j = 0
    while i < len(list1) and j < len(list2):
        if compare(list1[i], list2[j]):
            answer_list.append(list1[i])
            i += 1
        else:
            answer_list.append(list2[j])
            j += 1
    answer_list += list1[i:]
    answer_list += list2[j:]
    return answer_list
  
def merge_sort(nums, compare):
    if len(nums) <= 1:
        return nums[:]
    else:
        mid = int(len(nums) / 2)
        left = merge_sort(nums[: mid], compare)
        right = merge_sort(nums[mid :], compare)
        return merge(left, right, compare)

      
def main():
    nums = [3, 3, 10, 2, -3, 4, sys.maxsize]
    compare_fun = lambda x, y: x < y
    print(merge_sort(nums, compare_fun))

if __name__ == "__main__":
    main()