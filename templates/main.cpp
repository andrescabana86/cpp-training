/**
 * Templates are a way of abstraction
 * template <template params>
 * typeReturned fnName(...) {}
 */
#include <iostream>

template <size_t size>
void print(const int (&array)[size][size])
{
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << i << ": ";
        for (size_t j = 0; j < size; ++j) {
            std::cout << array[i][j] << '\t';
        }
        std::cout << std::endl;
    }
}

template <size_t size>
void printPtr(int **array)
{
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << i << ": ";
        for (size_t j = 0; j < size; ++j) {
            std::cout << array[i][j] << '\t';
        }
        std::cout << std::endl;
    }
}

template <size_t size>
void transpose(const int (&array)[size][size], int (&result)[size][size])
{
    for (size_t i = 0; i < size; ++i)
    {
        for (size_t j = 0; j < size; ++j) {
            result[j][i] = array[i][j];
        }
    }
}

template <size_t size>
void transposePtr(const int (&array)[size][size], int **result)
{
    for (size_t i = 0; i < size; ++i)
    {
        for (size_t j = 0; j < size; ++j) {
            result[j][i] = array[i][j];
        }
    }
}

int main() {
    // using a fixed size two dim array
    const int size = 3;
    int twoDimArr[size][size] = {
        1,2,3,4,
        5,6,7,8,
        9
    };
    int result[size][size];

    print<size>(twoDimArr);
    transpose(twoDimArr, result);
    print<size>(result);

    // using two dim pointer array
    int ** ptrResult = new int*[size];
    for (size_t i = 0; i < size; ++i)
    {
        ptrResult[i] = new int[size];
    }

    transposePtr<size>(twoDimArr, ptrResult);
    printPtr<size>(ptrResult);


    return 0;
}