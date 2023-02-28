#include <iostream>
#include <cstdio>   
#include <cmath>
#include <vector>

bool sumOfTwo(const std::vector<int>& v, int val, int& i, int& j)
{
    int size = sizeof(v) / sizeof(v[0]);
    bool isSumEqualVal = false;
    int sum = 0;

    int a = 0;
    int b = 0;

    auto endingPoint = v.begin();
    auto ve = v.end() - 1;

    for (auto it = v.begin(); it != v.end(); it++)
    {
        sum = *endingPoint + *it;
        a++;

        if (*it == *ve && *endingPoint != *ve)
        {
            a = b;
            b++;
            it = endingPoint;
            endingPoint++;
        }
        else if (it == v.end() - 1 && endingPoint == v.end() - 1)
        {
            it = v.end() - 1;
        }

        if (val == sum)
        {
            i = b;
            j = a;
            isSumEqualVal = true;
        }
        else if (it == v.end()-1 && isSumEqualVal == false)
        {
            i = -1;
            j = -1;
            isSumEqualVal = false;
        }
    }

    return isSumEqualVal;
}

int main() {
    int i = 0, j = 0, val = 0;
    std::vector<int> a{ 2, 4, 5, 8, 9, 11, 13, 15, 18 };
    val = 21;
    //val = 33;
    //val = 200;
    bool isSum = sumOfTwo(a, val, i, j);
}
