# Selection Sort Algorithm
This C code implements the selection sort algorithm to sort an array of structures in ascending order based on the key field. The program reads data from a CSV file, performs the selection sort, and outputs the sorted data.

## Getting Started
To compile and run the code, follow these steps:

1. Make sure you have a C compiler installed on your system (e.g., GCC).
2. Save the source code and the data file to the same directory.
3. Open a terminal or command prompt and navigate to the directory where the code file is located.
4. Run the following command to compile the code:

   ```bash
   gcc -o program selectionsort.c
   ```

   This command will generate an executable file named `program`.

5. Run the program:

   ```bash
   ./program
   ```

## Usage
Upon running the program, it will read the data from the `data.csv` file and perform the selection sort algorithm to sort the data based on the key field. The sorted data will be printed before and after the sorting process.

## Sample Data
The sample data you provided has the following format:

```
Key    Data1    Data2    Data3
-------------------------------
5      100.5    200.5    300.5
17     101.7    201.7    301.7
3      100.3    200.3    300.3
6      100.6    200.6    300.6
12     101.2    201.2    301.2
20     102      202      302
15     101.5    201.5    301.5
1      100.1    200.1    300.1
17     101.7    201.7    301.7
9      100.9    200.9    300.9
```

Each line represents a single data entry, with the key value followed by three data values (Data1, Data2, and Data3) separated by tabs or spaces.
Ensure that your data file follows this format and is named `data.csv` for the program to read it correctly.

## Implementation Details
The code defines a structure named `data` with the following fields:

- `key`: An integer representing the key used for sorting.
- `data1`, `data2`, `data3`: Double values representing additional data associated with the key.

The code reads data from the `data.csv` file using the `read_data` function. The function attempts to open the file and read each line, parsing the key and data values into the array of `data` structures.
The `selection_sort` function performs the selection sort algorithm on the array of structures to sort them in ascending order based on the key field. It calls the `search_min` function to find the index of the minimum key value between the `min` and `n` indices. The `swap` function is used to swap the positions of two elements in the array.
The `print_data` function is responsible for printing the key and data values of each structure in the array.

## Limitations
- The code assumes that the data file (`data.csv`) is properly formatted with the correct number of values per line and follows the key, data1, data2, data3 order.
- The code has a fixed array size of 1000 for storing the data entries. Ensure that the number of entries in the data file does not exceed this limit.
- The code does not handle errors or exceptions that may occur during file I/O operations.

## License
This project is licensed under the MIT License. Feel free to use and modify the code as per your requirements.
