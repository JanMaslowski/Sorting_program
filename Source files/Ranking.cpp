#include"Ranking.hh"
using namespace std;
Ranking* Ranking::make_ranking(int size)
{
    Ranking* tab=new Ranking[size];
    return tab;
};

void Ranking::add_film(Ranking* tab,string name, float rate,int position)
{
tab[position].name=name;
tab[position].rate=rate;
};

void Ranking::delete_errors()
{
    cout<<"Z pliku podstawowego zostaną usunięte pozycje uszkodzone"<<endl;
    string textLine;
    ifstream ranking ;
    ofstream ranking_ready;
    ranking.open("projekt2_dane.csv");
    ranking_ready.open("projekt_dane.txt");
    if(!ranking.is_open())
    {
        cout<<"Nie wczytano pliku, błąd"<<endl;
    }
    else
    { 
        while(!ranking.eof())
        {
            getline(ranking,textLine);
                int n = textLine.length();
                char buffer[n];
                strcpy(buffer, textLine.c_str());
                if(buffer[n-1]=='0')
                {

                ranking_ready<<textLine<<endl;
                }
        }
        
    }
    ranking_ready.close();
    ranking.close();
    cout<<"Pozycje uszkodzone zostały usunięte"<<endl;
}


Ranking* Ranking::transfer_to_array(int c)
{   
    ifstream ranking ;
    string tmp;
    int l=file_lines("projekt_dane.txt");
    if(c>l) 
    {
        c=l;
    }
    Ranking* tab=make_ranking(c);
    

    ranking.open("projekt_dane.txt");
    if(!ranking.is_open())
    {
        cout<<"Nie wczytano pliku, błąd"<<endl;
    }
    else
    { 
       for ( int i=0 ; i < c; i++)
        {

            float rate_float;
            string name;
            string textLine;
            char comma=',';
            getline(ranking,textLine);
            int count = 0;
            for (int p = 0; (p = textLine.find(comma, p)) != std::string::npos; p++) 
            {
            count++;
            }
            string tmpPartsTab[count+1];
            stringstream ss(textLine);
            for(int n=0;n<=count;n++)
                {
                string substr;
                getline(ss, substr, comma);
                tmpPartsTab[n]=substr;
                while(n<count&&n>0)
                    {
                    name+=substr;
                    break;
                    }
                if(n==count)
                    {
                    rate_float =stof(tmpPartsTab[count]); 

                    break;    
                    }
                }

                add_film(tab,name,rate_float,i);

        }
        ranking.close();
        return tab;
    }
    return 0;
}

int Ranking::file_lines(string name)

{
    string line;
    int count = 0;
    ifstream f(name);
    while(getline(f, line))
    count++;
    return count;
}
int Ranking::sort_good(Ranking* tab,int n)
{
    for (int i=0;i<n;i++)
    {
    if (tab[i].rate<=tab[i+1].rate)
    return 1;
    }
    return 0;
}
void Ranking::average(Ranking* tab,int n)
{
    double x;
    double y;
    double z;
    for (int i=0;i<n;i++)
    {
    y+=tab[i].rate;
    }
    x=y/n;
    if (n%2 == 0)
    {
        z = tab[(n+1)/2].rate+tab[n/2].rate;
        z = z/2;
    }
    else
    {
        z = tab [n/2].rate;
    }

    cout<<"Średnia arytmetyczna : "<<x<<" Mediana : "<<z<<endl;  
}