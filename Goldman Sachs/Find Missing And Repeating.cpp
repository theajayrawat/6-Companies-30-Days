// https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1
// TC: O(N)
// SC: O(1)

class Solution
{
public:
    vector<int> findTwoElement(vector<int> arr, int n)
    {
        // code here
        int repeat = 0;
        int missing = 0;
        for (int i = 0; i < n; i++)
        {
            while (arr[i] != i + 1)
            {
                int index = arr[i] - 1;
                if (arr[index] == index + 1)
                {
                    repeat = arr[index];
                    missing = i + 1;
                    break;
                }
                else
                {
                    swap(arr[i], arr[index]);
                }
            }
        }

        return {repeat, missing};
    }
};