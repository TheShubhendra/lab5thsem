import numpy as np

def remaining_elements(data, low, high):
   return '   ' * low + ' '.join(str(s) for s in data[low:high + 1])
 
  
def Bsearch(data, key):
    low = 0
    high = len(data) - 1
    loc = -1
    mid = (low + high + 1) // 2
    while low <= high and loc == -1:
        print(remaining_elements(data, low, high))
        print('   ' * mid, end='')
        print(' * ')
  
        if key == data[mid]:
            loc = mid 
        elif key < data[mid]:
            high = mid - 1 
        else:
            low = mid + 1  
        mid = (low + high + 1) // 2  
    return loc

def main():
    data = np.random.randint(10, 91, 15)
    data.sort()
    print("Sorted data:", data)
    
    while True:
        key = int(input('Enter your key to search (or -1 to quit): '))
        
        if key == -1:
            break 
        
        loc = Bsearch(data, key)
        
        if loc == -1:
            print('Item not found.')
        else:
            print(f'Item found at index {loc}')

if __name__ == '__main__':
    main()