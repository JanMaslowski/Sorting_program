
using namespace std;

void bucketSort(Ranking tab[], int n)
{

Ranking *first = new Ranking[500000],//Tworze kubełki
    *second = new Ranking[500000],    
    *third = new Ranking[500000],
    *fourth = new Ranking[500000],
    *fifth = new Ranking[500000];
    int help=0; //tworze indeksy do zliczania elementów w buforach
    int help1=0;
    int help2=0;
    int help3=0;
    int help4=0;
    for(int i=0;i<n;i++)
    {
    if(tab[i].rate==1.0||tab[i].rate==2.0)
    {
    first[help]=tab[i];
    help++;
    }
    else if(tab[i].rate==3.0||tab[i].rate==4.0)
    {
    second[help1]=tab[i];
    help1++;
    }
    else if(tab[i].rate==5.0||tab[i].rate==6.0)
    {
    third[help2]=tab[i];
    help2++;
    }
    else if(tab[i].rate==7.0||tab[i].rate==8.0)
    {
    fourth[help3]=tab[i];
    help3++;
    }
    else if(tab[i].rate==9.0||tab[i].rate==10.0)
    {
    fifth[help4]=tab[i];
    help4++;
    }
    else
    break;
    }
    // sortuje kubełki
    quickSort(first,0,help-1);
    quickSort(second,0,help1-1);
    quickSort(third,0,help2-1);
    quickSort(fourth,0,help3-1);
    quickSort(fifth,0,help4-1);


//scalam kubełki w tablice
    int k=0; 
    for(int g=0;g<help;g++)
    {
        tab[k]=first[g];
        k++;
    }
    
       for(int g=0;g<help1;g++)
    {
        tab[k]=second[g];
        k++;
    }
    for(int g=0;g<help2;g++)
    {
        tab[k]=third[g];
        k++;
    }
    for(int g=0;g<help3;g++)
    {
        tab[k]=fourth[g];
        k++;
    }
    for(int g=0;g<help4;g++)
    {
        tab[k]=fifth[g];
        k++;
    }

    delete[] first;
    delete[] second;
    delete[] third;
    delete[] fourth;
    delete[] fifth;
}
