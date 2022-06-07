#include <stdio.h>
#include <stdlib.h> 
static int total_nodes;

void printSubset(int A[], int size)
{
    printf("\nWeight : ");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int comparator(const void *pLhs, const void *pRhs)
{
    int *lhs = (int *)pLhs;
    int *rhs = (int *)pRhs;
    return *lhs > *rhs;
}

void subset_sum(int s[], int t[],int s_size, int t_size,int sum, int ite,int const target_sum) 
{
    total_nodes++;
    if( target_sum == sum )
    {
        printSubset(t, t_size);
        if( ite + 1 < s_size && sum - s[ite] + s[ite+1] <= target_sum )
        {
            subset_sum(s, t, s_size, t_size-1, sum - s[ite], ite + 1, target_sum);
        }
        return;
    }
    else
    {
        if( ite < s_size && sum + s[ite] <= target_sum )
        {
            for( int i = ite; i < s_size; i++ )
            {
                t[t_size] = s[i];
                if( sum + s[i] <= target_sum )
                {
                    subset_sum(s, t, s_size, t_size + 1, sum + s[i], i + 1, target_sum);
                }
            }
        }
    }
}


void generateSubsets(int s[], int size, int target_sum)
{
    int *tuplet_vector = (int *)malloc(size * sizeof(int));
    int total = 0;
    qsort(s, size, sizeof(int), &comparator);
    for( int i = 0; i < size; i++ )
    {
        total += s[i];
    }
    if( s[0] <= target_sum && total >= target_sum )
    {
        subset_sum(s, tuplet_vector, size, 0, 0, 0, target_sum);
    }
    free(tuplet_vector);
}


int main()
{
//  int weights[] = {15, 22, 14, 26, 32, 9, 16, 8};
    int n;
    printf("Number of weight : ");
    scanf("%d", &n);

    int weights[n];
    printf("\nEnter the %d weights : ",n);
    for(int i=0; i < n; i++){
        scanf("%d", &weights[i]);
    }

 int target ;
    printf("\nEnter target : ");
    scanf("%d", &target); 
 generateSubsets(weights, n, target);
 printf("\nNodes generated %d\n", total_nodes);
 return 0;
} 