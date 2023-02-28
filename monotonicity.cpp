#include <iostream>

size_t monotonicity(const int a[], size_t size, size_t& len) {
    
    int pt = 0;

    int pt_malejacy = 0;
    int len_malejacy = 0;
    int len_malejacy2 = 0;

    int index = 0;
    int len2 = 0;
    len = 0;

    bool mal = false;

    for (int i = 0; i < size; i++)
    {
        if (a[i] > a[i-1] && i + 2 < size && i - 1 != -1)
        {
            pt = i;
        }
        else if (a[i] < a[pt] && a[pt] > a[pt - 1])
        {
            if (len > len2)
            {
                len2 = len;
                len = 1;
            }
        }
        else if (pt > 0)
        {
            if (i + 1 == size && a[i] > a[pt - 1])
            {
                len--;
            }
        }

        if (a[i] < a[i-1] && i+2 < size && i - 1 != -1)
        {
            mal = true;
            pt_malejacy = i;
        }
        else if (a[i] > a[pt_malejacy] && a[pt_malejacy] < a[pt_malejacy - 1])   
        {
            if (len_malejacy > len_malejacy2)
            {
                len_malejacy2 = len_malejacy;
                len_malejacy = 2;
                if (pt_malejacy > 0 && pt == 0)
                {
                    len -= 2;
                }
            }
        }
        else if (pt_malejacy > 0)
        {
            if (i + 1 == size && a[i] < a[pt_malejacy - 1])
            {
                len_malejacy--;
            }
        }

         len++;
         if (mal == true)
         {
             len_malejacy++;
         }
    }


    if (len > len2)
    {
        index = pt;
    }
    if (len_malejacy > len_malejacy2 && len_malejacy > len)
    {
        index = pt_malejacy;
        len = len_malejacy;
    }
    else if (len_malejacy == len_malejacy2 && len_malejacy > len)
    {
         if (index < pt_malejacy)
         {
             index = index;
         }
         len = len_malejacy;
    }
    else if (len_malejacy == len && len > len2)
    {
         if (pt < pt_malejacy)
         {
             index = pt;
         }
         else
         {
             index = pt_malejacy;
         }
    }
    return index; 
}

void printResult(const int a[], size_t size,
    size_t ind, size_t len) {
    using std::cout;
    cout << "In array [ ";
    for (size_t i = 0; i < size; ++i) cout << a[i] << " ";
    cout << "]\nthe first longest "
        "monotonic sequence is\n[ ";
    for (size_t i = ind; i < ind + len; ++i)
        cout << a[i] << " ";
    cout << "] starting at index " << ind
        << " and of length " << len << "\n\n";
}

int main() {
    size_t len = 0, ind = 0, size = 0;
    
    int a1[] = { 4,4,5,4,4 };
    size = sizeof(a1) / sizeof(*a1);
    ind = monotonicity(a1, size, len);
    printResult(a1, size, ind, len);

    int a2[] = { 4,4,5,4,4,4 };
    size = sizeof(a2) / sizeof(*a2);
    ind = monotonicity(a2, size, len);
    printResult(a2, size, ind, len);

    int a3[] = { 4,5,4,4,5 };
    size = sizeof(a3) / sizeof(*a3);
    ind = monotonicity(a3, size, len);
    printResult(a3, size, ind, len);

    /*

    int a4[] = { 3,3,2,3,3 };
    size = sizeof(a4) / sizeof(*a4);
    ind = monotonicity(a4, size, len);
    printResult(a4, size, ind, len);

    int a5[] = { 3,3,3,3,3 };
    size = sizeof(a5) / sizeof(*a5);
    ind = monotonicity(a5, size, len);
    printResult(a5, size, ind, len);

    int a6[] = { 7, 2, 2, 1, 5, 7, 1, 3 };
    size = sizeof(a6) / sizeof(*a6);
    ind = monotonicity(a6, size, len);
    printResult(a6, size, ind, len);

    */
    
}
