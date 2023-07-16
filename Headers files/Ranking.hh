#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstring>
using namespace std;


class Ranking
{
    public:
    string name;
    float rate;
    void add_film(Ranking* tab,string name, float rate,int position);
    void delete_errors();
    int file_lines(string name);
    Ranking* transfer_to_array(int c);
    Ranking* make_ranking(int size);
    Ranking* fill_ranking();
    int sort_good(Ranking* tab, int n);
    void average(Ranking* tab,int n);
};