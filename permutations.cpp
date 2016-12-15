#include <iostream>
#include <vector>

using It = std::vector<int>::iterator;

void printVec(It begin, It end)
{
    for ( auto i = begin; i != end; ++i)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}

void permutate(std::vector<int> &vec, size_t positionSwapped)
{
    if (positionSwapped == vec.size())
    {
        printVec(vec.begin(), vec.end());
    }

    for (size_t i = positionSwapped; i < vec.size(); ++i)
    {
        std::swap(vec[positionSwapped], vec[i]);
        permutate(vec, positionSwapped+1);
        std::swap(vec[i],               vec[positionSwapped]);
    }
}

void permute(std::vector<int> vec)
{
    permutate(vec, 0);
}

int main()
{
    std::vector<int> vec {1,2,3};
    permute(vec);
}
