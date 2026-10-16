#include <stdio.h>

typedef struct {
    double min_temp;
    double max_temp;
    double average;
}HOMERSEKLET;

HOMERSEKLET analyze_temperatures(double *celsius_data, int count);

int main() {
    int n;
    printf("n=");
    scanf("%i", &n);
    double celsius[n];
    for (int i = 0; i < n; i++) {
        scanf("%lf", &celsius[i]);
    }
    HOMERSEKLET ho = analyze_temperatures(celsius, n);
    printf("Atlag: %lf\nMin: %lf\nMax: %lf\n " ,ho.average, ho.min_temp, ho.max_temp);
    
    return 0;
}


// Kiszamolja a statisztikakat es atvaltja a homersekleteket Fahrenheitre.
HOMERSEKLET analyze_temperatures(double *celsius_data, int count) {
    double sum = 0.0;          
    double average = 0.0;
    double min_temp = 9999.0;
    double max_temp = -9999.0;
    int valid_count = 0;
    int i = 0;

    // Kiszűrjük a hibás hosszúságot
    if (count <= 0) {
        printf("Nincs elem a tombben.\n");
       
    }

    // Túlcsordulás elleni védelem a lokális tömb miatt
    if (count > 100) {
        count = 100;
    }

    // Minimum, maximum keresése és összegzés
    for (i = 0; i < count; i++) {
        double current_celsius = celsius_data[i];
        
        sum = sum + current_celsius;
        valid_count = valid_count + 1;

        if (current_celsius < min_temp) {
            min_temp = current_celsius;
        }

        if (current_celsius > max_temp) {
            max_temp = current_celsius;
        }
    }
    average = sum / (double)valid_count;

    HOMERSEKLET ho;
    ho.min_temp=min_temp;
    ho.max_temp=max_temp;
    ho.average=average;

    return ho;
}
