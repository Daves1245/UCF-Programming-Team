#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <math.h>

#include "include/colors.h"
#include "include/swap.h"
#include "src/bubble.h"
#include "src/quicksort.h"
#include "src/selection.h"
#include "src/insertion.h"
#include "src/merge.h"
#include "src/counting.h"
#include "src/radix.h"

#define MAX_ARRAY_SIZE 5000
#define MAX_ELEMENT_SIZE 1000
#define ITERATIONS 100

#define MS_PER_SEC 1000

/* -------------------------------- Benchmarking boilerplate -------------------------------- */

/* Context for benchmarking information */
struct benchmark_context {
    int *arr;                  /* Array to be sorted */
    int *arrcpy;               /* Used by counting sort */
    int *arrcount;             /* Used by counting sort */
    int iterations;            /* Number of times to sort array */
    int max_element_size;      /* Max value any element of array can take */
    int max_array_size;        /* Maximum size of the array */
    int verbose;               /* Print out info while performing benchmark */
    int index_failed;          /* If positive, index of first unsorted element */
    int *left, *right;     /* Optional external swap arrays for mergesort */
} ctx;

/* Context for sorting function information */
struct sort_context {
    char *name;
    void (*sort_func)(void);
    void (*wrapper)(void (*)(void), struct benchmark_context *);
};

/* Most sorting functions just need the array and the size of the array */
void default_wrapper(void (*sort_func)(void), struct benchmark_context *ctx) {
    void (*sort)(int *, int) = (void (*)(int *, int)) sort_func;
    sort(ctx->arr, ctx->max_array_size);
}

/* Counting sort needs to know the maximum value of an element */
void counting_sort_wrapper(void *(sort_func)(void), struct benchmark_context *ctx) {
    void (*sort)(int *, int, int *, int *, int) = (void (*)(int *, int, int *, int*, int)) sort_func;
    sort(ctx->arr, ctx->max_array_size, ctx->arrcpy, ctx->arrcount, ctx->max_element_size);
}

/* Radix sort also needs extra information */
void radix_sort_wrapper(void *(sort_func)(void), struct benchmark_context *ctx) {
    void (*sort)(int *, int *, int, int, int) = (void (*)(int *, int *, int, int, int))(sort_func);
    sort(ctx->arr, ctx->arrcpy, ctx->max_array_size, 10, ctx->max_element_size);
}

void merge_sort_wrapper(void *(sort_func)(void), struct benchmark_context *ctx) {
    void (*sort)(int *, int, int *, int *) = (void (*)(int *, int, int *, int *)) (sort_func);
    sort(ctx->arr, ctx->max_array_size, ctx->left, ctx->right);
}

/* -------------------------------- Benchmarking boilerplate -------------------------------- */

/* The lower bits of a random number
 * generated using rand() are distressingly
 * nonrandom, so we use this method to generate
 * a random number within [min,max]
 */
inline int rng(long int max) {
    // return (int) ((double)(min + rand()) / ((double) RAND_MAX / ((double) (max - min + 1) + 1)));
    return (int) ((double) rand() / ((double) RAND_MAX + 1) * max);
}

/* Fill an array with random values up to MAX_VALUE */
void fill_random(int *arr, size_t len) {
    for (int i = 0; i < len; i++) {
        arr[i] = rng(MAX_ELEMENT_SIZE); 
    }
}

/* Print the elements in an array */
void print_arr(int *arr, size_t len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    puts("");
}

/* Check if an array is sorted */
int sorted(int *arr, size_t len) {
    for (int i = 1; i < len; i++) {
        if (arr[i] < arr[i - 1]) {
            return 0;
        }
    }
    return 1;
}

struct time_results {
    double avg;
    double best;
    double worst;
};

/* Perform a benchmark on a sorting function */
void benchmark(struct sort_context *s_ctx, struct benchmark_context *bm_ctx, struct time_results *t) {
    clock_t start, end;
    double avgt = 0, best_time = LONG_MAX, worst_time = 0, cur;
    bm_ctx->index_failed = -1;
    for (int i = 1; i <= bm_ctx->iterations; i++) {
        fill_random(bm_ctx->arr, bm_ctx->max_array_size);
        //clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
        bm_ctx->left = malloc(sizeof(int) * bm_ctx->max_array_size);
        bm_ctx->right = malloc(sizeof(int) * bm_ctx->max_array_size);
        if (!bm_ctx->left || !bm_ctx->right) {
            fprintf(stderr, "Could not allocate temporary memory\n");
        }
        start = clock();
        s_ctx->wrapper(s_ctx->sort_func, bm_ctx);
        end = clock();
        //clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
        /* We're measuring ms */
        cur = (MS_PER_SEC * (double)(end - start) / CLOCKS_PER_SEC);
        if (cur < best_time) {
            best_time = cur;
        }
        if (cur > worst_time) {
            worst_time = cur;
        }
        avgt += cur / bm_ctx->iterations;
        if (avgt < 0) {
            for (int i = 0; i < 3; i++) {
                printf("avgt: %f\n", avgt);
            }
        }
        if (bm_ctx->verbose) {
            print_arr(bm_ctx->arr, bm_ctx->max_array_size);
        }
        if (sorted(bm_ctx->arr, bm_ctx->max_array_size)) {
            printf("\tCase " YELLOW "#%d:" ANSI_RESET " [" GREEN "PASSED" ANSI_RESET "]\r", i);
        } else {
            // XXX set "if (sorted)", it's out of place
            bm_ctx->index_failed = i;
            break;
        }
    }
    t->avg = avgt;
    t->best = best_time;
    t->worst = worst_time;
}

int main(int argc, char **argv) {
//    int num_sorts = 8;
    int num_sorts = 3;

    srand(time(NULL));
    if (argc > 1) {
        ctx.max_array_size = atoi(argv[1]);
    } else {
        ctx.max_array_size = MAX_ARRAY_SIZE;
    } if (argc > 2) {
        ctx.iterations = atoi(argv[2]); 
    } else {
        ctx.iterations = ITERATIONS;
    } if (argc > 3) {
        if (strcmp(argv[3], "-v") == 0 || strcmp(argv[3], "--verbose") == 0) {
            ctx.verbose = 1;
        }
    }
    ctx.max_element_size = MAX_ELEMENT_SIZE;

    ctx.arr = malloc(sizeof(int) * ctx.max_array_size);
    ctx.arrcpy = malloc(sizeof(int) * ctx.max_array_size);
    ctx.arrcount = malloc(sizeof(int) * ctx.max_element_size);

    struct sort_context sortfuncs[] = {
        /*{"Insertion Sort", insertion_sort, default_wrapper},
        {"Selection Sort", selection_sort, default_wrapper},
        {"Bubble Sort", bubble_sort, default_wrapper},
        {"Merge Sort", merge_sort, merge_sort_wrapper},
        */{"Quick Sort", quick_sort, default_wrapper},
        {"Hoare-Partition Quick Sort", hoare_quick_sort, default_wrapper},
        {"Randomized-Partition Quick Sort", randomized_quick_sort, default_wrapper},
        {"Counting Sort", counting_sort, counting_sort_wrapper},
        {"Radix Sort", radix_sort, radix_sort_wrapper}
    };

    printf("Sorting %d arrays with %d randomly generated numbers...\n", ctx.iterations, ctx.max_array_size);
    for (int i = 0; i < num_sorts; i++) {
        printf(CYAN "%s:\n" ANSI_RESET, sortfuncs[i].name);
        struct time_results times;
        benchmark(&sortfuncs[i], &ctx, &times);
        if (ctx.index_failed > 0) {
            fprintf(stderr, "Case " YELLOW "#%d:" ANSI_RESET "[" RED "FAILED" ANSI_RESET "]\n", i);
            fprintf(stderr, "Contents of arr: ");
            for (int i = 0; i < ctx.max_array_size; i++) {
                if (i == ctx.index_failed) {
                    printf(RED "%d " ANSI_RESET, ctx.arr[i]);
                } else {
                    printf("%d ", ctx.arr[i]);
                }
            }
        } else {
            printf(GREEN "PASSED ALL TEST CASES" ANSI_RESET " (best = " GREEN "%.3fms" ANSI_RESET ", avg = " YELLOW "%.3fms" ANSI_RESET", worst = " RED "%.3f" ANSI_RESET "ms)\n", times.best, times.avg, times.worst);
        }
    }
    free(ctx.left);
    free(ctx.right);
    return 0;
}
