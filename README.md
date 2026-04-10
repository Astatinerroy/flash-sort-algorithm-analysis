# Flash Sort Algorithm Analysis EB3/68311/23

**Name:** Roy Kiprop  
**Registration Number:** EB3/67311/23  
**Programming Language:** C++  

## Project Description
This project implements the **Flash Sort algorithm**, a distribution-based sorting algorithm designed for large datasets.  
The program sorts a list of integers without using any built-in sorting functions and keeps track of:

- Number of comparisons  
- Number of swaps  

---

## How Flash Sort Works

1. **Classification:** Divides elements into classes based on value distribution.  
2. **Permutation:** Rearranges elements into approximate correct positions.  
3. **Final Insertion Sort:** Applies insertion sort to finalize ordering.  

**Step-by-step example:**  
Input: `[5, 2, 9, 1]`  
Pass 1: Classify → `[1, 2, 5, 9]`  
Pass 2: Rearrange → `[1, 2, 5, 9]`  
Pass 3: Final insertion sort → `[1, 2, 5, 9]`  
Output: `[1, 2, 5, 9]`

---

## Time Complexity

| Case | Complexity |
|------|------------|
| Best | O(n)       |
| Average | O(n)    |
| Worst | O(n²)     |

**Reasoning:**  
- Best case: Already distributed evenly, minimal swaps  
- Average case: Data partially sorted, moderate swaps  
- Worst case: All elements in wrong positions, maximum swaps  

---

## Space Complexity

- O(n) → Uses an extra array for classification (`L` array)  

---

## Experiment Results

| Input Size | Comparisons | Swaps |
|------------|------------|-------|
| 10         | X          | X     |
| 250        | X          | X     |
| 999        | X          | X     |
| 9999       | X          | X     |

*(Replace X with your program outputs)*

---

## How to Run

1. Compile the C++ code:  
```bash
g++ flashsort.cpp -o flashsort
