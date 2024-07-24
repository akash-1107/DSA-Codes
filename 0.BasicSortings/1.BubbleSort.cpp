//har baar j ,j+1 condition ke A/Q swap and isse last me chala jaeyaga sbse bada har baar
void bubble_sort(int arr[], int n)
{
    // bubble sort ->halka element bubble ke tarah upar uthega
    for (int i = n - 1; i >= 0; i--)
    { //i ka value 0 to n ka range batayega ki kaha tak adjacent swapping krna h
        int didSwap = 0;
        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                didSwap = 1; //ek bhi swap nhi mtlb sara jagah pe h sure 
                //becoz har baar loop me swapping full ho rha
            }
        }
        if (didSwap == 0)
        {
            break;
        }
    }
}