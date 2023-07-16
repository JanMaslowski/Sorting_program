void quickSort(Ranking *tab, int lewy, int prawy)
{
	if(prawy <= lewy) return;
	
	int i = lewy - 1, j = prawy + 1, 
	pivot = tab[(lewy+prawy)/2].rate; //wybieramy punkt odniesienia
	
	while(1) 
	{
		//szukam elementu wiekszego lub rownego piwot stojacego
		//po prawej stronie wartosci pivot
		while(pivot>tab[++i].rate);
		
		//szukam elementu mniejszego lub rownego pivot stojacego
		//po lewej stronie wartosci pivot
		while(pivot<tab[--j].rate);
		
		//jesli liczniki sie nie minely to zamień elementy ze soba
		//stojace po niewlasciwej stronie elementu pivot
		if( i <= j)
        {
			//funkcja swap zamienia wartosciami tab.rate.rate[i] z tab.rate.rate[j]
			swap(tab[i].rate,tab[j].rate);
            swap(tab[i].name,tab[j].name);
        }
        else
        {
			break;
        } 
	}

	if(j > lewy)
	quickSort(tab, lewy, j);
	if(i < prawy)
	quickSort(tab, i, prawy);
}