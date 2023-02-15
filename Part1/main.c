#include <stdio.h>
#include <string.h>

struct Month{
    const char *name[1];
    double sales;
};

//bubble sort data based on data[i].sales
void sortLists(struct Month *data){
    // struct Month test[] = **data;

    for (int i = 0; i < 12; ++i)
    {
        for (int j = 0; j < 12; ++j)
        {
            if (data[i].sales > data[j].sales)
            {
                struct Month temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
    // printf("finished");
}
int main(int argc, char const *argv[])
{
    const char *cMonths[12];
    cMonths[0] = "January";
    cMonths[1] = "February";
    cMonths[2] = "March";
    cMonths[3] = "April";
    cMonths[4] = "May";
    cMonths[5] = "June";
    cMonths[6] = "July";
    cMonths[7] = "August";
    cMonths[8] = "September";
    cMonths[9] = "October";
    cMonths[10] = "November";
    cMonths[11] = "December";

    FILE *file = fopen(argv[1], "r");
    double total = 0;
    struct Month data[12];
    printf("\nMonth Sales report:\n");

    int max=0, min=0;
    for (int i = 0; i < 12; ++i)
    {   
        double buff = 0;
        fscanf(file, "%le", &buff);
        total += buff;
        if (buff > data[max].sales) max = i;
        if (buff < data[min].sales) min = i;
        
        data[i] = (struct Month){.name = (cMonths[i]), .sales = buff};
        printf("%s: $%0.2f\n", *data[i].name, data[i].sales);

        
    }
    

    
    
    printf("\nSales Summary:\n");
    // printf("Total Sales: $%0.2f\n", total);
    printf("Highest Sales: $%0.2f - (%s)\n", data[max].sales, *data[max].name);
    printf("Lowest Sales: $%0.2f - (%s)\n", data[min].sales, *data[min].name);
    printf("Average Sales: $%0.2f\n", total/12);


    printf("\n6-Month Rolling Average:\n");
    for (int i = 0; i < 7; ++i)
    {
        double avg = 0;
        for (int j = i; j < i + 6; j++)
        {
            avg += data[j].sales;
        }
        printf("%s - %s: $%0.2f\n", cMonths[i], cMonths[i+6], avg/6);
    }

    sortLists(data); // Sort high to low
    printf("\nSales Report (Highest to Lowest):\n");
    for (int i = 0; i < 12; ++i)
    {
        printf("%s: $%0.2f\n", *data[i].name, data[i].sales);
    }
    return 0;
}