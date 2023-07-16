#include "Ranking.hh"
#include "quicksort.hh"
#include "mergesort.hh"
#include "bucketsort.hh"
#include <time.h>

int main()
{
    int start,stop;
    Ranking RANKING;
    Ranking* test=new Ranking;
menu:    
    cout<<"|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
cout<<"     Program sortuje Ranking wykorzystując algorytmy:"<<endl;
cout<<"           Quick sort Merge sort Bucket sort         "<<endl;
cout<<"|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
cout<<endl;


cout<<"Wybierz zadanie do wykonania"<<endl;
cout <<"1   Usuń zepsute komórki rankingu"<<endl;
cout<<"2    Wybierz wielkość tablicy do posortowania"<<endl;
cout<<"Możliwe wielkośći: 10 000 ; 100 000 ; 500 000 ; 1 000 000"<<endl;
char menu;
cin>>menu;
switch (menu)
{
    case '1':
    {
    int lines;
    lines=RANKING.file_lines("projekt2_dane.csv");
    cout<<"Liczba pozycji przed usunięciem uszkodzonych danych : "<<lines<<endl;
    start = clock();
    RANKING.delete_errors();
    stop = clock();
    double time = (double)(stop-start)/CLOCKS_PER_SEC;             
    cout<<"Czas naprawiania pliku : "<<time<<"[s]"<<endl;
    lines=RANKING.file_lines("projekt_dane.txt");
    cout<<"Liczba pozycji po usunięciu : "<<lines<<endl;
    cout<<endl;
    goto menu;
    }
    case '2':
    cout<<"Wybierz wielkość tablicy:"<<endl;
    cout<<"1->10 000 , 2->100 000 , 3-> 500 000 , 4->1 000 000"<<endl;
    char number;
    cin>>number;
    switch (number)
    {
        case '1':
        {
        int n=10000;
        Ranking* test_quick=new Ranking;
        test_quick=RANKING.transfer_to_array(n);
        start = clock(); 
        quickSort(test_quick,0,n-1);
        stop = clock();
        double time = (double)(stop-start)/CLOCKS_PER_SEC;             
        cout<<"Czas sortowania algorytmem quick sort : "<<time<<"[s]"<<endl;
        int sortedGood=RANKING.sort_good(test_quick,n);
        RANKING.average(test_quick,n);
    /*
    for(int i=0;i<n;i++)
    {
       cout<<test_quick[i].name<<" || Ocena: ";
       cout<<test_quick[i].rate<<endl;

    }
    cout<<endl;
    */


        Ranking* test_merge=new Ranking;
        test_merge=RANKING.transfer_to_array(n);
        start = clock(); 
        mergeSort(test_merge,0,n-1);
        stop = clock();
        time = (double)(stop-start)/CLOCKS_PER_SEC;             
        cout<<"Czas sortowania algorytmem merge sort : "<<time<<"[s]"<<endl;
        int sortedGood1=RANKING.sort_good(test_merge,n);
        RANKING.average(test_merge,n);

        Ranking* test_bucket=new Ranking;
        test_bucket=RANKING.transfer_to_array(n);
        start = clock(); 
        bucketSort(test_bucket,n);
        stop = clock();
        time = (double)(stop-start)/CLOCKS_PER_SEC;             
        cout<<"Czas sortowania algorytmem bucket sort : "<<time<<"[s]"<<endl;
        RANKING.average(test_bucket,n);
        int sortedGood2=RANKING.sort_good(test_bucket,n);
        if(sortedGood!=0&&sortedGood1!=0&&sortedGood2!=0)
        {
        cout<<"Tablice są posortowane dobrze"<<endl;    
        }
        cout<<endl;
        

        goto menu;
        }
        case '2':
        {
        int n=100000;
        Ranking* test_quick=new Ranking;
        test_quick=RANKING.transfer_to_array(n);
        start = clock(); 
        quickSort(test_quick,0,n-1);
        stop = clock();
        double time = (double)(stop-start)/CLOCKS_PER_SEC;             
        cout<<"Czas sortowania algorytmem quick sort : "<<time<<"[s]"<<endl;
        int sortedGood=RANKING.sort_good(test_quick,n);
        RANKING.average(test_quick,n);
        delete[] test_quick;

        Ranking* test_merge=new Ranking;
        test_merge=RANKING.transfer_to_array(n);
        start = clock(); 
        mergeSort(test_merge,0,n-1);
        stop = clock();
        time = (double)(stop-start)/CLOCKS_PER_SEC;             
        cout<<"Czas sortowania algorytmem merge sort : "<<time<<"[s]"<<endl;
        int sortedGood1=RANKING.sort_good(test_merge,n);
        RANKING.average(test_merge,n);
        delete[] test_merge;

        Ranking* test_bucket=new Ranking;
        test_bucket=RANKING.transfer_to_array(n);
        start = clock(); 
        bucketSort(test_bucket,n);
        stop = clock();
        time = (double)(stop-start)/CLOCKS_PER_SEC;             
        cout<<"Czas sortowania algorytmem bucket sort : "<<time<<"[s]"<<endl;
        RANKING.average(test_bucket,n);
        int sortedGood2=RANKING.sort_good(test_bucket,n);
        if(sortedGood!=0&&sortedGood1!=0&&sortedGood2!=0)
        {
        cout<<"Tablice są posortowane dobrze"<<endl;    
        }
        cout<<endl;
        

        delete[] test_bucket;

        goto menu;
        }
        case '3':
        {
        int n=500000;
        Ranking* test_quick=new Ranking;
        test_quick=RANKING.transfer_to_array(n);
        start = clock(); 
        quickSort(test_quick,0,n-1);
        stop = clock();
        double time = (double)(stop-start)/CLOCKS_PER_SEC;             
        cout<<"Czas sortowania algorytmem quick sort : "<<time<<"[s]"<<endl;
        int sortedGood=RANKING.sort_good(test_quick,n);
        RANKING.average(test_quick,n);
        delete[] test_quick;

        Ranking* test_merge=new Ranking;
        test_merge=RANKING.transfer_to_array(n);
        start = clock(); 
        mergeSort(test_merge,0,n-1);
        stop = clock();
        time = (double)(stop-start)/CLOCKS_PER_SEC;             
        cout<<"Czas sortowania algorytmem merge sort : "<<time<<"[s]"<<endl;
        int sortedGood1=RANKING.sort_good(test_merge,n);
        RANKING.average(test_merge,n);
        delete[] test_merge;

        Ranking* test_bucket=new Ranking;
        test_bucket=RANKING.transfer_to_array(n);
        start = clock(); 
        bucketSort(test_bucket,n);
        stop = clock();
        time = (double)(stop-start)/CLOCKS_PER_SEC;             
        cout<<"Czas sortowania algorytmem bucket sort : "<<time<<"[s]"<<endl;
        RANKING.average(test_bucket,n);
        int sortedGood2=RANKING.sort_good(test_bucket,n);
        if(sortedGood!=0&&sortedGood1!=0&&sortedGood2!=0)
        {
        cout<<"Tablice są posortowane dobrze"<<endl;    
        }
        cout<<endl;
        delete[] test_bucket;

        
        goto menu;
        }

        case '4':
        {
        
        int lines1=RANKING.file_lines("projekt_dane.txt");
        int n=lines1;
        cout<<"Zostanie przeanalizowane "<<lines1<< " pozycji"<<endl;

        Ranking *test_quick=new Ranking;
        test_quick=RANKING.transfer_to_array(n);
        start = clock(); 
        quickSort(test_quick,0,n-1);
        stop = clock();
        double time = (double)(stop-start)/CLOCKS_PER_SEC;             
        cout<<"Czas sortowania algorytmem quick sort : "<<time<<"[s]"<<endl;
        int sortedGood=RANKING.sort_good(test_quick,n);
        RANKING.average(test_quick,n);
        delete[] test_quick;


        Ranking* test_merge=new Ranking;
        test_merge=RANKING.transfer_to_array(n);
        start = clock(); 
        mergeSort(test_merge,0,n-1);
        stop = clock();
        time = (double)(stop-start)/CLOCKS_PER_SEC;             
        cout<<"Czas sortowania algorytmem merge sort : "<<time<<"[s]"<<endl;
        int sortedGood1=RANKING.sort_good(test_merge,n);
        RANKING.average(test_merge,n);
        delete[] test_merge;


        Ranking* test_bucket=new Ranking;
        test_bucket=RANKING.transfer_to_array(n);
        start = clock(); 
        bucketSort(test_bucket,n);
        stop = clock();
        time = (double)(stop-start)/CLOCKS_PER_SEC;             
        cout<<"Czas sortowania algorytmem bucket sort : "<<time<<"[s]"<<endl;
        RANKING.average(test_bucket,n);
        int sortedGood2=RANKING.sort_good(test_bucket,n);
        if(sortedGood!=0&&sortedGood1!=0&&sortedGood2!=0)
        {
        cout<<"Tablice są posortowane dobrze"<<endl;    
        }
        cout<<endl;
        delete[] test_bucket;

        goto menu;
        }

    }
    goto menu;
    break;

}
 
    


};