void merge(Ranking array[], int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
  
    // Tworze pomocnicze tablice
    auto *leftArray = new Ranking[subArrayOne],
         *rightArray = new Ranking[subArrayTwo];
  
    // kopiuje dane do pomocniczych tablic
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

  
    auto indexOfSubArrayOne = 0, // Adresy Tablic
        indexOfSubArrayTwo = 0; 
    int indexOfMergedArray = left; 
  
    // ponowne laczenie w tablice
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne].rate <= rightArray[indexOfSubArrayTwo].rate) 
        {
            array[indexOfMergedArray].rate = leftArray[indexOfSubArrayOne].rate;
            array[indexOfMergedArray].name = leftArray[indexOfSubArrayOne].name;
            indexOfSubArrayOne++;
        }
        else 
        {
            array[indexOfMergedArray].rate = rightArray[indexOfSubArrayTwo].rate;
            array[indexOfMergedArray].name = rightArray[indexOfSubArrayTwo].name;
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

//kopiowanie elementow jesli nie trzeba bylo ich zamieniac
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray].rate = leftArray[indexOfSubArrayOne].rate;
        array[indexOfMergedArray].name = leftArray[indexOfSubArrayOne].name;
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
//kopiowanie elementow jesli nie trzeba bylo ich zamieniac
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray].rate = rightArray[indexOfSubArrayTwo].rate;
        array[indexOfMergedArray].name = rightArray[indexOfSubArrayTwo].name;
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] rightArray;
    delete[] leftArray;

}

  
// wykonanie rekurencyjne
void mergeSort(Ranking array[], int const begin, int const end)
{
    if (begin >= end)
        return;
  
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}
  
