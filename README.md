# Sorting Algorithm Visualizer
## What this app does:
##### This app visualizes the different sorting algorithm using bars to represent an array of elements that are comparable (in this case comparable with their height). 
##### This app currently supports the following sorting algorithms: Merge Sort, Quick Sort, Bubble Sort, Selection Sort.


## Technologies used:
##### This app is made using C++ and Cinder UI library to handle graphics. You'll need to install and set up Cinder to work with the app. 

## How to use the app:
##### The UI is pretty intuitive with their respective buttons.
##### To use the extra features you need to utilize certain key presses.
#### Key Presses:
##### 'w' is for speeding up the simulation
##### 's' is for slowing down the simulation
##### 'c' is used for simulating all algorithms together but using a sorted array. This is done to observe the stability of the sorting algorithms on worst case (a sorted array)

## Results and findings:
##### For pseudo-randomly generated arrays:
##### Both quick sort and merge sort have similar time complexities with quick sort usually finishing first. This supports the fact that both sorting algorithms are O(n(log(n))
##### Both selection sort and bubble sort have poorer performance with bubble sort usually doing the worst. This supports the fact that both sorting algorithm are O(n^2)
##### At arrays of higher sizes the difference between these algorithm would follow their big O time complexities more closely.
##### For pre-sorted array quick sort that is previously the best became the slowest performing algorithm. Merge sort however, stay consistent and produce the best performance

## Conclusion:
##### Merge Sort is the most stable sorting algorithm with the same big O time complexity for best case and worst case scenarios: O(nlog(n))

