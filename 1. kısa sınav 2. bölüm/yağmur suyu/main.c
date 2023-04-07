#include <stdio.h>

//Akif Silan 12205505044
int maksimum_su_kapasitesi (int yukseklik[], int n) {
	
    int sol_maks[n], sag_maks[n];
    int i, su_kapasitesi = 0;
   
    sol_maks[0] = yukseklik[0];
    
	for (i = 1; i < n; i++) {  //sol tarafıyla kendi yüksekliğini ölçüyoruz
    	if(sol_maks[i-1] > yukseklik[i])
    	{
    		sol_maks[i] = sol_maks[i-1];
		}
		else
		{
			sol_maks[i] =  yukseklik[i];
		}
        sol_maks[i] = sol_maks[i-1] > yukseklik[i] ? sol_maks[i-1] : yukseklik[i];
    }

    sag_maks[n-1] = yukseklik[n-1];
    
    for (i = n-2; i >= 0; i--) {  //sağ tarafıyla kendi yüksekliğini ölçüyoruz
    	if (sag_maks[i+1] > yukseklik[i]) 
		{		
		   	sag_maks[i] =sag_maks[i+1]; 
    	}
    	else 
		{		
    	sag_maks[i]=  yukseklik[i];
    	}
        
    }

    for (i = 0; i < n; i++) {  //su kapasitesini hesaplıyoruz
    	if (sol_maks[i] < sag_maks[i])
    	{		
    	su_kapasitesi += (sol_maks[i] - yukseklik[i]);
    	}
    	else {		
    	su_kapasitesi += (sag_maks[i] - yukseklik[i]) ;
    	}       
    }

    return su_kapasitesi;
}

int main() {  // ve ekrana yazdırıyoruz
    int yukseklik[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n = sizeof(yukseklik) / sizeof(yukseklik[0]);
    printf("%d\n", maksimum_su_kapasitesi(yukseklik, n)); 

    return 0;
}

